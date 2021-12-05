/* * This file is the implementation to bst_tree * */
#include <cassert>
#include <sstream>
#include "node_btree.h"
#include "bst_tree.h"

namespace DS {

    template<typename T>
    void bst_tree<T>::bst_insert(const T &newDataItem, node *node_ptr) {
        if (node_ptr->left() == nullptr && node_ptr->data() > newDataItem) {
            node_ptr->left() = new node(newDataItem);
        } else if (node_ptr->right() == nullptr && node_ptr->data() <= newDataItem) {
            node_ptr->right() = new node(newDataItem);
        } else
            newDataItem <= node_ptr->data() ?
            bst_insert(newDataItem, node_ptr->left()) : bst_insert(newDataItem, node_ptr->right());
    }

    template<typename T>
    long bst_tree<T>::bst_height(const node *node_ptr) const {
        if (node_ptr == nullptr) return -1;
        long a = bst_height(node_ptr->left());
        long b = bst_height(node_ptr->right());
        if (a > b)
            return 1 + a;
        else
            return 1 + b;
    }

//Precondition: root_ptr is a root pointer of a binary search tree
//Postcondition: Returns true if target is in the BST, false otherwise
    template<typename Item>
    bool bst_tree<Item>::in_bst(const Item &newDataItem, node *node_ptr) {
        if (node_ptr == nullptr) return false;
        if (node_ptr->data() == newDataItem) return true;
        return newDataItem <= node_ptr->data() ? in_bst(newDataItem, node_ptr->left()) :
                                                 in_bst(newDataItem, node_ptr->right());
    }

    // Precondition: root_ptr is a root pointer of a binary search tree
    //  or may be NULL for an empty tree).
    // Postcondition: If target was in the tree, then one copy of target
    // has been removed, and root_ptr now points to the root of the new
    // (smaller) binary search tree. In this case the function returns true.
    // If target was not in the tree, then the tree is unchanged (and the
    // function returns false).
    template<typename T>
    bool bst_tree<T>::bst_remove(const T &target, node *&node_ptr) {
        //1 : tree is emtpy
        if (node_ptr == nullptr) return false;
        //2 : Tree not empty, target < than root
        if (target < node_ptr->data()) return bst_remove(target, node_ptr->left());
        //3 : tree not empty, target > than root
        if (target > node_ptr->data()) return bst_remove(target, node_ptr->right());
        //4 target == root node, do not need to check, if not < or >, than it

        //4a The root node has no left child
        if (node_ptr->left() == nullptr) {
            node *del = node_ptr;
            node_ptr = node_ptr->right(); // does the assignment operator cause a deep copy?
            delete del;

        } else
            //4bThe root does have a left child, remove the max from the left subtree
            bst_remove_max(node_ptr->left(), node_ptr->data());
        return true;
    }

    template<typename T>
    void
    bst_tree<T>::bst_remove_max(node *&root_ptr, T &removed) { // Is the highlighted error an issue (i.e. naming)?
        if (root_ptr->right() != nullptr)
            bst_remove_max(root_ptr->right(), removed);
        else {
            removed = root_ptr->data();
            node *del = root_ptr;
            root_ptr = root_ptr->left(); //// Was this to set root_ptr to nullptr?
            delete del;
        }
    }

    template<typename T>
    void bst_tree<T>::buildStringStream(const node *p, std::ostringstream &s, bool &firstOutputted) const {
        if (p == nullptr)
            return;
        buildStringStream(p->left(), s, firstOutputted);
        if (firstOutputted)
            s << ", " << p->data(); // Comma first because it'll get around the last print
        else
            s << p->data();
        firstOutputted = true;
        buildStringStream(p->right(), s, firstOutputted);
    }
} //end namespace DS