/******************************************************************************
 *
 * Module: Queue
 *
 * File Name: queue.c
 *
 * Description: Source file for Queue
 *
 * Created on: Sep 10, 2019
 *
 * Author: Hesham Hafez & Ahmed Eldakhly
 *
 *******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "queue.h"
/*******************************************************************************
 *                      Functions Definitions                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	CreatQueue
 *
 * Description: 	Create Queue
 *
 * Inputs:			uint8
 *
 * Return:			pointer to struct
 *******************************************************************************/
queue * CreatQueue(uint8 capacity)
{
	queue * new_queue = malloc(sizeof(queue));

	if(new_queue == NULL)
	{
		return NULL;
	}

	new_queue->capacity = capacity;
	new_queue->front = -1;
	new_queue->rear = -1;
	new_queue->array = malloc(capacity * sizeof(uint8));

	if(new_queue->array == NULL)
	{
		free(new_queue);
		return NULL;
	}

	return new_queue;
}

/*******************************************************************************
 * Function Name:	Enqueue
 *
 * Description: 	add element to queue
 *
 * Inputs:			pointer to queue struct
 * 					uint8
 *
 * Return:			enum Status
 *******************************************************************************/
Queue_status Enqueue(queue * queue_ptr,uint8 data)
{
	Queue_status EnQueue_Check = QUEUE_WORKING;
	if(queue_ptr->front == -1)
	{
		(queue_ptr->front)++;
	}
	if(queue_ptr->rear == -1)
	{
		EnQueue_Check = QUEUE_EMPTY;
		(queue_ptr->rear)++;
		queue_ptr->array[queue_ptr->rear]=data;

	}
	else if(queue_ptr->rear == ((queue_ptr->capacity)-1))
	{
		EnQueue_Check = QUEUE_FULL;
	}
	else
	{
		(queue_ptr->rear)++;
		queue_ptr->array[queue_ptr->rear]=data;

	}

	return EnQueue_Check;
}

/*******************************************************************************
 * Function Name:	Dequeue
 *
 * Description: 	remove element to queue
 *
 * Inputs:			pointer to queue struct
 *
 * Return:			enum Status
 *******************************************************************************/
Queue_status Dequeue(queue * queue_ptr)
{
	Queue_status DeQueue_Check =QUEUE_WORKING;
	if(queue_ptr->front == -1)
	{
		DeQueue_Check = QUEUE_EMPTY;
	}
	else if(queue_ptr->front == queue_ptr->rear)
	{
		queue_ptr->front = -1;
		queue_ptr->rear = -1;
		DeQueue_Check= QUEUE_EMPTY;
	}
	else if(queue_ptr->front == ((queue_ptr->capacity)-1))
	{
		DeQueue_Check = QUEUE_FULL;
	}
	else
	{
		(queue_ptr->front)++;
	}

	return DeQueue_Check;
}

/*******************************************************************************
 * Function Name:	Prackets
 *
 * Description: 	check if Brackets is Matched or not
 *
 * Inputs:			pointer to uint8
 *
 * Return:			uint8
 *******************************************************************************/
uint8 Prackets(uint8 * Str)
{
	CreatStack(10);
	uint8 OpenPracetCounter=0;
	uint8 ClosedPracetCounter=0;
	uint8 NotMatchedFlag=BRACKETS_MATCHED;
	for(uint8 i=0;Str[i]!='\0';i++)
	{
		if((Str[i]=='(')||(Str[i]=='{')||(Str[i]=='['))
		{
			push(new_stack,Str[i]);
			OpenPracetCounter++;
		}
		else if((Str[i]==')')||(Str[i]=='}')||(Str[i]==']'))
		{
			ClosedPracetCounter++;
			uint8 check=Str[i];
			switch(check)
			{
			case ')':
				if((new_stack->array[new_stack->top])=='(')
				{
					pop(new_stack);
				}
				else
				{
					NotMatchedFlag=BRACKETS_NOTMATCHED;
					break;
				}
				break;
			case '}':
				if((new_stack->array[new_stack->top])=='{')
				{
					pop(new_stack);

				}
				else
				{
					NotMatchedFlag=BRACKETS_NOTMATCHED;
					break;
				}
				break;
			case ']':
				if((new_stack->array[new_stack->top])=='[')
				{
					pop(new_stack);
				}
				else
				{
					NotMatchedFlag=BRACKETS_NOTMATCHED;
					break;
				}
				break;
			}
		}
		if(NotMatchedFlag==BRACKETS_NOTMATCHED)
		{
			break;
		}
	}
	if(NotMatchedFlag==BRACKETS_MATCHED)
	{

		if(OpenPracetCounter==ClosedPracetCounter)
		{
			NotMatchedFlag=BRACKETS_MATCHED;
		}
		else
		{
			NotMatchedFlag=BRACKETS_NOTMATCHED;
		}
	}
	return NotMatchedFlag;
}

