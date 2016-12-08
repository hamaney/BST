//
//  tree_balancer_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-23.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "bst.hpp"
#include "gtest/gtest.h"

namespace BSTNS{

class TreeBalancingFunctionsCollection : public ::testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown(){};
};

TEST_F(TreeBalancingFunctionsCollection, IsBalancedNodeFunction) {
  Tree tree({2});
  /*     _[2]
   */
  ASSERT_TRUE(tree.IsBalancedNode(tree.root.get()));

  tree.Insert(1);
  /*        _[2]
  //       /
  //     [1]
  */
  ASSERT_TRUE(tree.IsBalancedNode(tree.root.get()));

  tree.Insert(-1);
  /*        _[2]
   //       /
   //    _[1]
   //   /
   // [-1]
   */
  ASSERT_FALSE(tree.IsBalancedNode(tree.root.get()));

  tree.Insert(-2);
  /*          _[2]
   //         /
   //      _[1]
   //     /
   //   [-1]
   //   /
   // [-2]
   */
  ASSERT_FALSE(tree.IsBalancedNode(tree.root.get()));

  tree.Insert(0);
  /*             _[2]
   //           /
   //        _[1]
   //       /
   //    _[-1]_
   //   /     \
   // [-2]   [0]
   */
  ASSERT_FALSE(tree.IsBalancedNode(tree.root.get()));

  tree.Insert(3);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]
   //       /
   //    _[-1]_
   //   /     \
   // [-2]   [0]
   */
  ASSERT_FALSE(tree.IsBalancedNode(tree.root.get()));

  tree.Insert(5);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //    _[-1]_            [5]
   //   /     \
   // [-2]   [0]
   */
  ASSERT_TRUE(tree.IsBalancedNode(tree.root.get()));

  tree.Insert(4);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //    _[-1]_           _[5]_
   //   /      \         /
   // [-2]   [ 0]      [4]
   */
  ASSERT_TRUE(tree.IsBalancedNode(tree.root.get()));

  tree.Insert(7);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //    _[-1]_           _[5]_
   //   /      \         /     \
   // [-2]   [ 0]      [4]     [7]
   */
  ASSERT_TRUE(tree.IsBalancedNode(tree.root.get()));

  tree.Remove({-2, 0});
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //     [-1]            _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_TRUE(tree.IsBalancedNode(tree.root.get()));

  tree.Remove(-1);
  /*             _[2]_
   //           /      \
   //         [1]      [3]_
   //                      \
   //                     _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_FALSE(tree.IsBalancedNode(tree.root.get()));

  tree.Remove(1);
  /*             _[2]_
   //           /      \
   //         [1]      [3]_
   //                      \
   //                     _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_FALSE(tree.IsBalancedNode(tree.root.get()));
}

TEST_F(TreeBalancingFunctionsCollection,
       CheckIfNodeIsLeftHeavyWithLeftChildHasBalancingFactorEqualToOne) {
  Tree tree(5);
  /*        [5]
  */
  ASSERT_FALSE(tree.IsLeftLeft(tree.root.get()));

  tree.Insert(4);
  /*        _[5]
  //       /
  //     [4]
  */
  ASSERT_FALSE(tree.IsLeftLeft(tree.root.get()));

  tree.Insert(6);
  /*        _[5]_
  //       /     \
  //     [4]     [6]
  */
  ASSERT_FALSE(tree.IsLeftLeft(tree.root.get()));

  tree.Insert(7);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]
  */
  ASSERT_FALSE(tree.IsLeftLeft(tree.Find(6)));

  tree.Insert(9);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]_
  //                     \
  //                     [9]
  */
  ASSERT_FALSE(tree.IsLeftLeft(tree.Find(6)));

  tree.Insert(8);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]_
  //                     \
  //                    _[9]
  //                   /
  //                 [8]
  */
  ASSERT_FALSE(tree.IsLeftLeft(tree.Find(7)));

  tree.Insert(10);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]_
  //                     \
  //                    _[9]_
  //                   /     \
  //                 [8]    [10]
  */
  ASSERT_FALSE(tree.IsLeftLeft(tree.Find(7)));

  tree.Insert({3, 1});
  /*               _[5]_
  //              /     \
  //           _[4]     [6]_
  //          /              \
  //       _[3]              [7]_
  //      /                      \
  //    [1]                     _[9]_
  //                           /     \
  //                         [8]    [10]
  */
  ASSERT_TRUE(tree.IsLeftLeft(tree.Find(4)));

  tree.Insert(2);
  /*               _[5]_
  //              /     \
  //           _[4]     [6]_
  //          /              \
  //       _[3]              [7]_
  //      /                      \
  //    [1]_                    _[9]_
  //        \                  /     \
  //        [2]               [8]    [10]
  */
  ASSERT_FALSE(tree.IsLeftLeft(tree.Find(3)));
  ASSERT_TRUE(tree.IsLeftLeft(tree.Find(4)));

  tree.Insert(0);
  /*               _[5]_
  //              /     \
  //           _[4]     [6]_
  //          /              \
  //       _[3]              [7]_
  //      /                      \
  //   _[1]_                    _[9]_
  //  /     \                  /     \
  //[0]     [2]               [8]    [10]
  */
  ASSERT_FALSE(tree.IsLeftLeft(tree.Find(3)));
}
TEST_F(
    TreeBalancingFunctionsCollection,
    CheckIfNodeIsLeftHeavyWithRightChildHasBalancingFactorEqualToNegativeOne) {
  Tree tree(5);
  /*        [5]
  */
  ASSERT_FALSE(tree.IsLeftRight(tree.root.get()));

  tree.Insert(4);
  /*        _[5]
  //       /
  //     [4]
  */
  ASSERT_FALSE(tree.IsLeftRight(tree.root.get()));

  tree.Insert(6);
  /*        _[5]_
  //       /     \
  //     [4]     [6]
  */
  ASSERT_FALSE(tree.IsLeftRight(tree.root.get()));

  tree.Insert(7);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]
  */
  ASSERT_FALSE(tree.IsLeftRight(tree.Find(6)));

  tree.Insert(9);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]_
  //                     \
  //                     [9]
  */
  ASSERT_FALSE(tree.IsLeftRight(tree.Find(6)));

  tree.Insert(8);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]_
  //                     \
  //                    _[9]
  //                   /
  //                 [8]
  */
  ASSERT_FALSE(tree.IsLeftRight(tree.Find(7)));

  tree.Insert(10);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]_
  //                     \
  //                    _[9]_
  //                   /     \
  //                 [8]    [10]
  */
  ASSERT_FALSE(tree.IsLeftRight(tree.Find(7)));

  tree.Insert({3, 1});
  /*               _[5]_
  //              /     \
  //           _[4]     [6]_
  //          /              \
  //       _[3]              [7]_
  //      /                      \
  //    [1]                     _[9]_
  //                           /     \
  //                         [8]    [10]
  */
  ASSERT_FALSE(tree.IsLeftRight(tree.Find(4)));

  tree.Insert(2);
  /*               _[5]_
  //              /     \
  //           _[4]     [6]_
  //          /              \
  //       _[3]              [7]_
  //      /                      \
  //    [1]_                    _[9]_
  //        \                  /     \
  //        [2]               [8]    [10]
  */
  ASSERT_TRUE(tree.IsLeftRight(tree.Find(3)));
  ASSERT_FALSE(tree.IsLeftRight(tree.Find(4)));

  tree.Insert(0);
  /*               _[5]_
  //              /     \
  //           _[4]     [6]_
  //          /              \
  //       _[3]              [7]_
  //      /                      \
  //   _[1]_                    _[9]_
  //  /     \                  /     \
  //[0]     [2]               [8]    [10]
  */
  ASSERT_FALSE(tree.IsLeftRight(tree.Find(3)));
}
TEST_F(TreeBalancingFunctionsCollection,
       CheckIfNodeIsRightHeavyWithLeftChildHasBalancingFactorEqualToOne) {
  Tree tree(5);
  /*        [5]
  */
  ASSERT_FALSE(tree.IsRightLeft(tree.root.get()));

  tree.Insert(4);
  /*        _[5]
  //       /
  //     [4]
  */
  ASSERT_FALSE(tree.IsRightLeft(tree.root.get()));

  tree.Insert(6);
  /*        _[5]_
  //       /     \
  //     [4]     [6]
  */
  ASSERT_FALSE(tree.IsRightLeft(tree.root.get()));

  tree.Insert(7);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]
  */
  ASSERT_FALSE(tree.IsRightLeft(tree.Find(6)));

  tree.Insert(9);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]_
  //                     \
  //                     [9]
  */
  ASSERT_FALSE(tree.IsRightLeft(tree.Find(6)));

  tree.Insert(8);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]_
  //                     \
  //                    _[9]
  //                   /
  //                 [8]
  */
  ASSERT_TRUE(tree.IsRightLeft(tree.Find(7)));

  tree.Insert(10);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]_
  //                     \
  //                    _[9]_
  //                   /     \
  //                 [8]    [10]
  */
  ASSERT_FALSE(tree.IsRightLeft(tree.Find(7)));

  tree.Insert({3, 1});
  /*               _[5]_
  //              /     \
  //           _[4]     [6]_
  //          /              \
  //       _[3]              [7]_
  //      /                      \
  //    [1]                     _[9]_
  //                           /     \
  //                         [8]    [10]
  */
  ASSERT_FALSE(tree.IsRightLeft(tree.Find(4)));

  tree.Insert(2);
  /*               _[5]_
  //              /     \
  //           _[4]     [6]_
  //          /              \
  //       _[3]              [7]_
  //      /                      \
  //    [1]_                    _[9]_
  //        \                  /     \
  //        [2]               [8]    [10]
  */
  ASSERT_FALSE(tree.IsRightLeft(tree.Find(3)));
  ASSERT_FALSE(tree.IsRightLeft(tree.Find(4)));

  tree.Insert(0);
  /*               _[5]_
  //              /     \
  //           _[4]     [6]_
  //          /              \
  //       _[3]              [7]_
  //      /                      \
  //   _[1]_                    _[9]_
  //  /     \                  /     \
  //[0]     [2]               [8]    [10]
  */
  ASSERT_FALSE(tree.IsRightLeft(tree.Find(3)));
}
TEST_F(
    TreeBalancingFunctionsCollection,
    CheckIfNodeIsRightHeavyWithRightChildHasBalancingFactorEqualToNegativeOne) {
  Tree tree(5);
  /*        [5]
  */
  ASSERT_FALSE(tree.IsRightRight(tree.root.get()));

  tree.Insert(4);
  /*        _[5]
  //       /
  //     [4]
  */
  ASSERT_FALSE(tree.IsRightRight(tree.root.get()));

  tree.Insert(6);
  /*        _[5]_
  //       /     \
  //     [4]     [6]
  */
  ASSERT_FALSE(tree.IsRightRight(tree.root.get()));

  tree.Insert(7);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]
  */
  ASSERT_FALSE(tree.IsRightRight(tree.Find(6)));

  tree.Insert(9);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]_
  //                     \
  //                     [9]
  */
  ASSERT_TRUE(tree.IsRightRight(tree.Find(6)));

  tree.Insert(8);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]_
  //                     \
  //                    _[9]
  //                   /
  //                 [8]
  */
  ASSERT_FALSE(tree.IsRightRight(tree.Find(7)));

  tree.Insert(10);
  /*        _[5]_
  //       /     \
  //     [4]     [6]_
  //                 \
  //                 [7]_
  //                     \
  //                    _[9]_
  //                   /     \
  //                 [8]    [10]
  */
  ASSERT_FALSE(tree.IsRightRight(tree.Find(7)));

  tree.Insert({3, 1});
  /*               _[5]_
  //              /     \
  //           _[4]     [6]_
  //          /              \
  //       _[3]              [7]_
  //      /                      \
  //    [1]                     _[9]_
  //                           /     \
  //                         [8]    [10]
  */
  ASSERT_FALSE(tree.IsRightRight(tree.Find(4)));

  tree.Insert(2);
  /*               _[5]_
  //              /     \
  //           _[4]     [6]_
  //          /              \
  //       _[3]              [7]_
  //      /                      \
  //    [1]_                    _[9]_
  //        \                  /     \
  //        [2]               [8]    [10]
  */
  ASSERT_FALSE(tree.IsRightRight(tree.Find(3)));
  ASSERT_FALSE(tree.IsRightRight(tree.Find(4)));

  tree.Insert(0);
  /*               _[5]_
  //              /     \
  //           _[4]     [6]_
  //          /              \
  //       _[3]              [7]_
  //      /                      \
  //   _[1]_                    _[9]_
  //  /     \                  /     \
  //[0]     [2]               [8]    [10]
  */
  ASSERT_FALSE(tree.IsRightRight(tree.Find(3)));
}

