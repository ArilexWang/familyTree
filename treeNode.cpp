//
//  treeNode.cpp
//  Family
//
//  Created by Ricardo on 2016/12/8.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include "treeNode.hpp"

tree_Node::tree_Node() : _pFirstChild(nullptr),_pNextSibling(nullptr),_name("-1") {}

tree_Node::tree_Node(tree_Node* pFirstChild,tree_Node* pNextSibling,string name)
: _pFirstChild(pFirstChild), _pNextSibling(pNextSibling), _name(name) {}

tree_Node::tree_Node(string name) : _pFirstChild(nullptr),_pNextSibling(nullptr),_name(name){}

string tree_Node::getName() const{
    return _name;
}

tree_Node* tree_Node::getFirstChild(){
    return _pFirstChild;
}

tree_Node* tree_Node::getNextSibling(){
    return _pNextSibling;
}

void tree_Node::setName(string name){
    _name = name;
}

