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

#include <algorithm> //max(), move()
#include <cassert>   //asser
#include <memory>    //Uniqe_ptr<> ,make_unique<>
#include <vector>

#include "gtest/gtest_prod.h" // defines FRIEND_TEST for testing private funstions

namespace BSTNS
{

class Node;
typedef std::unique_ptr<Node> NodeUPtr;
typedef int Data;
typedef int Height;

class Node
{
  public:
    ~Node(){}; //TODO : Ask weather it is ok to leave desc pulic while having private constructor
    Data data;
    NodeUPtr left, right;
    Node *parent;
    bool is_left_node;
    Height height;
    static NodeUPtr CreateNode(const Data &entry = 0) { return std::make_unique<Node>(entry); }
  private:
    friend NodeUPtr std::make_unique<Node>(const Data &entry); //for printing tree with tree_printer.h

    Node(const Data &entry = 0)
        : data(entry),
          left(nullptr),
          right(nullptr),
          parent(nullptr),
          is_left_node(false),
          height(0){};
};

class BST
{
  public:
    // Creation
    BST(void); // Empty tree with no nodes
    BST(const Data &entry);
    BST(const std::vector<Data> &entries_container);
    ~BST();
    NodeUPtr root;
    // ==== INSERT =============================================================
    bool Insert(const Data &entry);
    bool Insert(const std::vector<Data> &entries_container);
    // ==== REMOVEyy ===========================================================
    bool Remove(const Data &target);
    bool Remove(const std::vector<Data> &entries_container);
    bool EmptyTheTree();
    // ==== SEARCH =============================================================
    Node *Find(const Data &target) const;
    Data GetMin(void) const;
    Data GetMax(void) const;
    // ==== BALANCE ============================================================
    bool Balance();
    bool IsBalanced();

  private:
    // ==== INSERT_ ============================================================
    Node *Insert_(NodeUPtr &root, const Data &entry);
    // ==== HEIGHT UPDATE_ =====================================================
    void UpdateHeight_(Node *node_parent);              // O(log(n))
    Height UpdateHeightOfNodeRecursively_(Node *node);  // O(nlog(n))
    void UpdateHeightOfNodeNonRecursively_(Node *node); // O(1)
    void UpdateTheParentsStartingFromParent_(
        Node *unupdated_parent_to_start_with); // O(log(n))
    Height CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(
        const Node *const node);
    // ==== NODE CONNECTIONS CHECKERS_ =========================================
    bool HasNoChildren_(const Node *const);
    bool HasTwoChildren_(const Node *const);
    bool HasOnlyLeftChild_(const Node *const);
    bool HasOnlyRightChild_(const Node *const);
    // ==== REMOVE_ ============================================================
    Node *Remove_(NodeUPtr &tree_root, Node *node_to_remove);
    Node *RemoveNodeWithNoChildren_(NodeUPtr &tree_root, Node *node_to_remove);
    Node *RemoveNodeWithTwoChildren_(NodeUPtr &tree_root, Node *node_to_remove);
    Node *RemoveNodeWithOnlyLeftChild_(NodeUPtr &tree_root, Node *node_to_remove);
    Node *RemoveNodeWithOnlyRightChild_(NodeUPtr &tree_root,
                                        Node *node_to_remove);
    // ==== SEARCH_ ============================================================
    Node *Find_(Node *const current_root, const Data &target) const;
    Node *GetMin_(Node *const current_root) const;
    Node *GetMax_(Node *const current_root) const;
    // ==== ROTATE =============================================================
    Node *RotateLeftAround_(NodeUPtr &pivot_node);
    Node *RotateRightAround_(NodeUPtr &pivot_node);
    // ==== BALANCE_ ===========================================================
    void Balance_(NodeUPtr &current_root);
    bool IsBalancedNode_(const Node *const node);
    bool IsBalanced_(const Node *const current_root);
    int BalanceFactorOfNode_(const Node *const node);
    /*
    //To check for
    //       []
    //      /L BF=2
    //    []
    //   /L BF=1
    // []
    */
    bool IsLeftLeft_(const Node *const node);
    /*To chrck for
    //   []
    //   /L BF=2
    // []
    //   \R BF=-1
    //   []
    */
    bool IsLeftRight_(const Node *const node);
    /*To check for
    // []
    //   \R BF=-2
    //    []
    //      \R BF=-1
    //       []
    */
    bool IsRightRight_(const Node *const node);
    /*To chrck for
    // []
    //   \R BF=-2
    //    []
    //   /L BF=1
    // []
    */
    bool IsRightLeft_(const Node *const node);
    bool IsLeftHeavy_(const Node *const node);
    bool IsRightHeavy_(const Node *const node);
    // ==== GTEST UT ===========================================================
    /*
    //The following is the name of the googletest classes that test some private
    //funtions. The test cases declared here as freind class are uncomented when
    //you run the unit test only
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
    FRIEND_TEST(TreeBalancingFunctionsCollection, TreeBalancePrivateFunction);
    // -- Node UT
    FRIEND_TEST(NodeClass, NodeConstructionDefaultValue);
};
} // of BSTNamespace

#endif /* BST_hpp */
