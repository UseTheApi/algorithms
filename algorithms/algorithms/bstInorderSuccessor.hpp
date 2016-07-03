//
//  bstInorderSuccessor.hpp
//  algorithms
//
//  Created by alifar on 7/2/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#ifndef bstInorderSuccessor_hpp
#define bstInorderSuccessor_hpp

#include <stdio.h>

struct BstNodeWithParent {
    int data;
    BstNodeWithParent *left;
    BstNodeWithParent *right;
    BstNodeWithParent *parent;
    BstNodeWithParent(int data);
private:
    BstNodeWithParent();
};

class BstWithParent{
    // the structure should like in binarySearchTree.hpp + parent. But due to short time and small task I leave it like this
public:
    BstNodeWithParent * insert(BstNodeWithParent *root, int data); // returns new root
    BstNodeWithParent * search(BstNodeWithParent *root, int key);
    BstNodeWithParent * remove(BstNodeWithParent* root, int key); // returns new root
    BstNodeWithParent * findMin(BstNodeWithParent *node);
    BstNodeWithParent * findSuccessorByParent(BstNodeWithParent *node);
    BstNodeWithParent * findSuccessorByRoot(BstNodeWithParent *root, BstNodeWithParent *node);
    BstWithParent();
    BstNodeWithParent * getRoot();
    void setRoot(BstNodeWithParent *node);
private:
    BstNodeWithParent *root;
};

#endif /* bstInorderSuccessor_hpp */
