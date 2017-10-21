if (NOT FIPS_IMPORT)
    cmake_minimum_required(VERSION 2.8)
    get_filename_component(FIPS_ROOT_DIR "../fips" ABSOLUTE)
    include("${FIPS_ROOT_DIR}/cmake/fips.cmake")
    fips_setup()
    fips_project(fips-shader-things)
endif()

fips_begin_module(shader-things)
    include_directories(.)
    fips_files(
        lex.yy.cpp glsl.tab.h glsl.tab.cpp
        AstNode.hpp AstNode.cpp AstNodeF.cpp
        shader.hpp shader.cpp
        sdf-shader.hpp sdf-shader.cpp
    )
fips_end_module()

if (NOT FIPS_IMPORT)
    fips_finish()
endif()


# LDFLAGS:  -L/usr/local/opt/flex/lib
# CPPFLAGS: -I/usr/local/opt/flex/include
# LDFLAGS:  -L/usr/local/opt/bison/lib
