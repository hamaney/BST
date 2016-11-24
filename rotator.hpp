//
//  rotator.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-14.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef rotator_hpp
#define rotator_hpp

#include "node.hpp"
/*
namespace BSTNS
{
 namespace Rotator{}
}
*/
namespace BSTNS {
namespace Rotator {
Node* RotateLeftAround(NodeUPtr &pivot_node);
Node* RotateRightAround(NodeUPtr &pivot_node);
}  // End of Rotator::
}  // End of BSTNS::

#endif /* rotator_hpp */
