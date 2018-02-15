/*
   COPYRIGHT (C) 2017 Naomi Burhoe (nrb74) All rights reserved.
   Binary Search Tree
   Author.  Naomi Burhoe
            nrb74@zips.uakron.edu
   Version. 1.01 12.01.2017
   Purpose: This program ...
*/
#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include "Treenode.hpp"

// Tree class-template definition
template<typename NODETYPE> class Tree {
public:
   // insert node in Tree
   void insertNode(const NODETYPE& value) {
      insertNodeHelper(&rootPtr, value);
   }

   // begin preorder traversal of Tree
   void preOrderTraversal() const {
      preOrderHelper(rootPtr);
   }

   // begin inorder traversal of Tree
   void inOrderTraversal() const {
      inOrderHelper(rootPtr);
   }

   // begin postorder traversal of Tree
   void postOrderTraversal() const {
      postOrderHelper(rootPtr);
   }

   // get the depth of the tree
   int getDepth() const {
      int totalDepth{0};
      int currentDepth{0};


      determineDepth(rootPtr, &totalDepth, &currentDepth);
      return totalDepth;
   }

   // begin binary search
   TreeNode<NODETYPE>* binaryTreeSearch(int val) const {
      return binarySearchHelper(rootPtr, val);
   }

private:
   TreeNode<NODETYPE>* rootPtr{nullptr};

   // utility function called by insertNode; receives a pointer
   // to a pointer so that the function can modify pointer's value
   void insertNodeHelper(
      TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
      // subtree is empty; create new TreeNode containing value
      if (*ptr == nullptr) {
         *ptr = new TreeNode<NODETYPE>(value);
      }
      else { // subtree is not empty
             // data to insert is less than data in current node
         if (value <= (*ptr)->data) {
            insertNodeHelper(&((*ptr)->leftPtr), value);
         }
         else {
            insertNodeHelper(&((*ptr)->rightPtr), value);
         }
      }
   }

   // utility function to perform preorder traversal of Tree
   void preOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         std::cout << ptr->data << ' '; // process node
         preOrderHelper(ptr->leftPtr); // traverse left subtree
         preOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform inorder traversal of Tree
   void inOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         inOrderHelper(ptr->leftPtr); // traverse left subtree
         std::cout << ptr->data << ' '; // process node
         inOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform postorder traversal of Tree
   void postOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         postOrderHelper(ptr->leftPtr); // traverse left subtree
         postOrderHelper(ptr->rightPtr); // traverse right subtree
         std::cout << ptr->data << ' '; // process node
      }
   }

   // calculate the depth of the tree
   void determineDepth(TreeNode<NODETYPE>* ptr, int &total, int &current) {

      if (ptr != nullptr) {
          current++;

          if (current > total) {
              total = current;
          }

          determineDepth(ptr->leftPtr, total, current);
          determineDepth(ptr->rightPtr, total, current);

          current--;
      }
      return;
   }

   // do a binary search on the Tree
   // from sources i have looked at, this seems the most viable option but I keep
   // getting the error that the way this is structured negates the use of const
   // with the value pointed to by "this" (the ptr?? what is being returned?)
   TreeNode<NODETYPE>* binarySearchHelper(TreeNode<NODETYPE>* ptr, int val){
    if(ptr == nullptr || ptr->data == val)
        return ptr;

    if(ptr->data < val)
        return binarySearchHelper(ptr->rightPtr, val);

    if(ptr->data > val)
        return binarySearchHelper(ptr->leftPtr, val);
   }

};

#endif // TREE_HPP
