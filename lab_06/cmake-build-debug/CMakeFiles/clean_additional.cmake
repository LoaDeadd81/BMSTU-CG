# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\lab_06_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\lab_06_autogen.dir\\ParseCache.txt"
  "lab_06_autogen"
  )
endif()
