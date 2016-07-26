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
    BstNodeWithParent * findSuccessorByParent(BstNodeWithParent *);
    BstNodeWithParent * findSuccessorByRoot(BstNodeWithParent *, BstNodeWithParent *);
};

#endif /* bstInorderSuccessor_hpp */
