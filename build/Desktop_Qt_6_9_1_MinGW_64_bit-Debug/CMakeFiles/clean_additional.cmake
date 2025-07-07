# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ServicePrinterManager_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ServicePrinterManager_autogen.dir\\ParseCache.txt"
  "ServicePrinterManager_autogen"
  )
endif()
