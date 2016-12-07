//
//  BST.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

/*

 ////TODO
- prevent acceing root members when root is deleted
- Functions to be Added
  // Balance()
  // Balance_(root)
  // IsBalanced()
  // Leftheavey or right heavy
  //Rotation functions
 */

#ifndef bst_hpp
#define bst_hpp

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

#include "gtest/gtest_prod.h"  // defines FRIEND_TEST for testing private funstions

//#include "height_updater.hpp"
#include "node.hpp"
#include "node_balance_checker.hpp"
//#include "node_connections_checker.hpp"
#include "node_finder.hpp"
//#include "node_inserter.hpp"
#include "node_remover.hpp"
#include "rotator.hpp"
#include "tree_printer.hpp"

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
    FRIEND_TEST(NodeConnectionsCheckerFunctionCollection, CheckIfNodeHasNoChildren);
    FRIEND_TEST(NodeConnectionsCheckerFunctionCollection, CheckIfNodeHasTwoChildren);
    FRIEND_TEST(NodeConnectionsCheckerFunctionCollection, CheckIfNodeHasOnlyLeftChild);
    FRIEND_TEST(NodeConnectionsCheckerFunctionCollection, CheckIfNodeHasOnlyRightChild);
};
}  // of BSTNamespace
#endif /* BST_hpp */