TEST_F(TreeBalancingFunctionsCollection, BalancingFactorFunction) {
  Tree tree({2});
  /*     _[2]
   */
  ASSERT_EQ(tree.BalanceFactorOfNode_(tree.root.get()), 0);

  tree.Insert(1);
  /*        _[2]
   //       /
   //     [1]
   */
  ASSERT_EQ(tree.BalanceFactorOfNode_(tree.root.get()), 1);

  tree.Insert(-1);
  /*        _[2]
   //       /
   //    _[1]
   //   /
   // [-1]
   */
  ASSERT_EQ(tree.BalanceFactorOfNode_(tree.root.get()), 2);

  tree.Insert(-2);
  /*          _[2]
   //         /
   //      _[1]
   //     /
   //   [-1]
   //   /
   // [-2]
   */
  ASSERT_EQ(tree.BalanceFactorOfNode_(tree.root.get()), 3);

  tree.Insert(0);
  /*             _[2]
   //           /
   //        _[1]
   //       /
   //    _[-1]_
   //   /     \
   // [-2]   [0]
   */
  ASSERT_EQ(tree.BalanceFactorOfNode_(tree.root.get()), 3);

  tree.Insert(3);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]
   //       /
   //    _[-1]_
   //   /     \
   // [-2]   [0]
   */
  ASSERT_EQ(tree.BalanceFactorOfNode_(tree.root.get()), 2);

  tree.Insert(5);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //    _[-1]_            [5]
   //   /     \
   // [-2]   [0]
   */
  ASSERT_EQ(tree.BalanceFactorOfNode_(tree.root.get()), 1);

  tree.Insert(4);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //    _[-1]_           _[5]_
   //   /      \         /
   // [-2]   [ 0]      [4]
   */
  ASSERT_EQ(tree.BalanceFactorOfNode_(tree.root.get()), 0);

  tree.Insert(7);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //    _[-1]_           _[5]_
   //   /      \         /     \
   // [-2]   [ 0]      [4]     [7]
   */
  ASSERT_EQ(tree.BalanceFactorOfNode_(tree.root.get()), 0);
  ASSERT_EQ(tree.BalanceFactorOfNode_(tree.Find(3)), -2);

  tree.Remove({-2, 0});
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //     [-1]            _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_EQ(tree.BalanceFactorOfNode_(tree.root.get()), -1);

  tree.Remove(-1);
  /*             _[2]_
   //           /      \
   //         [1]      [3]_
   //                      \
   //                     _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_EQ(tree.BalanceFactorOfNode_(tree.root.get()), -2);

  tree.Remove(1);
  /*             _[2]_
   //           /      \
   //         [1]      [3]_
   //                      \
   //                     _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_EQ(tree.BalanceFactorOfNode_(tree.root.get()), -3);
}
TEST_F(TreeBalancingFunctionsCollection, isLeftHeavyFunction) {
  Tree tree({2});
  /*     _[2]
   */
  ASSERT_FALSE(tree.IsLeftHeavy_(tree.root.get()));

  tree.Insert(1);
  /*        _[2]
   //       /
   //     [1]
   */
  ASSERT_FALSE(tree.IsLeftHeavy_(tree.root.get()));

  tree.Insert(-1);
  /*        _[2]
   //       /
   //    _[1]
   //   /
   // [-1]
   */
  ASSERT_TRUE(tree.IsLeftHeavy_(tree.root.get()));

  tree.Insert(-2);
  /*          _[2]
   //         /
   //      _[1]
   //     /
   //   [-1]
   //   /
   // [-2]
   */
  ASSERT_TRUE(tree.IsLeftHeavy_(tree.root.get()));

  tree.Insert(0);
  /*             _[2]
   //           /
   //        _[1]
   //       /
   //    _[-1]_
   //   /     \
   // [-2]   [0]
   */
  ASSERT_TRUE(tree.IsLeftHeavy_(tree.root.get()));

  tree.Insert(3);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]
   //       /
   //    _[-1]_
   //   /     \
   // [-2]   [0]
   */
  ASSERT_TRUE(tree.IsLeftHeavy_(tree.root.get()));

  tree.Insert(5);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //    _[-1]_            [5]
   //   /     \
   // [-2]   [0]
   */
  ASSERT_FALSE(tree.IsLeftHeavy_(tree.root.get()));

  tree.Insert(4);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //    _[-1]_           _[5]_
   //   /      \         /
   // [-2]   [ 0]      [4]
   */
  ASSERT_FALSE(tree.IsLeftHeavy_(tree.root.get()));

  tree.Insert(7);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //    _[-1]_           _[5]_
   //   /      \         /     \
   // [-2]   [ 0]      [4]     [7]
   */
  ASSERT_FALSE(tree.IsLeftHeavy_(tree.root.get()));

  tree.Remove({-2, 0});
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //     [-1]            _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_FALSE(tree.IsLeftHeavy_(tree.root.get()));

  tree.Remove(-1);
  /*             _[2]_
   //           /      \
   //         [1]      [3]_
   //                      \
   //                     _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_FALSE(tree.IsLeftHeavy_(tree.root.get()));

  tree.Remove(1);
  /*             _[2]_
   //           /      \
   //         [1]      [3]_
   //                      \
   //                     _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_FALSE(tree.IsLeftHeavy_(tree.root.get()));
}
TEST_F(TreeBalancingFunctionsCollection, isRightHeavyFunction) {
  Tree tree({2});
  /*     _[2]
   */
  ASSERT_FALSE(tree.IsRightHeavy_(tree.root.get()));

  tree.Insert(1);
  /*        _[2]
   `  //       /
   //     [1]
   */
  ASSERT_FALSE(tree.IsRightHeavy_(tree.root.get()));

  tree.Insert(-1);
  /*        _[2]
   //       /
   //    _[1]
   //   /
   // [-1]
   */
  ASSERT_FALSE(tree.IsRightHeavy_(tree.root.get()));

  tree.Insert(-2);
  /*          _[2]
   //         /
   //      _[1]
   //     /
   //   [-1]
   //   /
   // [-2]
   */
  ASSERT_FALSE(tree.IsRightHeavy_(tree.root.get()));

  tree.Insert(0);
  /*             _[2]
   //           /
   //        _[1]
   //       /
   //    _[-1]_
   //   /     \
   // [-2]   [0]
   */
  ASSERT_FALSE(tree.IsRightHeavy_(tree.root.get()));

  tree.Insert(3);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]
   //       /
   //    _[-1]_
   //   /     \
   // [-2]   [0]
   */
  ASSERT_FALSE(tree.IsRightHeavy_(tree.root.get()));

  tree.Insert(5);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //    _[-1]_            [5]
   //   /     \
   // [-2]   [0]
   */
  ASSERT_FALSE(tree.IsRightHeavy_(tree.root.get()));

  tree.Insert(4);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //    _[-1]_           _[5]_
   //   /      \         /
   // [-2]   [ 0]      [4]
   */
  ASSERT_FALSE(tree.IsRightHeavy_(tree.root.get()));

  tree.Insert(7);
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //    _[-1]_           _[5]_
   //   /      \         /     \
   // [-2]   [ 0]      [4]     [7]
   */
  ASSERT_FALSE(tree.IsRightHeavy_(tree.root.get()));

  tree.Remove({-2, 0});
  /*             _[2]_
   //           /      \
   //        _[1]      [3]_
   //       /              \
   //     [-1]            _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_FALSE(tree.IsRightHeavy_(tree.root.get()));

  tree.Remove(-1);
  /*             _[2]_
   //           /      \
   //         [1]      [3]_
   //                      \
   //                     _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_TRUE(tree.IsRightHeavy_(tree.root.get()));

  tree.Remove(1);
  /*             _[2]_
   //           /      \
   //         [1]      [3]_
   //                      \
   //                     _[5]_
   //                    /     \
   //                  [4]     [7]
   */
  ASSERT_TRUE(tree.IsRightHeavy_(tree.root.get()));
}

