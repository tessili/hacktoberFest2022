#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 5
void enqueue_arr(int);
void dequeue_arr();
void disp_arr();
void enqueue_link(int,char[]);
void dequeue_link();
void disp_link();
int q[size];
int front=-1;
int rear=-1;
struct node
{
	int data1;
	char data2[100];
	struct node *next;
};
struct node *front1=NULL;
struct node *rear1=NULL;
int count=0;
int main()
{
	int a,choice;
	char b[10];
	do
	{
		printf("\n\t\t\t\t!!QUEUE IMPLEMENTATION USING ARRAY AND LINKED-LIST!!");
		printf("\n\t\t\t\t****************************************************");
		printf("\n\t\t\t\t\t1.ENQUEUE(Array)\n\t\t\t\t\t2.DEQUEUE(Array)\n\t\t\t\t\t3.ENQUEUE(Linked-list)\n\t\t\t\t\t4.DEQUEUE(Linked-list)\n\t\t\t\t\t5.EXIT\n");
		printf("\n\tEnter the choice(1-5): ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\n\tEnter the Roll number of student to insert to queue: ");
					scanf("%d",&a);
					enqueue_arr(a);
					break;
			case 2: dequeue_arr();
					break;
			case 3: printf("\n\tEnter the Roll number and name of the student to insert to queue: ");
					scanf("%d",&a);
					scanf("%s",&b);
					enqueue_link(a,b);
					break;
			case 4: dequeue_link();
					break;
			case 5: printf("\n\tExiting....");
					exit(0);
			default:printf("\n\tEnter the correct choice!!\n");		
		}
	}while(choice!=5);	
}

void enqueue_arr(int c)
{
	if((front==0 && rear==size-1) || (front==rear+1))
	{
		printf("\n\t!!Queue Overflow!!\n");
	}
	else
	{
		if(front==-1)
			front=rear=0;
		else if (rear==size-1)
			rear=0;
		else
			rear++;
		q[rear]=c;
	}
	disp_arr();
}

void dequeue_arr()
{
	if(front==-1)
	{
		printf("\n\t!!Queue Underflow!!\n");
	}
	else
	{
		printf("\n\tDeleted Roll nmuber is : %d",q[front]);
		if(front==rear)
			front=rear=-1;	
		else if(front==size-1)
			front=0;			
		else
			front++;		
	}
	disp_arr();
}

void disp_arr()
{
	int i;
    if(front==-1)
	{
		printf("\n\tQueue is Empty!!\n");
	}
	else
	{
		printf("\n\tROLL-NUMBERS ARE:\n");
		if(rear>=front)
		{
			for(i=front;i<=rear;i++)
			{
				printf("\t\t\t | %d |\n",q[i]);
			}
			printf("\t\t\t -------");
		}
		else
		{
			for(i=front;i<size;i++)
			{
				printf("\t\t\t | %d |\n",q[i]);
			}
			for(i=0;i<=rear;i++)
			{
				printf("\t\t\t | %d |\n",q[i]);
			}
			printf("\t\t\t -------");
		}
	}
}

void enqueue_link(int c,char b[100])
{
	if(count>4)
	{
		printf("\n\t!!Queue Overflows!!");
	}
	else
	{
		struct node *newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data1=c;
		strcpy(newnode->data2,b);
		newnode->next=NULL;
		if(front1==NULL || rear1==NULL)
		{
			front1=newnode;
			rear1=newnode;
		}
		else
		{
			rear1->next=newnode;
			rear1=newnode;
		}
		count++;
	}
	disp_link();
}

void dequeue_link()
{
	struct node *ptr;
	ptr=front1;
	if(front1==NULL)  
    {
        printf("\n\t!!Queue Underflow!!\n");
        return;
    }
    else
    {
        front1=front1->next ;
        printf("\n\tThe Deleted data's are :%d and %s\t\n",ptr->data1,ptr->data2);
        free(ptr);
        count--;
    }
    disp_link();
}

void disp_link()
{
	struct node *ptr;
	ptr=front1;
	if(front1==NULL)
	{
		printf("\n\t!!The Queue is Empty!!\n");
		return;
	}
	else
	{
		printf("\n\t--------------------------\n");
		printf("\t| ROLL-NUMBER |   NAME   |\n");
		printf("\t--------------------------\n");
		while(ptr!=NULL)
		{
			printf("\t      %d     | %s \n",ptr->data1,ptr->data2);
			ptr=ptr->next;
		}
	}
}
