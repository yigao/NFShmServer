#! /usr/bin/python
# -*- encoding: utf-8 -*-

# Excel to Protobuf bin
# Copyright (c) 2015, calmwu
# All rights reserved.
# Email: wubo0067@hotmail.com

"""
	1：用protoc去生成proto对应的*.proto.ds文件
	2：解析proto.ds文件，生成Sheet_xxxx对象
	1：读取excel文件，各个sheet，sheet的名字对应
	层次分割符-是关键字，不能使用在cname中
"""

import xlrd
import sys
import os
import commands
import getopt
import re
import shutil
import ctypes
import time

import yd_fieldoptions_pb2

from google.protobuf import descriptor
from google.protobuf import message
from google.protobuf import reflection
from google.protobuf import descriptor_pb2
from google.protobuf.descriptor_pb2 import DescriptorProto
from google.protobuf import text_format

from google.protobuf import descriptor_database
from google.protobuf import descriptor_pool
from google.protobuf import message_factory

#全局变量
g_excel_data = []
g_proto_bindata = {}
g_excel_sheet_columnnames = set()
g_sheet_object_field_proterties = set()
#类型引用次数
g_layertype_instancecount = {}

g_pb_descriptor_pool = None
g_pb_factory = None
g_pb_packagename = None

#解析的枚举信息
g_pb_enum_infos = []

def read_proto_ds(proto_ds_file):
	""""""
	proto_ds_fd = open(proto_ds_file, 'rb')
	try:
		proto_ds_content = proto_ds_fd.read()
		print "file[%s] size[%d]" % (proto_ds_file, len(proto_ds_content))
		return proto_ds_content
	finally:
		proto_ds_fd.close()
	return ""

def parse_enum_descriptor(enum_type_desc):
	""""""
	global g_pb_descriptor_pool
	global g_pb_factory
	global g_pb_enum_infos

#	print "line(%s:%d) class_name[%s] enum_type_name[%s] enum_type_fullname[%s]" % (__file__, sys._getframe().f_lineno, \
#		enum_type_desc.__class__.__name__, enum_type_desc.name, enum_type_desc.full_name)

	for enum_type_value_desc in enum_type_desc.values:
		#enum的每个成员,
		#print "line(%s:%d) class_name[%s] value_name[%s] value_index[%d] value_number[%d]" % (__file__, sys._getframe().f_lineno, \
		#	enum_type_value_desc.__class__.__name__, enum_type_value_desc.name, enum_type_value_desc.index, enum_type_value_desc.number)

		#对于desc获取options都用GetOptions()方法，枚举如此，message如此
		enum_type_value_options = enum_type_value_desc.GetOptions();
		if None != enum_type_value_options:
			#print "line(%s:%d) class_name[%s]" % (__file__, sys._getframe().f_lineno, enum_type_value_options.__class__.__name__)
			# 这样就可以获得扩展了，如果有enum_cname的options
			enum_value_cname = enum_type_value_options.Extensions[yd_fieldoptions_pb2.field_enum_cname]
			if None != enum_value_cname:
				#print "line(%s:%d) enum_value_cname[%s]" % (__file__, sys._getframe().f_lineno, enum_value_cname)
				g_pb_enum_infos.append((enum_type_desc.name, enum_type_value_desc.number, enum_value_cname))
			else:
				g_pb_enum_infos.append((enum_type_desc.name, enum_type_value_desc.number, ""))
	#通过fullname都可以拿到对应的描述
	"""
	enum_desc = g_pb_descriptor_pool.FindEnumTypeByName(enum_type_desc.full_name)
	if None != enum_desc:
		print "line(%s:%d) class_name[%s]" % (__file__, sys._getframe().f_lineno, \
			enum_desc.__class__.__name__)
	"""

