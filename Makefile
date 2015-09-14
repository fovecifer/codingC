SRCS = $(wildcard *.c)

PROGS = bin/$(patsubst %.c,%,$(SRCS))

all: $(PROGS)

clean:
	rm -rf bin/*

bin/%: %.c

	$(CC) $(CFLAGS)  -o $@ $<
