#include <stdio.h>
#include <stdlib.h>
/*
    斜率拟合法是一种通过线性回归计算速度数据的趋势的方法。
    其基本思路是利用最小二乘法来计算速度数据的斜率，从而得出数据的趋势。

    根据斜率拟合法的算法思路，我们需要输入两个数组来计算数据的趋势：
    x数组：代表时间或数据点的序列，用于表示数据的时间顺序或数据点的编号。
    在斜率拟合法中，x数组通常表示时间的序列，用于区分不同数据点之间的时间间隔。
    y数组：代表速度数据的序列，用于表示数据点对应的速度数值。
    在斜率拟合法中，y数组通常表示速度数据的序列，用于计算速度数据的趋势。
    举例来说，假设我们想要计算一辆车在行驶过程中的速度趋势，我们可以将x数组表示时间的序列，
    y数组表示速度数据的序列，以秒为单位来表示时间的序列，以米每秒为单位来表示速度数据的序列。
    这样，通过斜率拟合法计算斜率，可以得到速度随时间的变化率，从而得出车辆的速度趋势。
*/


#define N 100

int main()
{
    int i, n;
    double x[N], y[N];
    double sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;
    double slope, intercept;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the data points:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    // Calculate the sum of x, y, x^2, and xy
    for(i = 0; i < n; i++)
    {
        sumx += x[i];
        sumy += y[i];
        sumx2 += x[i] * x[i];
        sumxy += x[i] * y[i];
    }

    // Calculate the slope and intercept
    slope = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    intercept = (sumy - slope * sumx) / n;

    // Print the result
    printf("The slope is: %lf\n", slope);
    printf("The intercept is: %lf\n", intercept);

    return 0;
}