#! /usr/bin/env python
# -*- coding: utf-8 -*-

# Google's protobuf Messages to SQL
# Copyright (c) 2015, calmwu
# All rights reserved.
# Email: wubo0067@hotmail.com

import sys
import os
import commands
import getopt
import re
import pdb
import shutil

reload(sys)
sys.setdefaultencoding('utf8')

from google.protobuf import descriptor
from google.protobuf import message
from google.protobuf import reflection
from google.protobuf import descriptor_pb2

from google.protobuf import descriptor_database
from google.protobuf import descriptor_pool
from google.protobuf import message_factory

#http://www.blogjava.net/DLevin/archive/2015/04/01/424012.html
import yd_fieldoptions_pb2
#import db_base_pb2

"""
mysql数据类型                           PROTOBUF数据类型
UNSIGNED                                u
INT                                     int32         
BIGINT                                  int64
FLOAT                                   float
DOUBLE                                  double
VARCHAR                                 string
BLOB                                    bytes
"""


#pb数据类型和mysql的列类型对应
pbtyp2sqltype_dict = {
5  : 'INT',
13 : 'INT UNSIGNED',
3  : 'BIGINT',
4  : 'BIGINT UNSIGNED',
8  : 'BOOL',
2  : 'FLOAT UNSIGNED',
1  : 'DOUBLE UNSIGNED',
9  : 'VARCHAR',
12 : 'BLOB',
11 : 'BLOB',
}

def read_proto_ds(proto_ds_file):
    """"""
    proto_ds_fd = open(proto_ds_file, 'rb')
    try:
        proto_ds_content = proto_ds_fd.read()
        print 'file[%s] size[%d]' % (proto_ds_file, len(proto_ds_content))
        return proto_ds_content
    finally:
        proto_ds_fd.close()
    return ""

