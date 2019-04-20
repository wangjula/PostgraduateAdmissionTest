//
//  uva_10340_all_in_all.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/20.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_10340_all_in_all.hpp"

#include<iostream>
#include<string>
using namespace std;
int test_uva_10340_all_in_all() {
    string s, t;
    while (cin >> s >> t) {
        int i, j;
        i = j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j++]) {
                ++i;
            }
        }
        if (i == s.length()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
	return 0;
}
