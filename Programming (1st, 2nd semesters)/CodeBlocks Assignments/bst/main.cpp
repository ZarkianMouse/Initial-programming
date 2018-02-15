
// =============================================
// = FIXME problem - binary search tree =
// =============================================
// EXAM PROBLEM PROGRAM
// COPYRIGHT (C)2015 The University of Akron, Department of Computer Science. All rights reserved.
// Instructions: You have one hour to debug the code. Make your changes and resubmit the code in this quiz when completed.
// Refer to the document "The BST FIXME problem", located under UNIT 3 content in Brightspace.
// This document contains the exact output that you must match for your submission to receive full credit.
//
// This program is intended exclusively for use by The University of Akron's Department of Computer Science
// as an in class problem.
//
// THIS PROGRAM'S CONTENT IS PROTECTED
// The code and associated content are either the property of, or used with permission by, The University of Akron,
// Department of Computer Science and may be protected by copyright and other restrictions. Copyrights in the site
// content may also be owned by individuals and entities other than, and in addition to, The University of Akron,
// Department of Computer Science. The use of this code by you, or anyone else authorized by you, is prohibited,
// except for purposes of completing the BST problem. Any unauthorized use of the coding may violate
// copyright laws, trademark laws, the laws of privacy and publicity, and communications regulations and statutes.


// The programmer has left for vacation in a big hurry, and you have been asked to fix this program's error(s)
// The program is poorly documented, not standard, and you will need to analyze the code and resolve the issue or issues that
// you encounter while testing. The program has been corrected once the test case completes and the success message
// wraps up the program (see the correct output). Do not change the test case coding in main. Only correct output yields the points!



#include <cstdlib>
#include <ctime>
#include <iostream>

class Node
{
    public :
  Node* left;
  Node* right;
  Node* next;
  Node** parentConnection;
  int data;

  Node(const int& num) : data(num), left(nullptr), right(nullptr), next(nullptr), parentConnection(nullptr) {};
};

class myTree
{
public:
  Node* root;

  myTree();
  ~myTree();

  void insert(Node* addThis);
  void insert(Node* addThis, Node* subRoot);

  void del(const int&);

  void preorder();
  void preorder(Node* subRoot);

  void inorder();
  void inorder(Node* subRoot);

  void postorder();
  void postorder(Node* subRoot);

  Node* search(const int& num);
  Node* search(Node*, const int&);

  void layerorder();

  void display();
  void display(Node*, const int&);

  void empty();

  Node* findIOP(Node*);
};

myTree::myTree()
{
  root = nullptr;
}

myTree::~myTree()
{}

void myTree::insert(Node* addThis)
{
  if (!root)
  {
    root = addThis;
  root->parentConnection = &root;
  }
  else
    insert(addThis, root);
  }

void myTree::insert(Node* addThis, Node* subRoot)
{
  if (addThis->data <= subRoot->data)
  {

    if (subRoot->left)
    {
      insert(addThis, subRoot->left);
    }
    else
    {
      subRoot->left = addThis;
      subRoot->left->parentConnection = &addThis;
    }
  }
  else
  {
    if (subRoot->right)
    {
      insert(addThis, subRoot->right);
    }
    else
    {
      subRoot->right = addThis;
      subRoot->right->parentConnection = &addThis;
    }
  }
}

void myTree::inorder()
{
  inorder(root); // start the recursion
  std::cout << std::endl;
}

void myTree::inorder(Node* subRoot)
{
  if (!subRoot)
      return;
  inorder(subRoot->left);
  std::cout << subRoot->data << " ";
  inorder(subRoot->right);
}

void myTree::preorder()
{
  preorder(root);
  std::cout << std::endl;
}

void myTree::preorder(Node* subRoot)
{
  if (!subRoot)
    return;
  std::cout << subRoot->data << " ";
  preorder(subRoot->left);
  preorder(subRoot->right);
}

void myTree::postorder()
{
  postorder(root);
  std::cout << std::endl;
}

void myTree::postorder(Node* subRoot)
{
  if (!subRoot)
  return;
  postorder(subRoot->left);
  postorder(subRoot->right);
  std::cout << subRoot->data << " ";
}

void myTree::del(const int& num)
{

  Node* del = search(num);
  if (!del)
    return;
  if (del->left == del->right)
  {
    *(del->parentConnection) = del->right;
  }

  else if (!del->left || !del->right)
  {
    if (del->left)
    {
      *(del->parentConnection) = del->right;
      del->left->parentConnection = del->parentConnection;
    }
    else
    {
      *(del->parentConnection) = del->left;
      del->right->parentConnection = del->parentConnection;
    }
}
else
{
  Node* iop = findIOP(del->left);

  if (iop->left)
  {
      iop->left->parentConnection = iop->parentConnection;
  }
  *(iop->parentConnection) = iop->left;

  iop->left = del->left;

  if (iop->left)
    iop->left->parentConnection = &iop->left;

  iop->right = del->right;
  if (iop->right)
    iop->right->parentConnection = &iop->right;

  *(del->parentConnection) = iop;
  iop->parentConnection = del->parentConnection;

  }
  delete del;
}

Node* myTree::search(const int& num)
{
    Node* node = search(root, num);
    return node;
}

Node* myTree::search(Node* subRoot, const int& num)
{
  if(!subRoot)
    return 0;
  else if (subRoot->data == num)
    return subRoot;
  else if (num < subRoot->data)
    return search(subRoot->left, num);
  return search(subRoot->right, num);
}

void myTree::display()
{
  display(root, 0);
}

void myTree::display(Node* subRoot, const int& indent)
{
  if (!subRoot)
  {
    for (int i = 0; i < indent; ++i)
    std::cout << " ";
    std::cout << "NULL" << std::endl;
  }
  else
  {
    display(subRoot->right, indent + 5);
    for (int i = 0; i < indent; ++i)
      std::cout << " ";
    std::cout << subRoot->data << std::endl;
    display(subRoot->left, indent + 5);
  }
}

Node* myTree::findIOP(Node* subRoot)
{
  if (subRoot && !subRoot->right)
    return subRoot;
  return findIOP(subRoot->right);
}

int main()
{
    std::srand(59);

    // create the tree
    myTree *bst = new myTree();
    int nodeNum;
    //fill the tree
    for (int i = 0; i < 10; ++i)
    {
        nodeNum = std::rand() % 100;
        bst->insert(new Node(nodeNum));
    }

    bst->display();
    std::cout << "********************************************" << std::endl;
    bst->inorder();
    std::cout << "********************************************" << std::endl;
    bst->preorder();
    std::cout << "********************************************" << std::endl;
    bst->postorder();
    std::cout << "********************************************" << std::endl;

    std::cout << "********************************************" << std::endl;
    bst->del(83);

    std::cout << "*********** SUCCESS ****************" << std::endl;
}
