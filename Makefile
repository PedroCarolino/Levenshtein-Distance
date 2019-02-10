CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c99 -pedantic
DEPS = 
Vflags = valgrind --leak-check=full
OBJ = main.o 
%.o: %.c $(DEPS)
				$(CC) -c -o $@ $< $(CFLAGS)

tp2: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

	rm -rf *.o

clean: 
	rm -rf *.o tp2

teste: tp2
	$(Vflags) ./tp2 < input1.txt 
	$(Vflags) ./tp2 < input2.txt 
	$(Vflags) ./tp2 < input3.txt 
	$(Vflags) ./tp2 < input4.txt 
	$(Vflags) ./tp2 < input5.txt 
	$(Vflags) ./tp2 < input6.txt 
	$(Vflags) ./tp2 < input7.txt 
	$(Vflags) ./tp2 < input8.txt 
	$(Vflags) ./tp2 < input9.txt 
	$(Vflags) ./tp2 < input10.txt 







