﻿GAME_NFRAME=..
GAME_SRC_PATH=../../../..

GAME_INSTALL_PATH=${GAME_SRC_PATH}/Install
GAME_BIN_PATH=${GAME_INSTALL_PATH}/Bin
GAME_DATA_PATH=${GAME_INSTALL_PATH}/Config/MMO/Data
GAME_SQL_PATH=${GAME_INSTALL_PATH}/Sql
GAME_BUILD_PATH=${GAME_SRC_PATH}/Build/game/MMO/NFLogicComm/makefile

MAKEFILE_PATH=${GAME_SRC_PATH}/game/MMO/NFLogicComm/makefiles
MAKE_PROTOC_GEN=${MAKEFILE_PATH}/protoc_gen.makefile
MAKE_EXCEL_GEN=${MAKEFILE_PATH}/excel_gen.makefile
MAKE_SQL_GEN=${MAKEFILE_PATH}/sql_gen.makefile

RESDB_EXCEL_PATH=${GAME_SRC_PATH}/game/MMO/Excel
PROTOCGEN_FILE_PATH=${GAME_BUILD_PATH}/temp

THIRD_PARTY_PATH=${GAME_SRC_PATH}/thirdparty
THIRD_PARTY_TOOLS_PATH=${THIRD_PARTY_PATH}/tools
THIRD_PARTY_INC_PATH=${THIRD_PARTY_PATH}/

TOOLS_PATH=${GAME_SRC_PATH}/tools
THIRD_PARTY_TOOLS_PATH=${TOOLS_PATH}
PROTOC=${THIRD_PARTY_TOOLS_PATH}/protoc
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
PROTOCOL_SVR_PATH=${GAME_SRC_PATH}/game/MMO/NFLogicComm/Message
PROTOCOL_COMM_PATH=${PROTOCOL_PATH}/common
PROTOCOL_KERNEL_PATH=${PROTOCOL_PATH}/kernel
PROTOCOL_STORESVR_PATH=${PROTOCOL_PATH}/storesvr
PROTOCOL_SS_PATH=${GAME_SRC_PATH}/src/NFServerComm/Message/proto_svr
PROTOCOL_SS_LOGIC_PATH=${PROTOCOL_SVR_PATH}/proto_svr
PROTOCOL_CS_LOGIC_PATH=${PROTOCOL_SVR_PATH}/proto_cs
RESDB_META_PATH=${PROTOCOL_SVR_PATH}/ResMetaS
COMMON_LOGIC_META_PATH=${PROTOCOL_SVR_PATH}/common

PROTOCOL_COMM_XML=${PROTOCOL_COMM_PATH}/proto_common.proto
PROTOCOL_KERNEL_XML=${PROTOCOL_KERNEL_PATH}/proto_kernel.proto
PROTOCOL_FIELD_XML=${PROTOCOL_KERNEL_PATH}/yd_fieldoptions.proto
PROTOCOL_SOTRE_XML=${PROTOCOL_STORESVR_PATH}/storesvr_sqldata.proto

