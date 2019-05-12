//
//  uva_1590_ip_networks.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/5/11.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_1590_ip_networks.hpp"

#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 1000 + 10;
int ipn[maxn][4];
const int Mask[] = {255, 254, 252, 248, 240, 224, 192, 128, 0};

bool LT(int i, int j) {
    for (int k = 0; k < 4; ++k) {
        if (ipn[i][k] < ipn[j][k]) {
            return true;
        } else if (ipn[i][k] > ipn[j][k]) {
            return false;
        }
    }
    return false;
}

void PrintIP(int ipn[]) {
    cout << ipn[0];
    for (int i = 1; i < 4; i++) {
        cout << "." << ipn[i];
    }
    cout << endl;
}

int test_uva_1590_ip_networks() {
    int m;
    while (cin >> m) {
        memset(ipn, 0, sizeof(ipn));
        int min = 0, max = 0;
        char ch;
        for (int i = 0; i < m; ++i) {
            cin >> ipn[i][0] >> ch >> ipn[i][1] >> ch >> ipn[i][2] >> ch >> ipn[i][3];
            if (LT(i, min)) {
                min = i;
            }
            if (LT(max, i)) {
                max = i;
            }
        }
        
        int ip[4], mask[4];
        memset(ip, 0, sizeof(ip));
        memset(mask, 0, sizeof(mask));
        for (int i = 0; i < 4; ++i) {
            int diff = 0, p = ipn[min][i], q = ipn[max][i];
            for (int j = 1; j <= 8; ++j) {
                if (p % 2 != q % 2) {
                    diff = j;
                }
                p /= 2;
                q /= 2;
            }
            
            mask[i] = Mask[diff];
            ip[i] = ipn[min][i] & mask[i];
            if (diff > 0) {
                break;
            }
        }
        
        PrintIP(ip);
        PrintIP(mask);
    }
    return 0;
}
