CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(NFPluginLoader)

AUX_SOURCE_DIRECTORY(. SRC)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src/NFComm/NFCore SRC)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src/NFComm/NFPluginModule SRC)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src/NFComm/NFKernelMessage SRC)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src/NFComm/NFShmCore SRC)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src/NFComm/NFPluginModule/NFJson2PB SRC)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src/NFComm/NFPluginModule/NFProto SRC)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/LuaBind/lpeg SRC)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/LuaBind/lua SRC)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/LuaBind/luacjson SRC)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/LuaBind/protoc-gen-lua SRC)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/LuaBind/lua_protobuf SRC)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/LuaBind/luafilesystem SRC)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/LuaBind/lua-fmt SRC)

if(WIN32)
	AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/common/sigar/win32 SRC)
	AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/common/hiredis/hiredis_win/hiredis SRC)
	AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/common/hwinfo/source/win SRC)
else(UNIX)
	AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/common/sigar/linux SRC)
	AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/common/hiredis/hiredis_linux/hiredis SRC)
	AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/common/hwinfo/source/linux SRC)
endif()

AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/thirdparty/common/lzf SRC)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC})

if (CMAKE_BUILD_TYPE STREQUAL "Release")
if(UNIX)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} resolv dl rt  pthread libprotobuf.a)
else(WIN32)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} msvcrt.lib ws2_32.lib version.lib netapi32.lib Dbghelp.lib)
endif()
	SET_TARGET_PROPERTIES(${PROJECT_NAME}
		PROPERTIES 
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Install/Bin/Release"
	)
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
if(UNIX)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} resolv dl rt pthread libprotobuf.a)
else(WIN32)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} msvcrtd.lib ws2_32.lib version.lib netapi32.lib Dbghelp.lib)
endif()
	SET_TARGET_PROPERTIES(${PROJECT_NAME}
		PROPERTIES 
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Install/Bin/Debug"
	)
elseif (CMAKE_BUILD_TYPE STREQUAL "DynamicRelease")
if(UNIX)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} resolv dl rt pthread libprotobuf.a)
else(WIN32)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} msvcrtd.lib ws2_32.lib version.lib netapi32.lib Dbghelp.lib)
endif()
	message("CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")

	SET_TARGET_PROPERTIES(${PROJECT_NAME}
		PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release"
	)

	ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND mv ${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tools/${PROJECT_NAME}
	)

elseif(CMAKE_BUILD_TYPE STREQUAL "DynamicDebug")
if(UNIX)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} resolv dl rt pthread libprotobuf.a)
else(WIN32)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} msvcrtd.lib ws2_32.lib version.lib netapi32.lib Dbghelp.lib)
endif()
	#TARGET_LINK_LIBRARIES(${PROJECT_NAME} resolv dl rt pthread libprotobuf.a)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
	SET_TARGET_PROPERTIES(${PROJECT_NAME} 
		PROPERTIES 
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Debug"
	)
endif()




