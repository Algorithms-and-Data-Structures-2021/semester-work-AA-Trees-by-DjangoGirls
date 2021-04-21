#pragma once
#include "node.hpp"
// Заголовочный файл с объявлением структуры данных

namespace itis
{

  struct AATree
  {
   public:
    Node * root;

    AATree();
    explicit AATree(Node *x);
    bool research(Node *root_pointer, int x);
    bool search(int x);
    void insert(int x);
    void removeData(int x);
    Node *removeData(Node * t, int x);
    Node *skew(Node *x);
    Node *split(Node *x);
    Node *insert(int x, Node *V);
    Node *decreaselvl(Node* t);
    Node *successor(Node * current);
    Node *predecessor(Node * current);
    Node *remove(Node* root_pointer, int x);
    ~AATree();
  };

}