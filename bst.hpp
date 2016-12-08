//
//  BST.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

/*

 ////TODO
- Functions to be Added
  // IsBalanced()
-
 */

#ifndef bst_hpp
#define bst_hpp

#include <algorithm>  //max(), move()
#include <cassert>    //asser
#include <memory>     //Uniqe_ptr<>
#include <vector>

//#include "gtest/gtest_prod.h"  // defines FRIEND_TEST for testing private funstions

#include "node.hpp"

namespace BSTNS {

class Node;
typedef std::unique_ptr<Node> NodeUPtr;
typedef int Data;
typedef int Height;

class Node {
 public:
  Node(Data entry = 0)
      : data(entry),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        is_left_node(false),
        height(0){};
  ~Node(){};
  Data data;
  NodeUPtr left, right;
  Node *parent;
  bool is_left_node;
  Height height;
};

class Tree {
 public:
  // Creation
  Tree(void);  // Empty tree with no nodes
  Tree(const Data &entry);
  Tree(const std::vector<Data> &entries_container);
  ~Tree();
  NodeUPtr root;

  // bool Tree::InsertAtRoot(const Data &entry){}; // TODO
  bool Insert(const Data &entry);
  bool Insert(const std::vector<Data> &entries_container);

  bool Remove(const Data &target);
  bool Remove(const std::vector<Data> &entries_container);
  bool EmptyTheTree();

  bool Balance();
  bool IsBalanced();

  Node *Find(const Data &target) const;
  Data GetMin(void) const;
  Data GetMax(void) const;

 private:
  // -- Insertion
  Node *Insert_(NodeUPtr &root, const Data &entry);
  // TODO :Move to node.h
  NodeUPtr NodeFactory_(const Data &entry);
  // -- Height Updaters
  void UpdateHeight_(Node *node_parent);               // O(log(n))
  Height UpdateHeightOfNodeRecursively_(Node *node);   // O(nlog(n))
  void UpdateHeightOfNodeNonRecursively_(Node *node);  // O(1)
  void UpdateTheParentsStartingFromParent_(
      Node *unupdated_parent_to_start_with);  // O(log(n))
  Height CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(
      const Node *const node);
  // -- Node Connections chekes
  bool HasNoChildren_(const Node *const);
  bool HasTwoChildren_(const Node *const);
  bool HasOnlyLeftChild_(const Node *const);
  bool HasOnlyRightChild_(const Node *const);
  // -- Node removers
  Node *RemoveNode(NodeUPtr &tree_root, Node *node_to_remove);
  Node *RemoveNodeWithNoChildren_(NodeUPtr &tree_root, Node *node_to_remove);
  Node *RemoveNodeWithTwoChildren_(NodeUPtr &tree_root, Node *node_to_remove);
  Node *RemoveNodeWithOnlyLeftChild_(NodeUPtr &tree_root, Node *node_to_remove);
  Node *RemoveNodeWithOnlyRightChild_(NodeUPtr &tree_root,
                                      Node *node_to_remove);
  // -- Finding a node
  Node *FindNode(Node *const current_root, const Data &target) const;
  Node *FindMinNode(Node *const current_root) const;
  Node *FindMaxNode(Node *const current_root) const;
  // -- Rotator
  Node *RotateLeftAround(NodeUPtr &pivot_node);
  Node *RotateRightAround(NodeUPtr &pivot_node);

  void BalanceNodes_(NodeUPtr &current_root);

  bool IsBalancedNode(const Node *const node);
  bool IsBalancedTree(const Node *const current_root);
  /*
   To chrck for
   []
   /L BF=2
   []
   /L BF=1
   []
   */
  bool IsLeftLeft(const Node *const node);
  /*To chrck for
   []
   /L BF=2
   []
   \R BF=-1
   []
   */
  bool IsLeftRight(const Node *const node);
  /*To chrck for
   []
   \R BF=-2
   []
   \R BF=-1
   []
   */
  bool IsRightRight(const Node *const node);
  /*To chrck for
   []
   \R BF=-2
   []
   /L BF=1
   []
   */
  bool IsRightLeft(const Node *const node);
  bool IsLeftHeavy_(const Node *const node);
  bool IsRightHeavy_(const Node *const node);
  int BalanceFactorOfNode_(const Node *const node);

