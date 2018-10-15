// FILE: Rec_node_tests.cpp
// CS 223 Winter 2018, Lab 8
// Node tests for a binary tree class
//
// Name:
// Date:

#include <sstream>
#include <iostream>
#include <cstdlib>
#include "node.h"  // provides empty_node, normal_node
#include "gtest/gtest.h"  // declares the testing framework

using namespace std;
using namespace binary_tree_lab;

namespace
{

/* TESTING PLAN:

TestEmptyNode (4)
   - isEmpty_and_clear
   - isLeaf_and_contains
   - size_and_height
   - preorder_and_inorder

   Note: empty_node::insert is tested along with normal_node::insert

TestNormalNodeConstructor
   - check_data_and_empty_subtrees

Test_insert_and_size
   - insert_into_empty_node
   - insert_into_left_subtree_of_size_one_tree
   - insert_into_right_subtree_of_size_one_tree
   - inserting_duplicate_has_no_effect
   - insert_5_3_2_4_8_7_9_6_in_that_order

Test_getMax_getMin
   - size_one_tree      << NOT PROVIDED
   - size_two_tree      << NOT PROVIDED
   - size_three_tree    << NOT PROVIDED
   - size_eight_tree    << NOT PROVIDED

Test_contains
   - size_one_tree      << NOT PROVIDED
   - size_two_tree      << NOT PROVIDED
   - size_three_tree    << NOT PROVIDED
   - size_eight_tree    << NOT PROVIDED

Test_isEmpty_isLeaf
   - size_one_tree
   - size_two_tree
   - size_three_tree
   - size_eight_tree

Test_height_and_clear
   - size_one_tree
   - size_two_tree
   - size_three_tree_height_one
   - size_three_tree_height_two
   - size_eight_tree

Test_preorder
   - size_one_tree                << NOT PROVIDED
   - size_two_tree                << NOT PROVIDED
   - size_three_tree_height_one   << NOT PROVIDED
   - size_three_tree_height_two   << NOT PROVIDED
   - size_eight_tree              << NOT PROVIDED

Test_inorder
   - size_one_tree
   - size_two_tree
   - size_three_tree_height_one
   - size_three_tree_height_two
   - size_eight_tree

*/

   TEST(TestEmptyNode, isEmpty_and_clear)
   {
      empty_node e1;
      EXPECT_TRUE(e1.isEmpty());
      e1.clear();
      EXPECT_TRUE(e1.isEmpty());
   }

   TEST(TestEmptyNode, isLeaf_and_contains)
   {
      empty_node e1;
      EXPECT_FALSE(e1.isLeaf());
      EXPECT_FALSE(e1.contains(0));
      EXPECT_FALSE(e1.contains(1));
      EXPECT_FALSE(e1.contains(2));
      EXPECT_FALSE(e1.contains(3));
   }

   TEST(TestEmptyNode, size_and_height)
   {
      empty_node e1;
      EXPECT_EQ(e1.size(), 0);
      EXPECT_EQ(e1.height(), -1);
   }

   TEST(TestEmptyNode, preorder_and_inorder)
   {
      empty_node e1;
      EXPECT_EQ(e1.preorder(), "");
      EXPECT_EQ(e1.inorder(), "");
   }

   TEST(TestNormalNodeConstructor, check_data_and_empty_subtrees)
   {
      normal_node n1(5);
      EXPECT_EQ(n1.getData(), 5);
      EXPECT_TRUE(n1.getLeft() -> isEmpty());
      EXPECT_TRUE(n1.getRight() -> isEmpty());
   }

   // Test_insert_and_size
   // - insert_into_empty_node
   // - insert_into_left_subtree_of_size_one_tree
   // - insert_into_right_subtree_of_size_one_tree
   // - inserting_duplicate_has_no_effect
   // - insert_5_3_2_4_8_7_9_6_in_that_order

