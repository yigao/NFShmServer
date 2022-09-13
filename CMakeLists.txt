CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(ShmNFrame)
add_compile_options(-std=c++11)

if( CMAKE_BUILD_TYPE STREQUAL "Release" )
	set(CMAKE_BUILD_TYPE "Release")
	set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fPIC")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fPIC -std=c++11 -g -O3 -Wall")
	add_definitions(
			-DNDEBUG
			-Wcomment
			-DNF_STATIC_PLUGIN
			-DLUA_COMPAT_5_1
			-fPIC
	)
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_BUILD_TYPE "Debug")
	set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fPIC")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -Wall -g -ggdb -fPIC")
	add_definitions(
			-D_DEBUG
			-Wcomment
			-DNF_STATIC_PLUGIN
			-DLUA_COMPAT_5_1
			-fPIC
	)
elseif(CMAKE_BUILD_TYPE STREQUAL "DynamicDebug")
	set(CMAKE_BUILD_TYPE "DynamicDebug")
	set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fPIC")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -Wall -g -ggdb -fPIC -Wextra -Wno-unused-parameter -Wno-conversion-null -Wno-unused-but-set-variable -Wno-int-to-pointer-cast -Wno-array-bounds")
	add_definitions(
			-D_DEBUG
			-Wcomment
			-DLUA_COMPAT_5_1
			-DNF_DYNAMIC_PLUGIN
			-fPIC
	)
elseif(CMAKE_BUILD_TYPE STREQUAL "DynamicRelease")
	set(CMAKE_BUILD_TYPE "DynamicRelease")
	set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fPIC")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fPIC -std=c++11 -O3 -g -Wall")

	add_definitions(
			-DNDEBUG
			-Wcomment
			-DLUA_COMPAT_5_1
			-DNF_DYNAMIC_PLUGIN
			-fPIC
	)
endif()

message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message("CMAKE_C_FLAGS = ${CMAKE_C_FLAGS}")
message("CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")

message("CONTRCT_VERSION_FILE = ${CONTRCT_VERSION_FILE}")
message("CONTRCT_VERSION_FILE2 = ${CONTRCT_VERSION_FILE2}")

SET(INCLUDE_DIR "/usr/local/include"
		"${CMAKE_SOURCE_DIR}/thirdparty"
		"${CMAKE_SOURCE_DIR}/thirdparty/LuaBind/lua"
		"${CMAKE_SOURCE_DIR}/thirdparty/common/"
		"${CMAKE_SOURCE_DIR}/thirdparty/mysql/include"
		"${CMAKE_SOURCE_DIR}/thirdparty/mysql/linux"
		"${CMAKE_SOURCE_DIR}/thirdparty/"
		"${CMAKE_SOURCE_DIR}/thirdparty/Theron/Include"
		"${CMAKE_SOURCE_DIR}/thirdparty/libevent/include"
		"${CMAKE_SOURCE_DIR}/thirdparty/libevent/linux/include"
		"${CMAKE_SOURCE_DIR}/thirdparty/zookeeper/include"
		"${CMAKE_SOURCE_DIR}/thirdparty/common/hiredis/hiredis_linux"
		"${CMAKE_SOURCE_DIR}/src"
		"${CMAKE_SOURCE_DIR}/src/NFComm/NFKernelMessage"
		"${CMAKE_SOURCE_DIR}/src/NFComm/NFMessageDefine")


if (CMAKE_BUILD_TYPE STREQUAL "Release")
	SET(LIB_DIR "/usr/lib"
			"${CMAKE_SOURCE_DIR}/thirdparty/lib64_release"
			"${CMAKE_SOURCE_DIR}/Build/Lib/Release")

	SET(LIB_LINK_DEP resolv dl rt pthread libprotobuf.a libCommon.a libLuaBind.a libNFMessageDefine.a libNFCore.a libNFPluginModule.a)

	SET(LIB_LINK_NF libNFKernelPlugin.a  NFTestPlugin.a)

elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
	SET(LIB_DIR "/usr/lib"
			"${CMAKE_SOURCE_DIR}/thirdparty/lib64_debug"
			"${CMAKE_SOURCE_DIR}/Build/Lib/Debug")

	SET(LIB_LINK_DEP resolv dl rt pthread libprotobuf.a libCommon.a libLuaBind.a libNFMessageDefine.a libNFCore.a libNFPluginModule.a)

	SET(LIB_LINK_NF libNFKernelPlugin.a  NFTestPlugin.a)
elseif (CMAKE_BUILD_TYPE STREQUAL "DynamicRelease")
	SET(LIB_DIR "." "/usr/lib"
			"${CMAKE_SOURCE_DIR}/thirdparty/lib64_release"
			"${CMAKE_SOURCE_DIR}/Build/Lib/Release"
			"${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release"
			)

	SET(LIB_LINK_DEP resolv dl rt pthread)
elseif(CMAKE_BUILD_TYPE STREQUAL "DynamicDebug")
	SET(LIB_DIR "." "/usr/lib"
			"${CMAKE_SOURCE_DIR}/thirdparty/lib64_debug"
			"${CMAKE_SOURCE_DIR}/Build/Lib/Debug"
			"${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Debug"
			)

	SET(LIB_LINK_DEP resolv dl rt pthread)
endif()

include_directories( ${INCLUDE_DIR} )

link_directories( ${LIB_DIR} )

ADD_SUBDIRECTORY("thirdparty")
ADD_SUBDIRECTORY("src")
ADD_SUBDIRECTORY("src/NFPluginLoader")

