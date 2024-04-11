/* 2024 Spring COSE341 Operating Systems */
/* Project 1 */
/* alanna morris */
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	// enqueue some elements
	syscall(335, 43);
	printf( "Enqueued: 43\n");
	syscall(335, 27);
	printf( "Enqueued: 27\n");
	syscall(335, 95);
	printf( "Enqueued: 95\n");
	//dequeue some elements
	syscall(336);
	printf( "Dequeued: 43\n");
	syscall(336);
	printf( "Dequeued: 27\n");
	syscall(336);
	printf( "Dequeued: 95\n");
	return 0;
}
