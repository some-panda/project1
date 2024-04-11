/* 2024 Spring COSE341 Operating System */
/* Project 1 */
/* alanna morris */

#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/linkage.h>
#define Q_SIZE 50 // random size, change if needed

// Global Variables
static int queue[Q_SIZE]; // queue int array
static int front = 0; // index for front of queue
static int rear = 0; // index for rear of queue

SYSCALL_DEFINE1(os2024_enqueue, int, a) {
	printk(KERN_INFO "[System call] os2024_enqueue(); -----\n");
        if (rear == Q_SIZE){
                printk(KERN_INFO "Queue full. Cannot enqueue %d.\n", a);
                return -1;
        }
        int i;
        // No duplicates allowed:
        for (i = front; i < rear; i++) {
                if (queue[i] == a) {
                        printk(KERN_INFO "Duplicates not allowed. Cannot enqueue.\n");
                        return -1;
                }
        }
        queue[rear] = a; // add new element
        rear++; // increment rear
        printk(KERN_INFO "Queue Front --------------------\n"); // print current queue
        int j;
        for (j = front; j < rear; j++){
                 printk(KERN_INFO "%d\n", queue[j]);
        }
        printk(KERN_INFO "Queue Rear ---------------------\n");
        return 0;
} // end of enqueue

SYSCALL_DEFINE0(os2024_dequeue) {
	printk(KERN_INFO "[System call] os2024_dequeue(); -----\n");
        if (rear == front) { // edge case, empty queue, do nothing, return
                printk(KERN_INFO "Queue empty. Cannot dequeue. \n");
                return -1;
        }
	int r;
	 //shift elements left to remove first element
	for ( r = front; r < rear; r++){
		queue[r] = queue[r + 1];
	}

        rear--; // decrement rear
        printk(KERN_INFO "Queue Front --------------------\n");
        if (rear != front) {
                int p;
                for (p = front; p < rear; p++) {
                        printk(KERN_INFO "%d\n", queue[p]);
                }
        }
        printk(KERN_INFO "Queue Rear ---------------------\n");
        return 0;
} // end of dequeue

