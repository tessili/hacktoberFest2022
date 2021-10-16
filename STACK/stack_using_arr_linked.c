#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 6
void push_arr(int);
void pop_arr();
void disp_arr();
void push_link(char[]);
void pop_link();
void disp_link();
int s[size],top1=-1,count=0;
struct node
{
	char data[100];
	struct node *next;
};
struct node *top=NULL;
int main()
{
	int a,choice;
	char b[10];
	do
	{
		printf("\n\t\t\t\t!!STACK IMPLEMENTATION USING ARRAY AND LINKED-LIST!!");
		printf("\n\t\t\t\t****************************************************");
		printf("\n\t\t\t\t\t1.PUSH(Array)\n\t\t\t\t\t2.POP(Array)\n\t\t\t\t\t3.PUSH(Linked-list)\n\t\t\t\t\t4.POP(Linked-list)\n\t\t\t\t\t5.EXIT\n");
		printf("\n\tEnter the choice(1-4): ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\n\tEnter the element to push(insert) to stack: ");
					scanf("%d",&a);
					push_arr(a);
					break;
			case 2: pop_arr();
					break;
			case 3: printf("\n\tEnter the strings to push(insert) to stack: ");
					scanf("%s",&b);
					push_link(b);
					break;
			case 4: pop_link();
					break;
			case 5: printf("\n\tExiting....");
					exit(0);
			default:printf("\n\tEnter the correct choice!!\n");		
		}
	}while(choice!=5);
}

void push_arr(int c)
{
	if(top1==(size-1))
	{
		printf("\n\t!!Stack Overflow!!\n");
	}
	else
	{
		top1++;
		s[top1]=c;
	}
	disp_arr();
}

void pop_arr()
{
	if(top1==-1)
	{
		printf("\n\t!!Stack Underflow!!\n");
	}
	else
	{
		printf("\n\tPopped element is(Array): %d",s[top1]);
		top1--;
	}
	disp_arr();
}

void disp_arr()
{
	int i;
	if(top1==-1)
	{
		printf("\n\t!!Stack is Empty!!\n");
	}
	else
	{
		printf("\n\tStack Elements are(Array):\n");
		for(i=top1;i>=0;i--)
		{
			printf("\t\t| %d |\n",s[i]);
		}
		printf("\t\t------");
	}
}
void push_link(char b[100])
{
	if(count>5)
	{
		printf("\n\t!!Stack Overflows!!");
		disp_link();
	}
	else
	{
		struct node *newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
		strcpy(newnode->data,b);
		newnode->next=NULL;
		if(top==NULL)
		{
			top=newnode;
		}
		else
		{
			newnode->next=top;
			top=newnode;
		}
		count++;
		disp_link();
	}
}

void pop_link()
{
	struct node *ptr;
	ptr=top;
	if(top==NULL)  
    {
        printf("\n\t!!Stack Underflow!!\n");
        return;
    }
    else
    {
        top=top->next ;
        printf("\n\tThe Popped element is(Linked-list): %s\t\n",ptr->data);
        free(ptr);
        count--;
    }
    disp_link();
}

void disp_link()
{
	struct node *ptr;
	ptr=top;
	if(top==NULL)
	{
		printf("\n\t!!The Stack is Empty!!\n");
		return;
	}
	else
	{
		printf("\n\tThe Stack elements are(Linked-list): \n");
		printf("\t\t----------------\n");
		while(ptr!=NULL)
		{
			printf("\t\t|   %s\n",ptr->data);
			ptr=ptr->next;
		}
		printf("\t\t----------------");
	}
}