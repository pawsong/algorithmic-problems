
#include <cassert>
#include <vector>

#include "tree.h"

#define TRACE_ZIGZAG 0

#if TRACE_ZIGZAG
#include <iostream>
#endif

// Utility: Node Factory.
template< class T>
TreeNode<T>* createTreeNode( const T& val ) {
  return new TreeNode<T>( val );
}

// SplayTree implementation.
template< class T >
TreeNode<T>* SplayTree<T>::splay( TreeNode<T>* node, std::vector< TreeNode<T> *>& path ) {
  assert( node != NULL );

  while ( path.size() > 0 ) {
    if ( path.size() == 1 ) {
      auto* parent = path.back();
      path.pop_back();

      if (parent->left() == node) {
#if TRACE_ZIGZAG
        std::cout << "zig(L)" << std::endl;
#endif
        TreeNode<T>* nodeRight = node->right();
        node->setRight(parent);
        parent->setLeft(nodeRight);
      }
      else {
#if TRACE_ZIGZAG
        std::cout << "zig(R)" << std::endl;
#endif
        assert( parent->right() == node );
        TreeNode<T>* nodeLeft = node->left();
        node->setLeft(parent);
        parent->setRight(nodeLeft);
      }
    }
    else {
      auto* parent = path.back();
      path.pop_back();
      auto* gparent  = path.back();
      path.pop_back();

      SplayTree::internalSplay( node, parent, gparent );

      if ( path.size() > 0 ) {
        if ( gparent == path.back()->left() ) {
          path.back()->setLeft(node);
        }
        else {
          assert( gparent == path.back()->right() );
          path.back()->setRight(node);
        }
      }
    }
  }

  return node;
}

template< class T>
TreeNode<T>* SplayTree<T>::internalSplay( TreeNode<T>* node, TreeNode<T>* parent, TreeNode<T>* gparent ) {
  assert( parent != NULL );
  assert( gparent != NULL );

  if ( gparent->left() == parent ) {
    // LL
    if ( parent->left() == node ) {
#if TRACE_ZIGZAG
      std::cout << "zigzig(LL)" << std::endl;
#endif
      gparent->setLeft( parent->right() );
      parent->setLeft( node->right() );
      node->setRight( parent );
      parent->setRight( gparent );
    }
    // LR
    else {
      assert( parent->right() == node );
#if TRACE_ZIGZAG
      std::cout << "zigzag(LR)" << std::endl;
#endif
      parent->setRight( node->left() );
      gparent->setLeft( node->right() );
      node->setLeft( parent );
      node->setRight( gparent );
    }
  }
  else {
    assert( gparent->right() == parent );
    // RL
    if ( parent->left() == node ) {
#if TRACE_ZIGZAG
      std::cout << "zigzag(RL)" << std::endl;
#endif
      parent->setLeft( node->right() );
      gparent->setRight( node->left() );
      node->setRight( parent );
      node->setLeft( gparent );
    }
    // RR
    else {
      assert( parent->right() == node );
#if TRACE_ZIGZAG
      std::cout << "zigzig(RR)" << std::endl;
#endif
      gparent->setRight( parent->left() );
      parent->setRight( node->left() );
      node->setLeft( parent );
      parent->setLeft( gparent );
    }
  }

  return node;
}

template< class T >
TreeNode<T>* SplayTree<T>::internalInsert( const T& elem, TreeNode<T>* node, std::vector< TreeNode<T>* >& path ) {
  assert( node != NULL );

  path.push_back(node);

  // Traverse left.
  if ( node->value() > elem ) {
    if ( node->left() != NULL ) {
      return SplayTree::internalInsert( elem, node->left(), path );
    }
    else {
      node->setLeft( ::createTreeNode(elem) );
      return node->left();
    }
  }
  // Traverse right.
  else {
    if ( node->right() != NULL ) {
      return SplayTree::internalInsert( elem, node->right(), path );
    }
    else {
      node->setRight( ::createTreeNode(elem) );
      return node->right();
    }
  }
}

template< class T >
void SplayTree<T>::insert( const T& elem ) {
  if ( root == NULL ) {
    root = ::createTreeNode( elem );
    return;
  }

  std::vector< TreeNode<T>* > path;
  TreeNode<T>* node = SplayTree::internalInsert( elem, root, path );

  root = SplayTree::splay(node, path);
}

template< class T >
const TreeNode<T>* SplayTree<T>::find( const T& ) const {
  return root;
}

// Instantiate the class for the int value type.
template class SplayTree<int>;
