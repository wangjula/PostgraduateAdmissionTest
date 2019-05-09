//
//  uva_201_squares.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/5/9.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_201_squares.hpp"

#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 10;
int H[maxn][maxn];
int V[maxn][maxn];

//暴力解，也可记录两点连通状态，效率更高
//int side[maxn*maxn][maxn*maxn],n;//side存储边，将二维转为一维存储
//int pos(int x,int y){return y+n*(x-1);}//返回二维点在side中的位置

bool Judge(int r, int c, int sz) {
    for (int i = r; i < r + sz; ++i) {
        if (V[c][i] == 0 || V[c+sz][i] == 0) {
            return false;
        }
    }
    for (int i = c; i < c + sz; ++i) {
        if (H[r][i] == 0 || H[r+sz][i] == 0) {
            return false;
        }
    }
    return true;
}

int Squares(int sz, int n) {
    int cnt = 0;
    for (int i = 1; i + sz <= n; ++i) {
        for (int j = 1; j + sz <= n; ++j) {
            if (Judge(i, j, sz)) {
                ++cnt;
            }
        }
    }
    return cnt;
}

int test_uva_201_squares() {
    int n, m, no = 0;
    while (cin >> n >> m) {
        memset(H, 0, sizeof(H));
        memset(V, 0, sizeof(V));
        
        char t;
        int r, c;
        for (int i = 0; i < m; ++i) {
            cin >> t >> r >> c;
            if (t == 'H') {
                H[r][c] = 1;
            } else if (t == 'V') {
                V[r][c] = 1;
            }
        }
        
        if (no > 0) {
            cout << endl;
            cout << "**********************************" << endl;
            cout << endl;
        }
        
        cout << "Problem #" << ++no << endl << endl;
        bool flag = false;
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            cnt = Squares(i, n);
            if (cnt != 0) {
                cout <<  cnt << " square (s) of size " << i << endl;
                flag = true;
            }
        }
        
        if (flag == false) {
            cout << "No completed squares can be found." << endl;
        }
        
    }
 	return 0;
}
