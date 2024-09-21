#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    int completed[n];
    for (int i = 0; i < n; i++) completed[i] = 0;

    int current_time = 0, completed_count = 0;

    while (completed_count != n) {
        int min_bt = 1e9, shortest = -1;
        for (int i = 0; i < n; i++) {
            if (!completed[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                shortest = i;
            }
        }

        current_time += bt[shortest];
        wt[shortest] = current_time - bt[shortest];
        completed[shortest] = 1;
        completed_count++;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAvgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d ", (i + 1));
        printf("          %d ", bt[i]);
        printf("            %d ", wt[i]);
        printf("                %d\n", tat[i]);
    }

    printf("\nAverage waiting time = %.2f", (float)total_wt / (float)n);
    printf("\nAverage turnaround time = %.2f\n", (float)total_tat / (float)n);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {6, 8, 7};

    findAvgTime(processes, n, burst_time);
    return 0;
}
