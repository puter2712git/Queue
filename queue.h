#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

typedef int element;

/* Node data structure which store element */
struct node {
	element data;
	struct node *next;
};

/* Queue data structure which connects nodes */
struct queue {
	struct node *front;
	struct node *rear;
};


/* Initialize queue */
void initialize(struct queue **_head);


/* Finalize queue */
void finalize(struct queue **_head);


/* Check the queue is empty */
bool is_empty(struct queue *_head);


/**
 * Check the queue is full
 * 
 * Because this queue is made by dynamic allocation,
 * there will be no full in queue data structure.
*/
// bool is_full(struct queue *_head);


/* Add the @item into the queue */
void enqueue(struct queue *_head, element _item);


/* Delete the item of the queue */
element dequeue(struct queue *_head);


/* Show data of the queue */
void dump_queue(struct queue *_head);

#endif