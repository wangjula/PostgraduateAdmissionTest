//
//  uva_133_the_dole_queue.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/24.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_133_the_dole_queue.hpp"

#include <iostream>
#include <iomanip>
using namespace std;
int Go(int *a, int p, int k, int n, int d) {
    while (k--) {
        p = (p + d + n) % n; //模拟循环列表
        while (a[p] == 0) {
            p = (p + d + n) % n;
        }
    }
    return p;
}

int test_uva_133_the_dole_queue() {
    int N, k, m;
    while (cin >> N >> k >> m && N && k && m) {
        int left = N, seq = 0;
        int *a = new int[N];
        for (int i = 0; i < N; ++i) {
            a[i] = i + 1;
        }
        
        int i = -1, j = N;
        while (left != 0) {
            if (seq++ > 0) {
                cout << ",";
            }
            
            i = Go(a, i, k, N, 1);
            j = Go(a, j, m, N, -1);
            if (i != j) {
                left -= 2;
                cout << setw(3) << a[i] << setw(3) << a[j];
                a[i] = a[j] = 0;
            } else {
                --left;
                cout << setw(3) << a[i];
                a[i] = 0;
            }
        }
        cout << endl;
        delete [] a;
    }
	return 0;
}
