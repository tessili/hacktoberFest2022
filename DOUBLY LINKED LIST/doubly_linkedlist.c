#include<stdio.h>
#include<stdlib.h>
void display_node();
void addfirst(int);
void add(int,int);
void dellast();
void del(int);
void search(int);

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;

int main()
{

	int choice,a,pos,b;
	do
	{
	  printf("\n\t\t\t\t!!SINGLY LINKED LIST MENU!!\n");
	  printf("\t\t\t\t***************************");
   	  printf("\n\t\t\t\t1.Add element(first Position):\n\t\t\t\t2.Add element(specified position)\n\t\t\t\t3.delete element(last Position)\n\t\t\t\t4.Delete element(specified value)\n\t\t\t\t5.Search\n\t\t\t\t6.Exit\n");
      printf("\tEnter your choice(1-6) : ");
      scanf("%d",&choice);
      switch(choice)
      {
		case 1: printf("\n\tEnter the value to add: ");
      	        scanf("%d",&a);
      	        addfirst(a);
      	        break;
      	case 2: printf("\n\tEnter the value to add:  ");
      	        scanf("%d",&a);
      	        printf("\n\tEnter the position: ");
      	        scanf("%d",&pos);
      	        add(a,pos);
      	        break;
      	case 3: dellast();
      	        break;
      	case 4: printf("\n\tEnter the value to delete: ");
      	        scanf("%d",&a);
      	        del(a);
      	        break;
      	case 5: printf("\n\tEnter the value to Search: ");
      			scanf("%d",&b);
      			search(b);
      	        break;        
      	case 6:	printf("\n\tExiting......");
      	        exit(0);
      	default:printf("\n\tEnter correct choice!!\n");
      }
    }while(choice!=6);
    return 0;
}
void display_node()
{

	struct node *ptr;
	if(head==NULL)
	{
		printf("\n\t!!The List is Empty!!\n");
		return;
	}
	else
	{
		ptr=head;
		printf("\n\tThe elements are: ");
		while(ptr!=NULL)
		{
			printf(" %d ==>",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}
void addfirst(int a)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=a;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
	display_node();
}
void add(int a,int pos)
{
	
	int i;
	struct node *newnode;
	struct node *ptr;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=a;
	newnode->next=NULL;
	ptr=head;
	if(head==NULL)
    {
        printf("\n\t!!You can't add as the List is Empty!!\n");
        return;
    }
	else if(pos==1)
	{
		addfirst(a);
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->next;
			if(ptr==NULL)
            {
                printf("\n\t!!Invalid position!!\n");
                display_node();
                return;
            }
		}
	newnode->next=ptr->next;
	ptr->next=newnode;
	display_node();
	}
}
void dellast()
{
	struct node *ptr,*ptr1;
	ptr=head;
    if(head==NULL)
    {
        printf("\n\t!!You can't delete as the List is Empty!!\n");
        return;
    }
    else if(head->next==NULL)
    {
        head=NULL;
        printf("\n\tThe deleted element is:%d\t\n",ptr->data);
        free(ptr);
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        printf("\n\tThe deleted element is:%d\t\n",ptr->data);
        free(ptr);
    }
    display_node();
}
void del(int a)
{
    struct node *ptr,*ptr1;
    ptr=head;
    if(head==NULL)
    {
        printf("\n\t!!You can't delete as the List is Empty!!\n");
        return;
    }
    else
    {
		if(ptr->data==a)
        {
        	if(head->next==NULL)
    		{
    			head=NULL;
    			printf("\n\tThe deleted element is :%d\t\n",ptr->data);
    			free(ptr);
    			display_node();
			}
    		else
    		{
        		head=head->next ;
        		printf("\n\tThe deleted element is :%d\t\n",ptr->data);
        		free(ptr);
        		display_node();
    		}
        }
        else
        {
            while(ptr!=NULL) 
			{ 
				if(ptr->data!=a)
				{
					ptr1=ptr; 
					ptr=ptr->next;
					if(ptr==NULL)
                	{
                    	printf("\n\t!!Invalid Value!!\n");
                    	display_node();
                    	return;
               		}
				
				}
				else
				{
            		ptr1->next=ptr->next ;
            		printf("\n\tThe deleted element is:%d\t\n",ptr->data);
            		free(ptr);
            		display_node();
            		return;
        		}
        		
        	}
        }
    }
    //display_node();
}
void search(int b)
{
	int count=1;
	struct node *ptr;
	ptr=head;
	if(head==NULL)
	{
		printf("\n\t!!List is Empty!!\n");
        return;
	}
	else
	{
		while(ptr!=NULL)
		{
			if(ptr->data==b)
			{
				printf("\n\tElement %d is found at position %d\n",b,count);
				return;
			}
			else
			{
				count++;
				ptr=ptr->next;
			}
		}
		printf("\n\tElement %d is not present!!\n",b);
	}
	display_node();
	
}