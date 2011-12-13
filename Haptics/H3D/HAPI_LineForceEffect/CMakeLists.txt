cmake_minimum_required(VERSION 2.6.0)
project(Spring)

#Optional libs to link against:
SET(optionalLibs)

#Required libs to link against:
SET(requiredLibs)



SET(H3D_ROOT)
IF(EXISTS $ENV{H3D_ROOT})
	FILE(TO_CMAKE_PATH $ENV{H3D_ROOT} H3D_ROOT)
ENDIF(EXISTS $ENV{H3D_ROOT})
SET(CMAKE_MODULE_PATH ${H3D_ROOT}/build/modules)


#-----------------------------
#H3D
FIND_PACKAGE(H3DAPI REQUIRED)
IF (H3DAPI_FOUND)
	INCLUDE_DIRECTORIES( ${H3DAPI_INCLUDE_DIR})
	SET(requiredLibs ${requiredLibs} ${H3DAPI_LIBRARIES})
ENDIF(H3DAPI_FOUND)


#H3DUTIL
FIND_PACKAGE(H3DUTIL REQUIRED)
IF(H3DUTIL_FOUND)
	INCLUDE_DIRECTORIES( ${H3DUTIL_INCLUDE_DIR})
	SET(requiredLibs ${requiredLibs} ${H3DUTIL_LIBRARIES})
ENDIF(H3DUTIL_FOUND)

#HAPI
FIND_PACKAGE(HAPI REQUIRED)
IF(HAPI_FOUND)
	INCLUDE_DIRECTORIES( ${HAPI_INCLUDE_DIR})
	SET(requiredLibs ${requiredLibs} ${HAPI_LIBRARIES})
ENDIF(HAPI_FOUND)

#-------------------------------

#BUILD FILES
#ADD_EXECUTABLE(Spring_Exe ${Spring_SOURCE_DIR}/build/Spring_exe.cpp)

#shared library
ADD_EXECUTABLE(Spring ${Spring_SOURCE_DIR}/../Spring.cpp)
#ADD_LIBRARY(Spring SHARED ${Spring_SOURCE_DIR}/../Spring.cpp)

#------

#TARGET_LINK_LIBRARIES(Spring_Exe ${requiredLibs} ${optionalLibs})
TARGET_LINK_LIBRARIES(Spring ${requiredLibs} ${optionalLibs})


#SET_TARGET_PROPERTIES( Spring_Exe PROPERTIES DEBUG_POSTFIX "_d" )
SET_TARGET_PROPERTIES( Spring PROPERTIES DEBUG_POSTFIX "_d" )



IF( WIN32 AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT )
  # This command will only be run once for each new cache.
  SET( CMAKE_INSTALL_PREFIX ${Spring_SOURCE_DIR}/.. CACHE PATH
       "Install path prefix, prepended onto install directories." FORCE )
ENDIF( WIN32 AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT )

# Install to these directories.
INSTALL( TARGETS Spring #Spring_Exe
         LIBRARY DESTINATION lib
         RUNTIME DESTINATION bin
         ARCHIVE DESTINATION lib )