  /*
   The following is the name of the googletest classes that test some private
   funtions. The test cases declared here as freind class are uncomented when
   you run the unit test only
   *//*
  // Insertion UT
  FRIEND_TEST(NodeInserterFunctionsCollection, InsertUniqueEntriesToTheTree);
  FRIEND_TEST(NodeInserterFunctionsCollection, InsertAnExistingEntryToTheTree);
  FRIEND_TEST(NodeInserterFunctionsCollection,
              InsertingNewRootNodeAfterEmptyingTheTree);
  FRIEND_TEST(NodeInserterFunctionsCollection,
              InsertSquenceOfNewValuesToTheTree);
  // Height Updating UT
  FRIEND_TEST(TreeHeightUpdaterFunctionCollection,
              NodeHeightUpdatingNonRecursively);
  FRIEND_TEST(TreeHeightUpdaterFunctionCollection,
              ReadNodeHeightNonRecursively);
  FRIEND_TEST(TreeHeightUpdaterFunctionCollection,
              NodeHeightUpdatingRecursivelyForAllChildrens);
  FRIEND_TEST(TreeHeightUpdaterFunctionCollection, NodeParentHeightUpdating);
  FRIEND_TEST(TreeHeightUpdaterFunctionCollection,
              UpdateHeightTheInterfaceFunction);
  FRIEND_TEST(TreeHeightUpdaterFunctionCollection, UpdateHeightAfterRotation);
  // Node Connection Checking UT
  FRIEND_TEST(NodeConnectionsCheckerFunctionCollection,
              CheckIfNodeHasNoChildren);
  FRIEND_TEST(NodeConnectionsCheckerFunctionCollection,
              CheckIfNodeHasTwoChildren);
  FRIEND_TEST(NodeConnectionsCheckerFunctionCollection,
              CheckIfNodeHasOnlyLeftChild);
  FRIEND_TEST(NodeConnectionsCheckerFunctionCollection,
              CheckIfNodeHasOnlyRightChild);
  // Node removing
  FRIEND_TEST(NodeRemoverFunctionsCollection,
              RemoveNodeWithNoChildrenUsingPrivateHelper);
  FRIEND_TEST(NodeRemoverFunctionsCollection,
              RemoveNodeWithNoChildrenUsingRemoveNode);
  FRIEND_TEST(NodeRemoverFunctionsCollection,
              RemoveNodeWithOnlyRightChildUsingPrivateHelper);
  FRIEND_TEST(NodeRemoverFunctionsCollection,
              RemoveNodeWithOnlyRightChildUsingRemoveNode);
  FRIEND_TEST(NodeRemoverFunctionsCollection,
              RemoveNodeWithOnlyLeftChildUsingPrivateHelper);
  FRIEND_TEST(NodeRemoverFunctionsCollection,
              RemoveNodeWithOnlyLeftChildUsingRemoveNode);
  FRIEND_TEST(NodeRemoverFunctionsCollection,
              RemoveNodeWithTwoChildrenNodeIsALeftChildUsingPrivateHelper);
  FRIEND_TEST(NodeRemoverFunctionsCollection,
              RemoveNodeWithTwoChildrenNodeIsALeftChildUsingRemoveNode);
  FRIEND_TEST(NodeRemoverFunctionsCollection,
              RemoveNodeWithTwoChildrenNodeIsARightChildUsingPrivateHelper);
  FRIEND_TEST(NodeRemoverFunctionsCollection,
              RemoveNodeWithTwoChildrenNodeIsARightChildUsingRemoveNode);
  FRIEND_TEST(NodeRemoverFunctionsCollection,
              RemoveNodeWithTwoChildrenNodeIsTheRootUsingPrivateHelper);
  FRIEND_TEST(NodeRemoverFunctionsCollection,
              RemoveNodeWithTwoChildrenNodeIsTheRootUsingRemoveNode);
  FRIEND_TEST(
      NodeRemoverFunctionsCollection,
      RemoveNodeWithTwoChildrenHasRecursaiveCallToOtherRemoveFunctionsUsingPrivateHelper);
  FRIEND_TEST(
      NodeRemoverFunctionsCollection,
      RemoveNodeWithTwoChildrenHasRecursaiveCallToOtherRemoveFunctionsUsingRemoveNode);

  // Node finding UT
  FRIEND_TEST(NodeFinderFunctionCollections, FindAValueInTree);
  FRIEND_TEST(NodeFinderFunctionCollections, FindMinValue);
  FRIEND_TEST(NodeFinderFunctionCollections, FindMaxValue);
  FRIEND_TEST(NodeFinderFunctionCollections, WhenMaxValueIsTheSameAsMinValue);
  // Rotator funcitions UT
  FRIEND_TEST(RotatorFunctionsCollections, RotateLeftAboutTheTreeRoot);
  FRIEND_TEST(RotatorFunctionsCollections, RotateLeftAboutLeftChild);
  FRIEND_TEST(RotatorFunctionsCollections, RotateLeftAboutTheRightChild);
  FRIEND_TEST(RotatorFunctionsCollections,
              RotateLeftAboutTheRootWithTreeHasTwoNodesOnly);
  FRIEND_TEST(RotatorFunctionsCollections, RotateRightAboutTheTreeRoot);
  FRIEND_TEST(RotatorFunctionsCollections, RotateRightAboutLeftChild);
  FRIEND_TEST(RotatorFunctionsCollections, RotateRightAboutTheRightChild);
  FRIEND_TEST(RotatorFunctionsCollections,
              RotateRightAboutTheRootWithTreeHasTwoNodesOnly);
  // Balance UT
  FRIEND_TEST(TreeBalancingFunctionsCollection, IsBalancedNodeFunction);
  FRIEND_TEST(TreeBalancingFunctionsCollection,
              CheckIfNodeIsLeftHeavyWithLeftChildHasBalancingFactorEqualToOne);
  FRIEND_TEST(
      TreeBalancingFunctionsCollection,
      CheckIfNodeIsLeftHeavyWithRightChildHasBalancingFactorEqualToNegativeOne);
  FRIEND_TEST(TreeBalancingFunctionsCollection,
              CheckIfNodeIsRightHeavyWithLeftChildHasBalancingFactorEqualToOne);
  FRIEND_TEST(
      TreeBalancingFunctionsCollection,
      CheckIfNodeIsRightHeavyWithRightChildHasBalancingFactorEqualToNegativeOne);
  FRIEND_TEST(TreeBalancingFunctionsCollection, BalancingFactorFunction);
  FRIEND_TEST(TreeBalancingFunctionsCollection, isLeftHeavyFunction);
  FRIEND_TEST(TreeBalancingFunctionsCollection, isRightHeavyFunction);
  FRIEND_TEST(TreeBalancingFunctionsCollection, CheckIfTreeIsBalanced);
  // -- Node UT
  FRIEND_TEST(NodeClass, NodeConstructionDefaultValue);
      */
};
}  // of BSTNamespace

#endif /* BST_hpp */
