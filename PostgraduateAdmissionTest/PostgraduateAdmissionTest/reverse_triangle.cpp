//
//  reverse_triangle.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/3/30.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "reverse_triangle.hpp"

void reverse_triangle(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            printf(" ");
        }
        for (int j = 0; j < 2 * (n - i) - 1; ++j) {
            printf("#");
        }
        printf("\n");
    }
}

void test_reverse_triangle() {
    reverse_triangle(5);
}
