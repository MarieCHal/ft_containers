#ifndef UTILS_HPP
#define UTILS_HPP
#include "rb_tree.hpp"

namespace ft
{
    // Preorder
  void preOrderHelper(node_ptr node) 
  {
    if (node != &nil) {
      std::cout << node->data << " ";
      preOrderHelper(node->left);
      preOrderHelper(node->right);
    }
  }

  // Inorder
  void inOrderHelper(node_ptr node) {
    if (node != &nil) {
      inOrderHelper(node->left);
      std::cout << node->data << " ";
      inOrderHelper(node->right);
    }
  }

  // Post order
  void postOrderHelper(node_ptr node) {
    if (node != &nil) {
      postOrderHelper(node->left);
      postOrderHelper(node->right);
      std::cout << node->data << " ";
    }
  }
}

#endif