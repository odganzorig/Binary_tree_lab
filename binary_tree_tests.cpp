// FILE: binary_tree_tests.cpp
// CS 223 Winter 2018, Lab 8
// Tree tests for a binary tree class
//
// Barb Wahl & Theresa Wilson, 4-3-18

#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "binary_tree.h"  // provides both node classes, plus tree class
#include "gtest/gtest.h"  // declares the testing framework

using namespace std;
using namespace binary_tree_lab;

namespace
{

   /* TESTING PLAN:

   TestDefaultConstructor_isEmpty
      - construct_empty_tree

   TestSecondConstructor_contains_isEmpty
      - size_one_tree
      - size_two_tree
      - size_three_tree
      - size_eight_tree

   Test_insert_and_size
      - empty_tree_size_zero
      - insert_into_empty_tree
      - insert_into_left_subtree_of_size_one_tree
      - insert_into_right_subtree_of_size_one_tree
      - inserting_duplicate_has_no_effect
      - insert_5_3_2_4_8_7_9_6_in_that_order

   Test_getMax_getMin
      - size_one_tree
      - size_two_tree
      - size_three_tree
      - size_eight_tree
      - exception_thrown_getMax_of_empty_tree
      - exception_thrown_getMin_of_empty_tree

   Test_height_and_clear
      - empty_tree
      - size_one_tree
      - size_two_tree
      - size_three_tree_height_one
      - size_three_tree_height_two
      - size_eight_tree

   Test_preorder
      - empty_tree
      - size_one_tree
      - size_two_tree
      - size_three_tree_height_one
      - size_three_tree_height_two
      - size_eight_tree

   Test_inorder
      - empty_tree
      - size_one_tree
      - size_two_tree
      - size_three_tree_height_one
      - size_three_tree_height_two
      - size_eight_tree
   */

   // TestDefaultConstructor_isEmpty
   //    - construct_empty_tree

   TEST(TestDefaultConstructor_isEmpty, construct_empty_tree)
   {
      binary_tree t1;
      EXPECT_TRUE(t1.isEmpty());
   }

   // TestSecondConstructor_contains_isEmpty
   //    - size_one_tree
   //    - size_two_tree
   //    - size_three_tree
   //    - size_eight_tree

   TEST(TestSecondConstructor_contains_isEmpty, size_one_tree)
   {
      vector <int> v;
      v.push_back(5);
      binary_tree t1(v);
      EXPECT_TRUE(t1.contains(5));
      EXPECT_FALSE(t1.contains(4));
      EXPECT_FALSE(t1.contains(6));
      EXPECT_FALSE(t1.isEmpty());
   }

   TEST(TestSecondConstructor_contains_isEmpty, size_two_tree)
   {
      vector <int> v;
      v.push_back(5);
      v.push_back(2);
      binary_tree t1(v);
      EXPECT_TRUE(t1.contains(5));
      EXPECT_TRUE(t1.contains(2));
      EXPECT_FALSE(t1.contains(1));
      EXPECT_FALSE(t1.contains(3));
      EXPECT_FALSE(t1.isEmpty());
   }

   TEST(TestSecondConstructor_contains_isEmpty, size_three_tree)
   {
      vector <int> v;
      v.push_back(5);
      v.push_back(2);
      v.push_back(8);
      binary_tree t1(v);
      EXPECT_TRUE(t1.contains(5));
      EXPECT_TRUE(t1.contains(2));
      EXPECT_TRUE(t1.contains(8));
      EXPECT_FALSE(t1.contains(7));
      EXPECT_FALSE(t1.contains(9));
      EXPECT_FALSE(t1.isEmpty());
   }

   TEST(TestSecondConstructor_contains_isEmpty, size_eight_tree)
   {
      vector <int> v;
      v.push_back(5);
      v.push_back(3);
      v.push_back(4);
      v.push_back(8);
      v.push_back(2);
      v.push_back(9);
      v.push_back(6);
      v.push_back(7);
      binary_tree t1(v);
      for (int i = 2; i < 10; i++)
      {
         EXPECT_TRUE(t1.contains(i));
      }
      EXPECT_FALSE(t1.isEmpty());
   }

   // Test_insert_and_size
   //    - empty_tree_size_zero
   //    - insert_into_empty_tree
   //    - insert_into_left_subtree_of_size_one_tree
   //    - insert_into_right_subtree_of_size_one_tree
   //    - inserting_duplicate_has_no_effect
   //    - insert_5_3_2_4_8_7_9_6_in_that_order

