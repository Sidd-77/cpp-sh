# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -MMD -MP

# Directories
SRC_DIR = .
BUILD_DIR = build

# Source and object files
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))
DEPS = $(OBJ:.o=.d)

# Output executable
TARGET = shell

# Default rule: build executable
all: $(TARGET)

# Rule to compile executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile .cpp files into .o with dependency tracking
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include generated dependency files
-include $(DEPS)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Run program
run: all
	./$(TARGET)
