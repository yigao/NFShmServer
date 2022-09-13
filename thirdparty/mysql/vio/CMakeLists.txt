# Copyright (c) 2006, 2014, Oracle and/or its affiliates. All rights reserved.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; version 2 of the License.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include
${SSL_INCLUDE_DIRS})
ADD_DEFINITIONS(${SSL_DEFINES})

SET(VIO_SOURCES
  vio.c
  viosocket.c
  viossl.c
  viosslfactories.c
)

IF(WIN32)
  LIST(APPEND VIO_SOURCES
    viopipe.c
    vioshm.c
  )
ENDIF()

ADD_CONVENIENCE_LIBRARY(vio ${VIO_SOURCES})
TARGET_LINK_LIBRARIES(vio ${LIBSOCKET})


if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_C_COMPILER_ID MATCHES "Clang")
  my_check_c_compiler_flag("-Wno-unused-but-set-variable" UNUSED_BUT_SET)
  if (UNUSED_BUT_SET)
    target_compile_options(vio PRIVATE
       -Wno-unused-but-set-variable   # viosocket.c:748
    )
  endif()
endif()
