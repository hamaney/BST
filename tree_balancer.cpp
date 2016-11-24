//
//  tree_balancer.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-23.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "tree_balancer.hpp"

namespace BSTNS {
namespace TreeBalancer {
bool BalanceTheTree(NodeUPtr& root);
namespace PrivateHelper {
enum BalancingFactor { LL, LR, RR, RL };

bool isLeftHeavy_(NodeUPtr& root);
bool isRighttHeavy_(NodeUPtr& root);
bool isBalanced_(NodeUPtr& root);
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
}  // End BSTNS