def create_sql_createtable(message, table_id, tb_name, more_table):
    """"""
    #主键
    tb_primarykey = []
    tb_indexs = []
    tb_unique_indexs = []
    tb_keys = []
    tb_db_field_auto_increment_value = ""
    createtb_sql = ''
    if more_table == False:
        if tb_name != None and tb_name != '':
            createtb_sql = 'CREATE TABLE IF NOT EXISTS %s (\n' % (tb_name)
        else:
            tb_name = message.DESCRIPTOR.name
            createtb_sql = 'CREATE TABLE IF NOT EXISTS %s (\n' % (message.DESCRIPTOR.name)
    else:
        if tb_name != None and tb_name != '':
            createtb_sql = 'CREATE TABLE IF NOT EXISTS %s_%d (\n' % (tb_name,table_id)
        else:
            tb_name = message.DESCRIPTOR.name
            createtb_sql = 'CREATE TABLE IF NOT EXISTS %s_%d (\n' % (message.DESCRIPTOR.name,table_id)
    
    #循环每个字段
    field_line = ''
    db_field_bufsize    = 0
    col_line = ''
    addcol_sql = '/*\n'
    
    for field_desc in message.DESCRIPTOR.fields:
        field_line = ''
        col_line = ''
        
        if field_desc.type in pbtyp2sqltype_dict.keys():
            if pbtyp2sqltype_dict[field_desc.type] == 'BLOB':
                if field_desc.label == field_desc.LABEL_REPEATED:
                    field_options = field_desc.GetOptions()
                    if None != field_options:
                        if field_options.Extensions[yd_fieldoptions_pb2.no_db_field] == True:
                            continue
                        if field_options.Extensions[yd_fieldoptions_pb2.db_field_arysize] != '':
                            field_arysize = int(field_options.Extensions[yd_fieldoptions_pb2.db_field_arysize])
                            if field_arysize > 0:
                                for field_arysize_index in range(field_arysize):
                                    sub_message = field_desc.message_type
                                    for sub_field_desc in sub_message.fields:
                                        if sub_field_desc.type in pbtyp2sqltype_dict.keys():
                                            if pbtyp2sqltype_dict[sub_field_desc.type] == 'BLOB':
                                                field_line = ' %s_%d_%s %s' % (field_desc.name, field_arysize_index+1, sub_field_desc.name, pbtyp2sqltype_dict[sub_field_desc.type])
                                                col_line = 'alter table %s add column %s_%d_%s %s' % (tb_name, field_desc.name, field_arysize_index+1, sub_field_desc.name, pbtyp2sqltype_dict[sub_field_desc.type])
                                            else:
                                                sub_field_options = sub_field_desc.GetOptions()
                                                if None != sub_field_options:
                                                    field_line = ' %s_%d_%s %s' % (field_desc.name, field_arysize_index+1, sub_field_desc.name, pbtyp2sqltype_dict[sub_field_desc.type])
                                                    col_line = 'alter table %s add column %s_%d_%s %s' % (tb_name, field_desc.name, field_arysize_index+1, sub_field_desc.name, pbtyp2sqltype_dict[sub_field_desc.type])
                                                    #判断是否是字符串
                                                    if sub_field_desc.type == 9:
                                                        db_field_bufsize = sub_field_options.Extensions[yd_fieldoptions_pb2.db_field_bufsize]
                                                        field_line += '(' + str(db_field_bufsize) + ')'
                                                        col_line += '(' + str(db_field_bufsize) + ')'
    
                                                    #判断是否not null
                                                    if True == sub_field_options.Extensions[yd_fieldoptions_pb2.db_field_not_null]:
                                                        field_line += ' NOT NULL'
                                                        col_line += ' NOT NULL'
                                                else:
                                                    field_line = ' %s_%d_%s %s' % (field_desc.name, field_arysize_index, sub_field_desc.name, pbtyp2sqltype_dict[field_desc.type])
                                                    col_line = 'alter table %s add column %s_%d_%s %s' % (tb_name, field_desc.name, field_arysize_index, sub_field_desc.name, pbtyp2sqltype_dict[field_desc.type])
                                                
                                        field_line += ' ,\n'
                                        col_line += ';\n'
                                        createtb_sql += field_line
                                        addcol_sql += col_line
                    continue
                else:
                    field_options = field_desc.GetOptions()
                    if None != field_options:
                        if field_options.Extensions[yd_fieldoptions_pb2.no_db_field] == True:
                            continue
                    field_line = ' %s %s /*!99104 COMPRESSED */' % (field_desc.name, pbtyp2sqltype_dict[field_desc.type])
                    col_line = 'alter table %s add column %s %s ' % (tb_name, field_desc.name, pbtyp2sqltype_dict[field_desc.type])
            else:
                if field_desc.label == field_desc.LABEL_REPEATED:
                    field_options = field_desc.GetOptions()
                    if None != field_options:
                        if field_options.Extensions[yd_fieldoptions_pb2.no_db_field] == True:
                            continue
                        if field_options.Extensions[yd_fieldoptions_pb2.db_field_arysize] != '':
                            field_arysize = int(field_options.Extensions[yd_fieldoptions_pb2.db_field_arysize])
                            if field_arysize > 0:
                                for field_arysize_index in range(field_arysize):
                                    field_line = ' %s_%d %s' % (field_desc.name, field_arysize_index+1, pbtyp2sqltype_dict[field_desc.type])
                                    col_line = 'alter table %s add column %s_%d %s' % (tb_name, field_desc.name, field_arysize_index+1, pbtyp2sqltype_dict[field_desc.type])
                                    #判断是否是字符串
                                    if field_desc.type == 9:
                                        db_field_bufsize = field_options.Extensions[yd_fieldoptions_pb2.db_field_bufsize]
                                        field_line += '(' + str(db_field_bufsize) + ')'
                                        col_line += '(' + str(db_field_bufsize) + ')'
                                    
                                        
                                    #判断是否not null
                                    if True == field_options.Extensions[yd_fieldoptions_pb2.db_field_not_null]:
                                        field_line += ' NOT NULL'
                                        col_line += ' NOT NULL'
                                            
                                    field_line += ' ,\n'
                                    col_line += ';\n'
                                    createtb_sql += field_line
                                    addcol_sql += col_line
                    continue
                else:
                    field_options = field_desc.GetOptions()
                    if None != field_options:
                        if field_options.Extensions[yd_fieldoptions_pb2.no_db_field] == True:
                            continue
                    field_line = ' %s %s' % (field_desc.name, pbtyp2sqltype_dict[field_desc.type])
                    col_line = 'alter table %s add column %s %s' % (tb_name, field_desc.name, pbtyp2sqltype_dict[field_desc.type])
            #pdb.set_trace()
            
            #得到field的options
            field_options = field_desc.GetOptions()
            if None != field_options:
                #这里 options类型google.protobuf.internal.python_message._ExtensionDict
                #key类型是 _descriptor.FieldDescriptor，真是蛋疼
                #print "db_field_type = %d" % field_options.Extensions[yd_fieldoptions_pb2.db_field_type]

                if pbtyp2sqltype_dict[field_desc.type] == 'BLOB' and field_options.Extensions[yd_fieldoptions_pb2.field_bufsize] != '':
                	field_bufsize = int(field_options.Extensions[yd_fieldoptions_pb2.field_bufsize])
                	if field_bufsize > 16777216:
                	    #print "field_line[%s] field_desc.type[%s] field_typename[%s]" % (field_line, pbtyp2sqltype_dict[field_desc.type], field_typename)
                		field_line = field_line.replace(pbtyp2sqltype_dict[field_desc.type], 'LONGBLOB')
                		col_line = field_line.replace(pbtyp2sqltype_dict[field_desc.type], 'LONGBLOB')
                	elif field_bufsize > 65535:
                		field_line = field_line.replace(pbtyp2sqltype_dict[field_desc.type], 'MEDIUMBLOB')
                		col_line = field_line.replace(pbtyp2sqltype_dict[field_desc.type], 'MEDIUMBLOB')
                	
                #判断是否是字符串
                if field_desc.type == 9:
                    db_field_bufsize = field_options.Extensions[yd_fieldoptions_pb2.db_field_bufsize]
                    field_line += '(' + str(db_field_bufsize) + ')'
                    col_line += '(' + str(db_field_bufsize) + ')'
                
                not_null_flag = False
                primary_key_flag = False
                #判断是否是主键
                if field_options.Extensions[yd_fieldoptions_pb2.db_field_type] == yd_fieldoptions_pb2.E_FIELDTYPE_PRIMARYKEY:
                    tb_primarykey.append(field_desc.name)
                    primary_key_flag = True
                    field_line += ' NOT NULL'
                    col_line += ' NOT NULL'
                    not_null_flag = True 
                    
				#判断是否是索引字段
                if field_options.Extensions[yd_fieldoptions_pb2.db_field_type] == yd_fieldoptions_pb2.E_FIELDTYPE_INDEX:
                    tb_indexs.append(field_desc.name)

                #判断是否是索引字段
                if field_options.Extensions[yd_fieldoptions_pb2.db_field_type] == yd_fieldoptions_pb2.E_FIELDTYPE_UNIQUE_INDEX:
                    tb_unique_indexs.append(field_desc.name)    
					
                #判断是否not null
                if True == field_options.Extensions[yd_fieldoptions_pb2.db_field_not_null]:
                    if not_null_flag == False:
                        field_line += ' NOT NULL'
                        col_line += ' NOT NULL'

                #判断是否是自增字段
                if True == field_options.Extensions[yd_fieldoptions_pb2.db_field_auto_increment]:
                    if not_null_flag == False:
                        field_line += ' NOT NULL AUTO_INCREMENT'
                        col_line += ' NOT NULL AUTO_INCREMENT'
                    else:
                        field_line += ' AUTO_INCREMENT'
                        col_line += ' AUTO_INCREMENT'

                    if field_options.Extensions[yd_fieldoptions_pb2.db_field_auto_increment_value] != '':
                        db_field_auto_increment_value = int(field_options.Extensions[yd_fieldoptions_pb2.db_field_auto_increment_value])
                        if db_field_auto_increment_value > 0:
                            tb_db_field_auto_increment_value = "AUTO_INCREMENT = %d" %  (db_field_auto_increment_value)   

                    if field_options.Extensions[yd_fieldoptions_pb2.db_field_type] == yd_fieldoptions_pb2.E_FIELDTYPE_PRIMARYKEY:
                        #这个是主键递增字段
                        if primary_key_flag == False:
                            tb_primarykey.append(field_desc.name)
                    else:
                        #普通的key字段
                        tb_keys.append(field_desc.name)
                        
                if field_options.Extensions[yd_fieldoptions_pb2.db_field_comment] != '':
                        tb_comment = ' COMMENT "%s"' % field_options.Extensions[yd_fieldoptions_pb2.db_field_comment]
                        field_line += tb_comment
                        col_line += tb_comment
                            
            field_line += ' ,\n'
            col_line += ';\n'
        else:
            print 'field[%s] type[%d] is not support!' % (field_desc.name, field_desc.type)
        createtb_sql += field_line
        addcol_sql += col_line
    #print tb_index
    for tb_index in tb_indexs:	
	createtb_sql += ' INDEX(%s),\n' % tb_index
    for tb_unique_index in tb_unique_indexs:	
	createtb_sql += ' UNIQUE(%s),\n' % tb_unique_index
    #print tb_primarykey
    if len(tb_primarykey) > 0:
        createtb_sql += ' PRIMARY KEY(%s)' % ','.join(tb_primarykey)
    for tb_key in tb_keys:
        createtb_sql += ', KEY(%s)' % tb_key
    createtb_sql += ') %s ENGINE=InnoDB DEFAULT CHARSET=utf8;\n' % tb_db_field_auto_increment_value

    addcol_sql += '*/\n'
    createtb_sql += addcol_sql
    return createtb_sql

