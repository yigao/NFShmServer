#! /usr/bin/python
#coding=utf-8

# Protobuf 2 C Struct
# Copyright (c) 2015, calmwu
# All rights reserved.
# Email: wubo0067@hotmail.com

import sys
import os
import getopt
import pdb
import time
import shutil

from google.protobuf import descriptor
from google.protobuf import message
from google.protobuf import reflection
from google.protobuf import descriptor_pb2

from google.protobuf import descriptor_database
from google.protobuf import descriptor_pool
from google.protobuf import message_factory

#用统一的fieldoptions定义来取代各自的分开定义
import yd_fieldoptions_pb2
#import proto2struct_def_pb2

exclude_proto = ("google/protobuf/descriptor.proto", "yd_fieldoptions.proto")

class EnumDesc:
	""""""
	name = ""
	field_lst = []

class MessageFieldDesc:
	""""""
	#成员名字
	name = ""
	#成员c类型
	c_type = ""
	pb_type = ""
	convert_type = ""
	#是否是message
	is_message = False
	#是否是数组
	is_array = False
	#数组长度
	array_size = 0
	#是否是buffer
	is_buffer = False
	#buffer长度
	buffer_size = 0
	#是字符串
	is_string = False
	#是枚举
	is_enum = False
	no_field = False

class MessageDesc:
	""""""
	name = ""
	pb_msgname = ""
	field_lst = []
	func_write_to_pbmsg = ""
	func_read_from_pbmsg = ""
	func_new_proto = ""
	func_make_proto = ""

class FileDesc:
	""""""
	name = ""
	namespace = ""
	enum_lst = [];
	message_lst = [];
	include_lst = [];

g_filedesc = FileDesc()

def dump_object(obj):
    for descriptor in obj.DESCRIPTOR.fields:
        value = getattr(obj, descriptor.name)
        if descriptor.type == descriptor.TYPE_MESSAGE:
            if descriptor.label == descriptor.LABEL_REPEATED:
                map(dump_object, value)
            else:
                dump_object(value)
        elif descriptor.type == descriptor.TYPE_ENUM:
            enum_name = descriptor.enum_type.values[value].name
            print "%s: %s" % (descriptor.full_name, enum_name)
        else:
            print "%s: %s" % (descriptor.full_name, value)

