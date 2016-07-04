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
#include "bstWithParent.hpp"

class bstSuccessor: public BstWithParent{
public:
    BstNodeWithParent * findSuccessorByParent(BstNodeWithParent *node);
    BstNodeWithParent * findSuccessorByRoot(BstNodeWithParent *root, BstNodeWithParent *node);
};

#endif /* bstInorderSuccessor_hpp */
