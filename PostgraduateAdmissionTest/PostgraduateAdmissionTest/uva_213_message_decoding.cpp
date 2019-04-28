//
//  uva_213_message_decoding.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/28.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_213_message_decoding.hpp"

#include <iostream>
#include <string>
#include <map>
using namespace std;

char ReadChar() {
    char ch = cin.get();
    while (ch == '\n' || ch == '\r') {
        ch = cin.get();
    }
    return ch;
}

int ReadInt(int len) {
    int res = 0;
    for (int i = 0; i < len; ++i) {
        res = res * 2 + ReadChar() - '0';
    }
    return res;
}

int ReadLength() {
    return ReadInt(3);
}

int ReadKey(int len) {
    int key = ReadInt(len);
    if (key == (1 << len) - 1) {
        return -1;
    } else {
        return key;
    }
}

void Decode(map<int, map<int, char>> &m) {
    int len = 0, key = 0;
    while ((len = ReadLength()) != 0) {
        while ((key = ReadKey(len)) != -1) {
            cout << m[len][key];
        }
    }
    cout << endl;
}

void GetMap(map<int, map<int, char>> &m, string &str) {
    int i = 1, len = 0, cnt = 0;
    map<int, char> temp;
    for (;;) {
        len = 1 << i;
        temp.clear();
        for (int j = 0; j < len - 1; ++j) {
            if (cnt == str.length()) {
                m[i] = temp;
                return;
            }
            temp[j] = str[cnt];
            ++cnt;
        }
        m[i] = temp;
        ++i;
    }
}

bool GetHeader(string &str) {
    char ch = cin.peek();
    while (ch == '\n' || ch == '\r') {
        cin.get();
        ch = cin.peek();
    }
    if (getline(cin, str)) {
        return true;
    } else {
        return false;
    }
}

int test_uva_213_message_decoding() {
    string header;
    while (GetHeader(header)) {
        map<int, map<int, char>> m;
        GetMap(m, header);
        Decode(m);
    }
	return 0;
}