def create_sql_createtables(message, table_count, out_path, sheet_fullname, bin_filename, message_tbname):
    """"""
    createsql_file = 'create_' + message.DESCRIPTOR.name + '.sql'
    createsql_fd = open(createsql_file, 'w+')
    
    if table_count <= 1:
        sql_content = create_sql_createtable(message, 1, message_tbname, False)
        createsql_fd.write(sql_content)
    else:
        for id in xrange(table_count):
            sql_content = create_sql_createtable(message, id, message_tbname, True)
            createsql_fd.write(sql_content)

    if sheet_fullname != '' and bin_filename != '':
        if os.path.exists(bin_filename):
            binfile_fd = open(bin_filename, 'rb')
            binfile_content = binfile_fd.read()
            print "file[%s] size[%d]" % (bin_filename, len(binfile_content))
            sheet_table_cls = factory.GetPrototype(descriptor_pool.FindMessageTypeByName(sheet_fullname))
            sheet_table_object = sheet_table_cls()
            sheet_table_object.ParseFromString(binfile_content)
            create_sql_insert_datas(sheet_table_object, table_count, out_path, createsql_fd)
            binfile_fd.close()
        
    createsql_fd.close()
    
    if os.path.exists(out_path) and out_path != "./":
        shutil.copyfile(createsql_file, out_path + createsql_file)
        os.remove(createsql_file)

