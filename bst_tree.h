/* bst_tree.h
*** Data Structures - 9 A.M. ***
Program Name: Recursive Frequency List
Programmer Name: Anthony Duran
Date Submitted: 12/12/21
Purpose: Count and sort words in a file using a BST
Date Updated: N/A
Purpose for Update: N/A
Global Variable List: {avoid these}
Data Structure: Binary Tree


Precondition: None
Precondition: Inserts newDataItem into the binary search tree.  Calls bst_insert in all cases except for empty tree.
    void insert( const Item&);

Precondition: bst_height is implemented and works
Precondition: Returns the height of the binary tree pointed to by root_ptr by calling the private recursive
function called bst_height.  Recall that an empty tree is said to have height = -1.
    long height( ) const { return (root_ptr == NULL) ? -1 : bst_height(root_ptr);  };

Precondition: None
Postcondition: Calls the book/authors 'binary_tree_node' print-helper function to output the tree to stdout
void prettyprint() const;

Precondition: None
Postcondition: The book/authors 'binary_tree_node' inorder/preorder/postorder functions are called in order to output the ordered collapsed tree
void preorderprint() const;
void inorderprint() const;
void postorderprint() const;

Precondition: Tree has at least one node
Postcondition: Height of the tree is returned recursively, recall that a tree with one node is height of 0
long bst_height(const  binary_tree_node<Item>*) const;

Precondition: Tree has at least one node, ie height >= 0
Precondition: Inserts newDataItem into the binary search tree in the correct spot.
void bst_insert( const Item& newDataItem,binary_tree_node<Item>*);

 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream> //Very cool way to join strings with numbers and other types
#include "node_btree.h"
#include "frequency.h"

namespace DS {

    template<typename T>
    class bst_tree {
    public:
        typedef T value_type; // TYPE: frequency
        typedef DSBTREE::node<value_type> node; // TYPE: frequency
//        typedef frequency<std::string> word_type; //// TYPE: std::string

        bst_tree() { root_ptr = nullptr; }
        ~bst_tree() { clear(root_ptr); }

        std::string toString() const;
        bool insert(T &newDataItem);
//        void insert(T &newDataItem);
        value_type matchFound() { return duplicate->data(); }

    private:
        bool bst_insert(T &, node *);
//        void bst_insert(T &, node *);
        void clear(node *root);
        void buildStringStream(const node *, std::ostringstream &, bool &firstOutputted) const; //// <- done in lab

        node *root_ptr;
        node *duplicate;
    };

/**
 I recommend that you keep your BST has generic as possible, right now it is customized to only support frequency.
 You should only have to modify the insert to handle the “equal” or “already in tree” case”. You can do this by adding
 a argument/parameter to the insert function.
 **/

    template<typename T>
    //node*&
    bool bst_tree<T>::insert(T &newDataItem) {
        if (root_ptr == nullptr) {
            root_ptr = new node(newDataItem);
            return true;
        }
        else
            return bst_insert(newDataItem, root_ptr);
    }

    template<typename T>
    bool bst_tree<T>::bst_insert(T &newDataItem, node *node_ptr) { //// Conflicting logic. Orginally had == set to true and in main used a bool named increment. If true, increment but seemed to say (for the rest) false we didn't insert. Now inversed, logic states false IF == equal; intention is false that it is unique
        if (node_ptr->data() == newDataItem) {
            duplicate = node_ptr;
            return false; // TODO: try passing the node to a function
        }

        if (node_ptr->right() == nullptr && node_ptr->data() < newDataItem) {
            node_ptr->right() = new node(newDataItem);
            return true;
        } else if (node_ptr->left() == nullptr) {
            node_ptr->left() = new node(newDataItem);
            return true;
        } else
           return node_ptr->data() <= newDataItem ?
            bst_insert(newDataItem, node_ptr->right()) : bst_insert(newDataItem, node_ptr->left());
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

    template<typename T>
    void bst_tree<T>::clear(node *root) {
        if (root != nullptr) {
            clear(root->left());
            clear(root->right());
            delete root;
        }
    }

    template<typename T>
    std::string bst_tree<T>::toString() const {
        std::ostringstream s;
        bool firstNumberOutputted = false;
        buildStringStream(root_ptr, s, firstNumberOutputted);
        return s.str();
    }

} //End Namespace DS
#include "bst_tree.hpp"
#endif /* BSTREE_H_ */