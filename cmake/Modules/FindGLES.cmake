#
# Try to find GLES SDK library and include path.
# Once done this will define
#
# GLES_FOUND
# GLES_INCLUDE_PATH
# GLES_LIBRARY

IF (WIN32)
    FIND_PATH(GLES_INCLUDE_PATH pvr_openlib.h
            ${GLES_ROOT_DIR}/include
            /usr/include
            /usr/local/include
            /sw/include
            /opt/local/include
            DOC "The directory where pvr_openlib.h resides")
    # Prefer the static library.
    FIND_LIBRARY(EGL_LIBRARY
            NAMES libEGL.lib
            PATHS
            ${GLES_ROOT_DIR}/lib
            /usr/lib64
            /usr/lib
            /usr/local/lib64
            /usr/local/lib
            /sw/lib
            /opt/local/lib
            DOC "The EGL static library")
    FIND_LIBRARY(GLES_CM_LIBRARY
            NAMES libGLES_CM.lib libGLESv2.lib
            PATHS
            ${GLES_ROOT_DIR}/lib
            /usr/lib64
            /usr/lib
            /usr/local/lib64
            /usr/local/lib
            /sw/lib
            /opt/local/lib
            DOC "The libGLES_CM static library")
    FIND_LIBRARY(GLES_LIBRARY
            NAMES libGLESv2.lib
            PATHS
            ${GLES_ROOT_DIR}/lib
            /usr/lib64
            /usr/lib
            /usr/local/lib64
            /usr/local/lib
            /sw/lib
            /opt/local/lib
            DOC "The GLES static library")
ELSE (WIN32)
    FIND_PATH(GLES_INCLUDE_PATH pvr_openlib.h
            ${GLES_ROOT_DIR}/include
            $ENV{PROGRAMFILES}/GLES/include
            DOC "The directory where pvr_openlib.h resides")
    FIND_LIBRARY(EGL_LIBRARY
            NAMES libEGL
            PATHS
            ${GLES_ROOT_DIR}/bin
            DOC "The EGL library")
    FIND_LIBRARY(GLES_CM_LIBRARY
            NAMES libGLES_CM
            PATHS
            ${GLES_ROOT_DIR}/bin
            DOC "The libGLES_CM library")
    FIND_LIBRARY(GLES_LIBRARY
            NAMES libGLESv2
            PATHS
            ${GLES_ROOT_DIR}/bin
            DOC "The GLES library")
ENDIF (WIN32)

SET(GLES_FOUND "NO")
IF (GLES_INCLUDE_PATH AND GLES_LIBRARY AND GLES_CM_LIBRARY AND EGL_LIBRARY)
    SET(GLES_LIBRARIES ${GLES_LIBRARY} ${GLES_CM_LIBRARY} ${EGL_LIBRARY})
    SET(GLES_FOUND "YES")
    message(STATUS "GLES LIBRARIES FOUND")
ENDIF (GLES_INCLUDE_PATH AND GLES_LIBRARY AND GLES_CM_LIBRARY AND EGL_LIBRARY)
# message(STATUS "GLES LIBRARIES is ${GLES_LIBRARIES}")
INCLUDE(${CMAKE_ROOT}/Modules/FindPackageHandleStandardArgs.cmake)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLES DEFAULT_MSG GLES_LIBRARIES)
