CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(ShmNFrame)

message("CMAKE_VERSION: ${CMAKE_VERSION} ")
message("CMAKE_HOST_SYSTEM_NAME: ${CMAKE_HOST_SYSTEM_NAME} ")
message("CMAKE_HOST_SYSTEM: ${CMAKE_HOST_SYSTEM} ")

message("CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME} ")
message("CMAKE_SYSTEM: ${CMAKE_SYSTEM} ")

message("CMAKE_HOST_UNIX: ${CMAKE_HOST_UNIX} ")
message("CMAKE_HOST_WIN32: ${CMAKE_HOST_WIN32} ")

#---------------------------------------------------------------------------------------
# Compiler config
#---------------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 11)

if(UNIX)
	if (${CMAKE_VERSION} VERSION_LESS "3.22.0")
		set(DISTRO_ID "centos")
		set(DISTRO_VERSION_ID 7)
		message("DISTRO_ID: ${DISTRO_ID} ")
		message("DISTRO_VERSION_ID: ${DISTRO_VERSION_ID} ")
	else ()
		cmake_host_system_information(RESULT PRETTY_NAME QUERY DISTRIB_PRETTY_NAME)
		message(STATUS "${PRETTY_NAME}")

		cmake_host_system_information(RESULT DISTRO QUERY DISTRIB_INFO)
		foreach (VAR IN LISTS DISTRO)
			message(STATUS "${VAR}=`${${VAR}}`")
		endforeach ()
	endif()
endif()

if(WIN32)
    add_compile_options(/wd4819)
    add_compile_options(/wd4091)
    add_compile_options(/wd4251)
    add_compile_options(/wd4996)
    add_compile_options(/wd4275)
    add_compile_options(/wd4316)
    add_compile_options(/wd4244)
    add_compile_options(/wd4267)
    add_compile_options(/wd4244)
    add_compile_options(/wd4099)
    add_compile_options(/wd4018)
    add_compile_options(/wd4834)
    add_compile_options(/wd4065)
    add_compile_options(/wd4311)
    add_compile_options(/wd4309)
    add_compile_options(/wd4013)
    add_compile_options(/wd4024)
    add_compile_options(/wd4477)
    add_compile_options(/wd4133)
    add_compile_options(/wd4047)
    add_compile_options(/wd4099)
    add_compile_options(/wd4217)
    add_compile_options(/wd4286)
    add_compile_options(/wd4291)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
endif()


