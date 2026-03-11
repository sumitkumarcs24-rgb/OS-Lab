#include <stdio.h>

int main() {
    int n, bt[10], pr[10], rt[10], wt[10], tat[10];
    int time = 0, remain, i, highest;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Burst Time and Priority for P%d: ", i+1);
        scanf("%d %d", &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    remain = n;

    while(remain != 0) {
        highest = 0;

        for(i = 1; i < n; i++) {
            if(pr[i] < pr[highest] && rt[i] > 0)
                highest = i;
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0) {
            remain--;

            tat[highest] = time;
            wt[highest] = tat[highest] - bt[highest];

            awt += wt[highest];
            atat += tat[highest];
        }
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", i+1, bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", awt/n);
    printf("\nAverage Turnaround Time = %.2f", atat/n);

    return 0;
}
