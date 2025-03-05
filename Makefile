# Variáveis
GCC = gcc
CXXFLAGS = -Wall -Wextra -g
TARGET = test
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

# Regras
all: $(TARGET)

$(TARGET): $(OBJ)
	$(GCC) $(CXXFLAGS) -o $@ $^

%.o: %.c
	$(GCC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
