#include<stdio.h>
 
 int main()
 
{
    int n, b_time[20], w_time[20], ta_time[20], avw_time=0, avta_time=0, i, j;
    printf("\n Enter total number of processes:");
    scanf("%d",&n);
 
    printf("\n Enter Process Burst Time \n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&b_time[i]);
    }
 
    w_time[0]=0;   
 
    for(i=1; i<n; i++)
    {
        w_time[i]=0;
        for(j=0; j<i; j++)
            w_time[i] += b_time[j];
    }
 
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
 
    for(i=0; i<n; i++)
    {
        ta_time[i] = b_time[i] + w_time[i];
        avw_time += w_time[i];
        avta_time += ta_time[i];
        printf("\nP[%d]\t%d\t%d\t%d",i+1,b_time[i],w_time[i],ta_time[i]);
    }
 
    avw_time/=i;
    avta_time/=i;
    printf("\nAverage Waiting Time:%d",avw_time);
    printf("\nAverage Turnaround Time:%d",avta_time);
 
    return 0;
}