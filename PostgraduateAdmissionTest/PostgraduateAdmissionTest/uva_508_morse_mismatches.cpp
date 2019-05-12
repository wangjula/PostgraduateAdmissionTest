//
//  uva_508_morse_mismatches.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/5/12.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_508_morse_mismatches.hpp"

//这题描述，测试用例问题太多，用了大佬的代码
//https://blog.csdn.net/Good_night_Sion_/article/details/54729973
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

map<char,string> ctom;
map<string,string> mtot;
set<string> rep;

char ch;
string str,mor;
int cmp(string a,string b);

int test_uva_508_morse_mismatches() {
    while(cin >> ch && ch != '*') {
        cin >> mor;
        ctom[ch] = mor;
    }
    
    while(cin >> str && str[0] != '*'){
        mor.clear();
        for(auto be = str.begin(); be!=str.end(); ++be) {
            mor += ctom[*be];
        }
        
        if(mtot.find(mor) == mtot.end()) {
            mtot[mor] = str;
        } else {
            rep.insert(mor);
            if(mtot[mor] > str) {
                mtot[mor] = str;
            }
        }
    }
    
    while(cin >> mor && mor[0] != '*') {
        if(mtot.find(mor) != mtot.end())
            cout << mtot[mor] << (rep.find(mor) == rep.end() ? "\n" : "!\n");
        else{
            auto ans = mtot.begin();
            int k = 0x3f3f3f3f, m;
            for(auto be = mtot.begin(); be != mtot.end(); ++be){
                m = cmp(mor,be->first);
                if(k > m) {
                    k=m;
                    ans=be;
                }
            }
            cout<< ans->second << "?\n";
        }
    }
    ctom.clear();
    mtot.clear();
    rep.clear();
    return 0;
}

int cmp(string a,string b) {
    if(a.size() > b.size())
        swap(a, b);
    if(a != b.substr(0,a.size())) {
        return 0x3f3f3f3f;
    }
    return (int) (b.size()-a.size());
}