def parse_object_properties(record_object):
	""""""
	global g_sheet_object_field_proterties

	#解析sheet_record_object每个field属性
	for sheet_object_field_dec in record_object.DESCRIPTOR.fields:
		#descriptor.FieldDescriptor.LABEL_REPEATED = 3
		#要知道field类型的具体名字
		# sheet_object_field_dec的类型是FieldDescriptor
		sheet_object_field_options = sheet_object_field_dec.GetOptions()
		#这里可以拿到枚举对象的类名
		field_typename = ""

		if None != sheet_object_field_dec.enum_type:
			# EnumDescriptor
#			print "line(%s:%d) FieldType[%s] message[%s] field name[%s] full_name[%s] label[%d] index[%d] type[%d] cpp_type[%d] class[%s]" % (__file__, sys._getframe().f_lineno, \
#				sheet_object_field_dec.enum_type.name, record_object.DESCRIPTOR.full_name, sheet_object_field_dec.name, sheet_object_field_dec.full_name, sheet_object_field_dec.label, sheet_object_field_dec.index, \
#				sheet_object_field_dec.type, sheet_object_field_dec.cpp_type, sheet_object_field_dec.__class__.__name__)
			field_typename = sheet_object_field_dec.enum_type.name
			parse_enum_descriptor(sheet_object_field_dec.enum_type)
		elif None != sheet_object_field_dec.message_type:
			#print "line(%s:%d) FieldType[%s] message[%s] field name[%s] full_name[%s] label[%d] index[%d] type[%d] cpp_type[%d] class[%s]" % (__file__, sys._getframe().f_lineno, \
			#	sheet_object_field_dec.message_type.name, record_object.DESCRIPTOR.full_name, sheet_object_field_dec.name, sheet_object_field_dec.full_name, sheet_object_field_dec.label, sheet_object_field_dec.index, \
			#	sheet_object_field_dec.type, sheet_object_field_dec.cpp_type, sheet_object_field_dec.__class__.__name__)
			field_typename = sheet_object_field_dec.message_type.name
		else:
			# field_desc的containing_type就是其归属的message或enum的名字
			#print "line(%s:%d) FieldType[Normal] message[%s] field name[%s] full_name[%s] label[%d] index[%d] type[%d] cpp_type[%d] class[%s]" % (__file__, sys._getframe().f_lineno, \
			#	record_object.DESCRIPTOR.full_name, sheet_object_field_dec.name, sheet_object_field_dec.full_name, sheet_object_field_dec.label, sheet_object_field_dec.index, \
			#	sheet_object_field_dec.type, sheet_object_field_dec.cpp_type, sheet_object_field_dec.__class__.__name__)
			field_typename = "Normal"

		#field的cname，对应excel的列名
		column_name = sheet_object_field_options.Extensions[yd_fieldoptions_pb2.field_cname]
		if 0 != column_name:
			#插入field所有属性
			g_sheet_object_field_proterties.add((column_name, \
												 sheet_object_field_dec.index, \
												 sheet_object_field_dec.name, \
												 sheet_object_field_dec.label, \
												 sheet_object_field_dec.type, \
												 record_object.DESCRIPTOR.full_name, \
												 field_typename))
			#print "line(%s:%d) column_name[%s] index[%d] name[%s] label[%d] type[%d] belong_message_fullname[%s]" % \
			#	  (__file__, sys._getframe().f_lineno, column_name, sheet_object_field_dec.index, sheet_object_field_dec.name, \
				   #sheet_object_field_dec.label, sheet_object_field_dec.type, record_object.DESCRIPTOR.full_name)

def sheet_cell_value(sheet, row_index, col_index):
	if sheet.cell_type(row_index, col_index) == xlrd.XL_CELL_EMPTY or \
		sheet.cell_type(row_index, col_index) == xlrd.XL_CELL_BLANK:
		return 0
	elif sheet.cell_type(row_index, col_index) == xlrd.XL_CELL_TEXT and \
		len(sheet.cell_value(row_index, col_index)) == 0:
		return 0
	
	return sheet.cell_value(row_index, col_index)

