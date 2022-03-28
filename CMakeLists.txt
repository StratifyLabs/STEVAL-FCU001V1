cmake_minimum_required (VERSION 3.19)

set(SDK_DIRECTORY ${CMAKE_SOURCE_DIR}/SDK)
set(SOS_SDK_PATH ${SDK_DIRECTORY}/StratifyLabs-SDK)

set(CMAKE_MODULE_PATH ${SOS_SDK_PATH}/cmake)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_MODULE_PATH}/sos-toolchain.cmake)
include(sos-sdk)

message(FATAL_ERROR "Change the project name - then delete this line")
project(Boardv4 CXX C ASM)
include(CTest)

message(FATAL_ERROR "Update the architecture to match your CPU (v7m, v7em_f4sh, v7em_f5sh, v7em_f5dh - then delete this line")
set(SOS_ARCH v7em_f5dh)
set(SOS_ARCH_LIST "")

set(SOS_SDK_PULL_TARGET pull)
add_custom_target(pull
	COMMAND git pull
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(SDK)
message(FATAL_ERROR "Update the board name - then delete this line")
add_subdirectory(BoardName)
add_subdirectory(apps)

