# Install script for directory: /Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/box2d-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/box2d-src/include/box2d")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/box2d-build/src/cmake_install.cmake")
  include("/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/box2d-build/unit-test/cmake_install.cmake")
  include("/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/box2d-build/extern/glad/cmake_install.cmake")
  include("/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/box2d-build/extern/glfw/cmake_install.cmake")
  include("/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/box2d-build/extern/imgui/cmake_install.cmake")
  include("/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/box2d-build/extern/sajson/cmake_install.cmake")
  include("/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/box2d-build/testbed/cmake_install.cmake")

endif()