def find_enum_value(sheet, row_index, col_index, enum_typename):
	""""""
	global g_pb_enum_infos

	if sheet.cell_type(row_index, col_index) == xlrd.XL_CELL_EMPTY:
		return 0
	elif sheet.cell_type(row_index, col_index) == xlrd.XL_CELL_TEXT:
		#要找到对应string的枚举值
		cell_strval = sheet.cell_value(row_index, col_index)
		#循环查找
		for x_enum_typename, x_enum_number, x_enum_cellstr in g_pb_enum_infos:
			if x_enum_typename == enum_typename and cell_strval == x_enum_cellstr:
				return x_enum_number
	else:
		return int(sheet.cell_value(row_index, col_index))

def set_record_unit_value(record, sheet, row_index, col_index, field_property_name, field_property_type, field_typename ):
	""""""
#	print "line(%s:%d) set_record_unit_value row:col[%d:%d] %s [%d, %s]" % \
#		  (__file__, sys._getframe().f_lineno, row_index, col_index, field_property_name, field_property_type, field_typename)
	try:
		if descriptor.FieldDescriptor.TYPE_INT32  == field_property_type or \
		   descriptor.FieldDescriptor.TYPE_UINT32 == field_property_type or \
		   descriptor.FieldDescriptor.TYPE_INT64  == field_property_type or \
		   descriptor.FieldDescriptor.TYPE_BOOL  == field_property_type or \
		   descriptor.FieldDescriptor.TYPE_UINT64 == field_property_type:
			#设置属性值
			setattr(record, field_property_name, int(sheet_cell_value(sheet, row_index, col_index)))
		elif descriptor.FieldDescriptor.TYPE_STRING == field_property_type:
			cell_val = sheet.cell_value(row_index, col_index)
			#print "------------------", cell_val
			if cell_val.__class__.__name__ == 'unicode':
				setattr(record, field_property_name, cell_val)
			else:
				setattr(record, field_property_name, str(cell_val))
		elif descriptor.FieldDescriptor.TYPE_ENUM == field_property_type:
			setattr(record, field_property_name, find_enum_value(sheet, row_index, col_index, field_typename))
		elif descriptor.FieldDescriptor.TYPE_FLOAT == field_property_type or \
			 descriptor.FieldDescriptor.TYPE_DOUBLE == field_property_type:
			setattr(record, field_property_name, float(sheet_cell_value(sheet, row_index, col_index)))
		else:
			print "Error! sheet.cell_value(%d, %d) type[%d] is invalid!" % \
			(row_index, col_index, field_property_type)
			sys.exit(-1)
	except:
		print "\033[1;31;40m line(%s:%d) set_record_unit_value row:col[%d:%d] %s [%d, %s] \033[0m" % \
		(__file__, sys._getframe().f_lineno, row_index+1, col_index+1, field_property_name, field_property_type, field_typename)
		sys.exit(-1)
		
	return

def append_record_repeatedfield(record_repeatedfield, sheet, row_index, col_index, field_property_type):
	""""""
	#这里要用append
	if descriptor.FieldDescriptor.TYPE_INT32  == field_property_type or \
		descriptor.FieldDescriptor.TYPE_UINT32 == field_property_type or \
		descriptor.FieldDescriptor.TYPE_INT64  == field_property_type or \
		descriptor.FieldDescriptor.TYPE_BOOL  == field_property_type or \
		descriptor.FieldDescriptor.TYPE_UINT64 == field_property_type:
		record_repeatedfield.append(int(sheet_cell_value(sheet, row_index, col_index)))
	elif descriptor.FieldDescriptor.TYPE_STRING == field_property_type:
		cell_val = sheet.cell_value(row_index, col_index)
		if cell_val.__class__.__name__ == 'unicode':
			record_repeatedfield.append(cell_val)
		else:
			record_repeatedfield.append(str(cell_val))
	elif descriptor.FieldDescriptor.TYPE_ENUM == field_property_type:
		record_repeatedfield.append(int(sheet_cell_value(sheet, row_index, col_index)))
	elif descriptor.FieldDescriptor.TYPE_FLOAT == field_property_type or \
		descriptor.FieldDescriptor.TYPE_DOUBLE == field_property_type:
		record_repeatedfield.append(float(sheet_cell_value(sheet, row_index, col_index)))
	else:
		print "\033[1;31;40m Error! sheet.cell_value(%d, %d) type[%d] is invalid! \033[0m" % \
			(row_index, col_index, field_property_type)
		sys.exit(-1)
	return

