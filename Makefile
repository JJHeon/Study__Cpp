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
chrono2 \
unique-ptr \

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

chrono2: $(OBJ_DIR)/003_chrono2.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

unique-ptr: $(OBJ_DIR)/004_unique-ptr.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: clean all
clean:
	rm -f $(OBJECTS) $(TARGET)

