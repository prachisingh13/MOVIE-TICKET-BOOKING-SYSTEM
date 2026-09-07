cmake_minimum_required(VERSION 3.15)

project(MovieTicketBookingSystem
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(movie_booking ${SOURCES})

target_include_directories(movie_booking
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(movie_booking PRIVATE /W4)
else()
    target_compile_options(movie_booking PRIVATE -Wall -Wextra -pedantic)
endif()