# parent_layername，父层的名字，第一次为root
def fill_record(record, sheet, row_index, col_index, excel_sheet_col_count, recursion_count, parent_layertype, parent_layer_cname):
	""""""
	global g_sheet_object_field_proterties
	global g_layername_refcount

	#print "line(%s:%d) fill_record record[%s] start row:col[%d:%d] recursion_count[%d] parent_layertype[%s] parent_layer_cname[%s]++++++++++++++++" % \
	#	  (__file__, sys._getframe().f_lineno, record.DESCRIPTOR.full_name, row_index, col_index, recursion_count, parent_layertype, parent_layer_cname)

	# example Sheet-Sheetobject-1-CommodityFactoryAddress
	current_layer_typename = parent_layertype  + '-' + record.DESCRIPTOR.name + '-' + parent_layer_cname
	#计算这个类型下多少个实例，如果为空从1开始
	if g_layertype_instancecount.has_key(current_layer_typename):
		g_layertype_instancecount[current_layer_typename] += 1
	else:
		g_layertype_instancecount[current_layer_typename] = 1
	#当前层的id example Sheet-Sheetobject-1
	current_layerid = current_layer_typename + '-' + str(g_layertype_instancecount[current_layer_typename])

	current_layer_cname = parent_layer_cname
	if len(parent_layer_cname) > 0:
		current_layer_cname = parent_layer_cname + '-' + str(g_layertype_instancecount[current_layer_typename]) + '-'

	#print "line(%s:%d) current_layer_typename[%s] current_layerid[%s] current_layer_cname[%s]" % \
	#	  (__file__, sys._getframe().f_lineno, current_layer_typename, current_layerid, current_layer_cname)

	#循环每个列
	last_ok_col_index = 0;
	while col_index < excel_sheet_col_count:
		#得到sheet的列名
		column_name = sheet.cell_value(0, col_index)

		#print "line(%s:%d) now process excel column[%s] col_index[%d]" % (__file__, sys._getframe().f_lineno, column_name, col_index)
		#循环查找对应名字，sheet的列名要和field的cname对应
		is_find = False
		#field各项属性
		field_property_cname = ""
		field_property_index = 0
		field_property_name  = ""
		field_property_label = 0
		field_property_type  = 0
		field_belong_message_fullname = ""
		field_typename = ""

		#找到excel对应的field，填写相关属性
		for field_property in g_sheet_object_field_proterties:

			field_property_cname = field_property[0]
			field_property_index = field_property[1]
			field_property_name  = field_property[2]
			field_property_label = field_property[3]
			field_property_type  = field_property[4]
			field_belong_message_fullname = field_property[5]
			field_typename =field_property[6]

			compare_cname = current_layer_cname + field_property_cname
			compare_cname_len = len(compare_cname)
			column_prefixname = column_name[:compare_cname_len]

			#还要判断后缀
			column_postfixname = column_name[compare_cname_len:]
			#must_strictcompare = False
			if len(column_name) > len(compare_cname):
				#如果有超过部分，判断是否是分层部分，不是就要严格匹配
				if column_name[compare_cname_len] != '-':
					column_prefixname = column_name

			#print "------------compare_cname[%s] column_prefixname[%s]" % (compare_cname, column_prefixname)

			if compare_cname == column_prefixname and field_belong_message_fullname == record.DESCRIPTOR.full_name:
				#print "line(%s:%d) compare_cname[%s] column_prefixname[%s] column_name[%s] find is ok!" % \
				#	  (__file__, sys._getframe().f_lineno, compare_cname, column_prefixname, column_name)
				is_find = True
				last_ok_col_index = col_index;
				break;

