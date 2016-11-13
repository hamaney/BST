//
//  node_connections_checker.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef node_connections_checker_hpp
#define node_connections_checker_hpp
/*TODO :
 cleaner synatx

 */
#include "node.hpp"
class NodeConnectionsChecker {
 public:
  bool HasNoChildren(const Node *const) const;
  bool HasTwoChildren(const Node *const) const;
  bool HasOnlyLeftChild(const Node *const) const;
  bool HasOnlyRightChild(const Node *const) const;
};

#endif /* node_connections_checker_hpp */
