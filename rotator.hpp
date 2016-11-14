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
class Rotator{

    HeightUpdater  height_updater_;
public:
    bool RotateLeftAround(NodeUPtr &pivot_node);

};

#endif /* rotator_hpp */
