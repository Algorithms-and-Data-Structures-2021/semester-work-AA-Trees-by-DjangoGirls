#include <iostream>
#include "data_structure.hpp"

namespace itis {

  using namespace std;

  //  int main(int argc, char *argv[]) {
  //    for (int index = 0; index < argc; index++) {
  //      cout << index << ": " << argv[index] << endl;
  //    }
  //    return 0;
  //  }

  AATree::AATree()
  {
    this->root = nullptr;
  }

  AATree::AATree(Node *tree_root)
  {
    this->root = tree_root;
  }

  AATree::~AATree()
  {
    Node *curr = this->root;
  }


  Node *AATree::search(int x) {
    Node *ret = nullptr;
    Node *curr = this->root;
    Node *prev = nullptr;
    while (curr != nullptr)
    {
      prev = curr;
      if (x < curr->data)
      {
        curr = curr->left_child;
      } else if (x > curr->data)
      {
        curr = curr->right_child;
      } else
      {
        ret = curr;
        break;
      }
    }
//
    return chto-to;
  }


  void AATree::insert(int x)  // вставка как в обычном бинарном
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
          new_node->parent = curr;
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
          new_node->parent = curr;
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
      root->parent = nullptr;
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
      del->right_child->parent = L;
    }
    root = del->left_child;
    root->parent = nullptr;
    delete del;
  }

  // теперь нужно написать функцию, которая обрабатывает все варианты расположения вершин в АА дереве
  // и засунуть их в те что выше
}