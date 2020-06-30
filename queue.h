/*
 * queue.h
 *
 *  Created on: Sep 10, 2019
 *      Author: hp
 */

#ifndef QUEUE_H_
#define QUEUE_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include"std_types.h"
#include <stdio.h>
#include<stdlib.h>
#include "stack.h"

/*******************************************************************************
 *                        	Definitions				                           *
 *******************************************************************************/
#define BRACKETS_MATCHED 1
#define BRACKETS_NOTMATCHED 2
#define EnQueue 1
#define DeQueue 2
#define Exit 3

/*******************************************************************************
 *                         Queue Structures		                               *
 *******************************************************************************/
typedef struct
{
	uint8 * array;
	uint8 capacity;
	sint16 front;
	sint16 rear;
}queue;

/*******************************************************************************
 *                         Status Enum                       			       *
 *******************************************************************************/
typedef enum
{
	QUEUE_EMPTY,
	QUEUE_FULL,
	QUEUE_WORKING
}Queue_status;

/*******************************************************************************
 *                      Functions Prototypes                                   *
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
queue * CreatQueue(uint8 capacity);

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
Queue_status Enqueue(queue * queue_ptr,uint8 data);

/*******************************************************************************
 * Function Name:	Dequeue
 *
 * Description: 	remove element to queue
 *
 * Inputs:			pointer to queue struct
 *
 * Return:			enum Status
 *******************************************************************************/
Queue_status Dequeue(queue * queue_ptr);

/*******************************************************************************
 * Function Name:	Prackets
 *
 * Description: 	check if Brackets is Matched or not
 *
 * Inputs:			pointer to uint8
 *
 * Return:			uint8
 *******************************************************************************/
uint8 Prackets(uint8 * Str);

#endif /* QUEUE_H_ */
