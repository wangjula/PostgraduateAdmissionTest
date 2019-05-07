//
//  uva_1589_xiangqi.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/5/7.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_1589_xiangqi.hpp"

#include <iostream>
#include <cstring>
using namespace std;

const int hx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int hy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int hidx[] = {-1, -1, 0, 0, 0, 0, 1, 1};
const int hidy[] = {0, 0, -1, 1, -1, 1, 1, 1};
int maze[11][10];
int bx, by, rx, ry;

struct Killer {
    char type;
    int x, y;
};
Killer k[7];

int Count(int st, int ed, int c, int d) {
    int max, min;
    if (st > ed) {
        max = st;
        min = ed;
    } else {
        max = ed;
        min = st;
    }
    
    int cnt = 0;
    if (d == 0) { //同在竖线上
        for (int i = min + 1; i < max; ++i) {
            if ((i != bx || c != by) && maze[i][c] != 0) {
                ++cnt;
            }
        }
    } else {
        for (int i = min + 1; i < max; ++i) {
            if ((i != by || c != bx) && maze[c][i] != 0) {
                ++cnt;
            }
        }
    }
    return cnt;
}

bool CheckG(int x, int y, int i) {
    if (k[i].y == y && Count(x, k[i].x, y, 0) == 0) {
        return true;
    }
    return false;
}

bool CheckR(int x, int y, int i) {
    if (y == k[i].y && x == k[i].x) { //只有车吃掉有可能破除死局
        return false;
    }
    
    if (y == k[i].y && Count(x, k[i].x, y, 0) == 0) {
        return true;
    }
    if (x == k[i].x && Count(y, k[i].y, x, 1) == 0) {
        return true;
    }
    return false;
}

bool CheckC(int x, int y, int i) {
    if (y == k[i].y && Count(x, k[i].x, y, 0) == 1) {
        return true;
    }
    if (x == k[i].x && Count(y, k[i].y, x, 1) == 1) {
        return true;
    }
    return false;
}

bool Border(int x, int y) {
    return x < 1 || x > 3 || y < 4 || y > 6;
}

bool Hider(int x, int y) {
    return maze[x][y] != 0;
}

bool CheckH(int x, int y, int i) {
    for (int j = 0; j < 8; ++j) {
        int nx = k[i].x + hx[j];
        int ny = k[i].y + hy[j];
        if (!Border(nx, ny) && !Hider(k[i].x + hidx[j], k[i].y + hidy[j])) { //检查8个落点
            if (nx == x && ny == y) {
                return true;
            }
        }
    }
    return false;
}

bool Check(int x, int y, int n) {
    if (Border(x, y)) {
        return true;
    }
    
    for (int i = 0; i < n; ++i) {
        bool flag1 = k[i].type == 'G' && CheckG(x, y, i);
        bool flag2 = k[i].type == 'H' && CheckH(x, y, i);
        bool flag3 = k[i].type == 'C' && CheckC(x, y, i);
        bool flag4 = k[i].type == 'R' && CheckR(x, y, i);
        if (flag1 || flag2 || flag3 || flag4) {
            return true;
        }
    }
    
    return false;
}

bool CheckWin(int n) {
    if (ry == by && Count(rx, bx, by, 0) == 0) {
        return true;
    }
    return false;
}

int test_uva_1589_xiangqi() {
    Killer temp;
    int n;
    while (cin >> n >> bx >> by && n != 0 && bx != 0 && by != 0) {
        memset(maze, 0, sizeof(maze));
        for (int i = 0; i < n; ++i) {
            cin >> temp.type >> temp.x >> temp.y;
            if (temp.type == 'G') {
                rx = temp.x;
                ry = temp.y;
            }
            k[i] = temp;
        }
        
        for (int i = 0; i < n; ++i) {
            maze[k[i].x][k[i].y] = 1;
        }
        
        bool win = CheckWin(n);
        if (win) {
            cout << "NO" << endl;
            continue;
        }
        
        bool flag1 = Check(bx + 1, by, n);
        bool flag2 = Check(bx - 1, by, n);
        bool flag3 = Check(bx, by + 1, n);
        bool flag4 = Check(bx, by - 1, n);
        bool lose = flag1 && flag2 && flag3 && flag4;
        
        if (lose) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
	return 0;
}
