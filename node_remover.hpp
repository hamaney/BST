//
//  node_remover.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef node_remover_hpp
#define node_remover_hpp

#include <cassert>  //assert
#include "height_updater.hpp"
#include "node.hpp"
#include "node_connections_checker.hpp"
#include "node_finder.hpp"

class NodeRemover {
 public:
  bool Remove(NodeUPtr &tree_root, Node *node_to_remove);

 private:
  NodeConnectionsChecker connection_checker_;
  NodeFinder node_finder_;
  HeightUpdater height_updater_;
  bool RemoveNodeWithNoChildren_(NodeUPtr &tree_root, Node *node_to_remove);
  bool RemoveNodeWithTwoChildren_(NodeUPtr &tree_root, Node *node_to_remove);
  bool RemoveNodeWithOnlyLeftChild_(NodeUPtr &tree_root, Node *node_to_remove);
  bool RemoveNodeWithOnlyRightChild_(NodeUPtr &tree_root, Node *node_to_remove);
  // Helper
  Node *FindMin_(Node *const current_node) const;
};

#endif /* node_remover_hpp */
