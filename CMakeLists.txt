cmake_minimum_required(VERSION 3.10)
project(FoodServiceApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -lbcrypt" )
# Source files
file(GLOB_RECURSE SOURCES
    "src/foodservice/*.cpp"
    "src/infrastructures/*.cpp"
    "src/interface/*.cpp"
    "src/payment/*.cpp"
    "src/roles/*.cpp"
    "main.cpp"
)
include(FetchContent)

FetchContent_Declare(json 
URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
DOWNLOAD_EXTRACT_TIMESTAMP true)
FetchContent_MakeAvailable(json)


# Include directories
include_directories(include)

find_library(BCRYPT_LIBRARY
    NAMES bcrypt
    PATHS /usr/local/lib
    NO_DEFAULT_PATH # Only search in the specified paths
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${BCRYPT_LIBRARY} nlohmann_json::nlohmann_json)
# Create directories for object files (optional, but good practice)
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    OBJECT_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/obj"
)