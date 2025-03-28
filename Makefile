BIN_DIR = bin

TARGET = $(BIN_DIR)/app

all: $(TARGET)

$(TARGET): main.o task.o menu.o inputer.o
	mkdir -p $(BIN_DIR)
	gcc -o $(TARGET) main.o task.o menu.o inputer.o
	rm -f *.o

main.o: main.c
	gcc -c main.c -o main.o

task.o: domain/task/task.c domain/task/task.h
	gcc -c domain/task/task.c -o task.o

menu.o: domain/menu/menu.c domain/menu/menu.h
	gcc -c domain/menu/menu.c -o menu.o

inputer.o: domain/inputer/inputer.c domain/inputer/inputer.h
	gcc -c domain/inputer/inputer.c -o inputer.o

clean:
	rm -f *.o
	rm -rf $(BIN_DIR)/*
	rmdir $(BIN_DIR)
