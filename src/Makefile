CC = gcc
CFLAGS = -Iinclude -Llib
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = $(BIN_DIR)/main.exe

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    $(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
    rm -rf $(OBJ_DIR)/*.o $(TARGET)