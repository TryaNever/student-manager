CC = gcc

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iinclude

# Sous Windows, on ajoute l'extension .exe
TARGET = student_manager.exe

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@if exist "src\*.o" powershell -Command "Remove-Item -Force src/*.o"

fclean: clean
	@if exist $(TARGET) powershell -Command "Remove-Item -Force $(TARGET)"

re: fclean all
