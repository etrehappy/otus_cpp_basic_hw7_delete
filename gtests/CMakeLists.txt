cmake_minimum_required(VERSION 3.26)

project(prj_test_list)

include(FetchContent)
FetchContent_Declare(
  googletest
  # URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  URL "C:/Libraries/GoogleTest/googletest-03597a01ee50ed33e9dfd640b249b4be3799d395.zip"
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SOURCE_DIR 
	 "${CMAKE_SOURCE_DIR}/../source"
)

add_executable(test_list 
	tests_list.cpp
	${SOURCE_DIR}/u_list.cpp
	${SOURCE_DIR}/u_list.h
)

target_include_directories(test_list PUBLIC ${SOURCE_DIR})
target_link_libraries(test_list PUBLIC gtest gtest_main)

set_target_properties(test_list PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)