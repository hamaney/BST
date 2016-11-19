//
//  tree_nodes_height_updater.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef height_updater_class_hpp
#define height_updater_class_hpp

#include <algorithm>  //std::max
#include <cassert>    // assert()
#include "node.hpp"
#include "node_connections_checker.hpp"
/*
namespace BSTNS{
 namespace HeightUpdater{
  namespace PrivateHelper{
  }
 }
}
*/
namespace BSTNS {
namespace HeightUpdater {
void UpdateHeight(Node *node_parent);              // O(log(n))
Height UpdateHeightOfNodeRecursively(Node *node);  // O(nlog(n))

namespace PrivateHelper {
void UpdateHeightOfNodeNonRecursively_(Node *node);  // O(1)
void UpdateTheParentsStartingFromParent_(
    Node *unupdated_parent_to_start_with);  // O(log(n))
Height CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(
    const Node *const node);

}  // End PrivateHelper::
}  // End HeightUpdater::
}  // End BSTNS::

#endif /* tree_nodes_height_updater_hpp */