def create_sql_insert_data(sheet_message, table_id):
    #循环每个字段
    field_line = ''
    db_field_bufsize = 0
    createtb_sql = ""

    for sheet_field_desc, sheet_field_value in sheet_message.ListFields():
        if pbtyp2sqltype_dict[sheet_field_desc.type] != 'BLOB':
            continue
        for list_field_value in sheet_field_value:
            sql_value = {}
            for field_desc, field_value in list_field_value.ListFields():
                if field_desc.type in pbtyp2sqltype_dict.keys():
                    if pbtyp2sqltype_dict[field_desc.type] != 'BLOB':
                        if field_desc.label == field_desc.LABEL_REPEATED:
                            field_options = field_desc.GetOptions()
                            if None != field_options:
                                if field_options.Extensions[yd_fieldoptions_pb2.no_db_field] == True:
                                    continue
                                if field_options.Extensions[yd_fieldoptions_pb2.db_field_arysize] != '':
                                    field_arysize = int(field_options.Extensions[yd_fieldoptions_pb2.db_field_arysize])
                                    if field_arysize > 0:
                                        sub_field_count = 0
                                        for sub_list_field_value in field_value: 
                                            sub_field_count = sub_field_count + 1
                                            name = '%s_%d' % (field_desc.name, sub_field_count)
                                            sql_value[name] = sub_list_field_value
                        else:
                            field_options = field_desc.GetOptions()
                            if None != field_options:
                                if field_options.Extensions[yd_fieldoptions_pb2.no_db_field] == True:
                                    continue
                            sql_value[field_desc.name] = field_value        
                    else:
                        if field_desc.label == field_desc.LABEL_REPEATED:
                            field_options = field_desc.GetOptions()
                            if None != field_options:
                                if field_options.Extensions[yd_fieldoptions_pb2.no_db_field] == True:
                                    continue
                                if field_options.Extensions[yd_fieldoptions_pb2.db_field_arysize] != '':
                                    field_arysize = int(field_options.Extensions[yd_fieldoptions_pb2.db_field_arysize])
                                    if field_arysize > 0:
                                        sub_field_count = 0
                                        for sub_list_field_value in field_value:
                                            sub_field_count = sub_field_count + 1
                                            for sub_field_desc, sub_field_value in sub_list_field_value.ListFields():
                                                if sub_field_desc.type in pbtyp2sqltype_dict.keys():
                                                    if pbtyp2sqltype_dict[sub_field_desc.type] != 'BLOB':
                                                        name = '%s_%d_%s' % (field_desc.name, sub_field_count,sub_field_desc.name)
                                                        sql_value[name] = sub_field_value
                                                    else:
                                                        sub_field_count = sub_field_count + 1
                                                        name = '%s_%d_%s' % (field_desc.name, sub_field_count,sub_field_desc.name)
                                                        sql_value[name] = sub_field_value.SerializeToString()
                        else:
                            if None != field_options:
                                if field_options.Extensions[yd_fieldoptions_pb2.no_db_field] == True:
                                    continue
                            sql_value[field_desc.name] = field_value            
                else:
                    print 'field[%s] type[%d] is not support!' % (field_desc.name, field_desc.type)

            inserttb_sql_fmt = 'INSERT INTO {tbname} ({columns}) VALUES({values});\n'
            tb_column_names = []
            tb_column_values = []
            for field,value in sql_value.items():
                tb_column_names.append(field)
                strValue = ""
                strValue += "'"
                strValue += str(value)
                strValue += "'"
                tb_column_values.append(strValue)
            sql_column_names = ','.join(tb_column_names)
            sql_column_values = ','.join(tb_column_values)

            insert_sql = inserttb_sql_fmt.format(tbname=list_field_value.DESCRIPTOR.name, columns=sql_column_names, values=sql_column_values)
            createtb_sql += insert_sql
              
    return createtb_sql            
                    

