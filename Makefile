# Build Variable
CXX = g++

# Build Option Variable
CXXFLAGS = -Wall -O2 -std=c++17

# Linker Option
LDFLAGS =

# Source File Directory
SRC_DIR = ./src

# Object File Directory
OBJ_DIR = ./obj


# Header Files
HDRS = -I$(SRC_DIR)

# Source Files
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cc))

# Object Files
OBJS = $(SRCS:.cc=.o)
OBJECTS = $(patsubst %.o, $(OBJ_DIR)/%.o, $(OBJS))

# Target Variable
TARGET = \
random \
random2 \
chrono \
chrono-1 \
chrono2 \
unique-ptr \
unique-ptr2 \
unique-ptr3 \
exception \
exception2 \
exception3 \
string-1 \
algorithm-1 \
algorithm-2 \
algorithm-3 \

# Target Files
# TARGETS = $(patsubst %, %.out, $(TARGET))


all: $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) $(HDRS) -c $< -o $@

random: $(OBJ_DIR)/000_random.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

random2: $(OBJ_DIR)/001_random2.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

chrono: $(OBJ_DIR)/002_chrono.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

chrono-1: $(OBJ_DIR)/002_chrono-1.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

chrono2: $(OBJ_DIR)/003_chrono2.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

unique-ptr: $(OBJ_DIR)/004_unique-ptr.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

unique-ptr2: $(OBJ_DIR)/005_unique-ptr2.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

unique-ptr3: $(OBJ_DIR)/006_unique-ptr3.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

exception: $(OBJ_DIR)/007_exception.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

exception2: $(OBJ_DIR)/008_exception2.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

exception3: $(OBJ_DIR)/009_exception3.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

string-1: $(OBJ_DIR)/010_string-1.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

algorithm-1: $(OBJ_DIR)/011_algorithm-1.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

algorithm-2: $(OBJ_DIR)/011_algorithm-2.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

algorithm-3: $(OBJ_DIR)/011_algorithm-3.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: clean all
clean:
	rm -f $(OBJECTS) $(TARGET)

