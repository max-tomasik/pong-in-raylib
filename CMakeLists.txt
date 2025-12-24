# ---------------------------
# Minimum CMake version required
# ---------------------------
cmake_minimum_required(VERSION 3.16)

# ---------------------------
# Project definition
# ---------------------------
# Set the project name and languages (C and C++)
project(MyProject LANGUAGES C CXX)

# ---------------------------
# C++ and C Standards
# ---------------------------
# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ---------------------------
# Output directories
# ---------------------------
# By default, CMake outputs binaries in <build>/ directory
# You can customize it like this:
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# ---------------------------
# Include directories
# ---------------------------
# Add the include/ folder so headers are found
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    # Add more include directories if needed
    # ${PROJECT_SOURCE_DIR}/thirdparty/somelib/include
)

# ---------------------------
# Source files
# ---------------------------
# Automatically find all source files in src/ and lib/
file(GLOB_RECURSE SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.*"
    "${PROJECT_SOURCE_DIR}/lib/*.*"
)

# ---------------------------
# Create executable
# ---------------------------
# Main executable target
add_executable(${PROJECT_NAME} ${SRC_FILES})

# ---------------------------
# Optional: Separate library target
# ---------------------------
# If you want to build lib/ as a separate library:
# file(GLOB_RECURSE LIB_FILES "${PROJECT_SOURCE_DIR}/lib/*.*")
# add_library(MyLibrary STATIC ${LIB_FILES})
# target_include_directories(MyLibrary PUBLIC ${PROJECT_SOURCE_DIR}/include)
# Then link the library to the executable:
# target_link_libraries(${PROJECT_NAME} MyLibrary)

# ---------------------------
# Optional: Link external libraries
# ---------------------------
target_link_libraries(${PROJECT_NAME} 
    raylib
)

# ---------------------------
# Optional: Compiler flags
# ---------------------------
# Uncomment to add extra flags
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2")

# ---------------------------
# Optional: Add subdirectories
# ---------------------------
# If you have multiple modules or subprojects
# add_subdirectory(lib/somelib)
# add_subdirectory(src/module)

