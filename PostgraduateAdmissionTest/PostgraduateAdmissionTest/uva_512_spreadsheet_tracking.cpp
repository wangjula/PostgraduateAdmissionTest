//
//  uva_512_spreadsheet_tracking.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/29.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_512_spreadsheet_tracking.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool flag = true;

struct Command {
    string cmd;
    vector<int> p;
};

void InsC(vector<int> &p, int &r, int &c) {
    int sz = p[0], dc = 0;
    for (int i = 1; i <= sz; ++i) {
        if (flag == true && p[i] <= c) {
            ++dc;
        }
    }
    c += dc;
}

void InsR(vector<int> &p, int &r, int &c) {
    int sz = p[0], dr = 0;
    for (int i = 1; i <= sz; ++i) {
        if (flag == true && p[i] <= r) {
            ++dr;
        }
    }
    r += dr;
}

void DelC(vector<int> &p, int &r, int &c) {
    int sz = p[0], dc = 0;
    for (int i = 1; i <= sz; ++i) {
        if (p[i] == c) {
            flag = false;
        }
        if (flag == true && p[i] < c) {
            ++dc;
        }
    }
    c -= dc;
}

void DelR(vector<int> &p, int &r, int &c) {
    int sz = p[0], dr = 0;
    for (int i = 1; i <= sz; ++i) {
        if (p[i] == r) {
            flag = false;
        }
        if (flag == true && p[i] < r) {
            ++dr;
        }
    }
    r -= dr;
}

void Ex(vector<int> &p, int &r, int &c) {
    if (r == p[0] && c == p[1]) {
        r = p[2];
        c = p[3];
    } else if (r == p[2] && c == p[3]) {
        r = p[0];
        c = p[1];
    }
}

void Cmd(vector<Command> &cmds, int &r, int &c) {
    for (int i = 0; i < cmds.size(); ++i) {
        string cmd = cmds[i].cmd;
        if (cmd == "DR") {
            DelR(cmds[i].p, r, c);
        } else if (cmd == "DC") {
            DelC(cmds[i].p, r, c);
        } else if (cmd == "IC") {
            InsC(cmds[i].p, r, c);
        } else if (cmd == "IR") {
            InsR(cmds[i].p, r, c);
        } else if (cmd == "EX") {
            Ex(cmds[i].p, r, c);
        }
    }
}

void Query(int sz, vector<Command> &cmds) {
    int r, c;
    for (int i = 0; i < sz; ++i) {
        cin >> r >> c;
        int r1 = r, c1 = c;
        flag = true;
        Cmd(cmds, r, c);
        if (flag == false) {
            cout << "Cell data in (" << r1 << "," << c1 << ") GONE" << endl;
        } else {
            cout << "Cell data in (" << r1 << "," << c1 << ") moved to (" << r
                 << "," << c << ")"<< endl;
        }
    }
}

int test_uva_512_spreadsheet_tracking() {
    int r, c, line = 0;
    while (cin >> r >> c && r !=0 && c != 0) {
        if (line++ > 0) {
            cout << endl;
        }
        cout << "Spreadsheet #" << line << endl;
        
        vector<Command> cmds;
        vector<int> temp_p;
        Command temp;
        int cmd_cnt = 0, p;
        cin >> cmd_cnt;
        for (int i = 0; i < cmd_cnt; ++i) {
            temp_p.clear();
            cin >> temp.cmd;
            cin >> p;
            temp_p.push_back(p);
            if (temp.cmd == "EX") {
                for (int j = 0; j < 3; ++j) {
                    cin >> p;
                    temp_p.push_back(p);
                }
            } else {
                for (int j = 0; j < temp_p[0]; ++j) {
                    cin >> p;
                    temp_p.push_back(p);
                }
            }
            
            temp.p = temp_p;
            cmds.push_back(temp);
        }
        
        int query_cnt = 0;
        cin >> query_cnt;
        Query(query_cnt, cmds);
    }
	return 0;
}
