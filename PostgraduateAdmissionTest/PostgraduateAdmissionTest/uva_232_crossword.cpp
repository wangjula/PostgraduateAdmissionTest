//
//  uva_232_crossword.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/13.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_232_crossword.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int test_uva_232_crossword() {
    int r, c, line = 0;
    while (cin >> r && r != 0) {
        cin >> c;
        vector<string> ss;
        vector<vector<int>> a;
        int num = 0;
        for (int i = 0; i < r; ++i) {
            string matrix;
            cin >> matrix;
            ss.push_back(matrix);
            vector<int> ar;
            a.push_back(ar);
            if (i == 0) {
                for (int j = 0; j < matrix.length(); ++j) {
                    if (matrix[j] != '*') {
                        a[0].push_back(++num);
                    } else {
                        a[0].push_back(-1);
                    }
                }
            } else {
                for (int j = 0; j < matrix.length(); ++j) {
                    if (matrix[j] == '*') {
                        a[i].push_back(-1);
                    } else if (j == 0 || matrix[j-1] == '*' || ss[i-1][j] == '*') {
                        a[i].push_back(++num);
                    } else {
                        a[i].push_back(-2);
                    }
                }
            }
        }
        
        if (line > 0) {
            cout << endl;
        }
        
        cout << "puzzle #" << ++line << ":" << endl;
        cout << "Across" << endl;
        string temp;
        for (int i = 0; i < r; ++i) {
            int j = 0;
            while (j < c) {
                temp.clear();
                num = 0;
                if (a[i][j] > 0) {
                    num = a[i][j];
                    while (j < c && a[i][j] != -1) {
                        temp += ss[i][j];
                        ++j;
                    }
                    cout << setw(3) << num << "." << temp << endl;
                } else {
                    ++j;
                }
            }
        }
        
        cout << "Down" << endl;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                temp.clear();
                num = 0;
                if (a[i][j] > 0 && (i == 0 || a[i-1][j] == -1)) {
                    num = a[i][j];
                    int temp_i = i;
                    while (temp_i < r && a[temp_i][j] != -1) {
                        temp += ss[temp_i][j];
                        ++temp_i;
                    }
                    cout << setw(3)<< num << "." << temp << endl;
                }
            }
        }
    }
	return 0;
}
