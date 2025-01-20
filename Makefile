# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source and object files
SRC = main.cpp cd.cpp execute.cpp inputParser.cpp pipes.cpp redirections.cpp  
OBJ = $(SRC:.cpp=.o)

# Output executable
TARGET = shell

# Default rule: build executable
all: $(TARGET)

# Rule to compile executable
$(TARGET): $(OBJ)
    $(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile .cpp files into .o
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
    rm -f $(OBJ) $(TARGET)

# Run program
run: all
    ./$(TARGET)
