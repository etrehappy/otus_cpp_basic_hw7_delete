cmake_minimum_required(VERSION 3.26)

project(prj_test_containers)

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

add_executable(test_containers
	tests.cpp
	${SOURCE_DIR}/u_list.cpp
	${SOURCE_DIR}/u_vector.ipp
)

target_include_directories(test_containers PRIVATE ${SOURCE_DIR})
target_link_libraries(test_containers PRIVATE gtest gtest_main)
target_link_libraries(test_containers PRIVATE gmock gmock_main)

set_target_properties(test_containers PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

if(MSVC)
	set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_containers)	
endif()