def write_hfile():
	""""""
	global g_filedesc

	#创建h文件
	h_file = open(g_filedesc.name + ".h", "w")

	h_file.write("#pragma once\n\n")

	h_file.write("#include <stdint.h>\n")
	h_file.write("#include <NFComm/NFShmCore/NFSizeString.h>\n")
	h_file.write("#include <NFComm/NFShmCore/NFArray.h>\n")
	h_file.write("#include <NFComm/NFShmCore/NFSeqOP.h>\n")
	h_file.write("#include <NFComm/NFShmCore/NFShmMgr.h>\n")
	for include_file in g_filedesc.include_lst:
		h_file.write("#include \"%s\"\n" % include_file)
	h_file.write("\n")

	#写入名字空间
	h_file.write("namespace %s_s {\n\n" % g_filedesc.namespace)

	#写入所有枚举对象
	#不用写入，protoc生成的h文件可以直接使用
	"""
	for enum_desc in g_filedesc.enum_lst:
		h_file.write("\tenum %s {\n" % enum_desc.name)
		for enum_field in enum_desc.field_lst:
			h_file.write("\t\t%s = %d;\n" % (enum_field[0], enum_field[1]))
		h_file.write("\t};\n\n")
	"""

	#写入所有struct
	for message_desc in g_filedesc.message_lst:
		h_file.write("\tstruct %s_s : public NFDescStoreSeqOP {\n" % message_desc.name)
		h_file.write("\t\t%s_s();\n" % message_desc.name)
		h_file.write("\t\tint CreateInit();\n")
		h_file.write("\t\tint ResumeInit();\n")
		for msg_field in message_desc.field_lst:
			line = ""

			if msg_field.no_field == True:
				continue

			if 	msg_field.is_array == True or msg_field.is_buffer == True:
				if msg_field.is_array == True and  msg_field.is_buffer == False:
					if int(msg_field.array_size) > 0:
						line += "\t\tNFArray<%s, %d> %s" % (msg_field.c_type,  msg_field.array_size,  msg_field.name)
						line += ";\n"
				elif msg_field.is_array == False and msg_field.is_buffer == True:
					if int(msg_field.buffer_size) > 0:
						if 'bytes' == msg_field.pb_type:
							line += "\t\tNFSizeBuffer<%d> %s" % (msg_field.buffer_size, msg_field.name)
							line += ";\n"
						else:
							line += "\t\tNFSizeString<%d> %s" % (msg_field.buffer_size, msg_field.name)
							line += ";\n"
				elif msg_field.is_array == True and msg_field.is_buffer == True:
					if int(msg_field.array_size) > 0 and int(msg_field.buffer_size) > 0:
						if 'bytes' == msg_field.pb_type:
							#数组有效长度
							line += "\t\tNFArray<NFSizeBuffer<%d>, %d> %s" % (msg_field.buffer_size,  msg_field.array_size, msg_field.name)
							line += ";\n"
						else:
							#数组有效长度
							line += "\t\tNFArray<NFSizeString<%d>, %d> %s" % (msg_field.buffer_size,  msg_field.array_size, msg_field.name)
							line += ";\n"
			else:
				line += "\t\t%s %s" % (msg_field.c_type, msg_field.name)
				line += ";\n"

			h_file.write(line)

		#写入转换函数
		h_file.write("\n")
		message_desc.func_write_to_pbmsg = "write_to_pbmsg(const struct %s_s & obj, %s & msg)" % (message_desc.name, message_desc.pb_msgname)
		message_desc.func_read_from_pbmsg = "read_from_pbmsg(const %s & msg, struct %s_s & obj)" % (message_desc.pb_msgname, message_desc.name)
		message_desc.func_new_proto = "new_pbmsg()"
		message_desc.func_make_proto = "make_pbmsg()"

		h_file.write("\t\tstatic void %s;\n" % (message_desc.func_write_to_pbmsg))
		h_file.write("\t\tstatic void %s;\n" % (message_desc.func_read_from_pbmsg))
		h_file.write("\t\tstatic %s* %s{ return new %s(); }\n" % (message_desc.pb_msgname, message_desc.func_new_proto, message_desc.pb_msgname))
		h_file.write("\t\tstatic %s %s{ return %s(); }\n" % (message_desc.pb_msgname, message_desc.func_make_proto, message_desc.pb_msgname))
		h_file.write("\t};\n")
		h_file.write("\ttypedef struct %s_s %s_t;\n\n" % (message_desc.name, message_desc.name))

	h_file.write("}\n\n")
	h_file.close()

