//
//  uva_227_puzzle.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/8.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_227_puzzle.hpp"
#include <cstdio>
#include <cstring>

void swap(char (*a)[10], int i1, int j1, int i2, int j2) {
    char temp = a[i1][j1];
    a[i1][j1] = a[i2][j2];
    a[i2][j2] = temp;
}

int test_uva_227_puzzle() {
    const char * NOT_EXIST = "This puzzle has no final configuration.";
    char a[5][10];
    int line = 1;
    while (true) {
        bool flag = true;
        int b_i = -1, b_j = -1;
        
        char ch = getchar();
        while (ch == '\n') {
            ch = getchar();
        }
        
        if (ch == 'Z') {
            return 0;
        }
        
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                while (ch == '\n' && j != 4) {
                    ch = getchar();
                }
                
                if (ch == '\n') {
                    a[i][j] = ' ';
                } else {
                    a[i][j] = ch;
                }
                if (a[i][j] == ' ') {
                    b_i = i;
                    b_j = j;
                }
                ch = getchar();
            }
        }
        
        while (true) {
            while (ch == '\n') {
                ch = getchar();
            }
            
            if (ch == '0') {
                break;
            }
            
            if (ch == 'A') {
                if (b_i - 1 < 0) {
                    flag = false;
                    break;
                }
                swap(a, b_i, b_j, b_i - 1, b_j);
                b_i = b_i - 1;
            } else if (ch == 'B') {
                if (b_i + 1 > 4) {
                    flag = false;
                    break;
                }
                swap(a, b_i, b_j, b_i + 1, b_j);
                b_i = b_i + 1;
            } else if (ch == 'L') {
                if (b_j - 1 < 0) {
                    flag = false;
                    break;
                }
                swap(a, b_i, b_j, b_i, b_j - 1);
                b_j = b_j - 1;
            } else if (ch == 'R') {
                if (b_j + 1 > 4) {
                    flag = false;
                    break;
                }
                swap(a, b_i, b_j, b_i, b_j + 1);
                b_j = b_j + 1;
            }
//            else {
//                flag = false;
//            }
            ch = getchar();
        }
        
        while (ch != '0') {
            ch = getchar();
        }
        
        if (line != 1) {
            printf("\n");
        }
        
        printf("Puzzle #%d:\n", line++);
        if (flag == false) {
            printf("%s\n", NOT_EXIST);
        } else {
            for (int i = 0; i < 5; ++i) {
                printf("%c", a[i][0]);
                for (int j = 1; j < 5; ++j) {
                    printf(" %c", a[i][j]);
                }
                printf("\n");
            }
        }
    }
	return 0;
}
