#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

// N deve ser uma potência de 2 (ex: 256, 512, 1024)
#ifndef N
#define N 512
#endif

void fft(double complex *a, int n) {
    if (n <= 1) return;

    // Divisão (Divide and Conquer)
    double complex *even = malloc(n/2 * sizeof(double complex));
    double complex *odd = malloc(n/2 * sizeof(double complex));
    for (int i = 0; i < n/2; i++) {
        even[i] = a[2*i];
        odd[i] = a[2*i+1];
    }

    fft(even, n/2);
    fft(odd, n/2);

    // Conquista (Combine)
    for (int k = 0; k < n/2; k++) {
        double complex t = cexp(-2.0 * I * M_PI * k / n) * odd[k];
        a[k] = even[k] + t;
        a[k + n/2] = even[k] - t;
    }

    free(even);
    free(odd);
}

int main() {
    double complex data[N];
    for (int i = 0; i < N; i++) {
        data[i] = sin(i) + I * cos(i); // Dados de entrada aleatórios
    }

    fft(data, N);
    return 0;
}