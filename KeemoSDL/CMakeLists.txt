# add the executable
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

set(IMGUI_FILES


        "imgui/imconfig.h"

        "imgui/imgui.h"
        "imgui/imgui.cpp"

        "imgui/imgui_draw.cpp"
        "imgui/imgui_demo.cpp"

        "imgui/imgui_impl_opengl2.h"
        "imgui/imgui_impl_opengl2.cpp"

        "imgui/imgui_impl_sdl.h"
        "imgui/imgui_impl_sdl.cpp"

        "imgui/imgui_internal.h"

        "imgui/stb_rect_pack.h"

        "imgui/stb_textedit.h"

        "imgui/stb_truetype.h"
        )

add_executable(main main.cpp KeemoUi.cpp KeemoUi.hpp ${IMGUI_FILES})
add_dependencies(main KeemoLib)
target_include_directories(main PRIVATE ${SDL2_INCLUDE_DIRS})
target_include_directories(main PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(main PRIVATE KeemoLib ${SDL2_LIBRARIES})
target_link_libraries(main PRIVATE ${OPENGL_LIBRARIES})