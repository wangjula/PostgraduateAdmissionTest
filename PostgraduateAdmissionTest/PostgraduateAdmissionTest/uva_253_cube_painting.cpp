//
//  uva_253_cube_painting.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/5/10.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_253_cube_painting.hpp"

#include <iostream>
#include <string>
using namespace std;

//将不同面翻转到最上，有6种方案，下标映射表示如下：
const int rot[][6] = {{1, 2, 3, 4, 5, 6}, {4, 2, 1, 6, 5, 3}, {3, 2, 6, 1, 5, 4},
    {6, 2, 4, 3, 5, 1}, {2, 6, 3, 4, 1, 5}, {5, 1, 3, 4, 6, 2}};

//4个面水平翻转，每个面依次到正前方，有4种方案，下标映射如下：
//     其中t需要存储选定最上，最下面后其余4个面的下标，用于进行第2次映射
const int rot4[][4] = {{2, 3, 4, 5}, {4, 2, 5, 3}, {3, 5, 2, 4}, {5, 4, 3, 2}};
int GetIndex(int i, int j) {
    return rot[i][j] - 1;
}

int GetIndex4(int t[], int i, int j) {
    return t[rot4[i][j] - 2];
}

int test_uva_253_cube_painting() {
    string temp, cu1, cu2;
    while (cin >> temp) {
        cu1 = temp.substr(0, 6);
        cu2 = temp.substr(6, 6);
        
        int t[4];
        bool flag = false;
        for (int i = 0; i < 6; ++i) { //比较1号，6号面
            if (cu1[0] == cu2[GetIndex(i, 0)] && cu1[5] == cu2[GetIndex(i, 5)]) {
                for (int j = 0; j < 4; ++j) {
                    t[j] = GetIndex(i, j + 1);
                }
                for (int j = 0; j < 4; ++j) { //水平翻转并比较剩余4个面
                    if (cu1[1] == cu2[GetIndex4(t, j, 0)] && cu1[2] == cu2[GetIndex4(t, j, 1)]
                        && cu1[3] == cu2[GetIndex4(t, j, 2)] && cu1[4] == cu2[GetIndex4(t, j, 3)]) {
                        flag = true;
                        break;
                    }
                }
            }
        }
        
        if (flag) {
            cout << "TRUE" << endl;
        } else {
            cout << "FALSE" << endl;
        }
    }
	return 0;
}
