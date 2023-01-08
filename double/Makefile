OBJS = double.o
CC = gcc

double: ${OBJS}
	${CC} ${OBJS} -o $@

clean:
	-del *.o

.c.o:
	${CC} -c $<
