//
//  print_permutation.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/3/31.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "print_permutation.hpp"

bool hashTable[10] = {false};
int ans[10] = {-1};
int c[10] = {0};

void back_trace(int k, int n) {
    if (k == n) {
        for (int i = 1; i <= n; ++i) {
            printf("%d", ans[i]);
            if ((n > 3 && i == 3) || (n > 6 && i == 6)) {
                printf(" ");
            }
        }
        printf("\n");
        return;
    }
    
    ++k;
    for (int i = 1; i <= n; ++i) {
        if (hashTable[c[i]] == false) {
            ans[k] = c[i]; //填充第k个空格，填满n个才能组成方案
            hashTable[c[i]] = true;
            back_trace(k, n);
            hashTable[c[i]] = false;
        }
    }
}
void test_print_permutation() {
    for (int i = 0; i <= 9; ++i) {
        c[i] = i;
    }
    back_trace(0, 3);
}
