#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;
    printf("Proceso %d se coloca en la cola con tiempo de espera %d\n", processes[0], wt[0]);

    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
        printf("Proceso %d se coloca en la cola con tiempo de espera %d\n", processes[i], wt[i]);
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAvgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Calcular tiempos de espera
    findWaitingTime(processes, n, bt, wt);

    // Calcular tiempos de turnaround
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Mostrar resultados
    printf("\nProcesses  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d ", (i + 1));
        printf("          %d ", bt[i]);
        printf("            %d ", wt[i]);
        printf("                %d\n", tat[i]);
    }

    printf("\nAverage waiting time = %.2f", (float)total_wt / (float)n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / (float)n);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {10, 5, 8};

    // Ejecutar la función para calcular tiempos de espera y turnaround
    findAvgTime(processes, n, burst_time);
    
    return 0;
}
