//
//  uva_1368_dna_consensus.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/14.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_1368_dna_consensus.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int T;
    cin >> T;
    map<char, int> atgc;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<string> ss;
        string temp;
        for (int i = 0; i < m; ++i) {
            cin >> temp;
            ss.push_back(temp);
        }
        
        temp.clear();
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            atgc['A'] = 0;
            atgc['C'] = 0;
            atgc['G'] = 0;
            atgc['T'] = 0;
            for (int i = 0; i < m; ++i) {
                ++atgc[ss[i][j]];
            }
            
            char max_key = 'A';
            int max = -1;
            for (map<char, int>::iterator iter = atgc.begin(); iter != atgc.end(); ++iter) {
                if (iter -> second > max) {
                    max = iter -> second;
                    max_key = iter -> first;
                }
            }
            temp += max_key;
            for (int i = 0; i < m; ++i) {
                if (max_key != ss[i][j]) {
                    ++sum;
                }
            }
        }
        cout << temp << endl;
        cout << sum << endl;
    }
	return 0;
}
