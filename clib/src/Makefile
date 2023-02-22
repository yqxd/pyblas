include ../make.inc

OBJS = clib.o tools.o
MYLIB = ../libclib.a

.PHONY: lib clean

lib: $(OBJS)
	$(AR) $(ARFLAGS) $(MYLIB) $(OBJS)
	$(RANLIB) $(MYLIB)

clean:
	$(RM) $(OBJS) *.o *.exe

.SUFFIXES: .o .c
.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<
