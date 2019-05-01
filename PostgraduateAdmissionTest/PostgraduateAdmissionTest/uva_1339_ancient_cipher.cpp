//
//  uva_1339_ancient_cipher.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/5/1.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_1339_ancient_cipher.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int test_uva_1339_ancient_cipher() {
    string enc, ori;
    int let1[26], let2[26];
    while (cin >> enc >> ori) {
        memset(let1, 0, sizeof(let1));
        memset(let2, 0, sizeof(let2));
        for (int i = 0; i < enc.length(); ++i) {
            ++let1[ori[i] - 'A'];
            ++let2[enc[i] - 'A'];
        }
        
        sort(let1, let1 + 26);
        sort(let2, let2 + 26);
        
        bool flag = true;
        for (int i = 0; i < 26; ++i) {
            if (let1[i] != let2[i]) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
	return 0;
}
