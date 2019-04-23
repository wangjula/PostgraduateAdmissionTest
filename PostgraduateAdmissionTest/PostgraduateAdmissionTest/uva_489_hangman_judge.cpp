//
//  uva_489_hangman_judge.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/23.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_489_hangman_judge.hpp"

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void Guess(int *p, string & gus, int left) {
    int cnt = 7, index;
    for (int i = 0; i < gus.length(); ++i) {
        index = gus[i] - 'a';
        if (p[index] == 0) {
            --cnt;
            if (cnt == 0) {
                cout << "You lose." << endl;
                return;
            }
        } else {
            --left;
            p[index] = 0;
            if (left == 0) {
                cout << "You win." << endl;
                return;
            }
        }
    }
    cout << "You chickened out." << endl;
}

int test_uva_489_hangman_judge() {
    int rnd = 0;
    int p[26];
    string puz, gus;
    while (cin >> rnd && rnd != -1) {
        cout << "Round " << rnd << endl;
        cin >> puz >> gus;
        memset(p, 0, sizeof(p));
        int left = 0, index = 0;
        for (int i = 0; i < puz.length(); ++i) {
            index = puz[i] - 'a';
            if (p[index] == 0) {
                ++left;
            }
            ++p[index];
        }
        Guess(p, gus, left);
    }
	return 0;
}
