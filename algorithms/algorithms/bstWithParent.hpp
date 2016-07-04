//
//  bstWithParent.hpp
//  algorithms
//
//  Created by alifar on 7/4/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#ifndef bstWithParent_hpp
#define bstWithParent_hpp

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
    BstWithParent();
    BstNodeWithParent * getRoot();
    void setRoot(BstNodeWithParent *node);
private:
    BstNodeWithParent *root;
};


#endif /* bstWithParent_hpp */
