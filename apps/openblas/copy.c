#include <klib.h>

#define MIN_SIZE 10
#define MAX_SIZE 100
#define SIZE_STEP 10
#define LOOPS 10

void copy(int n, float *x, float *y) {
    for (int i = 0; i < n; i++) {
        y[i] = x[i];
    }
}

int main() {
    uint32_t t0, t1;
    float x[MAX_SIZE];
    float y[MAX_SIZE];
    printf("Size\tKB/s\tTime(ms)\n");

    for (int n = MIN_SIZE; n <= MAX_SIZE; n+=SIZE_STEP) {
        double timeg = 0;

        for (int turn = 0; turn < LOOPS; turn++)
        {
            // 随机生成 x
            for (int i = 0; i < n; i++) {
                x[i] = (float)(rand() % 100) / 10.0;
            }

            t0 = uptime();
            copy(n, x, y);
            t1 = uptime();
            timeg += t1 - t0;
        }
        timeg = timeg / LOOPS;
        
        double mbytes = (double)n * sizeof(float) / 1024;
        printf("%d\t%.02f\t%.02f\n", n, mbytes / (timeg / 1000), timeg);
    }

    return 0;
}