INCLUDE = -Iinclude
CFLAGS = $(INCLUDE)
LIBS = lib/libfdr.a
CC= gcc

all: bin/S210110115

bin/S210110115 : src/S210110115.c
	$(CC) $(CFLAGS) -o bin/S210110115 src/S210110115.c $(LIBS)
	
clean:
	rm bin/*
