cmake_minimum_required (VERSION 3.1)
include(include.cmake)
project(nvim-ui)

# flex bison
add_sources(lex.yy.cpp glsl.tab.h glsl.tab.cpp)
include_directories(flex_bison)
#add_library(parser STATIC "${SOURCES}")


# sokol
include_directories(sokol)
set_dir("sokol")
add_sources(sokol_gfx.h _sokol_gfx_gl.impl.h)

# imgui
include_directories(imgui)
set_dir("imgui")
add_sources(imgui.h imgui.cpp imgui_draw.cpp imgui_internal.h)

# glfw
add_subdirectory(glfw)
include_directories(glfw/include)

set_dir("")
add_sources(nvim-ui.cpp shader.hpp shader.cpp)
add_sources(AstNode.hpp AstNode.cpp AstNodeF.cpp)
add_sources(sdf-shader.hpp sdf-shader.cpp)
add_executable(NvimUI "${SOURCES}")
target_link_libraries(
	NvimUI glfw ${GLFW_LIBRARIES}
	)
	#"${PROJECT_SOURCE_DIR}/flex_bison/glsl_parser.lib"

add_custom_command(
	TARGET NvimUI PRE_BUILD
	COMMAND make
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/flex_bison
)