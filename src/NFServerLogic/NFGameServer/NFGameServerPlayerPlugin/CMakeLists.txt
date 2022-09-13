CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(NFGameServerPlugin)

include_directories("${CMAKE_SOURCE_DIR}/thirdparty")

AUX_SOURCE_DIRECTORY(. SRC)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
	SET(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/Build/Lib/Release")
	ADD_LIBRARY( ${PROJECT_NAME} STATIC ${SRC} )
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
	SET(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/Build/Lib/Debug")
	ADD_LIBRARY( ${PROJECT_NAME} STATIC ${SRC} )
elseif (CMAKE_BUILD_TYPE STREQUAL "DynamicRelease")
	SET(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release")
	ADD_LIBRARY( ${PROJECT_NAME} SHARED ${SRC} )
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} NFMessageDefine)

	ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD
			COMMAND mv ${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release/lib${PROJECT_NAME}.so ${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release/lib${PROJECT_NAME}.bak.so
			COMMAND  ${CMAKE_SOURCE_DIR}/tools/VMProtect/vmprotect_con ${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release/lib${PROJECT_NAME}.bak.so ${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release/lib${PROJECT_NAME}.upx.so
			COMMAND  ${CMAKE_SOURCE_DIR}/tools/NFAddSoShell --contract=${CMAKE_CONTRACE_INFO} --machineaddr=${CMAKE_MACHINE_ADDR} --srcfile=${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release/lib${PROJECT_NAME}.upx.so --dstfile=${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release/lib${PROJECT_NAME}.so
			COMMAND rm ${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release/lib${PROJECT_NAME}.bak.so ${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release/lib${PROJECT_NAME}.upx.so
			)
elseif(CMAKE_BUILD_TYPE STREQUAL "DynamicDebug")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
	SET(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Debug")
	link_directories("${CMAKE_SOURCE_DIR}/thirdparty/lib64_debug")
	ADD_LIBRARY( ${PROJECT_NAME} SHARED ${SRC} )
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} NFMessageDefine)
endif()


