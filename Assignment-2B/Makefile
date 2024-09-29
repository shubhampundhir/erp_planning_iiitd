# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++14   # Added -std=c++14 to enable C++14 features

# Executable name
TARGET = assignment_2b

# List of source files
SRCS = Book.cpp classFunctions.cpp functions.cpp Journals.cpp Library.cpp \
       LibraryItem.cpp main.cpp PublicationRank.cpp User.cpp

# Object files (same names as source files, but with .o extension)
OBJS = $(SRCS:.cpp=.o)

# Default rule to compile the program
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files (Windows version)
clean:
	del /Q *.o $(TARGET).exe
