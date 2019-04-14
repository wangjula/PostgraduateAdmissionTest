//
//  uva_1586_molar_mass.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/6.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_1586_molar_mass.hpp"
#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
void test_uva_1586_molar_mass() {
    const int maxn = 80 + 5;
    char a[maxn];
    std::map<char, double> m;
    m['C'] = 12.01;
    m['H'] = 1.008;
    m['O'] = 16.00;
    m['N'] = 14.01;
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        double ans = 0;
        fgets(a, maxn - 1, stdin);
        int num = 0;
        char pre;
        for (int j = 0; j < strlen(a); ++j) {
            if (isdigit(a[j])) {
                num = a[j] - '0';
                while (isdigit(a[++j])) {
                    num = num * 10 + (a[j] - '0');
                }
                ans += m[pre] * (num - 1);
                
                if (isalpha(a[j])) {
                    --j;
                }
            } else if (isalpha(a[j])){
                pre = a[j];
                ans += m[pre];
            }
        }
        
        printf("%.3lf\n", ans);
    }
}