   TEST(Test_insert_and_size, insert_into_empty_node)
   {
      empty_node e1;
      node * ptr = e1.insert(5);
      EXPECT_EQ(ptr -> getData(), 5);
      EXPECT_TRUE(ptr -> getLeft() -> isEmpty());
      EXPECT_TRUE(ptr -> getRight() -> isEmpty());
      EXPECT_EQ(ptr -> size(), 1);
      EXPECT_EQ(e1.size(), 0);
      delete ptr;
   }

   TEST(Test_insert_and_size, insert_into_left_subtree_of_size_one_tree)
   {
      normal_node n1(5);
      node * ptr1 = &n1;
      node * ptr2 = n1.insert(2);
      EXPECT_EQ(ptr1, ptr2);
      EXPECT_EQ(ptr1 -> getData(), 5);
      EXPECT_EQ(ptr1 -> getLeft() -> getData(), 2);
      EXPECT_TRUE(ptr1 -> getRight() -> isEmpty());
      EXPECT_EQ(n1.size(), 2);
      EXPECT_EQ(n1.getLeft() -> size(), 1);
   }

   TEST(Test_insert_and_size, insert_into_right_subtree_of_size_one_tree)
   {
      normal_node n1(5);
      node * ptr1 = &n1;
      node * ptr2 = n1.insert(8);
      EXPECT_EQ(ptr1, ptr2);
      EXPECT_EQ(ptr1 -> getData(), 5);
      EXPECT_EQ(ptr1 -> getRight() -> getData(), 8);
      EXPECT_TRUE(ptr1 -> getLeft() -> isEmpty());
      EXPECT_EQ(n1.size(), 2);
      EXPECT_EQ(n1.getRight() -> size(), 1);
   }

   TEST(Test_insert_and_size, inserting_duplicate_has_no_effect)
   {
      normal_node n1(5);
      n1.insert(2);
      n1.insert(8);
      // root value is 5, left tree holds 2, right tree holds 8
      node * ptr = n1.insert(5);
      EXPECT_EQ(ptr, &n1);
      EXPECT_EQ(n1.getData(), 5);
      EXPECT_EQ(n1.getLeft() -> getData(), 2);
      EXPECT_EQ(n1.getRight() -> getData(), 8);
      EXPECT_EQ(n1.size(), 3);
   }

   TEST(Test_insert_and_size, insert_5_3_2_4_8_7_9_6_in_that_order)
   {
      empty_node e1;
      node * ptr = e1.insert(5);
      ptr -> insert(3);
      EXPECT_EQ(ptr -> getLeft() -> getData(), 3);
      ptr -> insert(2);
      EXPECT_EQ(ptr -> getLeft() -> getLeft() -> getData(), 2);
      ptr -> insert(4);
      EXPECT_EQ(ptr -> getLeft() -> getRight() -> getData(), 4);
      ptr -> insert(8);
      EXPECT_EQ(ptr -> getRight() -> getData(), 8);
      ptr -> insert(7);
      EXPECT_EQ(ptr -> getRight() -> getLeft() -> getData(), 7);
      ptr -> insert(9);
      EXPECT_EQ(ptr -> getRight() -> getRight() -> getData(), 9);
      ptr -> insert(6);
      EXPECT_EQ(ptr -> getRight() -> getLeft() -> getLeft() -> getData(), 6);
      EXPECT_EQ(ptr -> size(), 8);
      EXPECT_EQ(ptr -> getLeft() -> size(), 3);
      EXPECT_EQ(ptr -> getRight() -> size(), 4);
      delete ptr;
   }

   // Test_getMax_getMin
   //    - size_one_tree      << NOT PROVIDED
   //    - size_two_tree      << NOT PROVIDED
   //    - size_three_tree    << NOT PROVIDED
   //    - size_eight_tree    << NOT PROVIDED

   TEST(Test_getMax_getMin, size_one_tree)
   {
      normal_node n1(5);
      EXPECT_EQ(n1.getMax(), 5);
      EXPECT_EQ(n1.getMin(), 5);
   }

