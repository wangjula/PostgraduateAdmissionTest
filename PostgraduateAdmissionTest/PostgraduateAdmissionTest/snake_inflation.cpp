//
//  snake_inflation.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/1.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "snake_inflation.hpp"
#include <cstring>



void snake_inflation(int n) {
    static const int maxn = 100 + 5;
    int a[maxn][maxn];
    
    memset(a, 0, sizeof(a));
    int tot = 1, r = 0, c = n - 1;
    
    a[r][c] = tot;
    while (tot < n * n) {
        while (r + 1 < n && a[r+1][c] == 0) {
            a[++r][c] = ++tot;
        }
        while (c - 1 >= 0 && a[r][c-1] == 0) {
            a[r][--c] = ++tot;
        }
        while (r - 1 >= 0 && a[r-1][c] == 0) {
            a[--r][c] = ++tot;
        }
        while (c + 1 < n && a[r][c+1] == 0) {
            a[r][++c] = ++tot;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}

void test_snake_inflation() {
    snake_inflation(5);
}
