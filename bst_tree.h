/* bst_tree.h
** Data Structures - 9 A.M. **
Program Name: Recursive Frequency List
Programmer Name: Anthony Duran
Date Submitted: 12/12/21
Purpose: Count and sort words in a file using a BST
Date Updated: N/A
Purpose for Update: N/A
Global Variable List: {avoid these}
Data Structure: Binary Tree

TYPEDEFS and MEMBER CONSTANTS for the bst_tree class:
    typedef T value_type
        bst_tree::value_type is the template for the binary tree. It can be any data type.

    typedef DSBTREE::node<value_type> node
        DSBTREE::node<value_type> node is the pointer for the root of the binary tree and all it's subtrees.

CONSTRUCTOR for the bst_tree class:
    bst_tree()
        Default constructor, does NOT initialize anything on the heap
        Precondition: N/A
        Postcondition: Initialized object

    bst_tree(const bst_tree<T>&);
        A memory safe copy constructor
        Precondition: N/A
        Postcondition: A copy of the passed bst_tree is created.

Destructor
    ~bst_tree()
        Precondition: N/A
        Postcondition: All heap storage is reclaimed

MODIFICATION MEMBER FUNCTIONS for the bst_tree:
    bst_tree<T> &operator=(node other);
        A memory safe copy constructor
        Precondition: N/A
        Postcondition: A copy of the passed bst replaces the current contents of the tree.

    void bst_tree<T>::inorder(bst_tree<T> &rhs)
        Precondition: N/A
        Precondition: Inserts argument into a new bst_tree. Passes private root to private function

    void bst_tree<T>::_inorder(node *rhs)
        Precondition: N/A
        Precondition: Inserts argument into a new bst_tree. Specific frequency obj creation is handled by the freqObj function

    void bst_tree<T>::freqObj(frequency<std::string> value, bst_tree <frequency<std::basic_string<char>>> *rhs)
        Precondition: N/A
        Precondition: Create frequency Object. Inserts argument into the bst_tree

    void insert(T&, void(*)(T&))
        Precondition: Function pointer to handle the case where a duplicate is encountered. Tree has at least one node.
        Postcondition: Argument is set as a node within data structure. For almost all cases, this function will
            call bst_insert, except an uninitialized tree.

    void bst_insert(T&, node *, void(*)(T&));
        Precondition: N/A
        Precondition: Inserts argument into the bst_tree. Special cases are handled by insert(T&, void(*)(T&))

    void clear()
        Precondition: N/A
        Postcondition: All heap storage is freed and object is set to initial state

    node * preorder(node *);
        Precondition: N/A
        Postcondition: Assists copy constructor to perform a deep copy

CONSTANT MEMBER FUNCTIONS for the bst_tree class:

    std::string toString() const;
        Precondition: The object has overridden the << operator
        Postcondition: Prints the data of the bst_tree formatted

    void buildStringStream(const node *, std::ostringstream &, bool &firstOutputted) const;
        Precondition: The object has overridden the << operator
        Postcondition: Assists toString() traverse the data within to print each node



VALUE SEMANTICS for the sequence class:
    Assignment and the copy constructor may be used with objects represented by the template.

DYNAMIC MEMORY USAGE by the List
   If there is insufficient dynamic memory, then the following functions
   throw a BAD_ALLOC exception: The constructors, insert.

Invariant declaration
        This class will maintain the structural organization required to form a Binary Search Tree. The first input
   will determine a large portion of the entire structure's outcome. When the situation arises that a duplicate value is
   encountered, the optionality is available for the user to determine how it's handled if they pass in a function ptr.
   Whether that be going left or right, how the data of the node reacts, etc.
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
        bst_tree(const bst_tree<T> &);

        std::string toString() const;
        void insert(T &, void(*)(T &));
        bst_tree<T> &operator=(node other);
        void inorder(bst_tree<T> &);

    private:
        void _inorder(node *);
        node *preorder(node *);
        void clear(node *root);
        void buildStringStream(const node *, std::ostringstream &, bool &firstOutputted) const;
        void bst_insert(T &, node *, void(*)(T &));
        void freqObj(frequency<std::string> value, bst_tree<frequency<std::basic_string<char>>> *rhs);

    //    void recurseLeft(node *);

        node *root_ptr;
    };

/**
Instead you want to do a IN ORDER traversal of the alpha tree...The ACTION will be

insert A NEW frequency object into the freqTree using the data and freqency from the alphaTree node.
**/
    template<typename T>
    void bst_tree<T>::freqObj(frequency<std::string> value, bst_tree<frequency<std::basic_string<char>>> *rhs) {
        frequency<std::string> item(value.getData(), value.getFrequency());
        rhs->insert(item, nullptr);
    }

