//
//  uva_1587_box.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/20.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_1587_box.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Pair {
    int x, y;
    Pair(int x1, int y1) {
        if (x1 < y1) {
            x = x1;
            y = y1;
        } else {
            x = y1;
            y = x1;
        }
    }
};

bool Possible(vector<Pair> & g) {
    map<int, int> m;
    for (int i = 0; i < 6; i += 2) {
        ++m[g[i].x];
        ++m[g[i].y];
        ++m[g[i+1].x];
        ++m[g[i+1].y];
        if (g[i].x != g[i+1].x || g[i].y != g[i+1].y) {
            return false;
        }
    }
    
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        if (it -> second % 4 != 0) {
            return false;
        }
    }
    return true;
}

bool Cmp(Pair &p1, Pair &p2) {
    if (p1.x != p2.x) {
        return p1.x < p2.x;
    } else {
        return p1.y < p2.y;
    }
}

int test_uva_1587_box() {
    vector<Pair> g;
    int w, h;
    while (cin >> w >> h) {
        g.clear();
        Pair temp = Pair(w, h);
        g.push_back(temp);
        for (int i = 1; i < 6; ++i) {
            cin >> w >> h;
            Pair temp = Pair(w, h);
            g.push_back(temp);
        }
        
        sort(g.begin(), g.end(), Cmp);
        if (Possible(g)) {
            cout << "POSSIBLE" << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
	return 0;
}
