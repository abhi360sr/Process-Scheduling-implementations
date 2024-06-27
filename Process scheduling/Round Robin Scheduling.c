#include <stdio.h>

#define MAX 10

int n, ts = 0, complete = 0, time = 0, TAT[MAX], WT[MAX], BT[MAX], rem_BT[MAX];

int main() {

    double AvgTAT = 0, AvgWT = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the Time Slice: ");
    scanf("%d", &ts);

    for (int i = 0; i < n; i++) {
        printf("Enter the Burst Time of P%d: ", i + 1);
        scanf("%d", &BT[i]);
        rem_BT[i] = BT[i];
    }

    while (complete != n) {
        for (int i = 0; i < n; i++) {
            if (rem_BT[i] > 0) {
                if (rem_BT[i] > ts) {
                    rem_BT[i] -= ts;
                    time += ts;
                } else {
                    time += rem_BT[i];
                    TAT[i] = time;
                    rem_BT[i] = 0;
                    complete++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        WT[i] = TAT[i] - BT[i];
        AvgTAT += TAT[i];
        AvgWT += WT[i];
    }

    AvgTAT /= n;
    AvgWT /= n;

    printf("\nAVERAGE TURNAROUND TIME: %.3f", AvgTAT);
    printf("\nAVERAGE WAITING TIME: %.3f", AvgWT);

    return 0;
}