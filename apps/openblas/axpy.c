#include <klib.h>

void axpy(int n, float a, float *x, float *y, float *result) {
    for (int i = 0; i < n; i++) {
        result[i] = a * x[i] + y[i];
    }
}

int main() {
    for (int n = 1; n <= 6; n++) {
        float a = (float)(rand() % 100) / 10.0; // 随机生成 a
        float x[n];
        float y[n];
        float result[n];

        // 随机生成 x 和 y
        for (int i = 0; i < n; i++) {
            x[i] = (float)(rand() % 100) / 10.0;
            y[i] = (float)(rand() % 100) / 10.0;
        }

        axpy(n, a, x, y, result);

        // 打印结果
        printf("n = %d, a = %f\n", n, a);
        printf("x: ");
        for (int i = 0; i < n; i++) {
            printf("%f ", x[i]);
        }
        printf("\n");

        printf("y: ");
        for (int i = 0; i < n; i++) {
            printf("%f ", y[i]);
        }
        printf("\n");

        printf("result: ");
        for (int i = 0; i < n; i++) {
            printf("%f ", result[i]);
        }
        printf("\n\n");
    }

    return 0;
}