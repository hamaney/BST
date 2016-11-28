//
//  height_updater_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-17.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include <memory>
#include <vector>
#include "bst.hpp"
#include "gtest/gtest.h"
#include "height_updater.hpp"
#include "rotator.hpp"

using namespace BSTNS;
using namespace BSTNS::HeightUpdater;
using namespace BSTNS::HeightUpdater::PrivateHelper;
using namespace BSTNS::Rotator;

class TreeHeightUpdaterFunctionCollection : public ::testing::Test {
 public:
  virtual void SetUp() {
    entries = {4, 2, 1, 3, 6, 5};
    tree.Insert(entries);
  }
  virtual void TearDown(){};
  Tree tree;
  std::vector<Data> entries;
};

TEST_F(TreeHeightUpdaterFunctionCollection, NodeHeightUpdatingNonRecursively) {
  Data six_original_parent_height = tree.Find(6)->parent->height;
  Data two_original_parent_height = tree.Find(2)->parent->height;

  ASSERT_EQ(tree.Find(6)->height, 1);
  /*        ____[4(2)]____
  //       /              \
  //     _[2(1)]_      _[6(1)]
  //    /        \    /
  //  [1(0)]  [3(0)][5(0)]
  */
  tree.Find(5)->height = 99;
  /*        ____[4(2)]____
  //       /              \
  //     _[2(1)]_      _[6(1)]
  //    /        \    /
  //  [1(0)]  [3(0)][5(99)]
  */
  UpdateHeightOfNodeNonRecursively_(tree.Find(6));
  /*        ____[4(2)]____
  //       /              \
  //     _[2(1)]_      _[6(100)]
  //    /        \    /
  //  [1(0)]  [3(0)][5(99)]
  */
  ASSERT_EQ(tree.Find(6)->height, 100);
  ASSERT_EQ(tree.Find(6)->parent->height, six_original_parent_height);

  ASSERT_EQ(tree.Find(2)->height, 1);
  /*        ____[4(2)]____
  //       /              \
  //     _[2(1)]_      _[6(100)]
  //    /        \    /
  //  [1(0)]  [3(0)][5(99)]
  */
  tree.Find(1)->height = 88;
  tree.Find(3)->height = 77;
  /*        ____[4(2)]____
  //       /              \
  //     _[2(1)]_        _[6(100)]
  //    /        \      /
  //  [1(88)]  [3(77)][5(99)]
  */
  UpdateHeightOfNodeNonRecursively_(tree.Find(2));
  /*        ____[4(2)]____
  //       /              \
  //     _[2(89)]_      _[6(1)]
  //    /          \    /
  //  [1(88]  [3(77)][5(5)]
  */
  ASSERT_EQ(tree.Find(2)->height, 89);
  ASSERT_EQ(tree.Find(2)->parent->height, two_original_parent_height);

  ASSERT_EQ(tree.Find(4)->height, 2);
  /*        ____[4(2)]____
  //       /              \
  //     _[2(89)]_     _[6(100)]
  //    /         \   /
  //  [1(88)]  [3(77)][5(99)]
  */
  tree.Find(1)->height = 33;
  tree.Find(3)->height = 44;
  /*         ____[4(2)]_____
   //       /               \
   //     _[2(89)]_       _[6(100)]
   //    /          \    /
   //  [1(33)]   [3(44)][5(99)]
   */
  UpdateHeightOfNodeNonRecursively_(tree.Find(4));
  /*         ____[4(101)]_____
   //       /                 \
   //     _[2(89)]_       _[6(100)]
   //    /          \    /
   //  [1(33)]   [3(44)][5(99)]
   */
  ASSERT_EQ(tree.Find(4)->height, 101);
}
TEST_F(TreeHeightUpdaterFunctionCollection, ReadNodeHeightNonRecursively) {
  /*        ____[4(2)]____
  //       /              \
  //     _[2(1)]_      _[6(1)]
  //    /        \    /
  //  [1(0)]  [3(0)][5(0)]
  */
  tree.Find(1)->height = 33;
  tree.Find(2)->height = 89;
  tree.Find(3)->height = 44;
  tree.Find(5)->height = 99;
  tree.Find(6)->height = 111;
  tree.Find(4)->height = 88;
  /*         ____[4(2)]_____
  //       /               \
  //     _[2(89)]_       _[6(111)]
  //    /          \    /
  //  [1(33)]   [3(44)][5(99)]
  */
  ASSERT_EQ(
      CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(tree.Find(1)),
      0);
  ASSERT_EQ(
      CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(tree.Find(2)),
      45);
  ASSERT_EQ(
      CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(tree.Find(3)),
      0);
  ASSERT_EQ(
      CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(tree.Find(5)),
      0);
  ASSERT_EQ(
      CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(tree.Find(6)),
      100);
  ASSERT_EQ(
      CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(tree.Find(4)),
      112);
}
TEST_F(TreeHeightUpdaterFunctionCollection,
       NodeHeightUpdatingRecursivelyForAllChildrens) {
  /*        ____[4(2)]____
  //       /              \
  //     _[2(1)]_      _[6(1)]
  //    /        \    /
  //  [1(0)]  [3(0)][5(0)]
  */

  ASSERT_EQ(tree.Find(4)->height, 2);
  Height root_height_modified = 111;
  tree.Find(2)->height = root_height_modified;
  tree.Find(2)->height = 99;
  tree.Find(6)->height = 88;
  tree.Find(1)->height = 77;
  tree.Find(3)->height = 66;
  tree.Find(5)->height = 55;
  /*        ____[4(111)]___
  //       /               \
  //     _[2(99)]_       _[6(88)]
  //    /         \     /
  //  [1(77)]  [3(66)] [5(55)]
  */
  UpdateHeightOfNodeRecursively(tree.Find(4));
  /*        ____[4(2)]_____
  //       /               \
  //     _[2(1)]_       _[6(1)]
  //    /        \     /
  //  [1(0)]  [3(0)] [5(0)]
  */

  ASSERT_EQ(tree.Find(4)->height, 2);
}
TEST_F(TreeHeightUpdaterFunctionCollection, NodeParentHeightUpdating) {
  entries = {4, 2, 1, 3, 7, 5, 6};
  Tree tree(entries);

  /*        ____[4(3)]____
  //       /              \
  //     _[2(1)]_      _[7(2)]
  //    /        \    /
  //  [1(0)]  [3(0)][5(1)]
  //                  \
  //                 [6(0)]
  */

  ASSERT_EQ(tree.Find(4)->height, 3);
  ASSERT_EQ(tree.Find(2)->height, 1);
  tree.Find(1)->height = 77;
  /*        ____[4(3)]_____
  //       /               \
  //     _[2(1)]_        _[7(2)]
  //    /         \     /
  //  [1(77)]  [3(0)][5(1)]
  //                  \
  //                 [6(0)]
  */
  UpdateTheParentsStartingFromParent_(tree.Find(2));
  /*        ____[4(79)]____
  //       /               \
  //     _[2(78)]_       _[7(2)]
  //    /         \     /
  //  [1(77)]  [3(0)][5(1)]
  //                  \
  //                 [6(0)]
  */
  ASSERT_EQ(tree.Find(2)->height, 78);
  ASSERT_EQ(tree.Find(4)->height, 79);

  tree.Find(6)->height = 55;
  /*        ____[4(79)]____
  //       /               \
  //     _[2(78)]_       _[7(2)]
  //    /         \     /
  //  [1(77)]  [3(0)][5(1)]
  //                  \
  //                 [6(55)]
  */
  ASSERT_EQ(tree.Find(5)->height, 1);
  UpdateTheParentsStartingFromParent_(tree.Find(5));
  /*        ____[4(79)]____
  //       /               \
  //     _[2(78)]_       _[7(57)]
  //    /         \     /
  //  [1(77)]  [3(0)][5(56)]
  //                  \
  //                 [6(55)]
  */
  ASSERT_EQ(tree.Find(5)->height, 56);
  ASSERT_EQ(tree.Find(7)->height, 57);
  ASSERT_EQ(tree.Find(4)->height, 79);

  tree.Find(1)->height = 56;
  tree.Find(3)->height = 56;
  /*        ____[4(79)]____
  //       /               \
  //     _[2(78)]_       _[7(57)]
  //    /         \     /
  //  [1(56)]  [3(56)][5(56)]
  //                  \
  //                 [6(55)]
  */
  UpdateTheParentsStartingFromParent_(tree.Find(2));
  /*        ____[4(58)]____
  //       /               \
  //     _[2(57)]_       _[7(57)]
  //    /         \     /
  //  [1(56)]  [3(56)][5(56)]
  //                  \
  //                 [6(55)]
  */
  ASSERT_EQ(tree.Find(2)->height, 57);
  ASSERT_EQ(tree.Find(4)->height, 58);
}

