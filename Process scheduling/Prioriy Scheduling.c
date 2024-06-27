#include <stdio.h>
#define MAX 10;

struct process {
    int p_no;
    int pr;
    int bt;
};
int main()
{
    int TAT[100],WT[100],n;
    struct process p[100],temp;
    double avgtt,avgwt;
    printf("Enter number of process");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter burst time of P%d",i);
        scanf("%d",&p[i].bt);
        printf("Enter priority of P%d",i);
        scanf("%d",&p[i].pr);
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].pr>p[j+1].pr)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

 TAT[0]=p[0].bt;
 WT[0]=0;
 avgtt=TAT[0];
 avgwt=0;

 for(int i=0;i<n;i++){
    TAT[i]=TAT[i-1]+p[i].bt;
    WT[i]=TAT[i]-p[i].bt;
    avgtt+=TAT[i];
    avgwt+=WT[i];
 }

 avgtt/=n;
 avgwt/=n;
 printf("AVERAGE TURNAROUND TIME ID %lf",avgtt);
 printf("AVERAGE WAITING TIME IS %lf",avgwt);
 
 return 0;

}