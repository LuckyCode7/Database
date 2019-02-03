cmake_minimum_required(VERSION 3.2)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(database)

set(SRC_LIST
    inc/Adress.hpp
    inc/Database.hpp
    inc/Employee.hpp
    inc/Exceptions.hpp
    inc/RandomData.hpp
    inc/Person.hpp
    inc/Student.hpp
    inc/DataValidator.hpp
    inc/PeselValidator.hpp 
    inc/NameValidator.hpp
    inc/AdressValidator.hpp
    inc/GenderValidator.hpp
    src/Adress.cpp
    src/Database.cpp
    src/Employee.cpp
    src/Person.cpp
    src/Student.cpp
    src/DataValidator.cpp
    src/PeselValidator.cpp 
    src/NameValidator.cpp
    src/AdressValidator.cpp
    src/GenderValidator.cpp
    src/main.cpp
)

include_directories(src)
add_library(${PROJECT_NAME}-lib ${SRC_LIST})
add_executable(${PROJECT_NAME} src/main.cpp)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib pthread)
else (UNIX)
    target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
endif (UNIX)

set(TEST_SRC_LIST
    test/DataValidatorTest.cpp
    test/AdressTest.cpp
    test/AdressValidatorTest.cpp
    test/GenderValidatorTest.cpp
    test/NameValidatorTest.cpp
    test/PeselValidatorTest.cpp
    test/StudentTest.cpp
    test/EmployeeTest.cpp
    test/DatabaseTest.cpp
    test/test_main.cpp
)

link_libraries(gtest)
add_executable(${PROJECT_NAME}-ut ${TEST_SRC_LIST})
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)