TEST_F(TreeHeightUpdaterFunctionCollection, UpdateHeightTheInterfaceFunction) {
  entries = {4, 2, 1, 3, 7, 5, 6};
  Tree tree(entries);

  /*        ____[4(3)]____
   //       /              \
   //     _[2(1)]_      _[7(2)]
   //    /        \    /
   //  [1(0)]  [3(0)][5(1)]
   //                  \
   //                 [6(0)]
   */

  tree.Find(1)->height = 77;
  /*        ____[4(3)]_____
  //       /               \
  //     _[2(1)]_        _[7(2)]
  //    /         \     /
  //  [1(77)]  [3(0)][5(1)]
  //                  \
  //                 [6(0)]
  */
  UpdateHeight(tree.Find(2));
  /*        ____[4(79)]____
  //       /               \
  //     _[2(78)]_       _[7(2)]
  //    /         \     /
  //  [1(77)]  [3(0)][5(1)]
  //                  \
  //                 [6(0)]
  */
  ASSERT_EQ(tree.Find(2)->height, 78);
  ASSERT_EQ(tree.Find(4)->height, 79);

  tree.Find(6)->height = 55;
  /*        ____[4(79)]____
  //       /               \
  //     _[2(78)]_       _[7(2)]
  //    /         \     /
  //  [1(77)]  [3(0)][5(1)]
  //                  \
  //                 [6(55)]
  */
  ASSERT_EQ(tree.Find(5)->height, 1);
  UpdateHeight(tree.Find(5));
  /*        ____[4(79)]____
  //       /               \
  //     _[2(78)]_       _[7(57)]
  //    /         \     /
  //  [1(77)]  [3(0)][5(56)]
  //                  \
  //                 [6(55)]
  */
  ASSERT_EQ(tree.Find(5)->height, 56);
  ASSERT_EQ(tree.Find(7)->height, 57);
  ASSERT_EQ(tree.Find(4)->height, 79);

  tree.Find(1)->height = 56;
  tree.Find(3)->height = 56;
  /*        ____[4(79)]____
  //       /               \
  //     _[2(78)]_       _[7(57)]
  //    /         \     /
  //  [1(56)]  [3(56)][5(56)]
  //                  \
  //                 [6(55)]
  */
  UpdateHeight(tree.Find(2));
  /*        ____[4(58)]____
  //       /               \
  //     _[2(57)]_       _[7(57)]
  //    /         \     /
  //  [1(56)]  [3(56)][5(56)]
  //                  \
  //                 [6(55)]
  */
  ASSERT_EQ(tree.Find(2)->height, 57);
  ASSERT_EQ(tree.Find(4)->height, 58);
}

