CC=gcc
CFLAGS=-Iinclude
DEPS = http_server.hpp
exec = server.o
sources = $(wildcard source/*.cpp)
objects = $(sources:.c=.o)
flags = -g -Wall -lm -ldl -fPIC -rdynamic -I./include
flags = -I./include

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c %.h
	gcc -c $(flags) $< -o $@

clean:
	-rm *.out
	-rm *.o
	-rm *.a
	-rm source/*.a
	-rm source/*.o