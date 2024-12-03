# Each subdirectory contains a separate module of maurilib
file(GLOB V_GLOB LIST_DIRECTORIES true "*")
FOREACH (dir ${V_GLOB})
    IF (IS_DIRECTORY ${dir})
        get_filename_component(module ${dir} NAME_WLE)
        message(${module})
        file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${module}/*.cpp")
        list(FILTER sources EXCLUDE REGEX ".*\\.test\\.cpp$")
        file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${module}/*.hpp")
        file(GLOB_RECURSE tests CONFIGURE_DEPENDS "${module}/*.test.cpp")

        add_library(${module} ${sources} ${headers})
        target_include_directories(${module}
            PUBLIC
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
                $<INSTALL_INTERFACE:include>
        )
        add_library(mauri::${module} ALIAS ${module})

        # TODO: Add tests

        # Install the library
        install(TARGETS ${module} EXPORT maurilibTargets
            ARCHIVE DESTINATION lib
            LIBRARY DESTINATION lib
            RUNTIME DESTINATION bin
            INCLUDES DESTINATION include
        )

        # Install headers
        install(FILES ${headers} DESTINATION include/mauri/${module})
    ENDIF ()
ENDFOREACH()

# Export the targets for use by other projects
install(EXPORT maurilibTargets
    NAMESPACE mauri::
    DESTINATION lib/cmake/maurilib
)

# Create a package configuration file for find_package support
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/maurilibConfigVersion.cmake"
    COMPATIBILITY AnyNewerVersion
)

configure_file(
    "${CMAKE_SOURCE_DIR}/cmake/maurilibConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/maurilibConfig.cmake"
    @ONLY
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/maurilibConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/maurilibConfigVersion.cmake"
    DESTINATION lib/cmake/maurilib
)