TEST_F(TreeHeightUpdaterFunctionCollection, UpdateHeightAfterRotation) {
  entries = {1, 2, 3, 4, 5};
  Tree tree(entries);

  /* [1(4))]_
  //         \
  //       [2(3)]_
  //               \
  //              [3(2)]_
  //                     \
  //                    [4(1)]_
  //                           \
  //                         [5(0)]
  */
  auto latest_updated_node = RotateLeftAround(tree.root);
  /*      _[2(3)]_
  //     /        \
  //  [1(4)]      [3(2)]_
  //                     \
  //                    [4(1)]_
  //                           \
  //                         [5(0)]
  */
  ASSERT_EQ(tree.root->height, 3);
  ASSERT_EQ(tree.Find(1)->height, 4);
  ASSERT_EQ(tree.Find(3)->height, 2);
  ASSERT_EQ(tree.Find(4)->height, 1);
  ASSERT_EQ(tree.Find(5)->height, 0);

  UpdateHeight(latest_updated_node);
  /*      _[2(3)]_
  //     /        \
  //  [1(0)]      [3(2)]_
  //                     \
  //                    [4(1)]_
  //                           \
  //                         [5(0)]
  */
  ASSERT_EQ(tree.Find(1)->height, 0);
  ASSERT_EQ(tree.Find(2)->height, 3);
  ASSERT_EQ(tree.Find(3)->height, 2);
  ASSERT_EQ(tree.Find(4)->height, 1);
  ASSERT_EQ(tree.Find(5)->height, 0);

  latest_updated_node = Rotator::RotateLeftAround(tree.root->right);
  /*      _[2(3)]_
  //     /        \
  //  [1(0)]     _[4(1)]_
  //            /         \
  //         [3(2)]       [5(0)]
  */

  ASSERT_EQ(tree.Find(1)->height, 0);
  ASSERT_EQ(tree.Find(2)->height, 3);
  ASSERT_EQ(tree.Find(3)->height, 2);
  ASSERT_EQ(tree.Find(4)->height, 1);
  ASSERT_EQ(tree.Find(5)->height, 0);

  UpdateHeight(latest_updated_node);
  /*      _[2(2)]_
  //     /        \
  //  [1(0)]     _[4(1)]_
  //            /         \
  //         [3(0)]       [5(0)]
  */
  ASSERT_EQ(tree.Find(1)->height, 0);
  ASSERT_EQ(tree.Find(2)->height, 2);
  ASSERT_EQ(tree.Find(3)->height, 0);
  ASSERT_EQ(tree.Find(4)->height, 1);
  ASSERT_EQ(tree.Find(5)->height, 0);
}
