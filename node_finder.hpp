//
//  node_finder.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef node_finder_hpp
#define node_finder_hpp

#include <cassert>
#include "node.hpp"
class NodeFinder {
 public:
  Node *Find(Node *const current_root, const Data &target) const;
  Node *FindMin(Node *const current_root) const;
  Node *FindMax(Node *const current_root) const;
};

#endif /* node_finder_hpp */
