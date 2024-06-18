find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_library(io "src/IO/Procedures/PlainText.cpp")
target_include_directories(io PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(engine "src/Engine/Window.cpp" "src/Engine/Logger.cpp" "src/Platform/WindowLinux.cpp" "src/Renderer/Program.cpp" "src/Renderer/Shader.cpp" "src/Renderer/ElementBuffer.cpp" "src/Renderer/VertexArray.cpp" "src/Renderer/VertexBuffer.cpp")
target_link_libraries(engine PUBLIC OpenGL::OpenGL glad::glad glfw spdlog::spdlog)
target_include_directories(engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")