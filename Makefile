CC=g++
CFLAGS=-std=c++17 -Wall -Werror

SRC=src
OBJ=obj

SOURCES=$(wildcard $(SRC)/*.cpp)
OBJECTS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))
DEP=$(OBJECTS:%.o=%.d)

.PHONY: all
all : $(OBJECTS)
	$(CC) $^ -o sevens

-include $(DEP)

$(OBJ)/%.o: $(SRC)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(SRC) -MMD -c $< -o $@

.PHONY: clean
clean:
	rm $(OBJ)/*.o $(OBJ)/*.d sevens
