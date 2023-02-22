all:
	cd ./src && make
	cd ./test && make

clean:
	$(RM) $(OBJS) *.o *.exe *.a
	cd ./src && make clean
	cd ./test && make clean

.SUFFIXES: .o .c
.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<
