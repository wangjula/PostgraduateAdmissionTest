//
//  uva_455_periodic_strings.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/7.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_455_periodic_strings.hpp"
#include <cstdio>
#include <cstring>

bool IsPeriodic(char * s, int i, int j, int n) {
    bool flag = true;
    int len = j - i;
    if (n % len != 0) {
        return false;
    }
    
    while (j < n) {
        if (s[i++] != s[j++]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int test_uva_455_periodic_strings() {
    const int maxn = 80 + 5;
    char s[maxn];
    int N;
    scanf("%d", &N);
    getchar();
    while (N--) {
        getchar();
        fgets(s, maxn - 1, stdin);
        int j = 0, n = (int) strlen(s) - 1;
        while (++j < n) {
            if (IsPeriodic(s, 0, j, n)) {
                break;
            }
        }
        printf("%d\n", j);
        if (N > 0) {
            printf("\n");
        }
    }
	return 0;
}
