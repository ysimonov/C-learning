cmake_minimum_required(VERSION 3.13)  # CMake version check
project(numeric_data)               # Create project "numeric_data"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
# add_executable(main main.cpp)
add_executable(main ${SOURCE_FILES})

target_link_libraries(main
  PUBLIC
    xtensor-io
#   PROPERTIES
#   INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib;${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}"
#   BUILD_WITH_INSTALL_RPATH ON
)

add_definitions(-DHAVE_CBLAS=1)

if (WIN32)
    find_package(OpenBLAS REQUIRED)
    set(BLAS_LIBRARIES ${CMAKE_INSTALL_PREFIX}${OpenBLAS_LIBRARIES})
else()
    find_package(BLAS REQUIRED)
    find_package(LAPACK REQUIRED)
endif()


message(STATUS "BLAS VENDOR:    " ${BLA_VENDOR})
message(STATUS "BLAS LIBRARIES: " ${BLAS_LIBRARIES})
target_link_libraries(main ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})
