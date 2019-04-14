//
//  uva_1585_score.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/6.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_1585_score.hpp"
#include <cstring>

void test_uva_1585_score() {
    const int maxn = 80 + 5;
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        int tot = 0, sum = 0;
        char a[maxn];
        fgets(a, maxn - 1, stdin);
        for (int j = 0; j < strlen(a); ++j) {
            if (a[j] == 'O') {
                ++sum;
                tot += sum;
            } else {
                sum = 0;
            }
        }
        printf("%d\n", tot);
    }
}
