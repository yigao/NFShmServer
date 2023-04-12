﻿GAME_NFRAME=..
GAME_SRC_PATH=../../../

GAME_INSTALL_PATH=${GAME_SRC_PATH}/Install
GAME_BIN_PATH=${GAME_INSTALL_PATH}/Bin
GAME_DATA_PATH=${GAME_INSTALL_PATH}/Config/Data
GAME_SQL_PATH=${GAME_INSTALL_PATH}/Sql
GAME_BUILD_PATH=${GAME_SRC_PATH}/Build/NFComm/makefile

MAKEFILE_PATH=${GAME_SRC_PATH}/src/NFComm/makefiles
MAKE_PROTOC_GEN=${MAKEFILE_PATH}/protoc_gen.makefile
MAKE_EXCEL_GEN=${MAKEFILE_PATH}/excel_gen.makefile
MAKE_SQL_GEN=${MAKEFILE_PATH}/sql_gen.makefile

RESDB_EXCEL_PATH=${GAME_SRC_PATH}/Excel
PROTOCGEN_FILE_PATH=${GAME_BUILD_PATH}/temp

THIRD_PARTY_PATH=${GAME_SRC_PATH}/thirdparty
THIRD_PARTY_TOOLS_PATH=${THIRD_PARTY_PATH}/tools
THIRD_PARTY_INC_PATH=${THIRD_PARTY_PATH}/

TOOLS_PATH=${GAME_SRC_PATH}/tools
THIRD_PARTY_TOOLS_PATH=${TOOLS_PATH}
PROTOC=protoc
PROTO2STRUCT=python ${TOOLS_PATH}/proto_2_struct/proto2struct.py
EXCEL2BIN=python ${TOOLS_PATH}/excel_2_bin/excel2bin_new.py
PROTO2SQL=python ${TOOLS_PATH}/proto_2_sql/proto2sql.py
PROTO2STRUCT_PATH=${TOOLS_PATH}/proto_2_struct/
EXCEL2BIN_PATH=${TOOLS_PATH}/excel_2_bin/
PROTO2SQL_PATH=${TOOLS_PATH}/proto_2_sql/

MAKE_SINGLE_JOB_NUM=4

#######################
#protocol define
#######################

PROTOCOL_PATH=${GAME_SRC_PATH}/src/NFComm/Message
PROTOCOL_COMM_PATH=${PROTOCOL_PATH}/common
PROTOCOL_KERNEL_PATH=${PROTOCOL_PATH}/kernel
PROTOCOL_CS_PATH=${PROTOCOL_PATH}/proto_cs
PROTOCOL_STORESVR_PATH=${PROTOCOL_PATH}/storesvr
PROTOCOL_SS_PATH=${PROTOCOL_PATH}/proto_svr

PROTOCOL_COMM_XML=${PROTOCOL_COMM_PATH}/proto_common.proto
PROTOCOL_COMM_H=${PROTOCGEN_FILE_PATH}/proto_common.pb.h ${PROTOCGEN_FILE_PATH}/proto_common_s.h
PROTOCOL_COMM_CPP=${PROTOCGEN_FILE_PATH}/proto_common.pb.cc ${PROTOCGEN_FILE_PATH}/proto_common_s.cpp
PROTOCOL_COMM_DESCRIPTOR=${PROTOCGEN_FILE_PATH}/proto_common.proto.ds
PROTOCOL_COMM_PY=${PROTOCGEN_FILE_PATH}/proto_common_pb2.py

PROTOCOL_KERNEL_XML=${PROTOCOL_KERNEL_PATH}/proto_kernel.proto
PROTOCOL_KERNEL_H=${PROTOCGEN_FILE_PATH}/proto_kernel.pb.h
PROTOCOL_KERNEL_CPP=${PROTOCGEN_FILE_PATH}/proto_kernel.pb.cc

PROTOCOL_FIELD_XML=${PROTOCOL_KERNEL_PATH}/yd_fieldoptions.proto
PROTOCOL_FIELD_H=${PROTOCGEN_FILE_PATH}/yd_fieldoptions.pb.h
PROTOCOL_FIELD_CPP=${PROTOCGEN_FILE_PATH}/yd_fieldoptions.pb.cc
PROTOCOL_FIELD_PY=${PROTOCGEN_FILE_PATH}/yd_fieldoptions_pb2.py

PROTOCOL_SOTRE_XML=${PROTOCOL_STORESVR_PATH}/storesvr_sqldata.proto
PROTOCOL_SOTRE_H=${PROTOCGEN_FILE_PATH}/storesvr_sqldata.pb.h
PROTOCOL_SOTRE_CPP=${PROTOCGEN_FILE_PATH}/storesvr_sqldata.pb.cc

PROTOCOL_COMM_DESCRIPTOR=${PROTOCGEN_FILE_PATH}/proto_common.proto.ds

PROTOCGEN_CPP= ${PROTOCOL_COMM_CPP} ${PROTOCOL_KERNEL_CPP} ${PROTOCOL_FIELD_CPP} ${PROTOCOL_SOTRE_CPP}

PROTOCGEN_H=${PROTOCOL_COMM_H} ${PROTOCOL_KERNEL_H} ${PROTOCOL_FIELD_H} ${PROTOCOL_SOTRE_H}

ALL_PROTOCGEN_FILE=${PROTOCGEN_CPP} ${PROTOCGEN_H}
ALL_PROTOC_DESCRIPTOR_FILE=${PROTOCOL_COMM_DESCRIPTOR}
ALL_PROTOCGEN_PY=${PROTOCOL_FIELD_PY}

NEW_PROTOCGEN_KERNEL_FILE_PATH=${GAME_SRC_PATH}/src/NFComm/NFKernelMessage

##########################
#
##########################
MAKE_COMPILE_LOG=${GAME_BUILD_PATH}/make_compile.log
MAKE_COMPILE_WARNING_LOG=${GAME_BUILD_PATH}/make_warning.log
MAKE_COMPILE_ERROR_LOG=${GAME_BUILD_PATH}/make_error.log
MAKE_DEPENDENT_LOG=${GAME_BUILD_PATH}/make_dependent.log
MAKE_DEPENDENT_ERROR_LOG=${GAME_BUILD_PATH}/make_dependent_error.log
MAKE_LINK_ERROR_LOG=${GAME_BUILD_PATH}/make_link_error.log

NEED_CLEAN_FILES=
