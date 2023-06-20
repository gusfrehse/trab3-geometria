CXXFLAGS += -Wall -Wextra -O0 -g -std=c++20
OBJS = windowing.o rangetree.o bsp.o

windowing : $(OBJS)

windowing.o : windowing.c rangetree.h util.h
rangetree.o : rangetree.c rangetree.h bsp.h util.h
bsp.o : bsp.c bsp.h util.h

run : windowing
	./windowing

clean :
	rm -f $(OBJS) windowing
