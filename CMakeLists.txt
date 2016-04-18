cmake_minimum_required(VERSION 2.8)

project(TensorUtils)
set( TensorUtils_VERSION_MAJOR 0 )
set( TensorUtils_VERSION_MINOR 1 )
set( TensorUtils_VERSION_PATCH 0 )
set( TensorUtils_VERSION "${TensorUtils_VERSION_MAJOR}.${TensorUtils_VERSION_MINOR}" )

set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#--- Declare options -----------------------------------------------------------
option(TensorUtils_documentation "Whether or not to create doxygen doc target.")

#--- Declare ROOT dependency ---------------------------------------------------
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(ROOT REQUIRED COMPONENTS MathCore )
include_directories(${ROOT_INCLUDE_DIRS})
MESSAGE(${ROOT_INCLUDE_DIRS})

#--- enable unit testing capabilities ------------------------------------------
include(CTest)

#--- enable CPack --------------------------------------------------------------
include(cmake/TensorUtilsCPack.cmake)

#--- target for Doxygen documentation ------------------------------------------
if(TensorUtils_documentation)
  include(cmake/TensorUtilsDoxygen.cmake)
endif()

#--- add version files ---------------------------------------------------------
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/TensorUtilsVersion.h
               ${CMAKE_CURRENT_BINARY_DIR}/TensorUtilsVersion.h )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/TensorUtilsVersion.h
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/TensorUtils )

#--- add CMake infrastructure --------------------------------------------------
include(cmake/TensorUtilsCreateConfig.cmake)

#--- add license files ---------------------------------------------------------
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE
              ${CMAKE_CURRENT_SOURCE_DIR}/NOTICE
        DESTINATION ${CMAKE_INSTALL_PREFIX})

#--- add actual library --------------------------------------------------------
## add include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

## select all source files
file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx)

## create a library target
add_library(tensorutils SHARED ${sources})

## install the example library into lib/
install(TARGETS tensorutils DESTINATION lib)

## install the headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/TensorUtils DESTINATION include)

## handling of test executables
add_subdirectory(tests)

## add the executables
add_subdirectory(exec)
