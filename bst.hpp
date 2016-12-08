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

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

#include "gtest/gtest_prod.h"  // defines FRIEND_TEST for testing private funstions

#include "node.hpp"
#include "tree_printer.hpp"
#include "node_balance_checker.hpp"
#include "rotator.hpp"





namespace BSTNS {
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

  void Print();
  void PrintHeights();  // rendring heightd for testing

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
  Node *FindNode(Node *const current_root, const Data &target)const;
  Node *FindMinNode(Node *const current_root)const;
  Node *FindMaxNode(Node *const current_root)const ;

  void BalanceNodes_(NodeUPtr &current_root);

  /*
   The following is the name of the googletest classes that test some private
   funtions. The test cases declared here as freind class are uncomented when
   you run the unit test only
   */
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
    
};
}  // of BSTNamespace

#endif /* BST_hpp */
