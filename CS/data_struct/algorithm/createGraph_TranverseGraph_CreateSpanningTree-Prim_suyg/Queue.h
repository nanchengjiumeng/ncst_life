#define MAXQUEUE 100
typedef int QueueEntry;

typedef struct queue
{
	int count;
	int front;
	int rear;
	QueueEntry entry[MAXQUEUE];
}Queue;

void EnQueue(Queue *, QueueEntry);
void InitQueue(Queue *);
void DeQueue(Queue *, QueueEntry *);
int QueueSize(Queue *);
int QueueEmpty(Queue);
int QueueFull(Queue *);

/*CreatQueue: create the queue.
precondition: None.
postcondition: The queue has been initialized to be empty.*/
void InitQueue(Queue *q)
{
	q->count = 0;
	q->front = 0;
	q->rear = -1;
}

/*Append: append an entry to the queue.
precondition: The queue has been created and is not full.
postcondition: The entry x has been stored in the queue as its last entry.*/
void EnQueue(Queue *q,QueueEntry x)
{
	if(QueueFull(q))
		printf("Can not append an entry to a full queue");
	else
	{
		q->count++;
		q->rear = (q->rear + 1) % MAXQUEUE;
		q->entry[q->rear] = x;
	}	
}

/*Serve: remove the first entry in the queue.
precondition: The queue has been created and is not empty.
postcondition: The first entry in the queue has been removed and returned as the value of x.*/
void DeQueue(Queue *q,QueueEntry *x)
{
	if(QueueEmpty(*q))
		printf("Can not serve from an empty queue");
	else
	{
		q->count--;
		*x = q->entry[q->front];
		q->front = (q->front + 1) % MAXQUEUE;
	}
}

/*QueueSize: return the number of the entries in the queue.
precondition: The queue q has been created.
postcondition: The function returns the value of entries in the q.*/
int QueueSize(Queue *q)
{
	return q->count;
}

/*QueueEmpty: returns non-zero if the queue is empty.
precondition: The queue q has been created.
postcondition: The function returns true or false according as queue q is empty or not.*/
int QueueEmpty(Queue q)
{
	if(q.count <= 0)
	{
 		return 1;
	}
	else
	{
		return 0;
	}
	
}
/*QueueFull: returns none-zero if the queue is full
precondition: The queue q has been created.
postcondition: The function returns true or false according as queue q is full or not.*/
int QueueFull(Queue *q)
{
	if(q->count >= MAXQUEUE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
