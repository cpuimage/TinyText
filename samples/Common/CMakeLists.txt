set(common_src source/es_util.cpp)
set(common_platform_src source/es_util_win32.cpp)
add_library(Common STATIC ${common_src} ${common_platform_src})
target_link_libraries(Common ${GLES_LIBRARIES})