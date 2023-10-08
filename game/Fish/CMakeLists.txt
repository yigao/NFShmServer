CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(SERVER_INCLUDE_DIR
        "${CMAKE_SOURCE_DIR}/game/Fish/NFLogicComm"
        "${CMAKE_SOURCE_DIR}/game/Fish/NFLogicComm/NFServerLogicMessage"
        "${CMAKE_SOURCE_DIR}/game/Fish/NFServerLogic"
        "${CMAKE_SOURCE_DIR}/src/NFServerComm/NFServerMessage")

include_directories( ${INCLUDE_DIR} ${SERVER_INCLUDE_DIR})

ADD_SUBDIRECTORY("NFLogicComm")
ADD_SUBDIRECTORY("NFServerLogic")
ADD_SUBDIRECTORY("NFFishRobot")
if(WIN32)
    ADD_SUBDIRECTORY("NFFishLoader")
endif()



