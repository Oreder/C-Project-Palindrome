# Compiler
CC := gcc

# Compiler options
FLAGS := -std=c99 -Wall -Werror

# Dependency
DEPS := btype.h palindrome.h exec.h

# Object files
OBJS := btype.o source.o palindrome.o exec.o

%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -c $<

main.exe: $(OBJS)
	$(CC) -o $@ $^
	
clean:
	rm *.o main.exe