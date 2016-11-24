//
//  node_inserter.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-21.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef node_inserter_hpp
#define node_inserter_hpp

#include <cassert>
#include <memory>
#include <vector>
#include "node.hpp"

/*
namespace BSTNS {
    namespace NodeInserter {
        namespace PrivateHelper{}}}
*/

namespace BSTNS {
namespace NodeInserter {
Node* InsertValue(NodeUPtr& root, const Data& entry);

namespace PrivateHelper {
NodeUPtr NodeFactory_(const Data& entry);
}
}
}

#endif /* node_inserter_hpp */
