//
//  sum_subsequence.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/3/30.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "sum_subsequence.hpp"
void sum_subsequence(int n, int m) {
    double sum = 0.0;
    for (int i = n; i <= m; ++i) {
        sum += 1 / ((double) i * (double) i);
    }
    printf("%.5lf\n", sum);
}

void test_sum_subsequence() {
    int n, m;
    while (scanf("%d%d", &n, &m) == 2 && n && m) {
        sum_subsequence(n, m);
    }
}
