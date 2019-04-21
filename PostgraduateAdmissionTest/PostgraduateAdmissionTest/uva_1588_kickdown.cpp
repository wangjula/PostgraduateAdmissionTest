//
//  uva_1588_kickdown.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/21.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_1588_kickdown.hpp"

#include <iostream>
#include <string>
using namespace std;

int Match(string &m, string &d) {
    int j = 0, k = 0, match = 0;
    for (int i = 0; i <= m.length() - d.length(); ++i) { //full match
        j = 0;
        k = i;
        while (j < d.length() && k < m.length()) {
            if (m[k] != '1' && d[j] != '1') {
                break;
            }
            ++j;
            ++k;
        }
        
        if (j == d.length()) { //full match
            match = j;
            break;
        }
    }
    
    if (match != 0) {
        return match;
    }
    
    int rmatch = 0; //right match
    for (int i = (int) (d.length() - 1); i >= 0; --i) {
        k = (int) (m.length() - 1);
        j = i;
        while (j >= 0) {
            if (m[k] != '1' && d[j] != '1') {
                break;
            }
            --j;
            --k;
        }
        if (j == -1) {
            rmatch = i + 1;
            break;
        }
    }
    
    int lmatch = 0;
    for (int i = 0; i < d.length(); ++i) {
        j = i;
        k = 0;
        while (j < d.length() && k < m.length()) {
            if (m[k] != '1' && d[j] != '1') {
                break;
            }
            ++j;
            ++k;
        }
        if (j == d.length()) { //left match
            lmatch = k;
            break;
        }
    }

    return rmatch > lmatch ? rmatch : lmatch;
}

int test_uva_1588_kickdown() {
    string m, d;
    while (cin >> m >> d) {
        int match = 0;
        if (m.length() > d.length()) {
            match = Match(m, d);
        } else {
            match = Match(d, m);
        }
        cout << m.length() + d.length() - match << endl;
    }
	return 0;
}
