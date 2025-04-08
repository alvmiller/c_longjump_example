#include <stdio.h>
#include <setjmp.h>

jmp_buf jump_buffer;

void error_handler()
{
   printf("The error is detected! Jumping back to main...\n");
   longjmp(jump_buffer, 1);
}

int main()
{
	if (setjmp(jump_buffer) == 0) {
		printf("Welcome to the program!\n");
		printf("Let's simulate an error...\n");
		error_handler();
	} else {
		printf("Back in main after longjmp().\n");
		printf("Error handling success.\n");
	}
	return 0;
}