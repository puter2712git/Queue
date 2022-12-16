#include "queue.h"


int main()
{
	struct queue *head;

	initialize(&head);

	enqueue(head, 5);
	enqueue(head, 10);
	enqueue(head, 15);

	dump_queue(head);

	dequeue(head);

	dump_queue(head);

	finalize(&head);

	return 0;
}