   TEST(Test_getMax_getMin, size_two_tree)
   {
      normal_node n1(5);
      n1.insert(2);
      EXPECT_EQ(n1.getMax(), 5);
      EXPECT_EQ(n1.getMin(), 2);
      EXPECT_EQ(n1.size(), 2);
   }

   TEST(Test_getMax_getMin, size_three_tree)
   {
      normal_node n1(5);
      n1.insert(2);
      n1.insert(8);
      EXPECT_EQ(n1.getMax(), 8);
      EXPECT_EQ(n1.getMin(), 2);
      EXPECT_EQ(n1.size(), 3);
   }

   TEST(Test_getMax_getMin, size_eight_tree)
   {
      normal_node n1(8);
      n1.insert(5);
      n1.insert(9);
      n1.insert(7);
      n1.insert(6);
      n1.insert(4);
      n1.insert(10);
      n1.insert(11);
      EXPECT_EQ(n1.getMax(), 11);
      EXPECT_EQ(n1.getMin(), 4);
      EXPECT_EQ(n1.size(), 8);
   }

   // Test_contains
   //    - size_one_tree      << NOT PROVIDED
   //    - size_two_tree      << NOT PROVIDED
   //    - size_three_tree    << NOT PROVIDED
   //    - size_eight_tree    << NOT PROVIDED

   TEST(Test_contains, size_one_tree)
   {
      normal_node n1(5);
      EXPECT_TRUE(n1.contains(5));
      EXPECT_FALSE(n1.contains(4));
      EXPECT_FALSE(n1.contains(1));
   }

   TEST(Test_contains, size_two_tree)
   {
      normal_node n1(5);
      n1.insert(2);
      EXPECT_TRUE(n1.contains(5));
      EXPECT_TRUE(n1.contains(2));
      EXPECT_FALSE(n1.contains(4));
      EXPECT_FALSE(n1.contains(1));
      EXPECT_EQ(n1.size(), 2);
   }

   TEST(Test_contains, size_three_tree)
   {
      normal_node n1(5);
      n1.insert(2);
      n1.insert(8);
      EXPECT_TRUE(n1.contains(5));
      EXPECT_TRUE(n1.contains(2));
      EXPECT_TRUE(n1.contains(8));
      EXPECT_FALSE(n1.contains(4));
      EXPECT_FALSE(n1.contains(1));
      EXPECT_EQ(n1.size(), 3);
   }

   TEST(Test_contains, size_eight_tree)
   {
     normal_node n1(8);
      n1.insert(5);
      n1.insert(9);
      n1.insert(7);
      n1.insert(6);
      n1.insert(4);
      n1.insert(10);
      n1.insert(11);
      EXPECT_TRUE(n1.contains(5));
      EXPECT_TRUE(n1.contains(9));
      EXPECT_TRUE(n1.contains(8));
      EXPECT_TRUE(n1.contains(7));
      EXPECT_TRUE(n1.contains(6));
      EXPECT_TRUE(n1.contains(4));
      EXPECT_TRUE(n1.contains(10));
      EXPECT_TRUE(n1.contains(11));
      EXPECT_FALSE(n1.contains(2));
      EXPECT_FALSE(n1.contains(1));
      EXPECT_EQ(n1.size(), 8);
   }

   // Test_isEmpty_isLeaf
   //    - size_one_tree
   //    - size_two_tree
   //    - size_three_tree
   //    - size_eight_tree

   TEST(Test_isEmpty_isLeaf, size_one_tree)
   {
      normal_node n1(5);
      EXPECT_FALSE(n1.isEmpty());
      EXPECT_TRUE(n1.isLeaf());
   }

   TEST(Test_isEmpty_isLeaf, size_two_tree)
   {
      normal_node n1(5);
      n1.insert(2);
      EXPECT_FALSE(n1.isEmpty());
      EXPECT_FALSE(n1.isLeaf());
      EXPECT_FALSE(n1.getLeft() -> isEmpty());
      EXPECT_TRUE(n1.getLeft() -> isLeaf());
   }

