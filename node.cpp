/*
*  FILE: node.cpp
*  CS 223 Winter 2018, Lab 8
*
*  Student Name: Od Ganzorig
*  Date: 04/03/2018
*     
*/

#include <iostream>
#include <sstream>
#include "node.h"   // provides node, empty_node, normal_node

using namespace std;

namespace binary_tree_lab

{

// ########### empty_node implementations ###########

// isEmpty
//   Postcondition: Returns `true` if the tree whose root is this node
//     has no stored data values; otherwise, returns `false`.
bool empty_node::isEmpty() const
{
	return true;
}

// clear
//   Postcondition: The node is empty.
void empty_node::clear()
{

}

// isLeaf
//   Postcondition: Returns `true` if this is a leaf node, otherwise
//     returns `false`.
//   Hint: An empty node is not a leaf node.
bool empty_node::isLeaf() const
{
	return false;
}

// contains
//   Postcondition: Returns `true` if the tree whose root is this node
//     contains the item `val`; otherwise, returns `false`.
bool empty_node::contains(int val) const
{
	return false;
}

// insert
//   Postcondition: Stores `val` in a new normal_node and returns a
//     pointer to that new node.
node * empty_node::insert(int val)
{
	node* temp = new normal_node(val);
	return temp;
}

// size
//   Postcondition: Returns the size (number of stored values) in the
//     tree rooted at this node.
size_t empty_node::size() const
{
	return 0;
}

// height
//   Postcondition: Returns the height of the tree rooted at this node.
//   Hint: How do we define the height of an empty tree?
int empty_node::height() const
{
	return -1;
}

// preorder
//   Postcondition: Returns the empty string.
//   Note: When traversing a tree, empty nodes are not reported.
std::string empty_node::preorder() const
{
	return "";
}

// inorder
//   Postcondition: Returns the empty string.
//   Note: When traversing a tree, empty nodes are not reported.
std::string empty_node::inorder() const
{
	return "";
}







// ########### normal_node implementations ###########

// normal_node node constructor
//   Initializes a leaf node.
//   Postcondition: The new node is a normal_node with data equal to
//     `val` and two empty subtrees.
normal_node::normal_node(int val)
{
	data = val;
	left = new empty_node;
	right = new empty_node;
}

// destructor
//   Deallocates memory for all descendants of this node.
normal_node::~normal_node()
{
	clear();
	delete left;
	delete right;
}

// isEmpty
//   Postcondition: Returns `true` if the tree whose root is this node
//     has no stored data values; otherwise, returns `false`.
bool normal_node::isEmpty() const
{
	return false;
}

// insert in a normal_node
//   Postcondition: Returns a pointer to this node.
//   Postcondition: `val` is an item in the tree rooted at this node.
//   Postcondition: The tree rooted at this node is still in binary-
//      search-tree order.
//
//   Implementation notes:
//     - If this node is already holding the value `val`, insert does
//       nothing but return the `this` pointer.
//     - Otherwise, depending on how `val` compares with the data
//       in this node, insert makes a recursive call to insert `val`
//       on either the left- or right-subtree of this node and returns
//       the `this` pointer.
//     - ** Duplicate values will not be inserted! **
node * normal_node::insert(int val)
{
	node* temp;
	if(val < data)
	{
		temp = (left -> insert(val));
		if (left -> isEmpty())
		{
			delete left;
		}
		left = temp;
	}
	else if(val > data)
	{
		temp = (right -> insert(val));
		if(right -> isEmpty())
		{
			delete right;
		}
		right = temp;
	}
	return this;
}

// size
//   Postcondition: Returns the size (number of stored values) in the
//     tree rooted at this node.
//   Implementation note:  Use recursive divide-and-conquer.
size_t normal_node::size() const
{
	// int leftn = (left -> size());
	// int rightn = (right -> size());
	// return (leftn + rightn) + 1;
	int leftn = left -> size();
	int rightn = right -> size();
	return (leftn + rightn)+1;
}

// getMax
//   Postcondition: Returns the largest item from the tree rooted at
//     this node.
int normal_node::getMax() const
{
	if(right -> isEmpty())
	{
		return data;
	}
	return right -> getMax();
	
}

// getMin
//   Postcondition: Returns the smallest item from the tree rooted at
//     this node.
int normal_node::getMin() const
{
	if(left -> isEmpty())
	{
		return data;
	}
	return left -> getMin();
}

// contains
//   Postcondition: Returns `true` if the tree whose root is this node
//     contains the item `val`; otherwise, returns `false`.
//
//   Hint: Similar logic to `insert(val)`.
bool normal_node::contains(int val) const
{
	if(val < data)
	{
		return left -> contains(val);
	}
	else if(val > data)
	{
		return right -> contains(val);
	}
	return true;
}

// isLeaf
//   Postcondition: Returns `true` if this node has empty left- and
//    right-subtrees; otherwise, returns `false`.
bool normal_node::isLeaf() const
{
	return (right -> isEmpty() && left -> isEmpty());
}

// height
//   Postcondition: Returns the height of the tree rooted at this node.
//   Implementation note:  Use recursive divide-and-conquer.
int normal_node::height() const
{
	int height1 = right -> height() + 1;
	int height2 = left -> height() + 1;
	if(height1 > height2)
		return height1;
	return height2;
}

// clear
//   Postcondition: This node is a leaf.
//   Implementation note:  Use recursive divide-and-conquer.
void normal_node::clear()
{

	if(!isLeaf())
	{
		right -> clear();
		left -> clear();
	}
	delete left;
	delete right;
	left = new empty_node();
	right = new empty_node();

}

// preorder
//   Prints the items in the tree rooted at the current node,
//     using a preorder traversal (root, left, right) and separating
//     the items with a single space.
std::string normal_node::preorder() const
{
	stringstream ss;
	ss << data << " " << left -> preorder() << right -> preorder();
	return ss.str();
}

// inorder for normal node
//   Prints the items in the tree rooted at the current node,
//     using an inorder traversal (left, root, right) and separating
//     the items with a single space.
std::string normal_node::inorder() const
{
	stringstream ss;
	ss << left -> inorder() << data << " " << right -> inorder();
	return ss.str();
}

} // namespace binary_tree_lab 