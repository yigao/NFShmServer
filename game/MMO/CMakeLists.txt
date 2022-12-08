CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(SERVER_INCLUDE_DIR
        "${CMAKE_SOURCE_DIR}/game/MMO/NFLogicComm"
        "${CMAKE_SOURCE_DIR}/game/MMO/NFLogicComm/NFServerLogicMessage"
        "${CMAKE_SOURCE_DIR}/game/MMO/NFLogicComm/RecastNavigation"
        "${CMAKE_SOURCE_DIR}/game/MMO/NFServerLogic"
        "${CMAKE_SOURCE_DIR}/src/NFServerComm/NFServerMessage")

include_directories( ${INCLUDE_DIR} ${SERVER_INCLUDE_DIR})

ADD_SUBDIRECTORY("NFLogicComm")
ADD_SUBDIRECTORY("NFServerLogic")