#			print "line(%s:%d) ------------field_property_cname[%s] field_property_index[%d] field_property_name[%s] field_property_label[%d] field_property_type[%d]" \
#				  % (__file__, sys._getframe().f_lineno, field_property_cname, field_property_index, field_property_name, field_property_label, field_property_type)
		""""""
		#判断查找结果，如果excel中没有列被描述就跳过该列
		if is_find == False:
			col_index = col_index + 1
			#print "line(%s:%d) excel column[%s] ignore" % (__file__, sys._getframe().f_lineno, column_name)
			continue

		#print "line(%s:%d) excel excel_col[%d] field_property_index[%d] field_property_name[%s] field_property_label[%d]" % \
		#	  (__file__, sys._getframe().f_lineno, col_index, field_property_index, field_property_name, field_property_label)

		#基本类型的成员
		if field_property_label != descriptor.FieldDescriptor.LABEL_REPEATED and \
			field_property_type != descriptor.FieldDescriptor.TYPE_MESSAGE:
			set_record_unit_value(record, sheet, row_index, col_index, field_property_name, field_property_type, field_typename)
		#基本类型的repeated
		elif field_property_label == descriptor.FieldDescriptor.LABEL_REPEATED and \
			field_property_type != descriptor.FieldDescriptor.TYPE_MESSAGE:
			record_repeatedfield = getattr(record, field_property_name)
			append_record_repeatedfield(record_repeatedfield, sheet, row_index, col_index, field_property_type)
		#message类型的repeated
		elif field_property_label == descriptor.FieldDescriptor.LABEL_REPEATED and \
			field_property_type == descriptor.FieldDescriptor.TYPE_MESSAGE:
			# 看来message对象都是# <class 'google.protobuf.internal.containers.RepeatedCompositeFieldContainer'>这个类型
			repeated_msgrepeatedfield = getattr(record, field_property_name)
			#增加一个对象，不同于record
			repeated_unit_msgrepeatedfield = repeated_msgrepeatedfield.add()
			#开始解析这个对象
			parse_object_properties(repeated_unit_msgrepeatedfield)

			input_layer_cname = current_layer_cname + field_property_cname
			if recursion_count == 0:
				input_layer_cname= field_property_cname

			#print "111: " + str(recursion_count)
			#print col_index
			col_index = fill_record(repeated_unit_msgrepeatedfield, sheet, row_index, col_index, \
									excel_sheet_col_count, recursion_count+1, current_layerid, input_layer_cname)
			#print col_index
			#print "222: " + str(recursion_count)
			last_ok_col_index = col_index - 1
			continue
		col_index = col_index + 1

	#print "line(%s:%d) fill_record record[%s] last_ok_col_index[%d] recursion_count[%d] completed---------------" % \
	#	  (__file__, sys._getframe().f_lineno, record.DESCRIPTOR.full_name, last_ok_col_index, recursion_count)

	if 0 == last_ok_col_index:
		print "\033[1;31;40m-------------line(%s:%d) Error!---------------\033[0m" % (__file__, sys._getframe().f_lineno)
		sys.exit(-1)

	return last_ok_col_index + 1