def create_sql_insert_datas(sheet_message, table_count, out_path, createsql_fd):
    """"""
    for id in xrange(table_count):
        sql_content = create_sql_insert_data(sheet_message, id)
        createsql_fd.write(sql_content)
    
    
def create_sql_insert(message, zdbsql_fd):
    """"""
    inserttb_sql_fmt = 'INSERT INTO {tbname}_{pad} ({columns}) VALUES({values});\n'
    tb_column_names = []
    tb_column_values = []
    
    for field_desc in message.DESCRIPTOR.fields:
        tb_column_names.append(field_desc.name)
        tb_column_values.append('?')

    sql_column_names = ','.join(tb_column_names)
    sql_column_values = ','.join(tb_column_values)
    
    #print sql_column_names
    #print sql_column_values
    
    insert_sql = inserttb_sql_fmt.format(tbname=message.DESCRIPTOR.name, pad='{}', columns=sql_column_names, values=sql_column_values)
    #print insert_sql
    zdbsql_fd.write(insert_sql)
    
    print "table[%s] insert sql ok!" % message.DESCRIPTOR.name

def create_sql_update(message, zdbsql_fd):
    """"""
    updatetb_sql_fmt = 'UPDATE {tbname}_{pad} SET {values} {conds};\n'
    tb_column_names = []
    tb_where_conds = []

    for field_desc in message.DESCRIPTOR.fields:
        tb_column_names.append(field_desc.name)

        field_options = field_desc.GetOptions()
        if field_options.Extensions[yd_fieldoptions_pb2.db_field_type] == yd_fieldoptions_pb2.E_FIELDTYPE_PRIMARYKEY:
            tb_where_conds.append(field_desc.name)

    sql_column_set = '=?,'.join(tb_column_names)
    sql_column_set += '=?'
    sql_where_conds = '=? and '.join(tb_where_conds)
    sql_where_conds += '=?'
    update_sql = updatetb_sql_fmt.format(tbname=message.DESCRIPTOR.name, pad='{0}', values=sql_column_set, conds='{1}')
    #print update_sql
    zdbsql_fd.write(update_sql)

    print "table[%s] update sql ok!" % message.DESCRIPTOR.name
    
