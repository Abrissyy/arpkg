CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
OUT_DIR = bin
OUT_EXEC = arpkg

SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/installer.cpp $(SRC_DIR)/updater.cpp $(SRC_DIR)/installed.cpp $(SRC_DIR)/locate.cpp $(SRC_DIR)/remover.cpp $(SRC_DIR)/credits.cpp
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(OUT_DIR)/$(OUT_EXEC)

$(OBJ_DIR) $(OUT_DIR):
	mkdir -p $@

$(OUT_DIR)/$(OUT_EXEC): $(OBJS) | $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

install: $(OUT_DIR)/$(OUT_EXEC)
	sudo chmod +x bin/arpkg

clean:
	rm -rf $(OBJ_DIR)/*.o $(OUT_DIR)/$(OUT_EXEC)