def read_excel(excel_file, excel_sheetname, proto_sheet_repeatedfieldname, sheet_record_object, sheet_object, start_row):
	"""
	excel_file：文件名
	excel_sheetname：文件sheet名
	proto_sheet_repeatedfieldname：repeat field成员名字
	sheet_record_object：成员对象
	sheet_object：sheet对象
	start_row：读取起始行
	"""
	parse_object_properties(sheet_record_object)

	excel_fd = xlrd.open_workbook(excel_file)
	#循环所有sheet
	for sheet in excel_fd.sheets():
		if 0 == cmp(sheet.name, excel_sheetname):
			#找到对应的sheet
			#sheet的行数
			excel_sheet_row_count = sheet.nrows
			#sheet的列数
			excel_sheet_col_count = sheet.ncols

			#print "line(%s:%d) excel sheet[%s] row_count[%d] col_count[%d] sheet_object_field_count[%d]" % \
			#(__file__, sys._getframe().f_lineno, sheet.name, excel_sheet_row_count, excel_sheet_col_count, len(sheet_record_object.DESCRIPTOR.fields))

			#通过反射获取sheet_object中repeated成员
			# <class 'google.protobuf.internal.containers.RepeatedCompositeFieldContainer'>
			repeated_records = getattr(sheet_object, proto_sheet_repeatedfieldname)
			#开始按行读取
			for row_index in xrange(start_row, excel_sheet_row_count):
				#在repeated对象中新增对象
				record = repeated_records.add()
				#开始解析sheet的列，填充record
				col_index = 0
				#递归的层数
				recursion_count = 0
				#以名字加行号作为root名字
				parent_layername = sheet_object.DESCRIPTOR.name
				fill_record(record, sheet, row_index, col_index, excel_sheet_col_count, recursion_count, parent_layername, "")
			return

	print "\033[1;31;40mError!! sheet[%s] not in excel[%s]!!!! must be check!!! \033[0m" % (excel_sheetname, excel_file)
	sys.exit(-1)

# proto中package就是excel的文件名
#excel2bin --excel=xxx.xsl --proto_ds=xxx.proto.ds --proto_packagename=test --proto_msgname=CommodityInfo
# --proto_sheet_msgname=Sheet_CommodityInfo --excel_sheetname=Sheet_CommodityInfo --out_path=../

def show_usage():
	print """usage for excel2bin example:
	./excel2bin --excel=x-1.xls
                --proto_ds=xxx.proto.ds
                --proto_packagename=xxx
                --proto_msgname=xxx
                --proto_sheet_msgname=xxx
                --excel_sheetname=xxx
                --start_row=xxx
                --out_path=./"""

