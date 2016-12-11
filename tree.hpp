//
//  tree.hpp
//  Family
//
//  Created by Ricardo on 2016/12/8.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>
#include <iostream>
#include "treeNode.hpp"

class familyTree{
private:
    tree_Node* root;
private:
    bool find(tree_Node* p,const string name,bool& isFind,tree_Node*& cur) const;
    bool findNode(string name,tree_Node*& ret);
public:
    familyTree();
    ~familyTree();
    void creatTree();
    void creatFamily();
    bool addFamilyMember();
    bool dissolveFamily();
    bool changeName();
    void destroyTree();
    void destroy(tree_Node* p,int& num);
};

#endif /* tree_hpp */
