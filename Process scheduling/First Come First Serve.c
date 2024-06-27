#include <stdio.h>

#define MAX 10

int main() {
    int n, TAT[MAX], WT[MAX], BT[MAX];
    double AvgTAT = 0, AvgWT = 0;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input the burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Enter the Burst Time of P%d: ", i);
        scanf("%d", &BT[i]);
    }

    // Calculate Turnaround Time (TAT) and Waiting Time (WT) for each process
    TAT[0] = BT[0]; // TAT for first process is its Burst Time
    WT[0] = 0; // WT for first process is 0
    AvgTAT = TAT[0];
    AvgWT = 0;

    for (int i = 1; i < n; i++) {
        TAT[i] = TAT[i-1] + BT[i]; // TAT = cumulative burst times
        WT[i] = TAT[i] - BT[i]; // WT = TAT - current process burst time
        AvgTAT += TAT[i];
        AvgWT += WT[i];
    }

    // Calculate average TAT and WT
    AvgTAT /= n;
    AvgWT /= n;

    // Output the results
    printf("AVERAGE TURNAROUND TIME: %.2f\n", AvgTAT);
    printf("AVERAGE WAITING TIME: %.2f\n", AvgWT);

    return 0;
}