def write_cppfile():
	""""""
	global g_filedesc

	#创建cpp文件
	cpp_file = open(g_filedesc.name + ".cpp", "w")

	cpp_file.write("#include \"%s.h\"\n\n" % g_filedesc.name)
	cpp_file.write("namespace %s_s {\n\n" % g_filedesc.namespace)

	x_postfix = int(time.time())

	#打包解包文件
	for message_desc in g_filedesc.message_lst:
		#contruct func
		cpp_file.write("%s_s::%s_s() {\n" % (message_desc.name, message_desc.name))
		cpp_file.write("\tif (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {\n")
		cpp_file.write("\t\tCreateInit();\n")
		cpp_file.write("\t} else {\n")
		cpp_file.write("\t\tResumeInit();\n")
		cpp_file.write("\t}\n")
		cpp_file.write("}\n\n")

		#CreateInit
		cpp_file.write("int %s_s::CreateInit() {\n" % (message_desc.name))
		for msg_field in message_desc.field_lst:
			if msg_field.no_field == True:
				continue
			if True != msg_field.is_array:
				#普通成员
				if 'bytes' != msg_field.pb_type and True != msg_field.is_string and True != msg_field.is_message:
					cpp_file.write("\t%s = (%s)0;\n" % (msg_field.name, msg_field.convert_type))

		cpp_file.write("\treturn 0;\n")
		cpp_file.write("}\n\n")

		#ResumeInit
		cpp_file.write("int %s_s::ResumeInit() {\n" % (message_desc.name))
		cpp_file.write("\treturn 0;\n")
		cpp_file.write("}\n\n")

		#write_to_pbmsg
		cpp_file.write("void %s_s::%s {\n" % (message_desc.name, message_desc.func_write_to_pbmsg))
		for msg_field in message_desc.field_lst:
			if msg_field.no_field == True:
				continue
			if True == msg_field.is_array:
				if  int(msg_field.array_size) > 0:
						#如果是数组成员
						cpp_file.write("\tfor(int32_t i = 0; i < obj.%s.GetSize() && i < obj.%s.GetMaxSize(); ++i) {\n" % (msg_field.name,  msg_field.name))
						if True == msg_field.is_string:
							cpp_file.write("\t\tmsg.add_%s((%s)obj.%s[i].Get());\n" % (msg_field.name.lower(), msg_field.convert_type, msg_field.name))
						elif 'bytes' == msg_field.pb_type and  int(msg_field.buffer_size) > 0:
							cpp_file.write("\t\tmsg.add_%s((%s)obj.%s[i].Get(), obj.%s[i].Size());\n" % (msg_field.name.lower(), msg_field.convert_type, msg_field.name, msg_field.name))
						elif False == msg_field.is_message:
							cpp_file.write("\t\tmsg.add_%s((%s)obj.%s[i]);\n" % (msg_field.name.lower(), msg_field.convert_type, msg_field.name))
						else:
							cpp_file.write("\t\t%s* temp_%s = msg.add_%s();\n" % (msg_field.pb_type, msg_field.name.lower(), msg_field.name.lower()))
							cpp_file.write("\t\t%s_s::write_to_pbmsg(obj.%s[i], *temp_%s);\n" % (msg_field.pb_type.split("::")[-1], msg_field.name, msg_field.name.lower()))
						cpp_file.write("\t}\n")
			else:
				#普通成员
				if 'bytes' == msg_field.pb_type:
					if int(msg_field.buffer_size) > 0:
							cpp_file.write("\tmsg.set_%s((%s)obj.%s.Get(), obj.%s.Size());\n" % (msg_field.name.lower(), msg_field.convert_type, msg_field.name, msg_field.name))
				elif True == msg_field.is_string:
					cpp_file.write("\tmsg.set_%s((%s)obj.%s.Get());\n" % (msg_field.name.lower(), msg_field.convert_type, msg_field.name))
				elif False == msg_field.is_message:
					cpp_file.write("\tmsg.set_%s((%s)obj.%s);\n" % (msg_field.name.lower(), msg_field.convert_type, msg_field.name))
				else:
					cpp_file.write("\t%s* temp_%s = msg.mutable_%s();\n" % (msg_field.pb_type, msg_field.name.lower(), msg_field.name.lower()))
					cpp_file.write("\t%s_s::write_to_pbmsg(obj.%s, *temp_%s);\n" % (msg_field.pb_type.split("::")[-1], msg_field.name, msg_field.name.lower()))
			x_postfix = x_postfix - 1

		cpp_file.write("}\n\n")

		"""--------------------------------------------------------------------"""
		#read_from_pbmsg
		cpp_file.write("void %s_s::%s {\n" % (message_desc.name, message_desc.func_read_from_pbmsg))
		cpp_file.write("\tmemset(&obj, 0, sizeof(struct %s_s));\n" % message_desc.name)
		for msg_field in message_desc.field_lst:
			if msg_field.no_field == True:
				continue
			if True == msg_field.is_array:
				if int(msg_field.array_size) > 0:
					cpp_file.write("\tobj.%s.SetSize(msg.%s_size() > obj.%s.GetMaxSize() ? obj.%s.GetMaxSize() : msg.%s_size());\n" % (msg_field.name, msg_field.name.lower(), msg_field.name,  msg_field.name, msg_field.name.lower()))
					cpp_file.write("\tfor(int32_t i = 0; i < obj.%s.GetSize(); ++i) {\n" % msg_field.name)
					if True == msg_field.is_string:
						cpp_file.write("\t\tobj.%s[i].Copy(msg.%s(i));\n" % (msg_field.name, msg_field.name.lower()))
						#cpp_file.write("\t\tstrncpy(obj.%s[i], msg.%s(i).c_str(), %d-1);\n" % (msg_field.name, msg_field.name.lower(), msg_field.buffer_size))
					elif True == msg_field.is_buffer and int(msg_field.buffer_size) > 0:
						if 'bytes' != msg_field.pb_type:
							cpp_file.write("\t\tobj.%s[i].Copy(msg.%s(i));\n" % (msg_field.name, msg_field.name.lower()))
							#cpp_file.write("\t\tmemcpy(obj.%s[i].Get(), msg.%s(i).c_str(), msg.%s().size());\n" % (msg_field.name, msg_field.name.lower(), msg_field.name.lower()))
						else:
							cpp_file.write("\t\tobj.%s[i].Copy(msg.%s(i));\n" % (msg_field.name, msg_field.name.lower()))
							#cpp_file.write("\t\tobj.%s_bytes_size = msg.%s().size() > %d ? %d : msg.%s().size();\n" % (msg_field.name, msg_field.name.lower(), msg_field.buffer_size,  msg_field.buffer_size, msg_field.name.lower()))
							#cpp_file.write("\t\tmemcpy(obj.%s[i].Get(), msg.%s(i).c_str(), obj.%s[i].GetMaxSize());\n" % (msg_field.name, msg_field.name.lower(), msg_field.buffer_size))
					elif True == msg_field.is_message:
						#cpp_file.write("#ifdef _DEBUG_\n")
						#cpp_file.write("assert(i < (int)ARRAYSIZE(obj.%s));\n" % msg_field.name)
						#cpp_file.write("#endif\n")
						#cpp_file.write("\t\tif (i >= (int)ARRAYSIZE(obj.%s))\n\t\t\tbreak;\n" % msg_field.name)
						cpp_file.write("\t\tconst %s & temp_%s = msg.%s(i);\n" % (msg_field.pb_type, msg_field.name.lower(), msg_field.name.lower()))
						cpp_file.write("\t\t%s_s::read_from_pbmsg(temp_%s, obj.%s[i]);\n" % (msg_field.pb_type.split("::")[-1], msg_field.name.lower(), msg_field.name))
					else:
						#cpp_file.write("#ifdef _DEBUG_\n")
						#cpp_file.write("assert(i < (int)ARRAYSIZE(obj.%s));\n" % msg_field.name)
						#cpp_file.write("#endif\n")
						#cpp_file.write("\t\tif (i >= (int)ARRAYSIZE(obj.%s))\n\t\t\tbreak;\n" % msg_field.name )
						cpp_file.write("\t\tobj.%s[i] = msg.%s(i);\n" % (msg_field.name, msg_field.name.lower()))
					cpp_file.write("\t}\n")
			else:
				if True == msg_field.is_string:
					cpp_file.write("\tobj.%s.Copy(msg.%s());\n" % (msg_field.name, msg_field.name.lower()))
					#cpp_file.write("\tstrncpy(obj.%s, msg.%s().c_str(), %d-1);\n" % (msg_field.name, msg_field.name.lower(), msg_field.buffer_size))
				elif True == msg_field.is_buffer:
					if int(msg_field.buffer_size) > 0:
						if 'bytes' != msg_field.pb_type:
							cpp_file.write("\tobj.%s.Copy(msg.%s());\n" % (msg_field.name, msg_field.name.lower()))
							#cpp_file.write("\tmemcpy(obj.%s, msg.%s().c_str(), msg.%s().size());\n" % (msg_field.name, msg_field.name.lower(), msg_field.name.lower()))
						else:
							cpp_file.write("\tobj.%s.Copy(msg.%s());\n" % (msg_field.name, msg_field.name.lower()))
							#cpp_file.write("\tobj.%s_bytes_size = msg.%s().size() > %d ? %d : msg.%s().size();\n" % (msg_field.name, msg_field.name.lower(), msg_field.buffer_size,  msg_field.buffer_size, msg_field.name.lower()))
							#cpp_file.write("\tmemcpy(obj.%s, msg.%s().c_str(), obj.%s_bytes_size);\n" % (msg_field.name, msg_field.name.lower(), msg_field.name))
				elif True == msg_field.is_message:
					cpp_file.write("\tconst %s & temp_%s = msg.%s();\n" % (msg_field.pb_type, msg_field.name.lower(), msg_field.name.lower()))
					cpp_file.write("\t%s_s::read_from_pbmsg(temp_%s, obj.%s);\n" % (msg_field.pb_type.split("::")[-1], msg_field.name.lower(), msg_field.name))
				else:
					cpp_file.write("\tobj.%s = msg.%s();\n" % (msg_field.name, msg_field.name.lower()))

			x_postfix = x_postfix - 1
		cpp_file.write("}\n\n")

	cpp_file.write("}")
	cpp_file.close()


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

