//
//  tree_balancer_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-23.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "bst.hpp"
#include "gtest/gtest.h"
#include "tree_balancer.hpp"

using namespace BSTNS;
using namespace BSTNS::TreeBalancer;
using namespace BSTNS::TreeBalancer::PrivateHelper;

class TreeBalancingFunctionsCollection : public ::testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown(){};
};

TEST_F(TreeBalancingFunctionsCollection, BalancingFactorFunction) {
  Tree tree({2});
  /*     _[2]
  */
  // ASSERT_EQ(BalanceFactorOfNode_(tree.root.get()), 0);

  tree.Insert(1);
  /*        _[2]
  //       /
  //     [1]
  */
  ASSERT_EQ(BalanceFactorOfNode_(tree.root.get()), 1);

  tree.Insert(-1);
  /*        _[2]
  //       /
  //    _[1]
  //   /
  // [-1]
  */
  ASSERT_EQ(BalanceFactorOfNode_(tree.root.get()), 2);

  tree.Insert(-2);
  /*          _[2]
  //         /
  //      _[1]
  //     /
  //   [-1]
  //   /
  // [-2]
  */
  ASSERT_EQ(BalanceFactorOfNode_(tree.root.get()), 3);

  tree.Insert(0);
  /*             _[2]
  //           /
  //        _[1]
  //       /
  //    _[-1]_
  //   /     \
  // [-2]   [0]
  */
  ASSERT_EQ(BalanceFactorOfNode_(tree.root.get()), 3);

  tree.Insert(3);
  /*             _[2]_
  //           /      \
  //        _[1]      [3]
  //       /
  //    _[-1]_
  //   /     \
  // [-2]   [0]
  */
  ASSERT_EQ(BalanceFactorOfNode_(tree.root.get()), 2);

  tree.Insert(5);
  /*             _[2]_
  //           /      \
  //        _[1]      [3]_
  //       /              \
  //    _[-1]_            [5]
  //   /     \
  // [-2]   [0]
  */
  ASSERT_EQ(BalanceFactorOfNode_(tree.root.get()), 1);

  tree.Insert(4);
  /*             _[2]_
  //           /      \
  //        _[1]      [3]_
  //       /              \
  //    _[-1]_           _[5]_
  //   /      \         /
  // [-2]   [ 0]      [4]
  */
  ASSERT_EQ(BalanceFactorOfNode_(tree.root.get()), 0);

  tree.Insert(7);
  /*             _[2]_
  //           /      \
  //        _[1]      [3]_
  //       /              \
  //    _[-1]_           _[5]_
  //   /      \         /     \
  // [-2]   [ 0]      [4]     [7]
  */
  ASSERT_EQ(BalanceFactorOfNode_(tree.root.get()), 0);
  ASSERT_EQ(BalanceFactorOfNode_(tree.Find(3)), -2);

  tree.Remove({-2, 0});
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //     [-1]            _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_EQ(BalanceFactorOfNode_(tree.root.get()), -1);

  tree.Remove(-1);
  /*             _[2]_
   //           /      \
   //         [1]      [3]_
   //                      \
   //                     _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_EQ(BalanceFactorOfNode_(tree.root.get()), -2);

  tree.Remove(1);
  /*             _[2]_
   //           /      \
   //         [1]      [3]_
   //                      \
   //                     _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_EQ(BalanceFactorOfNode_(tree.root.get()), -3);
  }
