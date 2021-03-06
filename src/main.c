#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>
#include "gemm.h"

double gettime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    return tv.tv_sec + 1e-6 * tv.tv_usec;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <size>\n", argv[0]);
        exit(-1);
    }
  
    const int n = atoi(argv[1]);

    double *a = (double *) malloc( n * n * sizeof(double));
    double *b = (double *) malloc( n * n * sizeof(double));
    double *c = (double *) malloc( n * n * sizeof(double));
  
    memset(a, 1, n * n * sizeof(double));
    memset(b, 2, n * n * sizeof(double));
    memset(c, 0, n * n * sizeof(double));
  
    double t = gettime();
    for (int i = 0; i < 100; i++) {
        gemm(n, c, a, b);
    }
    t = gettime() - t;

    printf("%d\t%f\t%E\n", n, t, 100 * 2 * pow(n, 3) / t);

    free(a);
    free(b);
    free(c);

    return 0;
}