PROTOCOL_SS_LOGIC_XML=$(wildcard ${PROTOCOL_SS_LOGIC_PATH}/*.proto)
PROTOCOL_SS_LOGIC_H=$(subst $(PROTOCOL_SS_LOGIC_PATH),$(PROTOCGEN_FILE_PATH),$(PROTOCOL_SS_LOGIC_XML:.proto=.pb.h))
PROTOCOL_SS_LOGIC_CPP=$(PROTOCOL_SS_LOGIC_H:.h=.cc)

PROTOCOL_CS_LOGIC_XML=$(wildcard ${PROTOCOL_CS_LOGIC_PATH}/*.proto)
PROTOCOL_CS_LOGIC_H=$(subst $(PROTOCOL_CS_LOGIC_PATH),$(PROTOCGEN_FILE_PATH),$(PROTOCOL_CS_LOGIC_XML:.proto=.pb.h))
PROTOCOL_CS_LOGIC_CPP=$(PROTOCOL_CS_LOGIC_H:.h=.cc)

RESDB_DESC_XML=$(wildcard ${RESDB_META_PATH}/*.proto)
RESDB_DESC_XML2=$(subst ${RESDB_META_PATH}/,,${RESDB_DESC_XML})
RESDB_DESC_TMP_BIN=$(subst ${RESDB_META_PATH},${GAME_DATA_PATH},${RESDB_DESC_XML})
RESDB_DESC_BIN=$(subst proto,bin,${RESDB_DESC_TMP_BIN})
RESDB_DESC_BIN2=$(subst ${GAME_DATA_PATH}/,,${RESDB_DESC_TMP_BIN})
RESDB_DESC_BIN3=$(subst .proto,,${RESDB_DESC_BIN2})
RESDB_DESC_EXCEL=$(wildcard ${RESDB_EXCEL_PATH}/*.xls)

RESDB_DESC_H=$(subst $(RESDB_META_PATH),$(PROTOCGEN_FILE_PATH),$(RESDB_DESC_XML:.proto=.pb.h))
RESDB_DESC_CPP=$(RESDB_DESC_H:.h=.cc)
RESDB_DESC_STRUCT_H=$(RESDB_DESC_H:.pb.h=_s.h)
RESDB_DESC_STRUCT_CPP=$(RESDB_DESC_STRUCT_H:.h=.cpp)
RESDB_META_DESCRIPTOR=${PROTOCGEN_FILE_PATH}/ResMeta.proto.ds

COMMON_LOGIC_DESC_XML=$(wildcard ${COMMON_LOGIC_META_PATH}/*.proto)
COMMON_LOGIC_DESC_XML2=$(subst ${COMMON_LOGIC_META_PATH}/,,${COMMON_LOGIC_DESC_XML})
COMMON_LOGIC_DESC_H=$(subst $(COMMON_LOGIC_META_PATH),$(PROTOCGEN_FILE_PATH),$(COMMON_LOGIC_DESC_XML:.proto=.pb.h))
COMMON_LOGIC_DESC_CPP=$(COMMON_LOGIC_DESC_H:.h=.cc)
COMMON_LOGIC_DESC_STRUCT_H=$(COMMON_LOGIC_DESC_H:.pb.h=_s.h)
COMMON_LOGIC_DESC_STRUCT_CPP=$(COMMON_LOGIC_DESC_STRUCT_H:.h=.cpp)
COMMON_LOGIC_META_DESCRIPTOR=${PROTOCGEN_FILE_PATH}/CommonLogic.proto.ds

PROTOCGEN_CPP= ${PROTOCOL_SS_LOGIC_CPP} ${RESDB_DESC_CPP} ${RESDB_DESC_STRUCT_CPP} ${PROTOCOL_CS_LOGIC_CPP} ${COMMON_LOGIC_DESC_CPP} ${COMMON_LOGIC_DESC_STRUCT_CPP}

PROTOCGEN_H=${PROTOCOL_SS_LOGIC_H} ${RESDB_DESC_H} ${RESDB_DESC_STRUCT_H} ${PROTOCOL_CS_LOGIC_H} ${COMMON_LOGIC_DESC_H} ${COMMON_LOGIC_DESC_STRUCT_H}

ALL_PROTOCGEN_FILE=${PROTOCGEN_CPP} ${PROTOCGEN_H}
ALL_PROTOC_DESCRIPTOR_FILE=${RESDB_META_DESCRIPTOR}
ALL_PROTOCGEN_PY=

NEW_PROTOCGEN_FILE_PATH=${GAME_SRC_PATH}/game/MMO/NFLogicComm/NFServerLogicMessage

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
RESDB_BIN_FILE=${GAME_DATA_PATH}/ConstDesc.bin ${GAME_DATA_PATH}/NameDesc.bin
