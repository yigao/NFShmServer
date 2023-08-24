CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(NFExcelProcess)

include_directories(
		minizip
		zlib
		MiniExcelReader)

AUX_SOURCE_DIRECTORY(. SRC)
AUX_SOURCE_DIRECTORY(../../NFComm/NFCore SRC)
AUX_SOURCE_DIRECTORY(../../NFComm/NFPluginModule SRC)
AUX_SOURCE_DIRECTORY(../../NFComm/NFKernelMessage SRC)
AUX_SOURCE_DIRECTORY(../../NFComm/NFShmCore SRC)
AUX_SOURCE_DIRECTORY(../../NFComm/NFPluginModule/NFJson2PB SRC)
AUX_SOURCE_DIRECTORY(../../NFComm/NFPluginModule/NFProto SRC)
AUX_SOURCE_DIRECTORY(../../../thirdparty/common/sigar/linux SRC)
AUX_SOURCE_DIRECTORY(../../../thirdparty/LuaBind/lpeg SRC)
AUX_SOURCE_DIRECTORY(../../../thirdparty/LuaBind/lua SRC)
AUX_SOURCE_DIRECTORY(../../../thirdparty/LuaBind/luacjson SRC)
AUX_SOURCE_DIRECTORY(../../../thirdparty/LuaBind/protoc-gen-lua SRC)
AUX_SOURCE_DIRECTORY(../../../thirdparty/LuaBind/lua_protobuf SRC)
AUX_SOURCE_DIRECTORY(../../../thirdparty/LuaBind/luafilesystem SRC)
AUX_SOURCE_DIRECTORY(../../../thirdparty/LuaBind/lua-fmt SRC)

AUX_SOURCE_DIRECTORY(../../../thirdparty/common/hiredis/hiredis_linux/hiredis SRC)
AUX_SOURCE_DIRECTORY(../../../thirdparty/common/hwinfo/source/linux SRC)
AUX_SOURCE_DIRECTORY(../../../thirdparty/common/lzf SRC)
AUX_SOURCE_DIRECTORY(./MiniExcelReader SRC)

file(GLOB NFFileProcess_minizip_C ./minizip/ioapi.c ./minizip/ioapi_mem.c ./minizip/unzip.c)
file(GLOB NFFileProcess_zlib_C ./zlib/*.c)

add_definitions(
		-DLUA_COMPAT_5_1
		-DLUA_USE_LINUX
)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC} ${NFFileProcess_minizip_C} ${NFFileProcess_zlib_C} )

if (CMAKE_BUILD_TYPE STREQUAL "Release")
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} resolv dl rt  pthread libprotobuf.a libxlnt.a)
	SET_TARGET_PROPERTIES(${PROJECT_NAME}
		PROPERTIES 
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Install/Bin/Release"
	)
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} resolv dl rt pthread libprotobuf.a libxlnt.a)
	SET_TARGET_PROPERTIES(${PROJECT_NAME}
		PROPERTIES 
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Install/Bin/Debug"
	)
elseif (CMAKE_BUILD_TYPE STREQUAL "DynamicRelease")
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} resolv dl rt pthread libprotobuf.a libxlnt.a)
	message("CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")

	SET_TARGET_PROPERTIES(${PROJECT_NAME}
		PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release"
	)

elseif(CMAKE_BUILD_TYPE STREQUAL "DynamicDebug")
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} resolv dl rt pthread libprotobuf.a libxlnt.a)
	#TARGET_LINK_LIBRARIES(${PROJECT_NAME} resolv dl rt pthread libprotobuf.a)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
	SET_TARGET_PROPERTIES(${PROJECT_NAME} 
		PROPERTIES 
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Debug"
	)
endif()




