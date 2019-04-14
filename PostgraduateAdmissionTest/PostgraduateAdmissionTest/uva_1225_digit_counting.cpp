//
//  uva_1225_digit_counting.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/7.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_1225_digit_counting.hpp"
#include <cstdio>
#include <cstring>
int test_uva_1225_digit_counting() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int N, cnt[10], temp;
        memset(cnt, 0, sizeof(cnt));
        
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            temp = i;
            int d = temp % 10;
            ++cnt[d];
            while ((temp /= 10) != 0) {
                d = temp % 10;
                ++cnt[d];
            }
        }
        
        printf("%d", cnt[0]);
        for (int i = 1; i < 10; ++i) {
            printf(" %d", cnt[i]);
        }
        printf("\n");
    }
    return 0;
}