if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_BUILD_TYPE "Release")
if(UNIX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fPIC -std=c++11 -g -O3 -Wall")
    add_definitions(
            -DNDEBUG
            -Wcomment
            -DNF_STATIC_PLUGIN
            -DEVPP_HTTP_CLIENT_SUPPORTS_SSL   #evpp http client ssl
            -DEVPP_HTTP_SERVER_SUPPORTS_SSL   #evpp http server ssl
            -DH_HAVE_CAMERON314_CONCURRENTQUEUE  #evpp need
            -DLUA_COMPAT_5_1
            -DLUA_USE_LINUX
            -fPIC
    )
else(WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWIN32_LEAN_AND_MEAN -D_WINSOCK_DEPRECATED_NO_WARNINGS -D_LIB -D_WIN32 -D_CONSOLE -DNF_NONCLIENT_BUILD -DUNICODE -D_UNICODE -D_WINDOWS -DWIN32 -D_DEBUG -DNF_STATIC_PLUGIN -DLUA_COMPAT_5_1 -D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_USRDLL -DDLL_EXPORTS -DMYSQLPP_MAKING_DLL -DHAVE_MYSQL_SSL_SET  -DBUILDING_LIBCURL -DCURL_STATICLIB ")	
endif()	
elseif (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_BUILD_TYPE "Debug")
if(UNIX)	
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -Wall -g -ggdb -fPIC")
    add_definitions(
            -D_DEBUG
            -Wcomment
            -DNF_STATIC_PLUGIN
            -DEVPP_HTTP_CLIENT_SUPPORTS_SSL   #evpp http client ssl
            -DEVPP_HTTP_SERVER_SUPPORTS_SSL   #evpp http server ssl
            -DH_HAVE_CAMERON314_CONCURRENTQUEUE  #evpp need
            -DLUA_COMPAT_5_1
            -DLUA_USE_LINUX
            -fPIC
    )
else(WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWIN32_LEAN_AND_MEAN -D_WINSOCK_DEPRECATED_NO_WARNINGS -D_LIB -D_WIN32 -D_CONSOLE -DNF_NONCLIENT_BUILD -DUNICODE -D_UNICODE -D_WINDOWS -DWIN32 -D_DEBUG -DNF_STATIC_PLUGIN -DLUA_COMPAT_5_1 -D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_USRDLL -DDLL_EXPORTS -DMYSQLPP_MAKING_DLL -DHAVE_MYSQL_SSL_SET  -DBUILDING_LIBCURL -DCURL_STATICLIB ")	
endif()	
elseif (CMAKE_BUILD_TYPE STREQUAL "DynamicDebug")
    set(CMAKE_BUILD_TYPE "DynamicDebug")
if(UNIX)	
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -Wall -g3 -ggdb -fPIC -Wextra -Wno-unused-parameter -Wno-conversion-null -Wno-unused-but-set-variable -Wno-int-to-pointer-cast -Wno-array-bounds")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -Wall -g3 -ggdb -fPIC")
    add_definitions(
            -D_DEBUG
            -DCHECK_MEM_LEAK
            -Wcomment
            -DLUA_COMPAT_5_1
            -DLUA_USE_LINUX
            -DNF_DYNAMIC_PLUGIN
            -DEVPP_HTTP_CLIENT_SUPPORTS_SSL   #evpp http client ssl
            -DEVPP_HTTP_SERVER_SUPPORTS_SSL   #evpp http server ssl
            -DH_HAVE_CAMERON314_CONCURRENTQUEUE  #evpp need
            -fPIC
            -Wno-error
    )
else(WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWIN32_LEAN_AND_MEAN -D_WINSOCK_DEPRECATED_NO_WARNINGS -D_LIB -D_WIN32 -D_CONSOLE -DNF_NONCLIENT_BUILD -DUNICODE -D_UNICODE -D_WINDOWS -DWIN32 -D_DEBUG -DNF_STATIC_PLUGIN -DLUA_COMPAT_5_1 -D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_USRDLL -DDLL_EXPORTS -DMYSQLPP_MAKING_DLL -DHAVE_MYSQL_SSL_SET  -DBUILDING_LIBCURL -DCURL_STATICLIB ")	
endif()	
elseif (CMAKE_BUILD_TYPE STREQUAL "DynamicRelease")
    set(CMAKE_BUILD_TYPE "DynamicRelease")
if(UNIX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fPIC -std=c++11 -O3 -g -Wall")
    #don't use -O3 用-O3来编译所有的软件包将产生更大体积更耗内存的二进制文件，
    #大大增加编译失败的机会或不可预知的程序行为（包括错误）。 这样做将得不偿失，记住过犹不及。 在gcc 4.x.中使用-O3是不推荐的
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -Wall -fPIC")

    add_definitions(
            -DNDEBUG
            -Wcomment
            -DLUA_COMPAT_5_1
            -DLUA_USE_LINUX
            -DNF_DYNAMIC_PLUGIN
            -DEVPP_HTTP_CLIENT_SUPPORTS_SSL   #evpp http client ssl
            -DEVPP_HTTP_SERVER_SUPPORTS_SSL   #evpp http server ssl
            -DH_HAVE_CAMERON314_CONCURRENTQUEUE  #evpp need
            -fPIC
            -Wno-error
    )
else(WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWIN32_LEAN_AND_MEAN -D_WINSOCK_DEPRECATED_NO_WARNINGS -D_LIB -D_WIN32 -D_CONSOLE -DNF_NONCLIENT_BUILD -DUNICODE -D_UNICODE -D_WINDOWS -DWIN32 -D_DEBUG -DNF_STATIC_PLUGIN -DLUA_COMPAT_5_1 -D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_USRDLL -DDLL_EXPORTS -DMYSQLPP_MAKING_DLL -DHAVE_MYSQL_SSL_SET  -DBUILDING_LIBCURL -DCURL_STATICLIB ")	
endif()	
endif()

message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message("CMAKE_C_FLAGS = ${CMAKE_C_FLAGS}")
message("CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")

message("CONTRCT_VERSION_FILE = ${CONTRCT_VERSION_FILE}")
message("CONTRCT_VERSION_FILE2 = ${CONTRCT_VERSION_FILE2}")

if(UNIX)
	SET(INCLUDE_DIR "/usr/local/include"
			"${CMAKE_SOURCE_DIR}/thirdparty"
			"${CMAKE_SOURCE_DIR}/thirdparty/LuaBind/lua"
			"${CMAKE_SOURCE_DIR}/thirdparty/common/"
			"${CMAKE_SOURCE_DIR}/thirdparty/mysql/include"
			"${CMAKE_SOURCE_DIR}/thirdparty/mysql/linux"
			"${CMAKE_SOURCE_DIR}/thirdparty/"
			"${CMAKE_SOURCE_DIR}/thirdparty/Theron/Include"
			"${CMAKE_SOURCE_DIR}/thirdparty/zdb"
			"${CMAKE_SOURCE_DIR}/thirdparty/libevent/include"
			"${CMAKE_SOURCE_DIR}/thirdparty/libevent/linux/include"
			"${CMAKE_SOURCE_DIR}/thirdparty/zookeeper/include"
			"${CMAKE_SOURCE_DIR}/thirdparty/common/hiredis/hiredis_linux"
			"${CMAKE_SOURCE_DIR}/src"
			"${CMAKE_SOURCE_DIR}/src/NFComm/NFKernelMessage"
			"${CMAKE_SOURCE_DIR}/src/NFComm/NFMessageDefine"
			"${CMAKE_SOURCE_DIR}/src/NFServerComm/NFServerMessage")
else(WIN32)
	SET(INCLUDE_DIR "/usr/local/include"
			"${CMAKE_SOURCE_DIR}/thirdparty"
			"${CMAKE_SOURCE_DIR}/thirdparty/LuaBind/lua"
			"${CMAKE_SOURCE_DIR}/thirdparty/common/"
			"${CMAKE_SOURCE_DIR}/thirdparty/mysql/include"
			"${CMAKE_SOURCE_DIR}/thirdparty/mysql/win"
			"${CMAKE_SOURCE_DIR}/thirdparty/"
			"${CMAKE_SOURCE_DIR}/thirdparty/Theron/Include"
			"${CMAKE_SOURCE_DIR}/thirdparty/zdb"
			"${CMAKE_SOURCE_DIR}/thirdparty/libevent/include"
			"${CMAKE_SOURCE_DIR}/thirdparty/libevent/win/include"
			"${CMAKE_SOURCE_DIR}/thirdparty/zookeeper/include"
			"${CMAKE_SOURCE_DIR}/thirdparty/common/hiredis/hiredis_win"
			"${CMAKE_SOURCE_DIR}/src"
			"${CMAKE_SOURCE_DIR}/src/NFComm/NFKernelMessage"
			"${CMAKE_SOURCE_DIR}/src/NFComm/NFMessageDefine"
			"${CMAKE_SOURCE_DIR}/src/NFServerComm/NFServerMessage")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
if(UNIX)
    SET(LIB_DIR "/usr/lib"
            "${CMAKE_SOURCE_DIR}/thirdparty/lib64_release"
            "${CMAKE_SOURCE_DIR}/Build/Lib/Release")

    SET(LIB_LINK_DEP resolv dl rt pthread libprotobuf.a libCommon.a libLuaBind.a libNFMessageDefine.a libNFCore.a libNFPluginModule.a)

    SET(LIB_LINK_NF libNFKernelPlugin.a NFTestPlugin.a)
else(WIN32)
	SET(LIB_DIR "${CMAKE_SOURCE_DIR}/thirdparty/lib64_release"
		"${CMAKE_SOURCE_DIR}/Build/Lib/Release")	
endif()		
elseif (CMAKE_BUILD_TYPE STREQUAL "Debug")
if(UNIX)
    SET(LIB_DIR "/usr/lib"
            "${CMAKE_SOURCE_DIR}/thirdparty/lib64_debug"
            "${CMAKE_SOURCE_DIR}/Build/Lib/Debug")

    SET(LIB_LINK_DEP resolv dl rt pthread libprotobuf.a libCommon.a libLuaBind.a libNFMessageDefine.a libNFCore.a libNFPluginModule.a)

    SET(LIB_LINK_NF libNFKernelPlugin.a NFTestPlugin.a)
else(WIN32)
	SET(LIB_DIR "${CMAKE_SOURCE_DIR}/thirdparty/lib64_debug"
		"${CMAKE_SOURCE_DIR}/Build/Lib/Debug")	
endif()		
elseif (CMAKE_BUILD_TYPE STREQUAL "DynamicRelease")
if(UNIX)
    message("DISTRO_ID: ${DISTRO_ID} ")
    message("DISTRO_VERSION_ID: ${DISTRO_VERSION_ID} ")

    if (DISTRO_ID STREQUAL "centos")
        message("DISTRO_ID: ${DISTRO_ID} ")
        message("DISTRO_VERSION_ID: ${DISTRO_VERSION_ID} ")
        SET(LIB_DIR "./" "/usr/lib"
                "${CMAKE_SOURCE_DIR}/thirdparty/lib64_release"
                "${CMAKE_SOURCE_DIR}/Build/Lib/Release"
                "${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release"
                )
    elseif (DISTRO_ID STREQUAL "ubuntu")
        SET(LIB_DIR "./" "/usr/lib"
                "${CMAKE_SOURCE_DIR}/thirdparty/lib64_release/ubuntu"
                "${CMAKE_SOURCE_DIR}/Build/Lib/Release"
                "${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Release"
                )
    endif ()


    SET(LIB_LINK_DEP resolv dl rt pthread)
endif()		
elseif (CMAKE_BUILD_TYPE STREQUAL "DynamicDebug")
if(UNIX)
    message("DISTRO_ID: ${DISTRO_ID} ")
    message("DISTRO_VERSION_ID: ${DISTRO_VERSION_ID} ")

    if (DISTRO_ID STREQUAL "centos")
        SET(LIB_DIR "." "/usr/lib"
                "${CMAKE_SOURCE_DIR}/thirdparty/lib64_debug"
                "${CMAKE_SOURCE_DIR}/Build/Lib/Debug"
                "${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Debug"
                )
    elseif (DISTRO_ID STREQUAL "ubuntu")
        SET(LIB_DIR "." "/usr/lib"
                "${CMAKE_SOURCE_DIR}/thirdparty/lib64_debug/ubuntu"
                "${CMAKE_SOURCE_DIR}/Build/Lib/Debug"
                "${CMAKE_SOURCE_DIR}/Install/Bin/Dynamic_Debug"
                )
    endif ()


    SET(LIB_LINK_DEP resolv dl rt pthread)
endif()	
endif()

include_directories(${INCLUDE_DIR})

link_directories(${LIB_DIR})

ADD_SUBDIRECTORY("thirdparty")
ADD_SUBDIRECTORY("src")
ADD_SUBDIRECTORY("game")
ADD_SUBDIRECTORY("src/NFPluginLoader")
ADD_SUBDIRECTORY("src/NFTools")