TEST_F(TreeBalancingFunctionsCollection, CheckIfTreeIsBalanced) {
  Tree tree({7});
  /*             _[7]_
  */
  ASSERT_TRUE(tree.IsBalancedTree(tree.root.get()));
  tree.Insert({3, 11});
  /*             _[7]_
  //           /      \
  //        _[3]     [11]_
  */
  ASSERT_TRUE(tree.IsBalancedTree(tree.root.get()));
  tree.Insert({13, 14});
  /*             _[7]_
   //           /     \
   //        _[3]     [11]_
   //                      \
   //                     [13]_
   //                          \
   //                          [14]
   */
  ASSERT_FALSE(tree.IsBalancedTree(tree.root.get()));
  tree.Insert({1, 0});
  /*             _[7]_
   //           /     \
   //        _[3]     [11]_
   //       /              \
   //    _[1]             [13]_
   //   /                      \
   //  [0]                     [14]
   */

  ASSERT_FALSE(tree.IsBalancedTree(tree.root.get()));
  tree.Insert(5);
  /*            _[7]_
  //           /     \
  //        _[3]     [11]_
  //       /    \         \
  //    _[1]    [5]      [13]_
  //   /                      \
  //  [0]                     [14]
  */
  ASSERT_FALSE(tree.IsBalancedTree(tree.root.get()));
  tree.Insert(9);
  /*             _[7]_
   //           /     \
   //        _[3]     [11]_
   //       /    \   /     \
   //    _[1]    [5][9]   [13]_
   //   /                      \
   //  [0]                     [14]
   */
  ASSERT_TRUE(tree.IsBalancedTree(tree.root.get()));
  tree.Remove(13);
  /*             _[7]_
   //           /     \
   //        _[3]     [11]_
   //       /    \   /     \
   //    _[1]    [5][9]   [14]
   //   /
   //  [0]
   */

  ASSERT_TRUE(tree.IsBalancedTree(tree.root.get()));
  tree.Remove(11);
  /*             _[7]_
   //           /     \
   //        _[3]     [9]_
   //       /    \        \
   //    _[1]    [5]      [14]
   //   /
   //  [0]
   */

  ASSERT_TRUE(tree.IsBalancedTree(tree.root.get()));
}
}
