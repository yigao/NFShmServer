CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(SERVER_INCLUDE_DIR
        "${CMAKE_SOURCE_DIR}/game/oldMMO/NFLogicComm"
        "${CMAKE_SOURCE_DIR}/game/oldMMO/NFLogicComm/NFServerLogicMessage"
        "${CMAKE_SOURCE_DIR}/game/oldMMO/NFServerLogic"
        "${CMAKE_SOURCE_DIR}/src/NFServerComm/NFServerMessage")

include_directories( ${INCLUDE_DIR} ${SERVER_INCLUDE_DIR})

#ADD_SUBDIRECTORY("MMO")
ADD_SUBDIRECTORY("oldMMO")


