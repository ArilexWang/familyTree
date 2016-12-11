//
//  treeNode.hpp
//  Family
//
//  Created by Ricardo on 2016/12/8.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#ifndef treeNode_hpp
#define treeNode_hpp

#include <stdio.h>
#include <string>

using namespace std;
class tree_Node{
    friend class familyTree;
private:
    tree_Node* _pFirstChild;
    tree_Node* _pNextSibling;
    string _name;
public:
    tree_Node();
    tree_Node(tree_Node* pFirstChild, tree_Node* pNextSilbing, string name);
    tree_Node(string name);
    string getName() const;
    void setName(string name);
    tree_Node* getFirstChild();
    tree_Node* getNextSibling();
};

#endif /* treeNode_hpp */
