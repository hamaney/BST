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
/*
namespace BSTNS
{   namespace NodeFinder{
    }
}
*/
namespace BSTNS {
namespace NodeFinder {
Node *FindNode(Node *const current_root, const Data &target);
Node *FindMinNode(Node *const current_root);
Node *FindMaxNode(Node *const current_root);
}  // End NodeFinder::
}  // End BSTNS::

#endif /* node_finder_hpp */
