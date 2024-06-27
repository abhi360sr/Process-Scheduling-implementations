#include <stdio.h>

struct process {
    int P_no;
    int bt;
};

int main() {
    int n, TAT[100], WT[100];
    struct process P[100], temp;
    double AvgTAT = 0, AvgWT = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst times
    for (int i = 0; i < n; i++) {
        P[i].P_no = i;
        printf("Enter the Burst Time of P%d: ", i);
        scanf("%d", &P[i].bt);
    }

    // Sorting processes based on burst time using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (P[j].bt > P[j + 1].bt) {
                temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }

    // Calculating Turnaround Time (TAT) and Waiting Time (WT)
    TAT[0] = P[0].bt;
    WT[0] = 0;
    AvgTAT = TAT[0];
    AvgWT = 0;

    for (int i = 1; i < n; i++) {
        TAT[i] = TAT[i - 1] + P[i].bt;
        WT[i] = TAT[i] - P[i].bt;
        AvgTAT += TAT[i];
        AvgWT += WT[i];
    }

    AvgTAT /= n;
    AvgWT /= n;

    printf("\nAVERAGE TURNAROUND TIME: %.2f", AvgTAT);
    printf("\nAVERAGE WAITING TIME: %.2f", AvgWT);

    return 0;
}