//
//  tree_balancer.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-23.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "node_balance_checker.hpp"

using namespace BSTNS::NodeBalanceChecker::PrivateHelper;

namespace BSTNS {
namespace NodeBalanceChecker {

bool IsBalancedNode(const Node* const node) {
  return ((BalanceFactorOfNode_(node) < 2) and
          (BalanceFactorOfNode_(node) > -2));
}

bool IsBalancedTree(const Node* const current_root) {
  if (!current_root) {
    return true;
  }

  if (IsBalancedTree(current_root->left.get()) and
      IsBalancedTree(current_root->right.get())) {
    return IsBalancedNode(current_root);
  } else {
    return false;
  }
}

bool IsLeftLeft(const Node* const node) {
  return (IsLeftHeavy_(node)) ? (BalanceFactorOfNode_(node->left.get()) >= 1)
                              : false;
  // return IsLeftHeavy_(node) and IsLeftHeavy_(node->left.get()) ;
}
bool IsLeftRight(const Node* const node) {
  return (IsLeftHeavy_(node)) ? (BalanceFactorOfNode_(node->left.get()) <= -1)
                              : false;
  // return IsLeftHeavy_(node) and IsRightHeavy_(node->left.get()) ;
}
bool IsRightLeft(const Node* const node) {
  return (IsRightHeavy_(node)) ? (BalanceFactorOfNode_(node->right.get()) >= 1)
                               : false;
  // return IsRightHeavy_(node) and IsLeftHeavy_(node->right.get()) ;
}
bool IsRightRight(const Node* const node) {
  return (IsRightHeavy_(node)) ? (BalanceFactorOfNode_(node->right.get()) <= -1)
                               : false;
  // return IsRightHeavy_(node) and IsRightHeavy_(node->right.get()) ;
}
namespace PrivateHelper {

bool IsLeftHeavy_(const Node* const node) {
  return BalanceFactorOfNode_(node) >= 2;
}
bool IsRightHeavy_(const Node* const node) {
  return BalanceFactorOfNode_(node) <= -2;
}
int BalanceFactorOfNode_(const Node* const node) {
  if (!node) {
    assert(0);
  } else {
    int left_child_balance_factor, right_child_balance_factor;
    if (!node->left) {
      left_child_balance_factor = -1;
    } else {
      left_child_balance_factor = node->left->height;
    }
    if (!node->right) {
      right_child_balance_factor = -1;
    } else {
      right_child_balance_factor = node->right->height;
    }
    return left_child_balance_factor - right_child_balance_factor;
  }
}
}  // End PrivateHelper::
}  // End TreeBalancer::
}  // End BSTNS::
