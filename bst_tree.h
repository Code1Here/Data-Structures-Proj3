/*  bst_tree.h
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
        typedef T value_type;
        typedef DSBTREE::node<value_type> node;

        bst_tree() { root_ptr = nullptr; }
        ~bst_tree() { clear(root_ptr); }
        bst_tree(bst_tree<T>&);

        std::string toString() const;
        void insert(T&, void(*)(T&));
    //  bst_tree<T>& operator=(node other);

        void printTree() const; //// Delete later

    private:
        void printTree(const node*, size_t= 0) const; //// Delete later

        void clear(node *root);
        void buildStringStream(const node *, std::ostringstream &, bool &firstOutputted) const;
        void bst_insert(T&, node *, void(*)(T&));
        node * preorder(node *);

        node *root_ptr;
    };

    template<typename T>
    DSBTREE::node<T> * bst_tree<T>::preorder(node * rhs) {
        if(rhs != nullptr)
        {
            node * copy_cat = new node(rhs->data());
            copy_cat->left() = preorder(rhs->left());
            copy_cat->right() = preorder(rhs->right());
            return copy_cat;
        }
        return nullptr;
    }

    template<typename T>
    bst_tree<T>::bst_tree (bst_tree<T> &value) {
        if (value.root_ptr == nullptr) {
            root_ptr = nullptr;
            return; // Special case: Parameter is nullptr
        }
        root_ptr = static_cast<node *>(preorder(value.root_ptr));
    }
//
//    template<typename T>
//    bst_tree<T>& bst_tree<T>::operator=(node other)    // Pass by value to generate a copy.
//    {
//        other.swap(*this);               // Swap the state of this and the
//        // copy we created in `other`
//        return *this;
//    }

    template<typename T>
    void bst_tree<T>::insert(T &newDataItem, void(*duplicate)(T&)) {
        if (root_ptr == nullptr) {
            root_ptr = new node(newDataItem);
        } else bst_insert(newDataItem, root_ptr, duplicate);
    }

    template<typename T>
    void bst_tree<T>::bst_insert(T &newDataItem, node *node_ptr, void(*duplicate)(T&)) {
        if (node_ptr->data() == newDataItem) { //// It is ambiguous whether a duplicate goes left or right so encapsulation until this level seems appropriate
            if(duplicate != nullptr) // TODO: maybe we let "them" decide to test instead of silently failing
                duplicate(node_ptr->data());
            return;
        }

        if (node_ptr->right() == nullptr && node_ptr->data() < newDataItem) {
            node_ptr->right() = new node(newDataItem);
        } else if (node_ptr->right() != nullptr && node_ptr->data() < newDataItem) {
            bst_insert(newDataItem, node_ptr->right(), duplicate);
        } else if (node_ptr->left() == nullptr) {
            node_ptr->left() = new node(newDataItem);
        } else
            node_ptr->data() <= newDataItem ?
            bst_insert(newDataItem, node_ptr->right(), duplicate) : bst_insert(newDataItem, node_ptr->left(), duplicate);
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
    std::string bst_tree<T>::toString() const {
        std::ostringstream s;
        bool firstNumberOutputted = false;
        buildStringStream(root_ptr, s, firstNumberOutputted);
        return s.str();
    }

    template<typename T>
    void bst_tree<T>::clear(node *root) {
        if (root != nullptr) {
            clear(root->left());
            clear(root->right());
            delete root;
        }
    }

} //End Namespace DS
#include "bst_tree.hpp"
#endif /* BSTREE_H_ */