#include "shell.h"
/**
 * print_prompt - prints the shell prompt
 */
void print_prompt1(void)
{
	write(2, "coolbean$ ", 10);
}
/**
 * print_promt2 - prints 2nd prompt
 */
void print_prompt2(void)
{
	write(2, "> ", 2);
}
