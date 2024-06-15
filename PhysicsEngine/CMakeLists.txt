find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_library(engine "src/Engine/Window.cpp" "src/Engine/Logger.cpp" "src/Platform/WindowLinux.cpp")
target_link_libraries(engine PRIVATE OpenGL::OpenGL glad::glad glfw spdlog::spdlog)
target_include_directories(engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")