   TEST(Test_isEmpty_isLeaf, size_three_tree)
   {
      normal_node n1(5);
      n1.insert(2);
      n1.insert(8);
      EXPECT_FALSE(n1.isEmpty());
      EXPECT_FALSE(n1.isLeaf());
      EXPECT_FALSE(n1.getRight() -> isEmpty());
      EXPECT_TRUE(n1.getRight() -> isLeaf());
   }

   TEST(Test_isEmpty_isLeaf, size_eight_tree)
   {
      empty_node e1;
      node * ptr = e1.insert(5);
      ptr -> insert(3);
      ptr -> insert(2);
      ptr -> insert(4);
      ptr -> insert(8);
      ptr -> insert(7);
      ptr -> insert(9);
      ptr -> insert(6);
      EXPECT_FALSE(ptr -> isEmpty());
      EXPECT_FALSE(ptr -> isLeaf());
      node* ptr_to_2 = ptr -> getLeft() -> getLeft();
      ASSERT_TRUE(ptr_to_2 -> getData() == 2);
      EXPECT_TRUE(ptr_to_2 -> isLeaf());
      node* ptr_to_3 = ptr -> getLeft();
      ASSERT_TRUE(ptr_to_3 -> getData() == 3);
      EXPECT_FALSE(ptr_to_3 -> isLeaf());
      node* ptr_to_4 = ptr -> getLeft() -> getRight();
      ASSERT_TRUE(ptr_to_4 -> getData() == 4);
      EXPECT_TRUE(ptr_to_4 -> isLeaf());
      node* ptr_to_8 = ptr -> getRight();
      ASSERT_TRUE(ptr_to_8 -> getData() == 8);
      EXPECT_FALSE(ptr_to_8 -> isLeaf());
      node* ptr_to_7 = ptr -> getRight() -> getLeft();
      ASSERT_TRUE(ptr_to_7 -> getData() == 7);
      EXPECT_FALSE(ptr_to_7 -> isLeaf());
      node* ptr_to_6 = ptr -> getRight() -> getLeft() -> getLeft();
      ASSERT_TRUE(ptr_to_6 -> getData() == 6);
      EXPECT_TRUE(ptr_to_6 -> isLeaf());
      node* ptr_to_9 = ptr -> getRight() -> getRight();
      ASSERT_TRUE(ptr_to_9 -> getData() == 9);
      EXPECT_TRUE(ptr_to_9 -> isLeaf());
      delete ptr;
   }

   // Test_height_and_clear
   //    - size_one_tree
   //    - size_two_tree
   //    - size_three_tree_height_one
   //    - size_eight_tree_height_two

   TEST(Test_height_and_clear, size_one_tree)
   {
      normal_node n1(5);
      EXPECT_EQ(n1.height(), 0);
      n1.clear();
      EXPECT_TRUE(n1.isLeaf());
   }

   TEST(Test_height_and_clear, size_two_tree)
   {
      normal_node n1(5);
      n1.insert(2);
      EXPECT_EQ(n1.height(), 1);
      n1.clear();
      EXPECT_TRUE(n1.isLeaf());
   }

   TEST(Test_height_and_clear, size_three_tree_height_one)
   {
      normal_node n1(5);
      n1.insert(2);
      n1.insert(8);
      EXPECT_EQ(n1.height(), 1);
      n1.clear();
      EXPECT_TRUE(n1.isLeaf());
   }

   TEST(Test_height_and_clear, size_three_tree_height_two)
   {
      normal_node n1(5);
      n1.insert(2);
      n1.insert(3);
      EXPECT_EQ(n1.height(), 2);
      n1.clear();
      EXPECT_TRUE(n1.isLeaf());
   }

