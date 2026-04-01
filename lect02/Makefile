CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Targets
TARGET = demo
TARGET_ADT = demo_adt

# Source files
SOURCES = demo.cpp Complex.cpp CustomVector.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Headers (for dependency tracking)
HEADERS = Complex.h CustomVector.h

# Default target - build both demos
all: $(TARGET) $(TARGET_ADT)

# Link object files to create main demo
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Build ADT demo (single file, no dependencies)
$(TARGET_ADT): demo_adt.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET_ADT) demo_adt.cpp

# Compile .cpp files to .o files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJECTS) $(TARGET) $(TARGET_ADT)

# Run the demo
run: $(TARGET)
	./$(TARGET)

# === MEMORY LEAK DETECTION ===

# FOR STUDENTS IN LAB (CSIL Linux machines):
# Use valgrind to check for memory leaks
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# FOR INSTRUCTOR ON macOS:
# Use AddressSanitizer (works on macOS and Linux!)

# AddressSanitizer compilation flags
SANITIZE_FLAGS = -fsanitize=address -fno-omit-frame-pointer

# Build and run with leak detection
sanitize:
	@echo "========================================="
	@echo "Building with AddressSanitizer (macOS)..."
	@echo "========================================="
	$(CXX) $(CXXFLAGS) $(SANITIZE_FLAGS) $(SOURCES) -o $(TARGET)
	@echo ""
	@echo "Running ./$(TARGET)..."
	@echo "Press Enter to continue between demos"
	@echo "Leaks will be reported automatically:"
	@echo "-----------------------------------------"
	./$(TARGET) || true
	@echo "-----------------------------------------"

# Phony targets (not actual files)
.PHONY: all clean run valgrind sanitize
