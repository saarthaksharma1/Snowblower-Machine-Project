# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/machinedemolib-src"
  "/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/machinedemolib-build"
  "/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix"
  "/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/tmp"
  "/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp"
  "/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src"
  "/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/saarthaksharma/CSE 335/sharm157-19/cmake-build-debug/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
