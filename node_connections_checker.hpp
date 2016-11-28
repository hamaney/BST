//
//  node_connections_checker.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef node_connections_checker_hpp
#define node_connections_checker_hpp

//TODO : cleaner synatx

/*
namespace BSTNS
{   namespace NodeConnectionsChecker{}}
*/
#include "node.hpp"
namespace BSTNS {
namespace NodeConnectionsChecker {
bool HasNoChildren(const Node *const);
bool HasTwoChildren(const Node *const);
bool HasOnlyLeftChild(const Node *const);
bool HasOnlyRightChild(const Node *const);
}  // End NodeConnectionsChecker::
}  // End BSTNS::
#endif /* node_connections_checker_hpp */
