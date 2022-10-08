#include <stdio.h>
struct priority
{
    int p_no;
    int AT, BT, CT, TAT, WT, PP, RT;
};

void sort(struct priority a[20], int n, int val)
{
    int i, j, flag;
    struct priority temp;
    for (i = 1; i < n; i++)
    {
        flag = 0;
        for (j = 0; j < n - i; j++)
        {
            if (val == 1)
            {
                if (a[j].PP > a[j + 1].PP)
                {
                    flag = 1;
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
            else if (val == 2)
            {
                if (a[j].CT > a[j + 1].CT)
                {
                    flag = 1;
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
            else
            {
                if (a[j].p_no > a[j + 1].p_no)
                {
                    flag = 1;
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        if (flag == 0)
            break;
    }
}
int crs[50];
int main()
{
    printf("/*********************************************************************");
    printf("\nAuthor Name     : MUHAMMED AYIMEN ABDUL LATHEEF");
    printf("\nRegister Number : 20419055");
    printf("\nDate            : 17-9-2021  ");
    printf("\nRoll-no         : 55");
    printf("\nAim             : Write a C program to implement Priority scheduling  ");
    printf("\n                  algorithm.(non-preemptive)");
    printf("\n********************************************************************/");
    int i, n, a, temp = 0;
    float WT_avg = 0, TAT_avg = 0;
    struct priority P[50];
    printf("\n\t\t\t\t\tPRIORITY SCHEDULING (NON-PREEMPTIVE)");
    printf("\n\t\t\t\t\t+----------------------------------+");
    printf("\n\nEnter the number of Processes : ");
    scanf("%d", &n);
    printf("\nEnter Arrival Time for Process 1 to %d :\n", n);
    for (i = 0; i < n; i++)
    {
        P[i].p_no = i + 1;
        scanf("%d", &P[i].AT);
    }
    printf("\nEnter Burst Time for Process 1 to %d :\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &P[i].BT);
    }
    printf("\nEnter Priorities for Process 1 to %d :\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &P[i].PP);
    }
    a = n;
    sort(P, n, 1);

    while (a)
    {
        for (i = 0; i < n; i++)
        {
            if (P[i].AT <= temp && crs[i] == 0)
            {

                temp += P[i].BT;
                P[i].CT = temp;
                a--;
                crs[i] = 1;
                break;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        P[i].TAT = P[i].CT - P[i].AT;
        TAT_avg += P[i].TAT;
        P[i].WT = P[i].TAT - P[i].BT;
        WT_avg += P[i].WT;
    }
    WT_avg /= n;
    TAT_avg /= n;

    sort(P, n, 2);
    P[0].RT = 0;
    for (i = 1; i < n; i++)
        P[i].RT = P[i - 1].CT - P[i].AT;

    printf("\n+-----+----------+----------- --+------------+-----------------+--------------+-----------------+---------------+\n");
    printf("| PID | Priority | Arrival Time | Burst Time | Completion Time | Waiting Time | Turnaround Time | Response Time |\n");
    printf("+-----+----------+--------------+------------+-----------------+--------------+-----------------+---------------+\n");

    sort(P, n, 3);
    for (i = 0; i < n; i++)
    {
        printf("| P%d  |    %2d    |      %2d      |     %2d     |        %2d       |      %2d      |        %2d       |       %2d      |\n", P[i].p_no, P[i].PP, P[i].AT, P[i].BT, P[i].CT, P[i].WT, P[i].TAT, P[i].RT);
        puts("+-----+----------+--------------+------------+-----------------+--------------+-----------------+---------------+");
    }

    printf("\nAverage Waiting Time    : %.2f\n\n", WT_avg);
    printf("Average Turnaround Time : %.2f\n\n", TAT_avg);
}