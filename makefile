CC = gcc

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iinclude

TARGET = student_manager.exe

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
RES_OBJ = resources.o

all: $(TARGET)

$(TARGET): $(OBJ) $(RES_OBJ)
	$(CC) $(OBJ) $(RES_OBJ) -o $(TARGET)

$(RES_OBJ): resources.rc app.manifest
	windres resources.rc -o $(RES_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(RES_OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all