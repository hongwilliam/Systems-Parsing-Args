all: parsing_args.c
	gcc parsing_args.c

run: all
	./a.out

clean:
	rm *.o
	rm *~
	rm a.out
