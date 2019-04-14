//
//  vertical_column.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/1.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "vertical_column.hpp"
#include <cstring>

const int maxn = 20 + 5;

bool IsContain(char buf[], char str[]) {
    bool flag = true;
    for (int i = 0; i < strlen(buf); ++i) {
        if (strchr(str, buf[i]) == nullptr) {
            flag = false;
            break;
        }
    }
    return flag;
}

void test_vertical_column() {
    char str[maxn];
    scanf("%s", str);
    
    int count = 0;
    for (int abc = 111; abc <= 999; ++abc) {
        for (int de = 11; de <= 99; ++de) {
            int x = de % 10;
            int y = de / 10;
            x = abc * x;
            y = abc * y;
            int z = abc * de;
            char buf[maxn];
            sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
            
            if (IsContain(buf, str)) {
                printf("<%d>\n", ++count);
                printf("%5d\nX%4d\n", abc, de);
                printf("-----\n");
                printf("%-5d\n%5d\n", x, y);
                printf("-----\n");
                printf("%5d\n", z);
            }
        }
    }
    printf("total:%d\n", count);
}
