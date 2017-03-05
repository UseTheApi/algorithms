//
//  main.cpp
//  algorithms. BST applications. lowest common ancestor.
//
//  Created by alifar on 11/26/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <lowest_common_ancestor.hpp>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
    cout << "Binary Search Tree. Lowest Common Ancestor" << endl;
    BinarySearchTree<int> tree;
    cout << "Insert integers into Tree: " << endl;
    int item;
    do{
        cin >> item;
        tree.Insert(item);
    } while(cin.get() != '\n');
    cout << "Enter an item for the task: " << endl;
    cin >> item;
    Tnode<int> *n1 = tree.Search(item);
    cout << "Enter an item for the task: " << endl;
    cin >> item;
    Tnode<int> *n2 = tree.Search(item);
    Tnode<int> *result = LowestCommonAncestorRoot(tree.get_root(), n1, n2);
    if(!result){
        cout << "No Common Ancestor Found..." << endl;
        return 0;
    }
    cout << "From Root: " << result->data << endl;

    result = LowestCommonAncestorParent(n1, n2);
    if(!result){
        cout << "No Common Ancestor Found..." << endl;
        return 0;
    }
    cout << "Using Parent Pointer: " <<  result->data << endl;
    return 0;
}
