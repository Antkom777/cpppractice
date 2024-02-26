cmake_minimum_required(VERSION 3.12)
project(ImageCache VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cpp
    )
set(HEADERS
    image_cache.hpp
    images.hpp
    )       
add_executable(ImageCache ${SOURCES} ${HEADERS})


