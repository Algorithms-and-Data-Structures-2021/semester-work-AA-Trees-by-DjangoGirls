#include <iostream>
#include "data_structure.hpp"

namespace itis {

  AATree::AATree() {
    this->root = nullptr;
  }

  AATree::AATree(Node *tree_root) {
    this->root = tree_root;
  }

  AATree::~AATree() {
    this->root = nullptr;
  }

  bool AATree::research(Node *root_pointer, int x) {
    bool found = false;
    if (root_pointer == nullptr) {
      return false;
    }
    int rval;
    Node *temp = root_pointer;
    while (!found) {
      rval = temp->data;
      if (x < rval) {
        if (temp->left_child != nullptr) {
          temp = temp->left_child;
        } else {
          break;
        }

      } else if (x > rval) {
        if (temp->right_child != nullptr) {
          temp = temp->right_child;
        } else {
          break;
        }

      } else {
        found = true;
      }
    }
    return found;
  }

  bool AATree::search(int x) {
    return (research(this->root, x));
  }

  Node *AATree::skew(Node *x) {
    if (x->left_child == nullptr) {
      return x;
    }
    if (x->left_child->lvl == x->lvl) {
      Node *y = x->left_child;
      x->left_child = y->right_child;
      y->right_child = x;
      return y;
    }
    return x;
  }

  Node *AATree::split(Node *x) {
    if (((x->left_child == nullptr) and (x->right_child == nullptr)) or (x->right_child == nullptr)
        or (x->right_child->right_child == nullptr)) {
      return x;
    }
    if (x->lvl == x->right_child->right_child->lvl) {
      Node *y = x->right_child;
      x->right_child = y->left_child;
      y->left_child = x;
      y->lvl++;
      return y;
    }
    return x;
  }

  bool isEmpty(Node *n) {
    return n->data == 0;
  }

  void AATree::insert(int x) {
    if (!research(root, x)) {
      root = insert(x, root);
      return;
    }
  }

  Node *AATree::insert(int x, Node *V) {
    if (V == nullptr) {
      return new Node(x);
    } else if (x < V->data) {
      V->left_child = insert(x, V->left_child);
    } else if (x > V->data) {
      V->right_child = insert(x, V->right_child);
    }
    V = skew(V);
    V = split(V);
    return V;
  }

  Node *AATree::predecessor(Node *current) {

    current = current->left_child;
    while (current->right_child != 0) {
      current = current->right_child;
    }
    return current;
  }

  Node *AATree::successor(Node *current) {

    current = current->right_child;
    while (current->left_child != 0) {
      current = current->left_child;
    }
    return current;
  }

  Node *AATree::decreaselvl(Node *t) {

    int s;
    if (t->left_child != 0 && t->right_child != 0) {

      if (t->left_child->lvl > t->right_child->lvl) {
        s = t->right_child->lvl;
      } else {
        s = t->left_child->lvl;
      }
      if (s < t->lvl) {
        t->lvl = s;
        if (t->right_child != 0 && s < t->right_child->lvl) {
          t->right_child->lvl = s;
        }
      }
    }

    return t;
  }

  Node *AATree::removeData(Node *t, int x) {
    Node *m;
    if (isEmpty(t))
      return 0;
    if (x < t->data) {
      t->left_child = removeData(t->left_child, x);
    } else if (x > t->data) {
      t->right_child = removeData(t->right_child, x);
    } else {
      if (t->left_child == 0 && t->right_child == 0) {
        return 0;
      }
      if (t->left_child == 0) {

        Node *l;
        l = successor(t);
        t->data = l->data;
        t->right_child = removeData(t->right_child, l->data);
      } else {
        Node *l;
        l = predecessor(t);
        t->data = l->data;
        t->left_child = removeData(t->left_child, l->data);
      }
    }
    t = decreaselvl(t);
    t = skew(t);
    if (t->right_child != 0) {
      m = t->right_child;
      t->right_child = skew(m);
      if (!isEmpty(m) && m->right_child != 0) {
        t->right_child->right_child = skew(m->right_child);
      }
      t = split(t);
    }

    return t;
  }

  void AATree::removeData(int x) {
    if (research(root, x)) {
      root = removeData(root, x);
      return;
    }
  }
}