def show_usage():
	print """usage for proto2struct example:
	./proto2struct.py --proto_ds=xxx.proto.ds --proto_fname=test.proto --out_path=./"""

if __name__ == "__main__":
	(opts, args) = getopt.getopt(sys.argv[1:], "d:f:o:", ["proto_ds=", "proto_fname=", "out_path="])

	if len(opts) < 2:
		show_usage()
		sys.exit(-1)

	proto_ds = ""
	proto_fname = ""
	out_path = ""

	for (o, a) in opts:
		if o in ("-d", "--proto_ds"):
			proto_ds = a
		elif o in ("-f", "--proto_fname"):
			proto_fname = a
			g_filedesc.name = proto_fname.split("/")[-1].split(".")[0] + "_s"
		elif o in ("-o", "--out_path"):
			out_path = a
		else:
			show_usage()
			sys.exit(-1)

	proto_ds_content = read_proto_ds(proto_ds)
	#反序列化生成DescriptorSet对象
	pb_descriptor_set = descriptor_pb2.FileDescriptorSet()
	pb_descriptor_set.ParseFromString(proto_ds_content)

	#构建descriptor_database对象
	i = 0
	pb_descriptor_db = descriptor_database.DescriptorDatabase()
	for proto_desc in pb_descriptor_set.file:

		"""if proto_desc.name not in exclude_proto:
			g_filedesc.include_lst.append(proto_desc.name.split(".")[0] + ".pb.h")
			g_filedesc.include_lst.append(proto_desc.name.split(".")[0] + "_s.h")
			print "proto_desc class[%s]" % proto_desc.__class__.__name__"""
		"""
file[full.proto.ds] size[4735]
[0] proto file[google/protobuf/descriptor.proto] type[FileDescriptorProto] package[google.protobuf]
[1] proto file[proto2struct_def.proto] type[FileDescriptorProto] package[proto2struct_def]
[2] proto file[test.proto] type[FileDescriptorProto] package[test]"""

		#print "[%d] proto file[%s] type[%s] package[%s]" % (i, proto_desc.name, proto_desc.DESCRIPTOR.name, proto_desc.package)
		i = i + 1

		if proto_desc.name == proto_fname:
			"""得到文件的namespace"""
			g_filedesc.namespace = proto_desc.package

			#生成include列表
			g_filedesc.include_lst.append(proto_fname.split(".")[0] + ".pb.h")
			g_filedesc.include_lst.append(proto_fname.split(".")[0] + "_s.h")
			"""这里得到该文件中的所有import项目"""
			for import_proto in proto_desc.dependency:
				#print "import_proto name[%s]" % import_proto
				if import_proto not in exclude_proto:
					g_filedesc.include_lst.append(import_proto.split(".")[0] + ".pb.h")
					g_filedesc.include_lst.append(import_proto.split(".")[0] + "_s.h")

			"""得到文件中所有的enum对象"""
			for enum_desc_proto in proto_desc.enum_type:

				enum_info = EnumDesc()
				enum_info.name = enum_desc_proto.name

				#print "enum[%s]" % enum_desc_proto.name
				for enum_value_desc_proto in enum_desc_proto.value:
					#print "\t[%s] [%d]" % (enum_value_desc_proto.name, enum_value_desc_proto.number)
					enum_info.field_lst.append((enum_value_desc_proto.name, enum_value_desc_proto.number))

				g_filedesc.enum_lst.append(enum_info)

			"""得到文件中所有的message对象"""
			for message_desc_proto in proto_desc.message_type:

				message_info = MessageDesc()
				message_info.name = message_desc_proto.name
				message_info.pb_msgname = "::" + g_filedesc.namespace + "::" + message_info.name
				message_info.field_lst = []

				"""print "message[%s] [%s] type[%s]" % (message_desc_proto.name, \
				message_desc_proto.DESCRIPTOR.full_name, message_desc_proto.DESCRIPTOR.name)"""
				"""message[C2A_AuthSyn] type[DescriptorProto]"""
				"""得到所有的fielddescriptor"""
				for field_desc_proto in message_desc_proto.field:

					message_field_info = MessageFieldDesc()
					message_field_info.name = field_desc_proto.name

					#根据label==repeated判断是否是数组
					if field_desc_proto.label == descriptor.FieldDescriptor.LABEL_REPEATED:
						message_field_info.is_array = True

					#判断类型
					if field_desc_proto.type == descriptor.FieldDescriptor.TYPE_DOUBLE:
						message_field_info.c_type = message_field_info.pb_type = message_field_info.convert_type = "double"
					elif field_desc_proto.type == descriptor.FieldDescriptor.TYPE_FLOAT:
						message_field_info.c_type = message_field_info.pb_type = message_field_info.convert_type = "float"
					elif field_desc_proto.type == descriptor.FieldDescriptor.TYPE_INT64:
						message_field_info.c_type = message_field_info.pb_type = message_field_info.convert_type = "int64_t"
					elif field_desc_proto.type == descriptor.FieldDescriptor.TYPE_UINT64:
						message_field_info.c_type = message_field_info.pb_type = message_field_info.convert_type = "uint64_t"
					elif field_desc_proto.type == descriptor.FieldDescriptor.TYPE_BOOL:
						message_field_info.c_type = message_field_info.pb_type = message_field_info.convert_type = "bool"
					elif field_desc_proto.type == descriptor.FieldDescriptor.TYPE_STRING:
						message_field_info.c_type = "char"
						message_field_info.pb_type = "string"
						message_field_info.convert_type = "const char*"
						message_field_info.is_buffer = True
						message_field_info.is_string = True
					elif field_desc_proto.type == descriptor.FieldDescriptor.TYPE_MESSAGE:
						message_field_info.c_type = message_field_info.convert_type = "struct " + field_desc_proto.type_name.split(".")[-1] + "_s"
						message_field_info.pb_type = "::" + g_filedesc.namespace + "::" + field_desc_proto.type_name.split(".")[-1]
						message_field_info.is_message = True
					elif field_desc_proto.type == descriptor.FieldDescriptor.TYPE_BYTES:
						message_field_info.c_type = "uint8_t"
						message_field_info.convert_type = "const void*"
						message_field_info.pb_type = "bytes"
						message_field_info.is_buffer = True
					elif field_desc_proto.type == descriptor.FieldDescriptor.TYPE_INT32:
						message_field_info.c_type = message_field_info.pb_type = message_field_info.convert_type = "int32_t"
					elif field_desc_proto.type == descriptor.FieldDescriptor.TYPE_UINT32:
						message_field_info.c_type = message_field_info.pb_type = message_field_info.convert_type = "uint32_t"
					elif field_desc_proto.type == descriptor.FieldDescriptor.TYPE_ENUM:
						message_field_info.c_type = message_field_info.pb_type = message_field_info.convert_type = "::" + g_filedesc.namespace + "::" + field_desc_proto.type_name.split(".")[-1]
						message_field_info.is_enum = True;
					else:
						print "\t Error ----[%s] number[%d] type_name[%s] is not support!!!" % \
						(field_desc_proto.name, field_desc_proto.number, field_desc_proto.type_name)

					"""print "\t[%s] number[%d] label[%s] type[%s] type_name[%s] pb_type[%s]" % \
					(field_desc_proto.name, field_desc_proto.number, str(field_desc_proto.label), \
					str(field_desc_proto.type), field_desc_proto.type_name, field_desc_proto.DESCRIPTOR.full_name)"""

					message_info.field_lst.append(message_field_info)
				g_filedesc.message_lst.append(message_info)
		pb_descriptor_db.Add(proto_desc)

	#构建DescriptorPool
	pb_descriptor_pool = descriptor_pool.DescriptorPool(pb_descriptor_db)

	#处理每个Message field的自定义option，其实在这里做更方便些
	for message in g_filedesc.message_lst:
		full_name = "%s.%s" % (g_filedesc.namespace, message.name)
		"""print "full_name", full_name"""
		message_desc = pb_descriptor_pool.FindMessageTypeByName(full_name)
		if message_desc is not None:
			"""print "message[%s] full_name[%s] fields[%d]" % (message_desc.name, message_desc.full_name, len(message_desc.fields))"""
			for msg_field_desc in message_desc.fields:
				#得到每个msg的field options
				msg_field_options = msg_field_desc.GetOptions()

				for msgfielddesc in message.field_lst:
					if msg_field_desc.name == msgfielddesc.name:
						"""print "\tfield: [%s]" % (msgfielddesc.name)"""
						if msg_field_options.Extensions[yd_fieldoptions_pb2.no_field] == True:
							msgfielddesc.no_field = True

						if msgfielddesc.is_array == True:
							ary_size = msg_field_options.Extensions[yd_fieldoptions_pb2.field_arysize]
							"""print "\t\t is_array[True] ary_size[%d]" % ary_size"""
							msgfielddesc.array_size = ary_size

						if msgfielddesc.is_buffer == True:
							buf_size = msg_field_options.Extensions[yd_fieldoptions_pb2.field_bufsize]
							"""print "\t\t is_buffer[True] buf_size[%d]" % buf_size"""
							msgfielddesc.buffer_size = buf_size

						#数值类型做特殊处理
						special_type = msg_field_options.Extensions[yd_fieldoptions_pb2.field_typename]
						if len(special_type) != 0:
							msgfielddesc.c_type = special_type
							"""print "\t\t c_type[%s]" % special_type"""
						else:
							"""print "\t\t c_type[%s]" % msgfielddesc.c_type"""

	write_hfile()
	write_cppfile()

	#移动到目标目录
	if os.path.exists(out_path) and out_path != "./":
		h_file = g_filedesc.name + ".h"
		cpp_file = g_filedesc.name + ".cpp"
		#先删除
		shutil.copyfile(h_file, out_path+h_file)
		shutil.copyfile(cpp_file, out_path+cpp_file)
		os.remove(h_file)
		os.remove(cpp_file)

