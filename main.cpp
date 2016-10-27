//
//  main.cpp
//  algorithms
//
//  Created by alifar on 6/24/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/* In order to run one of the tests including of appropriate .hpp file is required 
   ex. : #include "factorial_fibonacci.hpp" then comment out section marked TEST: Fibonacci and Factorial DP */


int main(int argc, const char * argv[]) {

// TEST: Lowest Common Ancestor: lowestCommonAncestor.hpp
//    Lca *tree = new Lca();
//    tree->setRoot(tree->insert(tree->getRoot(), 6));
//    tree->setRoot(tree->insert(tree->getRoot(), 7));
//    tree->setRoot(tree->insert(tree->getRoot(), 10));
//    tree->setRoot(tree->insert(tree->getRoot(), 3));
//    tree->setRoot(tree->insert(tree->getRoot(), 4));
//    tree->setRoot(tree->insert(tree->getRoot(), 5));
//    tree->setRoot(tree->insert(tree->getRoot(), 2));
//    
//    BstNodeWithParent *n1 = tree->search(tree->getRoot(), 2);
//    BstNodeWithParent *n2 = tree->search(tree->getRoot(), 5);
//    
//    std::cout << tree->lowestCommonAncesrotRoot(tree->getRoot(), n1, n2)->data << std::endl;
//    std::cout << tree->lowestCommonAncestorParent(n1, n2)->data << std::endl;
   
// TEST: check if trees are equal: equalTree.hpp (+ binarySearchTree.hpp)
//    Bst *tree1 = new Bst();
//    Bst *tree2 = new Bst();
//    tree1->insert(7);
//    tree1->insert(9);
//    tree1->insert(8);
//    tree1->insert(5);
//    tree1->insert(6);
//    
//    tree2->insert(7);
//    tree2->insert(9);
//    tree2->insert(8);
//    tree2->insert(5);
//    tree2->insert(6);
//    
//    std::cout << equalTrees(tree1->getRoot(), tree2->getRoot()) << std::endl; // cout 1 if true, 0 if false
    
// TEST: calculate the longest list of non-related nodes: nonRelativeNodes.hpp (+ binarySearchTree.hpp)
//    Bst *tree = new Bst();
//    tree->insert(7);
//    tree->insert(5);
//    tree->insert(10);
//    tree->insert(6);
//    tree->insert(3);
//    tree->insert(4);
//    tree->insert(1);
//    tree->insert(8);
//    tree->insert(11);
//    tree->insert(9);
//    tree->insert(12);
//    
//    std::vector<Tnode *> non_related_nodes = nonRelativeNodes(tree->getRoot());
//    for(auto it: non_related_nodes){
//        std::cout << it->data << " "; // 10 5 12 9 4 1
//    }
//    std::cout << std::endl;

// TEST: In Order Successor in BST: bstInorderSuccessor.hpp
//    bstSuccessor *tree = new bstSuccessor();
//    tree->setRoot(tree->insert(tree->getRoot(), 5));
//    tree->setRoot(tree->insert(tree->getRoot(), 7));
//    tree->setRoot(tree->insert(tree->getRoot(), 10));
//    tree->setRoot(tree->insert(tree->getRoot(), 3));
//    tree->setRoot(tree->insert(tree->getRoot(), 4));
//    BstNodeWithParent *temp = tree->getRoot()->left->right;
//    std::cout << tree->findSuccessorByParent(temp)->data << std::endl;
//    std::cout << tree->findSuccessorByRoot(tree->getRoot(), temp)->data << std::endl;

// TEST: deletion from BST: bstTraversals.hpp or binarySearchTree.hpp
//    Bst *tree = new Bst();
//    tree->insert(4);
//    tree->insert(6);
//    tree->insert(2);
//    tree->insert(5);
//    tree->insert(8);
//    tree->insert(3);
//    tree->insert(1);
//    std::cout << "Current root:" << tree->getRoot()->data << std::endl;
//    std::cout << "In Order Traversal:" << std::endl;
//    inOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
//    tree->setRoot(tree->remove(4));
//    std::cout << "Current root:" << tree->getRoot()->data << std::endl;
//    std::cout << "In Order Traversal:" << std::endl;
//    inOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
//    tree->setRoot(tree->remove(2));
//    std::cout << "Current root:" << tree->getRoot()->data << std::endl;
//    std::cout << "In Order Traversal:" << std::endl;
//    inOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
//    tree->setRoot(tree->remove(3));
//    std::cout << "Current root:" << tree->getRoot()->data << std::endl;
//    std::cout << "In Order Traversal:" << std::endl;
//    inOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
    
// TEST: BST insertion, search for key, find Min, find min in a subtree: binarySearchTree.hpp or bstTraversals.hpp
//    Bst *tree = new Bst();
//    tree->insert(4);
//    tree->insert(6);
//    tree->insert(2);
//    tree->insert(5);
//    tree->insert(8);
//    tree->insert(3);
//    tree->insert(1);
//    std::cout << tree->search(3)->data << std::endl;
//    std::cout << tree->findMin()->data << std::endl;
//    std::cout << tree->findSubtreeMin(tree->search(6))->data << std::endl;
    
// TEST: BST Traversals: bstTraversals.hpp
//    Bst *tree = new Bst();
//    tree->insert(4);
//    tree->insert(6);
//    tree->insert(2);
//    tree->insert(5);
//    tree->insert(8);
//    tree->insert(3);
//    tree->insert(1);
//    std::cout << "Pre Order Traversal:" << std::endl;
//    preOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
//    std::cout << "In Order Traversal:" << std::endl;
//    inOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
//    std::cout << "Post Order Traversal:" << std::endl;
//    postOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
//    std::cout << "In Order Traversal using Stack:" << std::endl;
//    inOrderTraversalStack(tree->getRoot());
//    std::cout << std::endl;
//    std::cout << "In Order Traversal Morris:" << std::endl;
//    inOrderTraversalNoRecursion(tree->getRoot());
//    std::cout << std::endl;
//    std::cout << "Breadth First Traversal using Queue:" << std::endl;
//    breadthFirstTraversalQueue(tree->getRoot());
//    std::cout << std::endl;
//    std::cout << "Breadth First Traversal using Height:" << std::endl;
//    breadthFirstTraversalHeight(tree->getRoot());
//    std::cout << std::endl;
 
    return 0;
}
