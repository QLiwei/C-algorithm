#include <stdio.h>
/*
    指数平滑法：这种方法是一种递归平滑算法，通过加权平均来计算速度数据的指数平均值。
    指数平滑法可以很好地处理速度数据中的波动，并在不需要存储大量历史数据的情况下捕捉数据趋势。
*/

int main() {
    // 定义速度数据数组
    float speed[10] = {3.4, 4.2, 4.6, 4.8, 4.7, 4.3, 4.1, 3.9, 3.7, 3.5};
    // 定义平滑指数
    float alpha = 0.2;
    // 定义平滑速度数组
    float smoothed_speed[10] = {0};
    // 定义循环变量
    int i;
    // 计算平滑速度
    smoothed_speed[0] = speed[0];
    for (i = 1; i < 10; i++) {
        smoothed_speed[i] = alpha * speed[i] + (1 - alpha) * smoothed_speed[i-1];
    }
    // 输出平滑速度
    printf("Speed of smoothing:\n");
    for (i = 0; i < 10; i++) {
        printf("%.2f\n", smoothed_speed[i]);
    }
    // 判断运动趋势
    if (smoothed_speed[9] > smoothed_speed[8] && smoothed_speed[8] > smoothed_speed[7]) {
        printf("The speed gradually increases\n");
    } else if (smoothed_speed[9] < smoothed_speed[8] && smoothed_speed[8] < smoothed_speed[7]) {
        printf("The speed gradually decreased\n");
    } else {
        printf("Fluctuating or steady speed\n");
    }
    return 0;
}
