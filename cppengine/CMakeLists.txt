cmake_minimum_required(VERSION 2.6)
project(CPPENGINE)

include_directories(
	${CPPENGINE_SOURCE_DIR} 
	${CPPENGINE_SOURCE_DIR}/../glew/include 
	${CPPENGINE_SOURCE_DIR}/../freeglut/include
)
link_directories(${CPPENGINE_BINARY_DIR})

set(cppengine_sources
	application.cpp 
	color.cpp 
	draw.cpp 
	exception.cpp 
	function.cpp 
	game.cpp 
	gcArray.cpp 
	gcObject.cpp 
	gcString.cpp 
	geometryShader.cpp 
	globals.cpp 
	graph.cpp 
	graphicsEffect.cpp 
	layer.cpp 
	light.cpp 
	lightSettings.cpp 
	lightVolume.cpp 
	map.cpp 
	objectRepresentation.cpp 
	path.cpp 
	physicsSettings.cpp 
	physicsSimulator.cpp 
	pixelShader.cpp 
	point.cpp 
	rectangle.cpp 
	scene.cpp 
	sceneGraph.cpp 
	timer.cpp 
	transition.cpp 
	variant.cpp 
	vertexShader.cpp 
	window.cpp
)

set(cbstring_sources
	gcstring/bstraux.c
	gcstring/bstrlib.c
	gcstring/bstrwrap.cpp
)

set(gs2cpp_sources
)

set(defines
	-DFREEGLUT_STATIC
	-DGLEW_STATIC
)

set(libs
	${CPPENGINE_SOURCE_DIR}/../freeglut/lib/libfreeglut32_static.a
	${CPPENGINE_SOURCE_DIR}/../glew/lib/libglew32.a
)
if(WIN32)
	set(w32libs opengl32 winmm)
endif()

set(CMAKE_CXX_FLAGS "-static-libgcc -static-libstdc++")

add_definitions(${defines})
add_executable(cppengine-cmake game.cpp ${cppengine_sources} ${gs2cpp_sources} ${cbstring_sources})
target_link_libraries(cppengine-cmake ${libs} ${w32libs})
