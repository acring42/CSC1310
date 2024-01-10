/**********************************************************************
	Title:        BinaryTree.h
	Author:       Austin Ring
	Date Created: 3/29/2021
***********************************************************************/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Pokemon.h"
#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
class BinaryTree{
    private:
        struct TreeNode{
            T value;
            TreeNode *left;
            TreeNode *right;
        };
        TreeNode *root;
    
        void insert(TreeNode *&, TreeNode *&);
        void destroySubTree(TreeNode *);
        void displayInOrder(TreeNode *) const;

    public:
        BinaryTree(){
            root = NULL;
        }
        ~BinaryTree(){
            destroySubTree(root);
        }
        void insertNode(T);
        void displayInOrder() const{
            displayInOrder(root); 
        }
        bool searchNode(T);
};
/////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void BinaryTree<T>::insert(TreeNode *&node, TreeNode *&newNode){
    if (node == nullptr)
        node = newNode;
    else if (*newNode->value < *node->value)
        insert(node->left, newNode);
    else 
        insert(node->right, newNode);
}
/////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void BinaryTree<T>::destroySubTree(TreeNode *node){
    if (node){
       if (node->left)
            destroySubTree(node->left);
       if (node->right)
            destroySubTree(node->right);
       delete node;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void BinaryTree<T>::insertNode(T item){
    TreeNode *newNode = nullptr;

    newNode = new TreeNode;
    newNode->value = item;
    newNode->left = newNode->right = nullptr;
    insert(root, newNode);
}
/////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void BinaryTree<T>::displayInOrder(TreeNode *node) const{
    if (node){
        displayInOrder(node->left);
        cout << *node->value << endl;
        displayInOrder(node->right);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool BinaryTree<T>::searchNode(T item){
    TreeNode *node = root;

    while (node){
        if (*node->value == *item)
            return true;
        else if (*item < *node->value)
            node = node->left;
        else
            node = node->right;
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////
#endif