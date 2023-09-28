# Directories
SRC_DIR = ./src
OBJ_DIR = ./obj
COMMANDS_SRC_DIR = ./src/commands
COMMAND_OBJ_DIR = ./obj/commands
EXEC_DIR = ./bin
INCLUDE_DIR = ./include/

# Compiler flags
CXX = clang++ -std=c++11
CXXFLAGS = -g -I $(INCLUDE_DIR)

# Source files and corresponding object files
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

COMMANDS_SRC := $(wildcard $(COMMANDS_SRC_DIR)/*.cpp)
COMMANDS_OBJS = $(patsubst $(COMMANDS_SRC_DIR)/%.cpp, $(COMMAND_OBJ_DIR)/%.o, $(COMMANDS_SRC))

LEXER_SRC = ./src/lexer.l
PARSER_SRC = ./src/parser.y
PARSER_OBJS = ./obj/parser.o ./obj/lexer.o

# ****************************************************
# Targets needed to bring the executable up to date

all: server

server: $(OBJS) $(COMMANDS_OBJS) $(PARSER_OBJS)
	$(CXX) $(CXXFLAGS) -o ./bin/$@ $(OBJS) $(COMMANDS_OBJS) $(PARSER_OBJS)
	# cp /Users/amit/Downloads/matrix.csv ./data/matrix.csv
	./bin/server

print: 
	echo $(COMMANDS_OBJS)
	echo "\n"
	echo $(COMMAND_OBJ_DIR)

clean:
	rm -rf obj/*
	rm -f bin/server
	rm -f log
	rm -rf data/temp/*
	rm -rf data/exports/*
	mkdir ./obj/commands

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/global.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
$(COMMAND_OBJ_DIR)/%.o: $(COMMANDS_DIR)/.cpp $(INCLUDE_DIR)/global.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PARSER_OBJS): $(LEXER_SRC) $(PARSER_SRC) 
	flex $(LEXER_SRC)
	bison -d $(PARSER_SRC)
	mv lex.yy.c src/lex.yy.c
	mv parser.tab.c src/parser.tab.c
	mv parser.tab.h include/parser.tab.h
	$(CXX) $(CXXFLAGS) -c -o obj/lexer.o src/lex.yy.c
	$(CXX) $(CXXFLAGS) -c -o obj/parser.o src/parser.tab.c