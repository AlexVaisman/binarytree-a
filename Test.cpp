#include "doctest.h"
#include <string>
#include <algorithm>  
#include <iostream> 
#include <sstream> 
#include "BinaryTree.hpp"
using namespace ariel;



TEST_CASE("Checking put functions"){
  BinaryTree<int> tree;
  CHECK((tree.size)==(0));
  tree.add_root(0);
  CHECK((tree.size)==(1));
  tree.add_right(0,5);
  CHECK((tree.size)==(2));
  tree.add_left(0,4);
  CHECK((tree.size)==(3));
  //checking if size dosent change after override
  tree.add_left(0,8);
  CHECK((tree.size)==(3));
  //checking if size dosent change after override of root
  tree.add_root(10);
  CHECK((tree.size)==(3));
  //checking if size dosent change after override
  tree.add_right(0,19);
  CHECK((tree.size)==(3));
}

//tree taken from : https://www.javadevjournal.com/data-structure/binary-tree-traversal/
TEST_CASE("Checking inorder"){
  BinaryTree<double> tree;
  tree.add_root(52);
  tree.add_left(52,40);
  tree.add_left(40,24);
  tree.add_right(24,32);
  tree.add_right(52,62);
  tree.add_right(62,69);
  tree.add_right(62,58);

  auto it = tree.begin_inorder();
  
  CHECK(*it  == 24);
  it++; 
  CHECK(*it  == 32);
  it++;  
  CHECK(*it  == 40);
  it++;  
  CHECK(*it  == 52);
  it++;  
  CHECK(*it  == 58);
  it++;  
  CHECK(*it  == 62);
  it++;  
  CHECK(*it  == 69);  
}


//tree taken from : https://www.javadevjournal.com/data-structure/binary-tree-traversal/
TEST_CASE("Checking preorder"){
  BinaryTree<std::string> tree;
  tree.add_root("52");
  tree.add_left("52","40");
  tree.add_left("40","24");
  tree.add_right("24","32");
  tree.add_right("52","62");
  tree.add_right("62","69");
  tree.add_right("62","58");

  auto it = tree.begin_preorder();
  
  CHECK(*it  == "52");
  it++; 
  CHECK(*it  == "40");
  it++;  
  CHECK(*it  == "24");
  it++;  
  CHECK(*it  == "32");
  it++;  
  CHECK(*it  == "62");
  it++;  
  CHECK(*it  == "58");
  it++;  
  CHECK(*it  == "69");  
}


//tree taken from : https://www.javadevjournal.com/data-structure/binary-tree-traversal/
TEST_CASE("Checking postorder"){
  BinaryTree<std::string> tree;
  tree.add_root("52");
  tree.add_left("52","40");
  tree.add_left("40","24");
  tree.add_right("24","32");
  tree.add_right("52","62");
  tree.add_right("62","69");
  tree.add_right("62","58");

  auto it = tree.begin_postorder();
  
  CHECK(*it  == "32");
  it++; 
  CHECK(*it  == "24");
  it++;  
  CHECK(*it  == "40");
  it++;  
  CHECK(*it  == "58");
  it++;  
  CHECK(*it  == "69");
  it++;  
  CHECK(*it  == "62");
  it++;  
  CHECK(*it  == "52");  
}