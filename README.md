
# Algoritmos de Planificación en Sistemas Operativos

Este proyecto contiene implementaciones de algunos de los algoritmos de planificación de CPU más comunes: **First-Come, First-Served (FCFS)**, **Shortest Job First (SJF)** y **Round Robin (RR)**. Además, se incluye un sistema para medir el rendimiento de cada algoritmo utilizando el tiempo de CPU.

## Algoritmos Implementados

### 1. First-Come, First-Served (FCFS)
El algoritmo **FCFS** ejecuta los procesos en el orden en que llegan. Los procesos que llegan primero son los que se ejecutan primero. Aunque es fácil de implementar, puede llevar a tiempos de espera prolongados, especialmente si un proceso largo llega antes que otros más cortos.

- **Función**: `findAvgTimeFCFS`
- **Entradas**: Procesos, número de procesos, tiempos de ráfaga (burst time).
- **Salida**: Tiempo promedio de espera y turnaround.

### 2. Shortest Job First (SJF) - No Preemptivo
El algoritmo **SJF** selecciona el proceso con el menor tiempo de ejecución estimado (burst time). Minimiza el tiempo promedio de espera, pero requiere conocer o estimar la duración de cada proceso, lo cual puede ser difícil en la práctica.

- **Función**: `findAvgTimeSJF`
- **Entradas**: Procesos, número de procesos, tiempos de ráfaga.
- **Salida**: Tiempo promedio de espera y turnaround.

### 3. Round Robin (RR)
El algoritmo **Round Robin** asigna tiempo de CPU a cada proceso de manera equitativa en intervalos de tiempo fijos (quantums). Si un proceso no se completa dentro del quantum asignado, se pone al final de la cola para esperar su próximo turno. Este algoritmo es justo y funciona bien en sistemas donde los tiempos de respuesta son importantes.

- **Función**: `findAvgTimeRR`
- **Entradas**: Procesos, número de procesos, tiempos de ráfaga y quantum.
- **Salida**: Tiempo promedio de espera y turnaround.

## Prueba de Rendimiento
El archivo incluye una función `measureTime()` que permite medir el tiempo de ejecución de cada algoritmo utilizando la función `clock()` de la biblioteca `time.h`. Esta función mide el tiempo de CPU que toma cada algoritmo en procesar una lista de procesos con tiempos de ráfaga definidos.

- **Función**: `measureTime`
- **Entradas**: Función de planificación (FCFS, SJF, RR), procesos, número de procesos, tiempos de ráfaga y quantum (si es necesario).
- **Salida**: Tiempo de ejecución medido en segundos.

## Compilación y Ejecución

Para compilar y ejecutar el programa en tu sistema, usa un compilador de C (como GCC).

### Instrucciones para compilar y ejecutar:

1. Clonar el repositorio o descargar los archivos.
2. Compilar el programa usando el siguiente comando:

```bash
gcc -o scheduling scheduling.c
```

3. Ejecutar el programa:

```bash
./scheduling
```

### Ejemplo de Salida:

El programa imprimirá el tiempo de ejecución para cada algoritmo en función de los tiempos de ráfaga dados:

```
Tiempo de ejecución para FCFS: 0.000002 segundos
Tiempo de ejecución para SJF: 0.000003 segundos
Tiempo de ejecución para Round Robin: 0.000004 segundos
```

### Modificaciones:

Puedes modificar los tiempos de ráfaga, el número de procesos o el quantum del algoritmo Round Robin directamente en el archivo `main()` para hacer pruebas adicionales.

---


