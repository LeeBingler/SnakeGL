cmake_minimum_required(VERSION 3.16)
project(test LANGUAGES C CXX)

# ── Standards ────────────────────────────────────────────────────────────────
set(CMAKE_C_STANDARD   11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ── compile_commands.json ─────────────────────────────────────────────────────
# Generates compile_commands.json in the build directory automatically.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ── Compiler flags (mirrors FLAGS = -g3 -g -Wall -Wextra) ────────────────────
add_compile_options(-g3 -g -Wall -Wextra)

# ── Sources ───────────────────────────────────────────────────────────────────
set(SRC_C
    src/Utils/glad.c
)

set(SRC_CPP
    src/main.cpp
    src/renderLoop.cpp
    src/Game.cpp
    src/font/TrueTypeFont.cpp
    src/Utils/Shader.cpp
    src/Utils/Texture2D.cpp
    src/Utils/OrthoCamera.cpp
    src/Utils/Window.cpp
    src/Utils/StateManager.cpp
    src/GUI/Map.cpp
    src/GUI/Snake.cpp
    src/GUI/Coin.cpp
    src/GUI/Timer.cpp
    src/GUI/States/GameState.cpp
    src/GUI/States/MenuState.cpp
    src/GUI/States/ExitState.cpp
    src/GUI/Button.cpp
    src/Core/Core.cpp
    src/Core/CoreSnake.cpp
)

# ── Executable ────────────────────────────────────────────────────────────────
add_executable(${PROJECT_NAME}
    ${SRC_C}
    ${SRC_CPP}
)

# ── GLFW3 (mirrors -L./lib/glfw3/src -lglfw3) ──────────────────────────────
# lib/glfw3/ is a pre-built CMake build tree (contains CMakeFiles/, not CMakeLists.txt).
# We import the already-compiled static library directly.
add_library(glfw3 STATIC IMPORTED)
set_target_properties(glfw3 PROPERTIES
    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/glfw3/src/libglfw3.a
)

# -- FreeType Lib --
# Disable FreeType's own dependencies don't needed
set(FT_DISABLE_ZLIB TRUE)
set(FT_DISABLE_BZIP2 TRUE)
set(FT_DISABLE_PNG TRUE)
set(FT_DISABLE_HARFBUZZ TRUE)
set(FT_DISABLE_BROTLI TRUE)

# Add FreeType as a subdirectory — CMake will build it automatically
add_subdirectory(lib/freetype)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
  glfw3
  freetype
)

# ── Include directory (mirrors INC = include/) ───────────────────────────────
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/lib/freetype/include
)

# symlink compile_commands.json to project root
# Many editors (clangd, VS Code) look for it next to CMakeLists.txt.
# Run once after cmake configure:
#   ln -sf build/compile_commands.json compile_commands.json
# Or add this custom target to do it automatically:
add_custom_target(symlink_compile_commands ALL
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
    COMMENT "Symlinking compile_commands.json to project root"
)

