cmake_minimum_required(VERSION 3.0)

project(opengl-template)
set(TARGET_NAME opengl-template)

add_executable(${TARGET_NAME}
    # ADD YOUR SOURCES FILE HERE
    src/main.c

    
    # DO NOT CHANGE THIS DEPENDENCIES
    deps/glad/glad.c
    deps/GLFW/glfw3.h
    deps/GLFW/glfw3native.h
    deps/GLFW/internal.h
    deps/GLFW/platform.h
    deps/GLFW/mappings.h
    deps/GLFW/context.c
    deps/GLFW/init.c
    deps/GLFW/input.c
    deps/GLFW/monitor.c
    deps/GLFW/platform.c
    deps/GLFW/vulkan.c
    deps/GLFW/window.c
    deps/GLFW/egl_context.c
    deps/GLFW/osmesa_context.c
    deps/GLFW/null_joystick.c
    deps/GLFW/null_init.c
    deps/GLFW/null_monitor.c
    deps/GLFW/null_window.c
    )


target_include_directories(${TARGET_NAME}
    PUBLIC 
    # ADD YOUR INCLUDE DIRECTORIES HERE
    
    # DO NOT CHANGE THIS
    src 
    deps
    )

if(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    target_sources(${TARGET_NAME} PRIVATE
        deps/GLFW/win32_init.c,
        deps/GLFW/win32_joystick.c
        deps/GLFW/win32_module.c
        deps/GLFW/win32_time.c
        deps/GLFW/win32_thread.c
        deps/GLFW/win32_window.c
        deps/GLFW/wgl_context.c
        )
    
    target_compile_definitions(${TARGET_NAME} _GLFW_WIN32 _CRT_SECURE_NO_WARNINGS)

elseif(${CMAKE_SYSTEM_NAME} MATCHES Linux)
    target_sources(${TARGET_NAME} PRIVATE
        deps/GLFW/posix_time.c
        deps/GLFW/posix_thread.c
        deps/GLFW/posix_module.c
        deps/GLFW/posix_poll.c
        deps/GLFW/glx_context.c
        deps/GLFW/osmesa_context.c
        deps/GLFW/linux_joystick.c
        )
    if($ENV{XDG_SESSION_TYPE} MATCHES x11)
        target_sources(${TARGET_NAME} PRIVATE
            deps/GLFW/x11_init.c
            deps/GLFW/x11_monitor.c
            deps/GLFW/x11_window.c
            deps/GLFW/xkb_unicode.c
            )
        target_compile_definitions(${TARGET_NAME} PUBLIC _GLFW_X11)
        target_link_libraries(${TARGET_NAME} "X11" "GL" "m")
    elseif($ENV{XDG_SESSION_TYPE} MATCHES wayland) 
        target_sources(${TARGET_NAME} PRIVATE
            deps/GLFW/wl_init.c
            deps/GLFW/wl_monitor.c
            deps/GLFW/wl_window.c
            )
        target_compile_definitions(${TARGET_NAME} PUBLIC _GLFW_WAYLAND)
        target_link_libraries(${TARGET_NAME} "GL" "m")
    endif()
else()
    message("Unsupported system")
endif()

