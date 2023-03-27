#include <stdio.h>
#define WINDOW_SIZE 5

/*
    移动平均法：这种方法计算一段时间内速度数据的平均值，然后使用平均值代替每个时间点的原始速度数据。
        通过这种方式，可以减少速度数据中的噪声和波动，从而更好地反映整体趋势。
        移动平均法可以使用简单移动平均（SMA）或加权移动平均（WMA）来实现。
*/

int main() {
    // 定义速度数据数组
    float speed[10] = {3.4, 4.2, 4.6, 4.8, 4.7, 4.3, 4.1, 3.9, 3.7, 3.5};
    // 定义速度平均值数组
    float avg_speed[10-WINDOW_SIZE+1] = {0};
    // 定义循环变量
    int i, j;
    // 计算速度平均值
    for (i = 0; i <= 10-WINDOW_SIZE; i++) {
        float sum = 0;
        for (j = i; j < i+WINDOW_SIZE; j++) {
            sum += speed[j];
        }
        avg_speed[i] = sum / WINDOW_SIZE;
    }
    // 输出速度平均值
    printf("average speed:\n");
    for (i = 0; i <= 10-WINDOW_SIZE; i++) {
        printf("%.2f ", avg_speed[i]);
    }
    return 0;
}