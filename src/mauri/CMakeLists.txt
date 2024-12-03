
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

        add_library(mauri_${module} ${sources} ${headers})
        target_include_directories(mauri_${module} PUBLIC ${CMAKE_SOURCE_DIR}/src)
        message(${CMAKE_CURRENT_SOURCE_DIR})
        add_library(mauri::${module} ALIAS mauri_${module})

        # TODO: Add tests
    ENDIF ()
ENDFOREACH()