   TEST(Test_insert_and_size, empty_tree_size_zero)
   {
      binary_tree t1;
      EXPECT_EQ(t1.size(), 0);
   }

   TEST(Test_insert_and_size, insert_into_empty_tree)
   {
      binary_tree t1;
      t1.insert(5);
      EXPECT_EQ(t1.size(), 1);
   }

   TEST(Test_insert_and_size, insert_into_left_subtree_of_size_one_tree)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(2);
      EXPECT_EQ(t1.size(), 2);
   }

   TEST(Test_insert_and_size, insert_into_right_subtree_of_size_one_tree)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(8);
      EXPECT_EQ(t1.size(), 2);
   }

   TEST(Test_insert_and_size, inserting_duplicate_has_no_effect)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(7);
      t1.insert(3);
      t1.insert(4);
      t1.insert(6);
      for (int i = 3; i < 8; i++)
      {
         t1.insert(i);
         EXPECT_EQ(t1.size(), 5);
      }
   }

   TEST(Test_insert_and_size, insert_5_3_2_4_8_7_9_6_in_that_order)
   {
      binary_tree t1;
      t1.insert(5);
      EXPECT_EQ(t1.size(), 1);
      t1.insert(3);
      EXPECT_EQ(t1.size(), 2);
      t1.insert(2);
      EXPECT_EQ(t1.size(), 3);
      t1.insert(4);
      EXPECT_EQ(t1.size(), 4);
      t1.insert(8);
      EXPECT_EQ(t1.size(), 5);
      t1.insert(7);
      EXPECT_EQ(t1.size(), 6);
      t1.insert(9);
      EXPECT_EQ(t1.size(), 7);
      t1.insert(6);
      EXPECT_EQ(t1.size(), 8);
   }

   // Test_getMax_getMin
   //    - size_one_tree
   //    - size_two_tree
   //    - size_three_tree
   //    - size_eight_tree
   //    - exception_thrown_getMax_of_empty_tree
   //    - exception_thrown_getMin_of_empty_tree

   TEST(Test_getMax_getMin, size_one_tree)
   {
      binary_tree t1;
      t1.insert(5);
      EXPECT_EQ(t1.getMax(), 5);
      EXPECT_EQ(t1.getMin(), 5);
   }

   TEST(Test_getMax_getMin, size_two_tree)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(2);
      EXPECT_EQ(t1.getMax(), 5);
      EXPECT_EQ(t1.getMin(), 2);
   }

   TEST(Test_getMax_getMin, size_three_tree)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(2);
      t1.insert(8);
      EXPECT_EQ(t1.getMax(), 8);
      EXPECT_EQ(t1.getMin(), 2);
   }

   TEST(Test_getMax_getMin, size_eight_tree)
      {
      vector <int> v;
      v.push_back(5);
      v.push_back(3);
      v.push_back(4);
      v.push_back(8);
      v.push_back(2);
      v.push_back(9);
      v.push_back(6);
      v.push_back(7);
      binary_tree t1(v);
      EXPECT_EQ(t1.getMax(), 9);
      EXPECT_EQ(t1.getMin(), 2);
   }

   TEST(Test_getMax_getMin, exception_thrown_getMax_of_empty_tree)
   {
      try
      {
         binary_tree t1;
         t1.getMax();
         EXPECT_TRUE(false);
      }
      catch (domain_error e)
      {
         cout << "Exception thrown: " << endl;
         cout << e.what() << endl;
      }
   }

   TEST(Test_getMax_getMin, exception_thrown_getMin_of_empty_tree)
   {
      try
      {
         binary_tree t1;
         t1.getMin();
         EXPECT_TRUE(false);
      }
      catch (domain_error e)
      {
         cout << "Exception thrown: " << endl;
         cout << e.what() << endl;
      }
   }

   // Test_height_and_clear
   //    - empty_tree
   //    - size_one_tree
   //    - size_two_tree
   //    - size_three_tree_height_one
   //    - size_three_tree_height_two
   //    - size_eight_tree

   TEST(Test_height_and_clear, empty_tree)
   {
      binary_tree t1;
      EXPECT_EQ(t1.height(), -1);
      t1.clear();
      EXPECT_TRUE(t1.isEmpty());
   }

   TEST(Test_height_and_clear, size_one_tree)
   {
      binary_tree t1;
      t1.insert(5);
      EXPECT_EQ(t1.height(), 0);
      t1.clear();
      EXPECT_TRUE(t1.isEmpty());
   }

   TEST(Test_height_and_clear, size_two_tree)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(2);
      EXPECT_EQ(t1.height(), 1);
      t1.clear();
      EXPECT_TRUE(t1.isEmpty());
   }

   TEST(Test_height_and_clear, size_three_tree_height_one)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(2);
      t1.insert(8);
      EXPECT_EQ(t1.height(), 1);
      t1.clear();
      EXPECT_TRUE(t1.isEmpty());
   }

   TEST(Test_height_and_clear, size_three_tree_height_two)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(2);
      t1.insert(3);
      EXPECT_EQ(t1.height(), 2);
      t1.clear();
      EXPECT_TRUE(t1.isEmpty());
   }

   TEST(Test_height_and_clear, size_eight_tree)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(3);
      t1.insert(8);
      t1.insert(2);
      t1.insert(4);
      t1.insert(6);
      t1.insert(9);
      t1.insert(7);
      EXPECT_EQ(t1.height(), 3);
      t1.clear();
      EXPECT_TRUE(t1.isEmpty());
   }

   // Test_preorder
   //    - empty_tree
   //    - size_one_tree
   //    - size_two_tree
   //    - size_three_tree_height_one
   //    - size_three_tree_height_two
   //    - size_eight_tree

   TEST(Test_preorder, empty_tree)
   {
      binary_tree t1;
      string correct = "<empty tree>";
      EXPECT_EQ(correct, t1.preorder());
   }

   TEST(Test_preorder, size_one_tree)
   {
      binary_tree t1;
      t1.insert(5);
      string correct = "5 ";
      EXPECT_EQ(correct, t1.preorder());
   }

   TEST(Test_preorder, size_two_tree)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(3);
      string correct = "5 3 ";
      EXPECT_EQ(correct, t1.preorder());
   }
   TEST(Test_preorder, size_three_tree_height_one)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(2);
      t1.insert(8);
      string correct = "5 2 8 ";
      EXPECT_EQ(correct, t1.preorder());
   }

   TEST(Test_preorder, size_three_tree_height_two)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(2);
      t1.insert(3);
      string correct = "5 2 3 ";
      EXPECT_EQ(correct, t1.preorder());
   }

   TEST(Test_preorder, size_eight_tree)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(3);
      t1.insert(8);
      t1.insert(2);
      t1.insert(4);
      t1.insert(6);
      t1.insert(9);
      t1.insert(7);
      string correct = "5 3 2 4 8 6 7 9 ";
      EXPECT_EQ(correct, t1.preorder());
   }

   // Test_inorder
   //    - empty_tree
   //    - size_one_tree
   //    - size_two_tree
   //    - size_three_tree_height_one
   //    - size_three_tree_height_two
   //    - size_eight_tree

   TEST(Test_inorder, empty_tree)
   {
      binary_tree t1;
      string correct = "<empty tree>";
      EXPECT_EQ(correct, t1.inorder());
   }

   TEST(Test_inorder, size_one_tree)
   {
      binary_tree t1;
      t1.insert(5);
      string correct = "5 ";
      EXPECT_EQ(correct, t1.inorder());
   }

   TEST(Test_inorder, size_two_tree)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(3);
      string correct = "3 5 ";
      EXPECT_EQ(correct, t1.inorder());
   }
   TEST(Test_inorder, size_three_tree_height_one)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(2);
      t1.insert(8);
      string correct = "2 5 8 ";
      EXPECT_EQ(correct, t1.inorder());
   }

   TEST(Test_inorder, size_three_tree_height_two)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(2);
      t1.insert(3);
      string correct = "2 3 5 ";
      EXPECT_EQ(correct, t1.inorder());
   }

   TEST(Test_inorder, size_eight_tree)
   {
      binary_tree t1;
      t1.insert(5);
      t1.insert(3);
      t1.insert(8);
      t1.insert(2);
      t1.insert(4);
      t1.insert(6);
      t1.insert(9);
      t1.insert(7);
      string correct = "2 3 4 5 6 7 8 9 ";
      EXPECT_EQ(correct, t1.inorder());
   }

} // namespace

// main() for testing -- boilerplate
int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
