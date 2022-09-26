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

def show_usage():
	print """usage for excel2bin example:
	./filecopy --src=x-1.xls
                --dst=x-1.xls"""

if __name__ == "__main__":
	(opts, args) = getopt.getopt(sys.argv[1:], "s:d", ["src=", "dst="])

	if( 0 == len( opts ) ):
		show_usage()
		sys.exit( -1 )

	str_src_files = ""
	dst_files = ""

	reload(sys)
	sys.setdefaultencoding("utf-8")

	for (o, a) in opts:
		if o in ("-s", "--src"):
			str_src_files = a
		elif o in ("-d", "--dst"):
			dst_files = a
		else:
			print "unknown command!"
			show_usage()
			sys.exit(-1)

	print "Input parameters:\n\tsrc_files[%s] dest_files[%s]\n\t" % (str_src_files, dst_files)

	str_src_files = re.split("\s+", str_src_files)
	#print "Handle src files:%s" % (str_src_files)
	try:
		for src_file in str_src_files:
			if len(src_file) > 0 and os.path.isfile(src_file):
				file_name = os.path.basename(src_file)
				out_file = dst_files + file_name
				if os.path.isfile(out_file):
					if filecmp.cmp(src_file, out_file) == False:
						shutil.copyfile(src_file, out_file)
						print "dst file %s diff %s, need copy" % (out_file, src_file)
					else:
						print "dst file %s same %s, don't need copy" % (out_file, src_file)
				else:
					shutil.copyfile(src_file, out_file)
					print "%s not exist, copy %s" % (out_file, src_file)
			elif len(src_file) > 0:
				print "%s not exist, not copy" % (src_file)
	except:
		print "\033[1;31;40m some error \033[0m"
		sys.exit(-1)

	print "Success Handle all file copy"