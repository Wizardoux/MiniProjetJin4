# CMake generated Testfile for 
# Source directory: D:/Work/TSP2A/C++/RuinsOfScience
# Build directory: D:/Work/TSP2A/C++/RuinsOfScience/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(that-test-I-made "D:/Work/TSP2A/C++/RuinsOfScience/build/Debug/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "D:/Work/TSP2A/C++/RuinsOfScience/CMakeLists.txt;100;add_test;D:/Work/TSP2A/C++/RuinsOfScience/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(that-test-I-made "D:/Work/TSP2A/C++/RuinsOfScience/build/Release/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "D:/Work/TSP2A/C++/RuinsOfScience/CMakeLists.txt;100;add_test;D:/Work/TSP2A/C++/RuinsOfScience/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(that-test-I-made "D:/Work/TSP2A/C++/RuinsOfScience/build/MinSizeRel/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "D:/Work/TSP2A/C++/RuinsOfScience/CMakeLists.txt;100;add_test;D:/Work/TSP2A/C++/RuinsOfScience/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(that-test-I-made "D:/Work/TSP2A/C++/RuinsOfScience/build/RelWithDebInfo/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "D:/Work/TSP2A/C++/RuinsOfScience/CMakeLists.txt;100;add_test;D:/Work/TSP2A/C++/RuinsOfScience/CMakeLists.txt;0;")
else()
  add_test(that-test-I-made NOT_AVAILABLE)
endif()
subdirs("_deps/sfml-build")
subdirs("_deps/pugixml-build")
subdirs("_deps/imgui-sfml-build")
subdirs("mainLauncher")
subdirs("src")
subdirs("googletest-build")
