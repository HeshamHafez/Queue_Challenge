/*
 ============================================================================
 Name        : main.c
 Author      : Ahmed ElDakhly
 Date        : 11/9/2019
 Description : Linked List Exercises
 ============================================================================
 */

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include"stack.h"
#include"queue.h"
/*******************************************************************************
 *                       	Main Function		                               *
 *******************************************************************************/
int main(void)
{
	setvbuf(stdout, NULL, _IONBF,0);
	setvbuf(stderr, NULL, _IONBF, 0);
	uint8 Str[255];
	printf("Please enter your expression\n");
	scanf("%s",Str);
	queue * operations;
	queue * numbers;
	operations = CreatQueue(255);
	numbers = CreatQueue(255);
	uint8 pracket_check = Prackets(Str);
	uint8 num_counter = 0;
	uint8 sum = 0;

	if(pracket_check == BRACKETS_MATCHED)
	{
		for(uint8 i = 0; Str[i] !='\0';i++)
		{
			if((Str[i] >= '0' ) &&  (Str[i] <= '9'))
			{
				Enqueue(numbers , (Str[i]-48));
			}
			else if((Str[i] == '+') || (Str[i] == '-') || (Str[i] == '*') || (Str[i] == '/'))
			{
				Enqueue(operations , (Str[i]));
			}

			else
			{
				/*Do nothing*/
			}

		}
		num_counter =( operations -> rear)+1;
		sum = numbers->array[numbers->front];
		Dequeue(numbers);
		while(num_counter != 0)
		{
			switch(operations->array[operations->front])
			{
			case '+':
				sum += numbers->array[numbers->front];
				break;
			case '-':
				sum -= numbers->array[numbers->front];
				break;
			case '*':
				sum *= numbers->array[numbers->front];
				break;
			case '/':
				sum /= numbers->array[numbers->front];
				break;
			}
			Dequeue(numbers);
			Dequeue(operations);
			num_counter--;
		}
		printf("the sum = %d\n",sum);
	}
	else
	{
		printf("Brackets Not Matched\n");
	}
	return 0;


	//	Queue_status PopOperation;
	//	while(1)
	//	{
	//		printf("please Select mode\n1-EnQueue\n2-DeQueue\n3-Exit\n");
	//		scanf("%d",&x);
	//		switch(x)
	//		{
	//		case EnQueue:
	//			printf("please enter data to EnQueue");
	//			scanf("%d",&Data);
	//			Queue_status PushOperation=Enqueue(new_queue,Data);
	//			if(PushOperation==QUEUE_FULL)
	//			{
	//				printf("queue is full\n");
	//			}
	//			else
	//			{
	//				printf("%d is Enqueue\n",Data);
	//			}
	//			break;
	//		case DeQueue:
	//			PopOperation=Dequeue(new_queue);
	//			if(PopOperation==QUEUE_EMPTY)
	//			{
	//				printf("queue is Empty\n");
	//			}
	//			else
	//			{
	//				printf("dequeued\n");
	//			}
	//			break;
	//		case Exit:
	//			return 0;
	//
	//		}
	//
	//
	//	}


}

