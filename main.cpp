//
//  main.cpp
//  Family
//
//  Created by Ricardo on 2016/12/8.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include <iostream>
#include "tree.hpp"

int main(int argc, const char * argv[]) {
    char handle = '0';
    familyTree tree;
    tree.creatTree();
    while (handle!='E') {
        cout << "请选择要执行的操作：";
        cin >> handle;
        switch (handle) {
            case 'A':
                tree.creatFamily();
                break;
            case 'B':
                tree.addFamilyMember();
                break;
            case 'C':
                {
                    if(!tree.dissolveFamily()){
                        cout << "解散该家庭失败" << endl;
                    }
                    break;
                }
            case 'D':
                {
                    if(!tree.changeName()){
                        cout << "更改姓名失败" << endl;
                    }
                    break;
                }
            default:
                break;
        }
    }
    return 0;
}
