//
//  base_cpp_io.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/9.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "base_cpp_io.hpp"
#include <iostream>
#include <string>

using namespace std;
void base_cpp_io() {

}

int test_base_cpp_io() {
    string str;
    getline(cin, str);
    cout << str[str.length()-1] << endl;
    str += 'a';
    cout << str[0];
    for (int i = 1; i < str.length(); ++i) {
        cout << " " << str[i];
    }
    cout << endl;
    const char * c_s = str.c_str();
    cout << c_s << endl;
	return 0;
}
