SRCS = $(wildcard src/*.c)

SRCS2 = $(notdir $(SRCS))

CFLAGS = -Wall -g -pg -m64 -fPIC

PROGS = $(patsubst %.c,bin/%,$(SRCS2))

all: $(PROGS)

clean:
	rm -rf bin/*

bin/%: src/%.c

	$(CC) $(CFLAGS)  -o $@ $<