//    template<typename T>
//    void bst_tree<T>::recurseLeft(node *item) {
//        while (item->left() != nullptr)
//            item = item->left();
//    }

    template<typename T>
    //DSBTREE::node<T> *
    void bst_tree<T>::inorder(bst_tree<T> &rhs) {
        if (rhs.root_ptr != nullptr) {
            _inorder(rhs.root_ptr);
        }
    }

    template<typename T>
    void bst_tree<T>::_inorder(node *rhs) {
        if (rhs != nullptr) {
            _inorder(rhs->left());
            freqObj(rhs->data(), this);
            _inorder(rhs->right());
        }
    }

    template<typename T>
    void bst_tree<T>::bst_insert(T &newDataItem, node *node_ptr, void(*duplicate)(T &)) {
        // It is ambiguous whether a duplicate goes left or right so encapsulation until this level seems appropriate
        if (node_ptr->data() == newDataItem) {
            if (duplicate != nullptr)
                duplicate(node_ptr->data());
            else {
//                node_ptr->left() == nullptr ? // why doesn't the equal of <= handle anything? :[
//                        node_ptr->left() = new node(newDataItem) : (node_ptr = node_ptr->left()
             //   recurseLeft(node_ptr);
                node_ptr->left() = new node(newDataItem);
            }
            return;
        }

        if (node_ptr->data() < newDataItem && node_ptr->right() == nullptr) { // Insert value greater? Go right, IF free
            node_ptr->right() = new node(newDataItem);
        } else if (node_ptr->data() < newDataItem && node_ptr->right() != nullptr) { // Recurse right, IF not free
            bst_insert(newDataItem, node_ptr->right(), duplicate);
        } else if (node_ptr->left() == nullptr) { // Insert value lesser? Go left, IF free
            node_ptr->left() = new node(newDataItem);
        } else
            node_ptr->data() <= newDataItem ? // Recurse right, IF not free
            bst_insert(newDataItem, node_ptr->right(), duplicate) : bst_insert(newDataItem, node_ptr->left(),
                                                                               duplicate);
    }


    template<typename T>
    void bst_tree<T>::insert(T &newDataItem, void(*duplicate)(T &)) {
        if (root_ptr == nullptr) {
            root_ptr = new node(newDataItem);
        } else bst_insert(newDataItem, root_ptr, duplicate);
    }

    template<typename T>
    bst_tree<T>::bst_tree(const bst_tree<T> &value) {
        if (value.root_ptr == nullptr) {
            root_ptr = nullptr;
            return; // Special case: Parameter is nullptr
        }
        root_ptr = static_cast<node *>(preorder(value.root_ptr));
    }

    template<typename T>
    DSBTREE::node<T> *bst_tree<T>::preorder(node *rhs) {
        if (rhs != nullptr) {
            node *copy_cat = new node(rhs->data());
            copy_cat->left() = preorder(rhs->left());
            copy_cat->right() = preorder(rhs->right());
            return copy_cat;
        }
        return nullptr;
    }

    template<typename T>
    bst_tree<T> &bst_tree<T>::operator=(node other)    // Pass by value to generate a copy.
    {
        other.swap(*this);               // Swap the state of this and the
        // copy we created in `other`
        return *this;
    }

    template<typename T>
    void bst_tree<T>::buildStringStream(const node *p, std::ostringstream &s, bool &firstOutputted) const {
        if (p == nullptr)
            return;
        buildStringStream(p->left(), s, firstOutputted);
        if (firstOutputted)
            s << ", " << p->data(); // Comma first & avoid last print
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