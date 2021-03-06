/**
 * @file binarysearchtree.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 3-25-14
 *
 * A binary search tree.
 */

// Specification of ADT Binary Tree
//    Data object: A binary tree T that is either empty or in the form
//                 of a main root with children where a parent can have
//                 at most two children. It is ordered with smaller
//                 items to left and larger items to right
//    Operations: (a scaled-down version)
//       create, destroy, search, insert, remove, find (min, max)

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binarytree.h"
#include "node.h"

class BinarySearchTree: public BinaryTree
{
public:
   //@creates a new binary search tree
   //@post: an empty binary search tree object exists
   //@usage: BinarySearchTree bst;
   BinarySearchTree();

   //@releases memory for a binary search tree
   //@pre: binary search tree object exists
   //@post: binary search tree object does not exist
   //@usage: automatically done at end of scope
   ~BinarySearchTree();

   // *****************************************************************
   // *  pre for all member functions: binary search tree object exists
   // *****************************************************************

   //@searches for a key in a binary search tree object and
   //    retrieves the corresponding item
   //@pre: key has been assigned.
   //@post: theItem contains tkey with rest of the item if
   //    tkey is found in the binary search tree object
   //    else an exception is thrown
   //@usage: bst.Retrieve (item);
   bool Search (const ItemType& theItem) const;

   //@inserts a new item into the binary search tree
   //@pre: newItem has been assigned
   //@post: if the newItem's key is not already in the tree
   //       and there is memory available
   //         then the newItem is added to the tree
   //       else an exception is thrown
   //@usage: bst.Insert(item);
   void Insert (const ItemType& newItem);

   //@deletes an item from the binary search tree
   //@pre: newItem has been assigned
   //@post: if the newItem is found, deletes it.
   //@usage: bst.remove(item);
   void remove (const ItemType& theItem);

   //@finds the minimum item from the binary search tree
   //@pre: binary search tree object exists
   //@post: finds the minimum item.
   //@usage: bst.FindMin();
   ItemType FindMin() const;

   //@finds the maximum item from the binary search tree
   //@pre: binary search tree object exists
   //@post: finds the maximum item.
   //@usage: bst.FindMax();
   ItemType FindMax() const;

protected:  // recursive helper functions
   //@recursively searches (modeling on binary search) for a key
   //@pre: treeptr is assigned. newItem is assigned.
   //@post: searches for tkey in the tree with treeptr's root.
   //    If tkey is found, theItem is the key together with the other
   //    parts of the item. Else an exception is thrown.
   //@usage: retrieveItem (mroot, key, rest);
   bool lookup (Node * treeptr, const ItemType& theItem) const;

   //@pre: treeptr is assigned. newItem is assigned.
   //@post: adds an item to the tree.
   void insertItem (Node *& treeptr, const ItemType& newItem);

   //@pre: treeptr is assigned. theItem is assigned.
   //@post: deletes an item from the tree.
   void removeItem (Node *& treeptr, const ItemType& theItem, Node * treeItem);
 
   //@pre: treeptr is assigned.
   //@post: finds the minimum item.  
   Node * lookforMin(Node * treeptr) const;

   //@pre: treeptr is assigned.
   //@post: finds the maximum item.  
   Node * lookforMax(Node * treeptr) const;

   //@recursively searches (modeling on binary search) for parent node of a key
   //@pre: treeptr is assigned. newItem is assigned.
   //@post: searches for the key in the tree with treeptr's root.
   //    If tkey is found, theItem is the key together with the other
   //    parts of the item. Else an exception is thrown.
   //@usage: findItem (mroot, key, rest);
   Node * findItem(Node * treeptr, const ItemType& theItem) const;

};
#endif
