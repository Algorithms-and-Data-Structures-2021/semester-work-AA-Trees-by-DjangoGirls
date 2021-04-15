#pragma once
#include "node.hpp"
// Заголовочный файл с объявлением структуры данных

namespace itis
{

  struct AATree
  {
   public:
    Node *root;
    int size_;
    int max_lvl_;

    AATree();
    explicit AATree(Node *x);
    Node *search(int x);
    void insert(int x);
    void remove(int x);
    Node *skew(Node *x);
    Node *split(Node *x);
    ~AATree();
  };

}