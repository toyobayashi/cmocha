cmake_minimum_required(VERSION 3.6)

project(cmocha)

set(LIB_NAME cmocha)

include(cmake/lib.cmake)

execute_process(COMMAND node index.js
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  OUTPUT_VARIABLE DEPS_LIST_cmocha
)

if(DEPS_LIST_cmocha)
  string(REPLACE "\n" ";" DEPS_LIST_cmocha ${DEPS_LIST_cmocha})
  foreach(pkg ${DEPS_LIST_cmocha})
    message("add_subdirectory: ${pkg} ${pkg}")
    add_subdirectory(${pkg} ${pkg})
  endforeach()
endif()
