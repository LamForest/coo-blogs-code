cmake_minimum_required(VERSION 3.23)
project(main)
set(CMAKE_CXX_STANDARD 14)
add_definitions(-O3)
add_definitions(-fno-exceptions)
add_definitions(-fno-rtti)
add_definitions(-Wall)
# add_definitions()
# set (CMAKE_CXX_FLAGS "-O3" )

include_directories(${PROJECT_SOURCE_DIR}/thirdparty/google_benchmark/include)


link_directories(${PROJECT_SOURCE_DIR}/thirdparty/google_benchmark/build/src)


link_libraries(benchmark pthread)

# add_subdirectory(benchmark_example)

# add_subdirectory(shared_ptr)

# add_subdirectory(tutorial)

# add_subdirectory(cpp-con)

add_subdirectory(hashmap)