   TEST(Test_height_and_clear, size_eight_tree)
   {
      empty_node e1;
      node * ptr = e1.insert(5);
      ptr -> insert(3);
      ptr -> insert(2);
      ptr -> insert(4);
      ptr -> insert(8);
      ptr -> insert(7);
      ptr -> insert(9);
      ptr -> insert(6);
      EXPECT_EQ(ptr -> height(), 3);
      ptr -> clear();
      EXPECT_TRUE(ptr -> isLeaf());
      delete ptr;
   }

   // Test_preorder
   //    - size_one_tree                << NOT PROVIDED
   //    - size_two_tree                << NOT PROVIDED
   //    - size_three_tree_height_one   << NOT PROVIDED
   //    - size_three_tree_height_two   << NOT PROVIDED
   //    - size_eight_tree              << NOT PROVIDED

   TEST(Test_preorder, size_one_tree)
   {
      normal_node n1(5);
      string correct = "5 ";
      string actual = n1.preorder();
      EXPECT_EQ(correct, actual);
   }

   TEST(Test_preorder, size_two_tree)
   {
      normal_node n1(5);
      n1.insert(2);
      string correct = "5 2 ";
      string actual = n1.preorder();
      EXPECT_EQ(correct, actual);
   }

   TEST(Test_preorder, size_three_tree_height_one)
   {
      normal_node n1(5);
      n1.insert(2);
      n1.insert(8);

      string correct = "5 2 8 ";
      string actual = n1.preorder();
      EXPECT_EQ(correct, actual);
   }

   TEST(Test_preorder, size_three_tree_height_two)
   {
      normal_node n1(5);
      n1.insert(2);
      n1.insert(3);

      string correct = "5 2 3 ";
      string actual = n1.preorder();
      EXPECT_EQ(correct, actual);
   }

   TEST(Test_preorder, size_eight_tree)
   {
      empty_node e1;
      node * ptr = e1.insert(5);
      ptr -> insert(3);
      ptr -> insert(2);
      ptr -> insert(4);
      ptr -> insert(8);
      ptr -> insert(7);
      ptr -> insert(9);
      ptr -> insert(6);

      string correct = "5 3 2 4 8 7 6 9 ";
      string actual = ptr -> preorder();
      EXPECT_EQ(correct, actual);
      delete ptr;
   }

   // Test_inorder
   //    - size_one_tree
   //    - size_two_tree
   //    - size_three_tree_height_one
   //    - size_three_tree_height_two
   //    - size_eight_tree

   TEST(Test_inorder, size_one_tree)
   {
      normal_node n1(5);
      string correct = "5 ";
      string actual = n1.inorder();
      EXPECT_EQ(correct, actual);
   }

   TEST(Test_inorder, size_two_tree)
   {
      normal_node n1(5);
      n1.insert(2);
      string correct = "2 5 ";
      string actual = n1.inorder();
      EXPECT_EQ(correct, actual);
   }

   TEST(Test_inorder, size_three_tree_height_one)
   {
      normal_node n1(5);
      n1.insert(2);
      n1.insert(8);

      string correct = "2 5 8 ";
      string actual = n1.inorder();
      EXPECT_EQ(correct, actual);
   }

   TEST(Test_inorder, size_three_tree_height_two)
   {
      normal_node n1(5);
      n1.insert(2);
      n1.insert(3);

      string correct = "2 3 5 ";
      string actual = n1.inorder();
      EXPECT_EQ(correct, actual);
   }

   TEST(Test_inorder, size_eight_tree)
   {
      empty_node e1;
      node * ptr = e1.insert(5);
      ptr -> insert(3);
      ptr -> insert(2);
      ptr -> insert(4);
      ptr -> insert(8);
      ptr -> insert(7);
      ptr -> insert(9);
      ptr -> insert(6);

      string correct = "2 3 4 5 6 7 8 9 ";
      string actual = ptr -> inorder();
      EXPECT_EQ(correct, actual);
      delete ptr;
   }
} // namespace

// main() for testing -- boilerplate
int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
