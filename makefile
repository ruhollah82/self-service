# Set up compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -I./include
LIBRARIES = -lbcrypt

# Define directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BUILD_DIR = build

# Define the target executable
TARGET = main.out

# Collect all source files (.cpp) from the src directory (excluding main.cpp)
SOURCES := $(wildcard $(SRC_DIR)/**/*.cpp)
SOURCES_NO_MAIN := $(filter-out $(SRC_DIR)/main.cpp, $(SOURCES))

# Collect all object files (.o) by replacing .cpp with .o and placing them in the obj directory
OBJECTS := $(SOURCES_NO_MAIN:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Add obj/main.o separately
MAIN_OBJ := $(OBJ_DIR)/main.o

# Default target
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJECTS) $(MAIN_OBJ)
	$(CXX) $(OBJECTS) $(MAIN_OBJ) -o $(TARGET) $(LIBRARIES)

# Rule to create object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Create obj subdirectories
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile main.cpp separately
$(MAIN_OBJ): ./main.cpp
	@mkdir -p $(dir $@)  # Create obj subdirectories
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build and object directories
clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR) $(TARGET)

# For convenient compilation with 'make run'
run: $(TARGET)
	./$(TARGET)
