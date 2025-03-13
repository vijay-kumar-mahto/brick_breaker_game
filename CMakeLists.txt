cmake_minimum_required(VERSION 3.30)
project(BrickBreaker)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(BrickBreaker
        main.cpp
        src/Core/Game.cpp
        src/Core/Paddle.cpp
        src/Core/Ball.cpp
        src/Core/Brick.cpp
        src/Core/PowerUp.cpp
        src/UI/Interface.cpp
        src/Utils/GameRecords.cpp
        include/Core/State.h
)

target_include_directories(BrickBreaker PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Core # Added for Core headers
        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI   # Added for UI headers
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Utils # Added for Utils headers
)

target_link_libraries(BrickBreaker PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Resources)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Resources/font.ttf DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Resources/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Resources/paddle_hit.wav DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Resources/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Resources/brick_break.wav DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Resources/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Resources/power_up.wav DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Resources/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Resources/life_lost.wav DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Resources/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Resources/menu_click.wav DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Resources/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Resources/heart.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Resources/)