def create_sql_delete(message, zdbsql_fd):
    """"""
    deletetb_sql_fmt = 'DELETE FROM {tbname}_{pad} WHERE {conds};\n'
    tb_where_conds = []

    for field_desc in message.DESCRIPTOR.fields:	
        field_options = field_desc.GetOptions()
        if field_options.Extensions[yd_fieldoptions_pb2.db_field_type] == yd_fieldoptions_pb2.E_FIELDTYPE_PRIMARYKEY:
            tb_where_conds.append(field_desc.name)

    sql_where_conds = '=? and '.join(tb_where_conds)
    sql_where_conds += '=?'

    delete_sql = deletetb_sql_fmt.format(tbname=message.DESCRIPTOR.name, pad='{}', conds=sql_where_conds)
    zdbsql_fd.write(delete_sql)	

    print "table[%s] delete sql ok!" % message.DESCRIPTOR.name


def show_usage():
    print """usage for proto2sql example:
    ./proto2sql.py --proto_ds=xxx.proto.ds --message_fullname=xxx.xxx table_count=xxx --out_path=./"""


if __name__ == "__main__":
    (opts, args) = getopt.getopt(sys.argv[1:], "p:m:t:o:s:b:n", ["proto_ds=", "message_fullname=", "table_count=", "out_path=", "sheet_fullname=", "bin_filename=", "message_tbname="])
    
    if( 0 == len( opts ) ):
        show_usage()
        sys.exit( -1 )
        
    proto_ds_file = ""
    message_fullname  = ""
    message_tbname = ""
    sheet_fullname = ""
    bin_filename = ""
    table_count = 1
    out_path = ""
    
    for (o, a) in opts:
        if o in ("-p", "--proto_ds"):
            proto_ds_file = a
        elif o in ("-m", "--message_fullname"):
            message_fullname = a
        elif o in ("-n", "--message_tbname"):
            message_tbname = a    
        elif o in ("-t", "--table_count"):
            table_count = int(a)
        elif o in ("-o", "--out_path"):
            out_path = a
        elif o in ("-s", "--sheet_fullname"):
            sheet_fullname = a
        elif o in ("-b", "--bin_filename"): 
            bin_filename = a       
        else:
            print "unknown command!"
            show_usage()
            sys.exit(-1)
            
    print "args info:\n\tproto_ds[%s]\n\tmessage_fullname[%s]\n\ttable_count[%s]" % \
        (proto_ds_file, message_fullname, table_count)
    
        
    #导入proto生成的py文件
    if not os.path.exists(proto_ds_file):
        print "[%s] is not exist!" % proto_ds_file
        sys.exit(-1)
        
    #动态导入 不能用动态导入，依赖多了不好办，还是用proto.ds文件来解决问题
    #sql_py = __import__(proto_py_file)
    
    #读取prot_ds文件
    proto_ds_content = read_proto_ds(proto_ds_file)
    if 0 == len(proto_ds_content):
        print "[%s] is empty file!" % proto_ds_file
        sys.exit(-1)
        
    #创建对象的factory
    proto_ds_obj = descriptor_pb2.FileDescriptorSet()  
    proto_ds_obj.ParseFromString(proto_ds_content)
    descriptor_db = descriptor_database.DescriptorDatabase()
    for file_desc_proto in proto_ds_obj.file:
        descriptor_db.Add(file_desc_proto)
    descriptor_pool = descriptor_pool.DescriptorPool(descriptor_db)
    factory = message_factory.MessageFactory()
    
    #根据fullname创建类
    # <class 'google.protobuf.reflection.PlayerInfo'> 这里是个class
    table_cls = factory.GetPrototype(descriptor_pool.FindMessageTypeByName(message_fullname))
    #构建对象
    table_object = table_cls();    
    print "create table[%s] object" % table_object.DESCRIPTOR.full_name
    
    create_sql_createtables(table_object, table_count, out_path, sheet_fullname, bin_filename, message_tbname)

    
    #zdbsql_file = table_object.DESCRIPTOR.name + '.zdb_sql'
    #zdbsql_fd = open(zdbsql_file, 'w+')
    
    #create_sql_insert(table_object, zdbsql_fd)
    #create_sql_delete(table_object, zdbsql_fd)
    #create_sql_update(table_object, zdbsql_fd)    
    
   # zdbsql_fd.close()
    
   #移动到指定路径
    #if os.path.exists(out_path) and out_path != "./":
    #    shutil.copyfile(zdbsql_file, out_path + zdbsql_file)
    #    os.remove(zdbsql_file)

    print "proto2sql.py successful build!"

