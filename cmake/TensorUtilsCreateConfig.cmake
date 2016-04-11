include(CMakePackageConfigHelpers)
configure_file(cmake/TensorUtilsConfig.cmake.in "${PROJECT_BINARY_DIR}/TensorUtilsConfig.cmake" @ONLY)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/TensorUtilsConfigVersion.cmake
                                 VERSION ${TensorUtils_VERSION}
                                 COMPATIBILITY SameMajorVersion )

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/TensorUtilsConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/TensorUtilsConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake )
