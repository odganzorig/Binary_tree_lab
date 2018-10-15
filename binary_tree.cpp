/*
*  binary_tree.cpp 
*  Lab 8, CS 223
*
*  Name: Od Ganzorig
*  Date: 04/10/2018
*/


#include <iostream>
#include <string>
#include <vector>
#include "binary_tree.h"  // provides node classes as well as binary_tree

using namespace std;
namespace binary_tree_lab
{

// constructor
// 	Postcondition: The tree is initialized as an empty tree (root points
//      to an empty node).
binary_tree::binary_tree()
{
	root_ptr = new empty_node;
}

//
//	Postcondition: The tree holds the data values provided by `v`,
//      inserted into the tree in the order they appear in `v`.
binary_tree::binary_tree(std::vector<int> v)
{
	root_ptr = new normal_node(v[0]);
	for (size_t i = 1; i < v.size(); i++)
	{
		root_ptr -> insert(v[i]);
	}

}

//destructor
binary_tree::~binary_tree()
{
	clear();
	delete root_ptr;
}

// isEmpty
//	Postcondition: Return value is `true` if the tree has no stored values;
//      otherwise, return value is `false`.
bool binary_tree::isEmpty() const
{
	return root_ptr -> isEmpty();
}

// contains
//	Postcondition: Return value is `true` if `val` is in the tree; otherwise,
//      return value is `false`.
bool binary_tree::contains(int val) const
{
	return root_ptr -> contains(val);
}

// insert
//	Postcondition: Data value `val` has been inserted into the tree and the
//      size (number of data values in the tree) has increased by 1; but,
//      if an equivalent value was already in the tree, then the tree is
//      unchanged.
void binary_tree::insert(int val)
{
	if(isEmpty())
	{
		delete root_ptr;
		root_ptr = new normal_node(val);

	}
	else
	{
		root_ptr -> insert(val);
	}
	
	
}

// size
//	Postcondition: Return value is the number of data values stored in
//       the tree.
size_t binary_tree::size() const
{
	return root_ptr -> size();
}

// getMax
//	Precondition: The tree is not empty.
//     Postcondition: Return value is the largest value stored in the tree.
//     Exception: Throws domain_error if called on an empty tree.
int binary_tree::getMax() const
{
	if(isEmpty())
	{
		throw domain_error("An empty tree!");
	}
	
	return root_ptr -> getMax();
	
}

// getMin
// 	Precondition: The tree is not empty.
//     Postcondition: Return value is the smallest value stored in the tree.
//     Exception: Throws domain_error if called on an empty tree.
int binary_tree::getMin() const
{
	if(isEmpty())
	{
		throw domain_error("An empty tree!");
	}
	
	return root_ptr -> getMin();
	
}

// height
// 	Postcondition: Return value is the height (aka depth) of the tree.
int binary_tree::height() const
{
	return root_ptr -> height();
}

// clear
// 	Postcondition: The tree is empty.
void binary_tree::clear() 
{
	if(!isEmpty())
	{
		root_ptr -> clear();
		delete root_ptr;
		root_ptr = new empty_node;
	}
	
}
 // preorder
// 	Postcondition: Return value is a string for printing the values of the
//       tree according to a pre-order traversal, with a single space, " ",
//       inserted after each value, including the last value.
//     Postcondition: If the binary_tree is empty, the return
//       value is the string "<empty tree>".
std::string binary_tree::preorder() const
{
	if(isEmpty())
	{
		return "<empty tree>";
	}
	return root_ptr -> preorder();
}

// inorder
// 	Postcondition: Return value is a string for printing the values of the
//       tree according to an in-order traversal, with a single space, " ",
//       inserted after each value.  If the tree is empty, the return value
//       is the string "<empty tree>".
std::string binary_tree::inorder() const
{
	if(isEmpty())
	{
		return "<empty tree>";
	}
	return root_ptr -> inorder();
}


} // namespace binary_tree_lab
