cmake_minimum_required(VERSION 3.12)

add_executable(Atividade3 "Atividade3.cpp" "Atividade3.h"  "FlyCamera.h" "Shaders.h"  "Geometrias.h" "Uteis.h")



target_include_directories(Atividade3 PRIVATE	dependencias/glm
													dependencias/stb
													dependencias/glfw/include
													dependencias/glew/include)


target_link_directories(Atividade3 PRIVATE dependencias/glfw/lib-vc2022
												dependencias/glew/lib/Release/x64)

target_link_libraries(Atividade3 PRIVATE	glfw3.lib
												glew32.lib
												opengl32.lib)

add_custom_command(TARGET Atividade3 POST_BUILD
				   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/Atividade3/dependencias/glew/bin/Release/x64/glew32.dll" "${CMAKE_BINARY_DIR}/Atividade3"
				   COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_SOURCE_DIR}/Atividade3/shaders" "${CMAKE_BINARY_DIR}/Atividade3/shaders"
				   COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_SOURCE_DIR}/Atividade3/textures" "${CMAKE_BINARY_DIR}/Atividade3/textures"
)


