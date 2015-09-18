SRCS = $(wildcard *.c)

CFLAGS = -Wall -g -m64 -fPIC

PROGS = $(patsubst %.c,bin/%,$(SRCS))

all: $(PROGS)

clean:
	rm -rf bin/*

bin/%: %.c

	$(CC) $(CFLAGS)  -o $@ $<
