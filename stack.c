/******************************************************************************
 *
 * Module: Stack
 *
 * File Name: stack.c
 *
 * Description: Source file for Stack
 *
 * Created on: Sep 10, 2019
 *
 * Author: Hesham Hafez & Ahmed Eldakhly
 *
 *******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stack.h"
/*******************************************************************************
 *                      Global Variables  		                               *
 *******************************************************************************/
stack * new_stack;
/*******************************************************************************
 *                      Functions Definitions                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	CreatStack
 *
 * Description: 	Createt Stack
 *
 * Inputs:			uint8
 *
 * Return:			pointer to struct
 *******************************************************************************/
stack * CreatStack(uint8 capacity)
{
	new_stack = malloc(sizeof(stack));

	if(new_stack == NULL)
	{
		return NULL;
	}

	new_stack->capacity = capacity;
	new_stack->top = -1;
	new_stack->array = malloc(capacity * sizeof(uint8));

	if(new_stack->array == NULL)
	{
		free(new_stack);
		return NULL;
	}

	return new_stack;
}

/*******************************************************************************
 * Function Name:	push
 *
 * Description: 	add element to Stack
 *
 * Inputs:			pointer to stack struct
 * 					uint8
 *
 * Return:			enum Status
 *******************************************************************************/
status push(stack * stack_ptr,uint8 data)
{
	status PushCheck = WORKING;
	(stack_ptr->top)++;
	if(new_stack->top == -1)
	{
		PushCheck = EMPTY;
	}
	else if(new_stack->top == ((new_stack->capacity)-1))
	{
		PushCheck = FULL;
	}
	else
	{
		stack_ptr->array[stack_ptr->top]=data;
	}

	return PushCheck;

}

/*******************************************************************************
 * Function Name:	pop
 *
 * Description: 	remove element to Stack
 *
 * Inputs:			pointer to stack struct
 *
 * Return:			enum Status
 *******************************************************************************/
status pop(stack * stack_ptr)
{
	status PopCheck =WORKING;
	if(new_stack->top == -1)
	{
		PopCheck = EMPTY;
	}
	else if(new_stack->top == ((new_stack->capacity)-1))
	{
		PopCheck = FULL;
		(stack_ptr->top)--;
	}
	else
	{
		(stack_ptr->top)--;
	}

	return PopCheck;
}
