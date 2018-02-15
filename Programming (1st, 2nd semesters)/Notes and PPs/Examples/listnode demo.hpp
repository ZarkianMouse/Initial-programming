
#ifndef LISTNODE_HPP
#define LISTNODE_HPP
//   COPYRIGHT (C) Will Crissey, Jr. 2017  All rights reserved.
// ListNode class-template definition.
// here we need to do a forward declaration of class List
// this says that class (List) exists
// why? so it can be used in the friend declaration

template<typename NODETYPE> class List;

template<typename NODETYPE>
class ListNode
{

// This makes all member functions of our template List friends
// of the corresponding template ListNode
// So now they can access the private members of ListNode objects

   friend class List<NODETYPE>; // make List a friend

public:
// the constructor with initialization section
   explicit ListNode(const NODETYPE& info) // constructor
      : data{info}, nextPtr{nullptr} {}    // Assign null to avoid issues!
// getter
   NODETYPE getData() const {return data;} // return data in node


// contains private members data and nextPtr
private:
   NODETYPE data; // data
   ListNode<NODETYPE> *nextPtr; // pointer to the next ListNode object
};

#endif
