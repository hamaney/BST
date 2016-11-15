//
//  tree_nodes_height_updater.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef height_updater_class_hpp
#define height_updater_class_hpp

#include <algorithm> //std::max
#include <cassert>   // assert()
#include "node.hpp"
#include "node_connections_checker.hpp"
/*
namespace BSTNS{
    namespace HeightUpdater{
    }
}
*/
namespace BSTNS
{
namespace HeightUpdater
{
Height UpdateHeightOfNodeRecursively(Node *node);    // O(n)
Height UpdateHeightOfNodeNonRecursively(Node *node); // O(1)
void UpdateParentsHeightAfterAddingANode(
    Node *node); // O(log(n))input must have an updated height
void UpdateParentsHeightAfterRemovingANode(
    Node *node); // O(log(n))input must have an updated height
} //End HeightUpdater::
} // End BSTNS::

#endif /* tree_nodes_height_updater_hpp */
