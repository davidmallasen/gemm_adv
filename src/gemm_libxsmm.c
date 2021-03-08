#include "libxsmm.h"

void gemm(int n, double* c, double* a, double* b) {
    const double alpha = 1.0;
    const double beta = 0.0;
    const int lda = n;
    const int ldb = n;
    const int ldc = n;
    
    // Allocate memory for the column-major libxsmm library and assign values
    double* a_ = (double*) malloc(n * n * sizeof(double));
    double* b_ = (double*) malloc(n * n * sizeof(double));
    double* c_ = (double*) malloc(n * n * sizeof(double));
                    
    int i, j;
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            a_[i + n * j] = a[j + n * i];
            b_[i + n * j] = b[j + n * i];
        }
    }

    libxsmm_dgemm(NULL, NULL,
            &n, &n, &n, &alpha, a_, &lda, b_, &ldb, &beta, c_, &ldc);

    // Transpose the result back to row-major order and free memory
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            c[i + n * j] = c_[j + n * i];
        } 
    }

    free(c_);
    free(b_);
    free(a_);
}
