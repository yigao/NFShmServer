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
import string
import filecmp

def write_makefile(makefile_file, resmetas_makefile, file):
	makefile_file.write("${PROTOCGEN_FILE_PATH}/" + file + ".proto " + "${PROTOCGEN_FILE_PATH}/" + file + "_gen.makefile:${RESDB_EXCELMMO_PATH}/" + file + ".xlsx\n")
	makefile_file.write("\tmkdir -p ${PROTOCGEN_FILE_PATH}\n")
	makefile_file.write("\t${EXCEL2PROTO} --src=$^ --dst=${PROTOCGEN_FILE_PATH}/\n")
	makefile_file.write("\t${FILE_COPY_EXE} --src=\"" + "${PROTOCGEN_FILE_PATH}/" + file + ".proto " + "${PROTOCGEN_FILE_PATH}/" + file + "_gen.makefile"+ "\" --dst=${RESDB_META_PATH}/\n")
	makefile_file.write("\n\n")

	resmetas_makefile.write("${PROTOCGEN_FILE_PATH}/" + file + ".pb.h " + "${PROTOCGEN_FILE_PATH}/" + file + ".pb.cc " + "${PROTOCGEN_FILE_PATH}/" + file + "_s.h " +  "${PROTOCGEN_FILE_PATH}/" + file + "_s.cpp " + "${PROTOCGEN_FILE_PATH}/" + file + ".proto.ds:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/" + file + ".proto\n")
	resmetas_makefile.write("\tmkdir -p ${PROTOCGEN_FILE_PATH}\n")
	resmetas_makefile.write("\t${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/" + file + ".proto.ds " + " --cpp_out=${PROTOCGEN_FILE_PATH}\n")
	resmetas_makefile.write("\t${PROTO2STRUCT} --proto_ds=${PROTOCGEN_FILE_PATH}/" + file + ".proto.ds " + " --proto_fname=" + file + ".proto --out_path=${PROTOCGEN_FILE_PATH}/;\n")
	resmetas_makefile.write("\t${FILE_COPY_EXE} --src=\"" + "${PROTOCGEN_FILE_PATH}/" + file + ".pb.h " + "${PROTOCGEN_FILE_PATH}/" + file + ".pb.cc " + "${PROTOCGEN_FILE_PATH}/" + file + "_s.h " +  "${PROTOCGEN_FILE_PATH}/" + file + "_s.cpp \"" + " --dst=${NEW_PROTOCGEN_FILE_PATH}/\n")

def show_usage():
	print """usage for excel2bin example:
	./filecopy --src=x-1.xls
                --dst=x-1.xls"""

if __name__ == "__main__":
	(opts, args) = getopt.getopt(sys.argv[1:], "s:d:w", ["src=", "dst=", "work="])

	if( 0 == len( opts ) ):
		show_usage()
		sys.exit( -1 )

	str_src_files = ""
	dst_files = ""
	work = ""

	reload(sys)
	sys.setdefaultencoding("utf-8")

	for (o, a) in opts:
		if o in ("-s", "--src"):
			str_src_files = a
		elif o in ("-d", "--dst"):
			dst_files = a
		elif o in ("-w", "--work"):
			work = a
		else:
			print "unknown command!"
			show_usage()
			sys.exit(-1)

	print "Input parameters:\n\tsrc_files[%s] dest_files[%s]\n\t" % (str_src_files, dst_files)

	str_src_files = re.split("\s+", str_src_files)
	#print "Handle src files:%s" % (str_src_files)
	try:
		makefile_name = "tmp_excelmmo_gen.makefile"
		makefile_file = open(makefile_name, 'w')
		makefile_file.write("include ./define.makefile\n\n");
		makefile_file.write(".PHONY:all\n\n");
		makefile_file.write("all:${RESDB_BIN_FILE}\n\n");
		resmetas_makefile_name = "tmp_resmetas_gen.makefile"
		resmetas_makefile = open(resmetas_makefile_name, 'w')
		resmetas_makefile.write("include ./define.makefile\n\n");
		resmetas_makefile.write(".PHONY:all\n\n");
		resmetas_makefile.write("all:${RESDB_DESC_H} ${RESDB_DESC_CPP} ${RESDB_DESC_STRUCT_H} ${RESDB_DESC_STRUCT_CPP}\n\n");
		for src_file in str_src_files:
			if len(src_file) > 0:
				write_makefile(makefile_file,resmetas_makefile, src_file)

		makefile_file.close()
		resmetas_makefile.close()

		if os.path.exists(dst_files) and dst_files != "./":
			shutil.copyfile(makefile_name, dst_files + "excelmmo_gen.makefile")
			os.remove(makefile_name)
			shutil.copyfile(resmetas_makefile_name, dst_files + "resmetas_gen.makefile")
			os.remove(resmetas_makefile_name)
	except:
		print "\033[1;31;40m some error \033[0m"
		sys.exit(-1)

	print "Success Handle all file copy"