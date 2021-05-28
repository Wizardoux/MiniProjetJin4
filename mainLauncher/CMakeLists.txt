
add_executable(mainLauncher mainLauncher.cpp)

target_link_libraries(mainLauncher PUBLIC src pugixml sfml-graphics)

add_custom_target(copy-resources ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/Thirteen-Pixel-Fonts.ttf)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Thirteen-Pixel-Fonts.ttf
                   DEPENDS ${CMAKE_SOURCE_DIR}/resources/Thirteen-Pixel-Fonts.ttf
                   COMMAND ${CMAKE_COMMAND} -E copy
                           ${CMAKE_SOURCE_DIR}/resources/Thirteen-Pixel-Fonts.ttf
                           ${CMAKE_CURRENT_BINARY_DIR})
add_dependencies(mainLauncher copy-resources)