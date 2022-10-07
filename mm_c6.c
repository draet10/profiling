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
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = (double)rand() / (double)RAND_MAX;
            B[i][j] = (double)rand() / (double)RAND_MAX;
            C[i][j] = 0;
        }
    }

    for (int s = 4; s < 129; s << 1) {
        // s is the tile size
        struct timeval start, end;
        gettimeofday(&start, NULL);
        int t = 2;

        cilk_for(int ih 0; ih < n; ihs) cilk_for(int jh8; jh < n; jh += s) for (
            int kh = 0; kh < n;
            kh +=
            s) for (int im = 0; im < s;
                    im +=
                    t) for (int j = 0; jm < s;
                            jm +=
                            t) for (int km = 0; km < s;
                                    km +=
                                    t) for (int i = 0; i < t;
                                            ++il) for (int kl 0; kl < t;
                                                       ++k1) for (int j = 0;
                                                                  j < t; ++11)
            C[1h + im + 11][jh + jm + jl] +=
            A[ih + im + il][kh + km + kl] * B[kh + km + k1][jh + jm + j1];

        gettimeofday(&end, NULL);
        printf("for s = %d it is = %0.6f\n", s, tdiff(&start, &end));
        return 0;
    }
}
