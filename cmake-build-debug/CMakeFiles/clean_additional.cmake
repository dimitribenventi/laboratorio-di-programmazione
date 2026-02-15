# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "ActivityRegister_autogen"
  "CMakeFiles/ActivityRegister_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ActivityRegister_autogen.dir/ParseCache.txt"
  "CMakeFiles/runAllTests_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/runAllTests_autogen.dir/ParseCache.txt"
  "lib/googletest/googlemock/CMakeFiles/gmock_autogen.dir/AutogenUsed.txt"
  "lib/googletest/googlemock/CMakeFiles/gmock_autogen.dir/ParseCache.txt"
  "lib/googletest/googlemock/CMakeFiles/gmock_main_autogen.dir/AutogenUsed.txt"
  "lib/googletest/googlemock/CMakeFiles/gmock_main_autogen.dir/ParseCache.txt"
  "lib/googletest/googlemock/gmock_autogen"
  "lib/googletest/googlemock/gmock_main_autogen"
  "lib/googletest/googletest/CMakeFiles/gtest_autogen.dir/AutogenUsed.txt"
  "lib/googletest/googletest/CMakeFiles/gtest_autogen.dir/ParseCache.txt"
  "lib/googletest/googletest/CMakeFiles/gtest_main_autogen.dir/AutogenUsed.txt"
  "lib/googletest/googletest/CMakeFiles/gtest_main_autogen.dir/ParseCache.txt"
  "lib/googletest/googletest/gtest_autogen"
  "lib/googletest/googletest/gtest_main_autogen"
  "runAllTests_autogen"
  )
endif()
