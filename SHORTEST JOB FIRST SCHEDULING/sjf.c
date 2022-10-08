#include <stdio.h>

int p[30],bt[30],tat[30],tot_tat=0,sjf_tat=0,wt[30],tot_wt=0,sjf_wt=0,n;
float awt,avg_tat,avg_wt;
int wt_tat(int *a,int *b);
int swap(int *a,int *b);
int sort();
int main()
{
    int i;

    // read no: of processes
    printf("\nEnter the number of processes : \n");
    scanf("%d",&n);

    // read burst time (for each process n )
    printf("Enter burst time for each process :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    // sort according to burst time
    sort();
    wt_tat(&sjf_tat,&sjf_wt);
    printf("\n\nTotal turn around time = %d",sjf_tat);
    printf("\n\nAverage turn around time = %d",sjf_tat/n);
    printf("\n\nTotal Waiting time = %d",sjf_wt);
    printf("\n\nAverage Waiting time = %d",sjf_wt/n);
}


int sort()
{
	int i,j;

    // for each n process (i)
	for(i=0;i<n;i++)
	{
        // for each next process (j=i+1)
		for(j=i+1;j<n;j++)
		{
            // if bt[i]>bt[j] , swap bt & p 
			if(bt[i]>bt[j])
			{
				swap(&bt[j],&bt[i]);
				swap(&p[j],&p[i]);
			}
		}
	}
	return 0;
}
int swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
	return 0;
}
int wt_tat(int *a,int *b)
{
    int i;
    for(i=0;i<n;i++)
    {
        // for first process tat = bt
        if(i==0)
        tat[i]=bt[i];
        // from next process , new tat = tat +new bt   && total tat will be updated
        else
        tat[i]=tat[i-1]+bt[i];
        tot_tat=tot_tat+tat[i];
    }
    *a=tot_tat;
    // for first process wt=0
    wt[0]=0;
    // from second process , 
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tot_wt=tot_wt+wt[i];
    }
    *b=tot_wt;
    printf("\nProcess\t\tBurst Time\tTurnaround time\t\tWaiting time");
    for(i=0;i<n;i++)
    printf("\nprocess(%d)\t\t%d\t\t%d\t\t%d",p[i],bt[i],tat[i],wt[i]);
    return 0;
}
