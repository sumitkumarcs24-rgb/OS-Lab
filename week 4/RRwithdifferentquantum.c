#include <stdio.h>

int main() {
    int n, bt[20], rt[20], wt[20], tat[20];
    int i, time = 0, remain, tq, flag = 0;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;
    i = 0;

    while(remain != 0) {
        if(rt[i] <= tq && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if(rt[i] > 0) {
            rt[i] -= tq;
            time += tq;
        }

        if(rt[i] == 0 && flag == 1) {
            remain--;
            tat[i] = time;
            wt[i] = tat[i] - bt[i];
            flag = 0;
        }

        if(i == n - 1)
            i = 0;
        else
            i++;
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", awt/n);
    printf("\nAverage Turnaround Time = %.2f\n", atat/n);

    return 0;
}
