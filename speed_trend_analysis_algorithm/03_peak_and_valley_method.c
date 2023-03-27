#include <stdio.h>
/*
    峰谷法：峰谷法是一种简单的算法，用于寻找速度数据中的峰值和谷值，并通过它们的位置来确定运动趋势。
    当速度数据逐渐上升时，连续的三个谷值在两个峰值之间，当速度数据逐渐下降时，连续的三个峰值在两个谷值之间。
    通过峰谷法，可以识别速度数据的整体趋势并做出相应的决策。
*/


int main() {
    // 定义速度数据数组
    float speed[10] = {3.4, 4.2, 4.6, 4.8, 4.7, 4.3, 4.1, 3.9, 3.7, 3.5};
    // 定义峰谷数组
    int peaks[10] = {0};
    int valleys[10] = {0};
    // 定义循环变量
    int i;
    // 寻找峰谷
    for (i = 1; i < 9; i++) {
        if (speed[i] > speed[i-1] && speed[i] > speed[i+1]) {
            peaks[i] = 1;
        }
        if (speed[i] < speed[i-1] && speed[i] < speed[i+1]) {
            valleys[i] = 1;
        }
    }
    // 输出峰谷
    printf("peak valley:\n");
    for (i = 0; i < 10; i++) {
        printf("%d %d\n", peaks[i], valleys[i]);
    }
    // 判断运动趋势
    if (peaks[5] == 1 && peaks[6] == 1 && valleys[4] == 1 && valleys[5] == 1 && valleys[6] == 1) {
        printf("The speed gradually increases\n\n");
    } else if (valleys[5] == 1 && valleys[6] == 1 && peaks[5] == 1 && peaks[6] == 1 && peaks[7] == 1) {
        printf("The speed gradually decreased\n");
    } else {
        printf("Fluctuating or steady speed\n");
    }
    return 0;
}
