#include "queue.h"

/* printQueue
 * input: a pointer to a Queue
 * output: none
 *
 * Prints the elements in the Queue.
 */
void printQueue(Queue *pq) {
  LLNode *curr;
  if (pq == NULL) {
    printf("Queue pointer is NULL\n");
    return;
  }

  if (pq->qFront == NULL) {
    printf("Queue is empty\n");
    return;
  }

  curr = pq->qFront;
  while (curr != NULL) {
    printf("{%s, $%.2lf}", curr->qt->name, curr->qt->price );
  curr = curr->pNext;
  if(curr != NULL)
    printf( ", " );
  }
	printf("\n");
}


/* createQueue
 * input: none
 * output: a pointer to a queue (this is malloc-ed so must be freed eventually!)
 *
 * Creates a new empty queue and returns a pointer to it.
 */
Queue *createQueue( )
{
  Queue *pq = (Queue *)malloc( sizeof(Queue) );
  if( pq!=NULL )
  {
    pq->qFront = NULL;
    pq->qRear = NULL;
  }

  return pq;
}

/* freeQueue
 * input: a pointer to a Queue
 * output: none
 *
 * frees the given Queue pointer.  Also, you should remember to free the elements in the linked list!
 */
void freeQueue( Queue *pq )
{
  free(pq);
}

/* getNext
 * input: a pointer to a Queue
 * output: a pointer to queueType
 *
 * Returns the queueType stored at the front of the Queue.  It does not remove the element from the queue.
 */
queueType getNext( Queue *pq )
{
  if( isEmpty( pq ) )
  {
      /* no element to return */
      //JESS: removed this error - fprintf( stderr, "getNext: Queue is empty (returning NULL).\n" );
      return NULL;
  }
  return pq->qFront->qt;
}

/* dequeue
 * input: a pointer to a Queue
 * output: a queueType
 *
 * Dequeues and returns the queueType stored at the front of the Queue.  It does not free the dequeue-ed element.
 */
queueType dequeue( Queue *pq )
{
  LLNode *temp;
  queueType qt;

  if( isEmpty( pq ) )
  {
    /* no element to return */
    //JESS: removed this error - fprintf( stderr, "dequeue: Queue is empty (returning NULL).\n" );
    return NULL;
  }
  temp = pq->qFront;
  pq->qFront = pq->qFront->pNext;
  if( pq->qFront==NULL ){
    pq->qRear=NULL;
  }
  qt = temp->qt;
  free(temp);

  return qt;
}

/* enqueue
 * input: a pointer to a Queue, a queueType
 * output: none
 *
 * Inserts the process on the rear of the given Queue.
 */
void enqueue( Queue *pq, queueType qt )
{
  LLNode *node = (LLNode*)malloc(sizeof(LLNode));
  if(node==NULL){
    fprintf( stderr, "enqueue: Failed to allocate memory");
    exit(-1);
  }

  node->pNext=NULL;
  node->qt = qt;
  if( isEmpty(pq) ){
    pq->qFront = node;
    pq->qRear = node;
    return;
  }
  pq->qRear->pNext = node;
  pq->qRear = node;
}

/* isEmpty
 * input: a pointer to a Queue
 * output: a boolean
 *
 * returns TRUE if the Queue is empty and FALSE otherwise
 */
bool isEmpty( Queue *pq )
{
  if( pq->qFront==NULL && pq->qRear==NULL )
  {
    return true;
  }
  else if( pq->qFront==NULL || pq->qRear==NULL )
  {
    fprintf( stderr, "isEmpty: Queue had inconsistent values for front and rear.\n" );
    exit(-1);
  }
  return false;
}

