#include <stdio.h>
#include <time.h>

// Función para calcular los tiempos de espera en Round Robin
void findWaitingTimeRR(int processes[], int n, int bt[], int wt[], int quantum) {
    int rem_bt[n];
    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
    }

    int t = 0; // Tiempo actual

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // Aún queda un proceso pendiente
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
}

// Función para calcular el tiempo total de vuelta
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

// Función para calcular los tiempos promedio de espera y de respuesta
void findAvgTime(int processes[], int n, int bt[], int quantum, void (*findWaitingTime)(int[], int, int[], int[], int)) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Calcular tiempos de espera
    findWaitingTime(processes, n, bt, wt, quantum);

    // Calcular tiempos totales de vuelta
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes   Burst time   Waiting time   Turnaround time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

// Función para medir el tiempo de ejecución de los algoritmos
void measureTime(void (*findAvgTime)(int[], int, int[], int, void (*)(int[], int, int[], int[], int)), int processes[], int n, int bt[], int quantum, const char* algorithm_name) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    findAvgTime(processes, n, bt, quantum, findWaitingTimeRR);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución para %s: %f segundos\n", algorithm_name, cpu_time_used);
}

int main() {
    int processes[] = {1, 2, 3, 4, 5};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {10, 5, 8, 6, 2};
    int quantum = 2;

    measureTime(findAvgTime, processes, n, burst_time, quantum, "Round Robin");

    return 0;
}