if __name__ == "__main__":
	(opts, args) = getopt.getopt(sys.argv[1:], "e:d:p:m:s:n:l:o", ["excel=", "proto_ds=", "proto_packagename=", "proto_msgname=", \
                                                              "proto_sheet_msgname=", "excel_sheetname=", "start_row=", "out_path="])

	if( 0 == len( opts ) ):
		show_usage()
		sys.exit( -1 )

	excel_files = []
	proto_ds_file = ""
	proto_msgname = ""
	proto_msgfullname = ""
	#proto_packagename = ""
	proto_sheet_msgname = ""
	proto_sheet_msgfullname = ""
	excel_sheetnames = []
	proto_sheet_repeatedfieldname = ""
	bin_file = ""
	start_row = 1
	out_path = ""

	for (o, a) in opts:
		if o in ("-e", "--excel"):
			excel_files.append(a)
		elif o in ("-p", "--proto_ds"):
			proto_ds_file = a
		elif o in ("-p", "--proto_packagename"):
			g_pb_packagename = a
		elif o in ("-m", "--proto_msgname"):
			proto_msgname = a
			proto_msgfullname = g_pb_packagename + "." + proto_msgname
		elif o in ("-m", "--proto_sheet_msgname"):
			proto_sheet_msgname = a
			proto_sheet_msgfullname = g_pb_packagename + "." + proto_sheet_msgname
		elif o in ("-m", "--excel_sheetname"):
			excel_sheetnames.append(a)
		elif o in ("-l", "--start_row"):
			start_row = int(a)
			if start_row < 1:
				start_row = 1
		elif o in ("-o", "--out_path"):
			out_path = a
		else:
			print "unknown command!"
			show_usage()
			sys.exit(-1)

	proto_sheet_repeatedfieldname = proto_msgname + "_List"
	bin_file = proto_msgname + ".bin"

	print "Input parameters:\n\texcel_files[%s]\n\t \
	protods_file[%s]\n\t \
	proto_packagename[%s]\n\t \
	proto_msgname[%s]\n\t \
	proto_msgfullname[%s]\n\t \
	proto_sheet_msgname[%s]\n\t \
	proto_sheet_msgfullname[%s]\n\t \
	proto_sheet_repeatedfieldname[%s]\n\t \
	excel_sheetnames[%s]\n\t \
	bin_file[%s]" % \
	(excel_files, \
	proto_ds_file, \
	g_pb_packagename, \
	proto_msgname, \
	proto_msgfullname, \
	proto_sheet_msgname, \
	proto_sheet_msgfullname, \
	proto_sheet_repeatedfieldname, \
	excel_sheetnames, \
	bin_file)

    #读取该文件
	pb_ds_content = read_proto_ds(proto_ds_file)
    #文件描述集合
	pb_fds_obj = descriptor_pb2.FileDescriptorSet()
	#文件数据反序列化生成FileDescriptorSet对象
	pb_fds_obj.ParseFromString(pb_ds_content)
	#构建descriptor_database对象
	pb_descriptor_db = descriptor_database.DescriptorDatabase()

	for pb_file_desc_proto in pb_fds_obj.file:
		pb_descriptor_db.Add(pb_file_desc_proto)

	#构建DescriptorPool
	g_pb_descriptor_pool = descriptor_pool.DescriptorPool(pb_descriptor_db)
	#构建MessageFactory
	g_pb_factory = message_factory.MessageFactory()
	#返回类，动态的创建类，为excel的sheet页类
	sheet_cls = g_pb_factory.GetPrototype(g_pb_descriptor_pool.FindMessageTypeByName(proto_sheet_msgfullname))
	if None == sheet_cls:
		print "\033[1;31;40m Create sheet_cls by name[%s] failed!\033[0m" % proto_sheet_msgfullname
		sys.exit(-1)
	else:
		print "Create sheet_cls[%s]" % sheet_cls.DESCRIPTOR.name

	#返回类，动态创建类，为excel的sheet行记录类
	sheet_record_cls = g_pb_factory.GetPrototype(g_pb_descriptor_pool.FindMessageTypeByName(proto_msgfullname))
	if None == sheet_record_cls:
		print "\033[1;31;40m Create sheet_record_cls by name[%s] failed!\033[0m" % proto_sheet_msgfullname
		sys.exit(-1)
	else:
		print "Create sheet_record_cls[%s]" % sheet_record_cls.DESCRIPTOR.name

	#构造对象
	sheet_object = sheet_cls()
	sheet_record_object = sheet_record_cls()

    #读取excel，同时填写数据到message_obj中
	for excel_file in excel_files:
		for excel_sheetname in excel_sheetnames:
			print "now read excel[%s] sheet[%s]" % (excel_file, excel_sheetname)
			read_excel(excel_file, excel_sheetname, proto_sheet_repeatedfieldname, sheet_record_object, sheet_object, start_row)

	#print text_format.MessageToString(sheet_object)

	#将对象序列化到文件中
	#创建文件
	bin_f = open(bin_file, 'wb')
	serial_str = sheet_object.SerializeToString()
	#写入文件
	bin_f.write(serial_str)
	bin_f.close()

	#移动到指定路径
	if os.path.exists(out_path) and out_path != "./":
		shutil.copyfile(bin_file, out_path + bin_file)
		os.remove(bin_file)

	print "%s file successful build!" % bin_file
