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
#include "height_updater.hpp"
/*
namespace BSTNS
{
 namespace Rotator{}
}
*/
namespace BSTNS
{
namespace Rotator
{
bool RotateLeftAround(NodeUPtr &pivot_node);
bool RotateRightAround(NodeUPtr &pivot_node);
} // End of Rotator::
} // End of BSTNS::

#endif /* rotator_hpp */
