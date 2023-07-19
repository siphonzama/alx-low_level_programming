First day of C - Function pointers
dealing with function pointers, callbacks and how to deacalre them 

Function Pointer in C
Pointers to functions
Function Pointers in C / C++
why pointers to functions?
Everything you need to know about pointers in C

1. Write a function that prints a name.

Prototype: void print_name(char *name, void (*f)(char *));

2. Write a function that executes a function given as a parameter on each element of an array.

Prototype: void array_iterator(int *array, size_t size, void (*action)(int));

3. Write a function that searches for an integer.

Prototype: int int_index(int *array, int size, int (*cmp)(int));

4. Write a program that performs simple operations.

5. Write a program that prints the opcodes of its own main function.
