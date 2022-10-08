#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct priority_queue{
   int data_pri[MAX][2];
   int front, rear; 
}P_QUEUE;

void initialiseQueue (P_QUEUE *);
void Insert_Queue (P_QUEUE*,int,int);
void Delete_Queue (P_QUEUE*);
void swap(int*,int*);
void initialiseQueue (P_QUEUE *aq){
    aq->front=-1;
    aq->rear=-1;
}

void Insert_Queue(P_QUEUE*aq,int data,int pri){
    if(aq->front==-1 && aq->rear==-1){
        aq->front=0;
        aq->rear=0;
        aq->data_pri[aq->rear][0]=data;
        aq->data_pri[aq->rear][1]=pri;
        printf("Insertion Successful\n");
    }
    else if(aq->front==MAX-1){
        printf("Queue Overflow\n");
    }
    else if(aq->data_pri[aq->rear][1]<pri){
        aq->data_pri[++aq->rear][0]=data;
        aq->data_pri[aq->rear][1]=pri;
        printf("Insertion Successful\n");
    }
    else{
        aq->data_pri[++aq->rear][0]=data;
        aq->data_pri[aq->rear][1]=pri;
        int temp=aq->rear;
        while(temp!=0 && aq->data_pri[temp-1][1]>aq->data_pri[temp][1]){
            swap(&(aq->data_pri[temp][0]),&(aq->data_pri[temp-1][0]));
            swap(&(aq->data_pri[temp][1]),&(aq->data_pri[temp-1][1]));
            temp--;
        }
        printf("Insertion Successful\n");
    }

}

void Delete_Queue(P_QUEUE*aq){
    if(aq->front==-1 && aq->rear==-1)
        printf("Queue Empty\n");
    else if(aq->front==aq->rear){
        printf("Deleted Element: %d\n",aq->data_pri[aq->front][0]);
        initialiseQueue(aq);
    }
    else
        printf("Deleted Element: %d\n",aq->data_pri[aq->front++][0]);   
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

/* void disp(P_QUEUE q){
     int temp=q.front;
     while(1){
         printf("%d ",q.data_pri[temp][0]);
         if(temp==q.rear)
             break;
         temp++;
     }
 }*/

int main(){
    P_QUEUE q;
    int choice,again=1,val,pri;
    initialiseQueue(&q);
      while(again){
        printf("\n***LIST OF CHOICES***\n1: Insert Queue\n2: Delete Queue\n0: exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            again=0;            
            break;
        case 1:
            printf("Input Data: ");
            scanf("%d",&val);
            printf("Enter it's Priority: ");
            scanf("%d",&pri);
            Insert_Queue(&q,val,pri);
            break;
        case 2:
            Delete_Queue(&q);
            break;
        default:
            printf("ERROR: Wrong Input\n");
            break;
        }
    }
    return 0;
}

/*
                   ****Priority Queue Code Logic****

This code will take Input of Element and its (element) Priority in the queue.

Test Case (Priority Queue with 3 elements) 
Sequence of Input as follows

        Element                                Priority
          5                                       2
          7                                       0
          4                                       1

Output Queue will: 7->4->5 ( The queue is made base on Priority)
//  Hence Element with the least priority value will have the most Priority  //

** So on deletion 7 will be deleted first since it has the most priority **

*/