"""
enum[Proto_C2AEncryptType]
	[E_NO_ENCRYPT] [0]
	[E_AES] [1]
	[E_3DES] [2]
message[ClientInfo] [google.protobuf.DescriptorProto] type[DescriptorProto]
	[mac_addr] number[1] label[2] type[9] type_name[] pb_type[google.protobuf.FieldDescriptorProto]
	[network_type] number[2] label[2] type[5] type_name[] pb_type[google.protobuf.FieldDescriptorProto]
message[C2A_AuthSyn] [google.protobuf.DescriptorProto] type[DescriptorProto]
	[auth_data] number[1] label[2] type[9] type_name[] pb_type[google.protobuf.FieldDescriptorProto]
	[account_info] number[2] label[2] type[9] type_name[] pb_type[google.protobuf.FieldDescriptorProto]
	[encrypt_type] number[3] label[2] type[14] type_name[.test.Proto_C2AEncryptType] pb_type[google.protobuf.FieldDescriptorProto]
	[a] number[4] label[2] type[5] type_name[] pb_type[google.protobuf.FieldDescriptorProto]
	[b] number[5] label[3] type[5] type_name[] pb_type[google.protobuf.FieldDescriptorProto]
	[c] number[6] label[1] type[4] type_name[] pb_type[google.protobuf.FieldDescriptorProto]
	[d] number[7] label[2] type[5] type_name[] pb_type[google.protobuf.FieldDescriptorProto]
	[e] number[8] label[2] type[11] type_name[.test.ClientInfo] pb_type[google.protobuf.FieldDescriptorProto]

"""

