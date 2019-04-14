//
//  convert_decimal.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/3/30.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "convert_decimal.hpp"

const int maxp = 20;

void convert_decimal(int a, int b, int c) {
    char pattern[maxp];
    sprintf(pattern, "%%.%dlf\n", c);
    printf(pattern, c, (double) a / (double) b);
}

void test_convert_decimal() {
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3 && a && b && c) {
        convert_decimal(a, b, c);
    }
}
