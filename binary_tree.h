//  binary_tree.h
//  Header file for CS 223, Lab 8: Binary Search Tree Class
//
//  Barb Wahl & Theresa Wilson, 3-30-18
//
//  In this lab, node objects are linked together to create a binary search
//  tree. The binary_tree class encapsulates the workings of the tree into a
//  single object, instead of just providing "toolkit" functions as in Main
//  & Savitch Ch. 10.
//
//  The only instance variable for binary_tree is a pointer to the root
//  node, `root_ptr`.
//
//    - An empty tree is represented by making root_ptr point to a node of
//      type empty_node.
//
//    - A non-empty tree is represented by making root_ptr point to a node
//      of type normal_node, the root of the desired tree.
//
//  The tree is maintained as a binary search tree, which imposes a logic on
//  the `insert` and `contains` operations.  For a node storing data value K,
//  all the data for nodes in the left subtree are _less_ than K, and all
//  the data for nodes in the right subtree are _greater_ than K. Duplicate
//  values are never stored.
//
//  Because of the recursive structure of the tree, the tree functions are
//  implemented recursively.  A public "wrapper" simply sends the request
//  on to the root node, and conveys the result (if any) back to the caller.
//
//  ALL OF THESE FUNCTIONS (except for the constructors and destructor,
//  of course) are implemented in THREE FORMS:
//    - as tree functions (simple wrapper)
//    - as functions on normal nodes
//    - as functions on empty nodes
//
//  Note:  This is an example of the concept of "polymorphism" (literally,
//   "many forms") in object-oriented design.
//
//  ########### binary_tree class member functions ###########
//
//  binary_tree()
//    Postcondition: The tree is initialized as an empty tree (root points
//      to an empty node).
//
//  binary_tree(std::vector<int> v)
//    Postcondition: The tree holds the data values provided by `v`,
//      inserted into the tree in the order they appear in `v`.
//
//  ~binary_tree()
//     destructor
//
//  bool isEmpty()
//    Postcondition: Return value is `true` if the tree has no stored values;
//      otherwise, return value is `false`.
//
//  bool contains(int val)
//    Postcondition: Return value is `true` if `val` is in the tree; otherwise,
//      return value is `false`.
//
//  void insert(int val)
//    Postcondition: Data value `val` has been inserted into the tree and the
//      size (number of data values in the tree) has increased by 1; but,
//      if an equivalent value was already in the tree, then the tree is
//      unchanged.
//
//  size_t size()
//     Postcondition: Return value is the number of data values stored in
//       the tree.
//
//  int getMax()
//     Precondition: The tree is not empty.
//     Postcondition: Return value is the largest value stored in the tree.
//     Exception: Throws domain_error if called on an empty tree.
//
//  int getMin()
//     Precondition: The tree is not empty.
//     Postcondition: Return value is the smallest value stored in the tree.
//     Exception: Throws domain_error if called on an empty tree.
//
//  int height()
//     Postcondition: Return value is the height (aka depth) of the tree.
//
//  void clear()
//     Postcondition: The tree is empty.
//
//  std::string preorder()
//     Postcondition: Return value is a string for printing the values of the
//       tree according to a pre-order traversal, with a single space, " ",
//       inserted after each value, including the last value.
//     Postcondition: If the binary_tree is empty, the return
//       value is the string "<empty tree>".
//
//  std::string inorder()
//     Postcondition: Return value is a string for printing the values of the
//       tree according to an in-order traversal, with a single space, " ",
//       inserted after each value.  If the tree is empty, the return value
//       is the string "<empty tree>".
//
//  ########## Value Semantics for binary_tree Class ##########
//     The copy constructor and assignment operator are disabled.

/* DO NOT CHANGE THIS FILE! */

#ifndef binary_tree_H
#define binary_tree_H

#include <vector>
#include "node.h"    // provides node, empty_node, normal_node

namespace binary_tree_lab
{
  class binary_tree
  {
  public:
    // CONSTRUCTORS AND DESTRUCTOR
    binary_tree();
    explicit binary_tree(std::vector <int> v);
    ~binary_tree();

    // OTHER MEMBER FUNCTIONS
    bool isEmpty() const;
    bool contains(int val) const;
    void insert(int val);
    size_t size() const;
    int getMax() const;
    int getMin() const;
    int height() const;
    void clear();
    std::string preorder() const;
    std::string inorder() const;

  private:
    // INSTANCE VARIABLES
    node * root_ptr;

    // We disable the copy constructor and assignment operator by declaring
    // them private.

    // NOTE:  This means a binary_tree cannot be sent as a
    // value parameter and cannot be returned as a value.  Both of these
    // operations would trigger the copy constructor or assignment operator.

    // To send a binary_tree object as a parameter, use pass-by-reference.

    // *** Do not implement! ***
    binary_tree(const binary_tree &other);
    binary_tree operator=(const binary_tree &other);
  };

#endif /* binary_tree_H */

}  // namespace binary_tree_lab
