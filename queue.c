#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

void initialize(struct queue **_head)
{
	*_head = (struct queue*)malloc(sizeof(struct queue));
	(*_head)->front = NULL;
	(*_head)->rear = NULL;

	return;
}


void finalize(struct queue **_head)
{
	free(*_head);

	return;
}


bool is_empty(struct queue *_head)
{
	return !_head->front && !_head->rear;
}


void enqueue(struct queue *_head, element _item)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = _item;
	new->next = NULL;

	if (is_empty(_head)) {
		_head->front = new;
	}
	else {
		_head->rear->next = new;
	}
	_head->rear = new;

	return;
}


element dequeue(struct queue *_head)
{
	assert(!is_empty(_head));

	struct node *del = _head->front;
	element removed_item = del->data;
	_head->front = del->next;
	free(del);

	return removed_item;
}


void dump_queue(struct queue *_head)
{
	assert(!is_empty(_head));

	struct node *temp = _head->front;
	int index = 1;

	printf("==============================\n");
  printf("Print the elements of the queue.\n");
  
	while (temp) {
		printf("[%2d] : %d\n", index, temp->data);

		temp = temp->next;
		index++;
	}

  printf("==============================\n");

  return;
}