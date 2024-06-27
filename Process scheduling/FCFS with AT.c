#include <stdio.h>

struct Process {
    int P_no;
    int at;
    int bt;
} P[100], t;

int main() {
    int n, TAT[100], WT[100], CT[100];
    double AvgTAT = 0, AvgWT = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        P[i].P_no = i;
        printf("\nEnter the Arrival Time and Burst Time of P%d: ", i);
        scanf("%d %d", &P[i].at, &P[i].bt);
    }

    // Sort processes based on Arrival Time using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (P[j].at > P[j + 1].at) {
                t = P[j];
                P[j] = P[j + 1];
                P[j + 1] = t;
            }
        }
    }

    CT[0] = P[0].bt + P[0].at;
    TAT[0] = CT[0] - P[0].at;
    WT[0] = 0;
    AvgTAT = TAT[0];
    AvgWT = WT[0];

    for (int i = 1; i < n; i++) {
        CT[i] = CT[i - 1] + P[i].bt;
        TAT[i] = CT[i] - P[i].at;
        WT[i] = TAT[i] - P[i].bt;
        AvgTAT += TAT[i];
        AvgWT += WT[i];
    }

    AvgTAT /= n;
    AvgWT /= n;

    printf("\nAVERAGE TURNAROUND TIME: %f", AvgTAT);
    printf("\nAVERAGE WAITING TIME: %f", AvgWT);

    return 0;
}