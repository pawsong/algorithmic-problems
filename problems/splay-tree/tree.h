
#include <cstddef>

template<class T>
class TreeNode {
 private:
  TreeNode* r;
  TreeNode* l;
  T v;

 public:
  TreeNode( const T& val ) : v(val), r(NULL), l(NULL) {}

  // TODO: deep copy of the whole tree.
  TreeNode( const TreeNode& n ) {}
  TreeNode& operator=( const TreeNode& n ) {
    return *this;
  }

  inline const TreeNode* right() const {
    return r;
  }
  inline TreeNode* right() {
    return r;
  }
  inline const TreeNode* left() const {
    return l;
  }
  inline TreeNode* left() {
    return l;
  }
  inline const T& value() const {
    return v;
  }
  inline void setRight( TreeNode<T>* n ) {
    r = n;
  }
  inline void setLeft( TreeNode<T>* n ) {
    l = n;
  }
};

template<class T>
class SplayTree {
 private:
  TreeNode<T>* root;

  TreeNode<T>* splay( TreeNode<T>*, std::vector< TreeNode<T>* >& );
  TreeNode<T>* internalSplay( TreeNode<T>*, TreeNode<T>*, TreeNode<T>* );

  TreeNode<T>* internalInsert( const T&, TreeNode<T>*, TreeNode<T>* );
  TreeNode<T>* internalInsert( const T&, TreeNode<T>*, std::vector< TreeNode<T>* >& );

 public:
  SplayTree() : root(NULL) {}

  inline TreeNode<T>* rootNode() const {
    return root;
  }

  void insert( const T& );

  const TreeNode<T>* find( const T& ) const;
  bool contains( const T& val ) const {
    return (find( val ) != NULL);
  }
};
