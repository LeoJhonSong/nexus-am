#include <klib.h>

#define MIN_SIZE 10
#define MAX_SIZE 100
#define SIZE_STEP 10
#define LOOPS 10

float fabs(float x) {
    return x < 0 ? -x : x;
}

void amax(int n, float *x, float *result) {
    *result = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(x[i]) > *result) {
            *result = fabs(x[i]);
        }
    }
}

int main() {
    uint32_t t0, t1;
    float x[MAX_SIZE];
    float result;
    printf("Size\tKFlops\tTime(ms)\n");

    for (int n = MIN_SIZE; n <= MAX_SIZE; n+=SIZE_STEP) {

        double timeg = 0;

        for (int turn = 0; turn < LOOPS; turn++)
        {
            // 随机生成 x
            for (int i = 0; i < n; i++) {
                x[i] = (float)(rand() % 100) / 10.0;
            }

            t0 = uptime();
            amax(n, x, &result);
            t1 = uptime();
            timeg += t1 - t0;
        }
        timeg = timeg / LOOPS;
        
        printf("%d\t%.02f\t%.02f\n", n, 2.0 * (double)n / timeg, timeg);
    }

    return 0;
}