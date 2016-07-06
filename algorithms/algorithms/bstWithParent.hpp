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
    BstNodeWithParent(int);
private:
    BstNodeWithParent();
};

class BstWithParent{
    // the structure should like in binarySearchTree.hpp + parent. But due to short time and small task I leave it like this
public:
    BstNodeWithParent * insert(BstNodeWithParent *, int); // returns new root
    BstNodeWithParent * search(BstNodeWithParent *, int);
    BstNodeWithParent * remove(BstNodeWithParent *, int); // returns new root
    BstNodeWithParent * findMin(BstNodeWithParent *);
    BstWithParent();
    BstNodeWithParent * getRoot();
    void setRoot(BstNodeWithParent *);
private:
    BstNodeWithParent *root;
};


#endif /* bstWithParent_hpp */
