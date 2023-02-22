include ../make.inc

TOOL = tools.o
MYLIB = ../libclib.a

.PHONY: all clean

all: test_correctness.x

test_correctness.x: $(CLIB)  test_correctness.o
	$(LOADER) $(LDFLAGS) -o $@ $^ $(MYLIB) $(LIBS) $(SHAREDLIB)

clean:
	$(RM) $(OBJS) *.o *.x

.SUFFIXES: .o .c
.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<
