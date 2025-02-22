#include <klib.h>

#define MIN_SIZE 10
#define MAX_SIZE 100
#define SIZE_STEP 10
#define LOOPS 10

void axpy(int n, float a, float *x, float *y, float *result) {
    for (int i = 0; i < n; i++) {
        result[i] = a * x[i] + y[i];
    }
}

int main() {
    uint32_t t0, t1;
    float x[MAX_SIZE];
    float y[MAX_SIZE];
    float result[MAX_SIZE];
    printf("Size\tKFlops\tTime(ms)\n");

    for (int n = MIN_SIZE; n <= MAX_SIZE; n+=SIZE_STEP) {
        float a = (float)(rand() % 100) / 10.0; // 随机生成 a

        double timeg = 0;

        for (int turn = 0; turn < LOOPS; turn++)
        {
            // 随机生成 x 和 y
            for (int i = 0; i < n; i++) {
                x[i] = (float)(rand() % 100) / 10.0;
                y[i] = (float)(rand() % 100) / 10.0;
            }

            t0 = uptime();
            axpy(n, a, x, y, result);
            t1 = uptime();
            timeg += t1 - t0;
        }
        timeg = timeg / LOOPS;
        
        printf("%d\t%.02f\t%.02f\n", n, 2.0 * (double)n / timeg, timeg);
    }

    return 0;
}