/* * This file is the implementation to bst_tree * */
#include <cassert>
#include <sstream>
#include "node_btree.h"
#include "bst_tree.h"

namespace DS {
    /**   template<typename T> //// Don't customize for frequency
       bool bst_tree<T>::bst_insert(T &newDataItem, node *node_ptr) { //// auto-complete for frequency methods isn't appearing
           if(node_ptr->data() == newDataItem)
               return true;

           if (node_ptr->left() == nullptr && node_ptr->data() > newDataItem) {
               node_ptr->left() = new node(newDataItem);
               return false;
           } else if (node_ptr->right() == nullptr && node_ptr->data() <= newDataItem) {
               node_ptr->right() = new node(newDataItem);
               return false;
           } else
               newDataItem <= node_ptr->data() ?
               bst_insert(newDataItem, node_ptr->left()) : bst_insert(newDataItem, node_ptr->right());
       } */

    /*  template <typename T> //node*&
      void bst_tree<T>::insert(T& newDataItem) { //TODO: review -> alternative for string argument
          frequency<std::string> a(newDataItem, false);
          if ( root_ptr == nullptr )
              root_ptr = new node(a);
          else bst_insert(a, root_ptr);
      }

      template<typename T>
      void bst_tree<T>::bst_insert(T &newDataItem, node *node_ptr) {
          if (node_ptr->left() == nullptr && node_ptr->data() > newDataItem) {
              node_ptr->left() = new node(newDataItem);
          } else if (node_ptr->right() == nullptr && node_ptr->data() <= newDataItem) {
              node_ptr->right() = new node(newDataItem);
          } else
              newDataItem <= node_ptr->data() ?
              bst_insert(newDataItem, node_ptr->left()) : bst_insert(newDataItem, node_ptr->right());
      }*/

/**
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
 * */


   /* template<typename T>
    void bst_tree<T>::printTree() const {
        if (root_ptr == nullptr)
            std::cout << "Empty tree" << std::endl;
        else {
            std::cout << std::endl;
            printTree(root_ptr, 0);
            std::cout << std::endl;
        }
    }

    template<typename T>
    void bst_tree<T>::printTree(const node *node_ptr, size_t depth) const
// Library facilities used: iomanip, iostream, stdlib
    {
        //To output a binary tree in pretty ASCII we do INORDER
        //However, we go RIGHT first instead of LEFT
        if (node_ptr != nullptr) {
            printTree(node_ptr->right(), depth + 1);
            std::cout << std::setw(4 * depth) << ""; // Indent 4*depth spaces.
            std::cout << node_ptr->data() << std::endl;
            printTree(node_ptr->left(), depth + 1);
        }
    } */


} //end namespace DS