#include <iostream>
#include "data_structure.hpp"

namespace itis {


  AATree::AATree()
  {
    this->root = nullptr;
    this->size_ = 0;
    this->max_lvl_ = 0;
  }

  AATree::AATree(Node *tree_root)
  {
    this->root = tree_root;
    this->size_ = 1;
    this->max_lvl_ = 1;
  }

  AATree::~AATree()
  {
    this->root = nullptr;
    this->size_ = 0;
    this->max_lvl_ = 0;
  }

  bool AATree::research(Node *root_pointer, int x) {
    bool found = false;
    int rval;
    Node* temp = root_pointer;
    while(!found){
      rval = temp->data;
      if(x < rval){
        if(temp->left_child != 0){
          temp = temp->left_child;
        }else{
          break;
        }

      }else if(x > rval){
        if(temp->right_child != 0){
          temp = temp->right_child;
        }else{
          break;
        }

      }else{
        found = true;
      }
    }
    return found;
  }

  bool AATree::search(int x) {
    if(research(root, x)){
      return true;
    }
    return false;
  }

  void AATree::insert(int x)  // вставка как в обычном бинарном
  // все хуйня, надо переделать метод
  {
    if (root == nullptr)
    {
      root = new Node(x);
      return;
    }
    Node *curr = this->root;
    while (curr != nullptr)
    {
      if (x < curr->data)
      {
        if (curr->left_child == nullptr)
        {
          Node *new_node = new Node(x);
          curr->left_child = new_node;
          this->root = new_node;
          return;
        } else
        {
          curr = curr->left_child;
        }
      } else if (x >= curr->data)
      {
        if (curr->right_child == nullptr)
        {
          Node *new_node = new Node(x);
          curr->right_child = new_node;
          this->root = new_node;
          return;
        } else
        {
          curr = curr->right_child;
        }
      }
    }
  }

  void AATree::remove(int x)
  // удаление элемента как в бинарном, создание из него дерева, если необходимо и
  // приделать как правую вершину к изначальному дереву
  // все хуйня, надо переделать метод
  {
    Node *del = search(x);
    if (del == nullptr)
    {
      return;
    }
    Node *L = del->left_child;
    if (L == nullptr)
    {
      root = del->right_child;
      delete del;
      return;
    }
    while (L->right_child != nullptr)
    {
      L = L->right_child;
    }
    if (del->right_child != nullptr)
    {
      L->right_child = del->right_child;
    }
    root = del->left_child;
    delete del;
  }

  // теперь нужно написать функцию, которая обрабатывает все варианты расположения вершин в АА дереве
  // и засунуть их в те что выше
  Node *AATree::skew(Node *x) {
  if (x->left_child == nullptr) {
    return x;
  }  if (x->left_child->lvl == x->lvl) {
    Node *y = x->left_child;
    x->left_child = y->right_child;
    y->right_child = x;
    return y;
  }
  return x;

  }

  Node *AATree::split(Node *x) {
    if (((x->left_child == nullptr) and (x->right_child == nullptr))
        or (x->right_child == nullptr) or (x->right_child->right_child == nullptr)) {
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

}
