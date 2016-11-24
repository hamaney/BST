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
#include "node.hpp"
#include "node_connections_checker.hpp"
#include "node_finder.hpp"
/*
namespace BSTNS
{   namespace NodeRemover{
        namespace PrivateHelper{}}}*/

namespace BSTNS {
namespace NodeRemover {
Node *RemoveNode(NodeUPtr &tree_root, Node *node_to_remove);
namespace PrivateHelper {
Node *RemoveNodeWithNoChildren_(NodeUPtr &tree_root, Node *node_to_remove);
Node *RemoveNodeWithTwoChildren_(NodeUPtr &tree_root, Node *node_to_remove);
Node *RemoveNodeWithOnlyLeftChild_(NodeUPtr &tree_root, Node *node_to_remove);
Node *RemoveNodeWithOnlyRightChild_(NodeUPtr &tree_root, Node *node_to_remove);
}  // End of PrivateHelper::
}  // End of NodeRemover::
}  // End of BSTNS::

#endif /* node_remover_hpp */
