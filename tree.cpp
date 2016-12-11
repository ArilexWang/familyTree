//
//  tree.cpp
//  Family
//
//  Created by Ricardo on 2016/12/8.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include "tree.hpp"

familyTree::familyTree(){
    root = NULL;
}

familyTree::~familyTree(){
    if (root!=NULL) {
        int num = 0;
        destroy(root, num);
        root = NULL;
    }
}

void familyTree::creatTree(){
    string name;
    root = new tree_Node();
    cout << "首先建立一个家谱" << endl <<"请输入祖先的姓名：" ;
    cin >> name;
    root->_name = name;
    cout << "此家谱的祖先是：" << root->_name << endl;
}


bool familyTree::find(tree_Node* p, const string name, bool& isFind, tree_Node*& cur) const{
    if (isFind) {
        return isFind;
    }
    if (!p) {
        cur = NULL;
        return isFind;
    }
    if (p->_name == name) {
        cur = p;
        isFind = true;
        return isFind;
    }
    for (tree_Node* pNode = p->_pFirstChild; pNode; pNode = pNode->_pNextSibling) {
        find(pNode, name, isFind, cur);
        if (isFind) {
         return isFind;
        }
    }
    return isFind;
}

bool familyTree::findNode(string name, tree_Node*& ret){
    bool isFind = false;
    find(root, name, isFind, ret);
    return isFind;
}

void familyTree::creatFamily(){
    string fatherName;
    cout << "请输入要建立家庭的人的姓名：" ;
    cin >> fatherName;
    tree_Node* pFather;
    findNode(fatherName, pFather);
    cout << "请输入" << fatherName << "的儿女人数:";
    int num;
    cin >> num;
    string nextName;
    int curNum = 0;
    tree_Node* cur = pFather;
    tree_Node* newNode;
    cout << "请依次输入" << fatherName << "的儿女的姓名:";
    while (curNum < num) {
        cin >> nextName;
        if (curNum == 0) {
            newNode = new tree_Node(nextName);
            cur->_pFirstChild = newNode;
            cur = newNode;
            curNum++;
        }
        else{
            newNode = new tree_Node(nextName);
            cur->_pNextSibling = newNode;
            cur = newNode;
            curNum++;
        }
    }
    cout << pFather->_name << "的第一代子孙是：";
    cur = pFather->_pFirstChild;
    while (cur) {
        cout << cur->_name << "   ";
        cur = cur->_pNextSibling;
    }
    cout << endl;
}

bool familyTree::addFamilyMember(){
    string fatherName;
    cout << "请输入要添加儿子（女儿）的人的姓名:" ;
    cin >> fatherName;
    tree_Node* pFather;
    if(!findNode(fatherName, pFather)){
        cout << "家谱中没有这个人" << endl;
        return false;
    }
    cout << "请输入" << fatherName << "新添加的儿子（女儿）的名字:";
    string nextName;
    cin >> nextName;
    tree_Node* cur = pFather;
    tree_Node* newNode;
    if (cur->_pFirstChild == NULL) {
        newNode = new tree_Node(nextName);
        cur->_pFirstChild = newNode;
        return true;
    }
    else{
        cur = cur->_pFirstChild;
        while (cur->_pNextSibling) {
            cur = cur->_pNextSibling;
        }
        newNode = new tree_Node(nextName);
        cur->_pNextSibling = newNode;
        return true;
    }
    return false;
}

bool familyTree::dissolveFamily(){
    string fatherName;
    cout << "请输入要解散家庭的人的姓名:";
    cin >> fatherName;
    cout << "要解散家庭的人是：" << fatherName << endl;
    cout << fatherName << "的第一代子孙是:";
    tree_Node* pFather;
    tree_Node* cur,*del;
    if(!findNode(fatherName, pFather)){
        cout << "家谱中没有这个人" << endl;
        return false;
    }
    cur = pFather->_pFirstChild;
    del = cur;
    if (cur == NULL) {
        cout << "无";
        return true;
    }
    else{
        while (cur) {
            cur = cur->_pNextSibling;
            cout << del->_name;
            delete del;
            del = cur;
        }
        pFather->_pFirstChild = NULL;
        cout << endl;
        return true;
    }
    return false;
}

bool familyTree::changeName(){
    string preName,changeName;
    cout << "请输入要更改姓名的人的目前姓名：";
    cin >> preName;
    tree_Node* pPreName;
    if(!findNode(preName, pPreName)){
        cout << "家谱中没有这个人" << endl;
        return false;
    }
    else{
        cout << "请输入更改后的姓名:";
        cin >> changeName;
        pPreName->setName(changeName);
        cout << preName << "以更名为" << changeName << endl;
        return true;
    }
}

void familyTree::destroy(tree_Node* p, int& num){
    if (!p) {
        return;
    }
    destroy(p->_pFirstChild, num);
    destroy(p->_pNextSibling, num);
    delete p;
    num++;
}

void familyTree::destroyTree(){
    int num = 0;
    destroy(root, num);
    root = NULL;
    cout << "销毁了" << num << "个节点" << endl;
}


