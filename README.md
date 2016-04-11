# TensorUtils

Please add some lines describing the project!

## Building the project

Set the environment to a ROOT installation, created with CMake and then:

    mkdir build
    cd build
    cmake -DCMAKE_INSTALL_PREFIX=<installdir>  <path to sources>
    make -j<number of cores on your machine>
    make install


Pleae note that this project depends on an existing installation of gtest. It may be necessary to include its location into _CMAKE_PREFIX_PATH_. For further details please have a look at http://www.cmake.org/cmake-tutorial/ .

## Building the documentation

The documentation of the project is based on doxygen. Invoking

    make doc
    make install

installs the documentation into installdir/doxygen.

## Creating a package with CPack

A cpack based package can be created by invoking

    make package

## Running the tests

To run the tests of the project, first build it and then invoke

    make test

## Inclusion into other projects

If you want to build your own project against TensorUtils, CMake may be the best option for you. Just add its location to _CMAKE_PREFIX_PATH_ and call _find_package(TensorUtils)_ within your CMakeLists.txt.
