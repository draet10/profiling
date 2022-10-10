#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define n 4096

double A[n][n];
double B[n][n];
double C[n][n];

float tdiff(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) +
           1e-6 * (end->tv_usec - start->tv_usec);
}

int main(int argc, const char *argv[]) {
    int i, j, k, ih, jh, kh, kl;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            A[i][j] = (double)rand() / (double)RAND_MAX;
            B[i][j] = (double)rand() / (double)RAND_MAX;
            C[i][j] = 0;
        }
    }

    for (s = 4; s < 129; s << 1) {
        // s is the tile size
        struct timeval start, end;
        gettimeofday(&start, NULL);
        cilk_for(ih = 0; ih < n; ih += s) cilk_for(
            jh = 0; jh < n;
            jh += s) for (kh = 0; kh < n;
                          kh += s) for (il = 0; il < s;
                                        ++il) for (kl = 0; kl < s;
                                                   ++kl) for (j = 0; j < s;
                                                              ++jl)
            C[ih + il][jh + jl] += A[ih + il][kh + k1] * B[kh + kl][jh + jl];
        gettimeofday(&end, NULL);
        printf("for s = %d it is = %0.6f\n", s, tdiff(&start, &end));
        return 0;
    }
}
