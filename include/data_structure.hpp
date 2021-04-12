#pragma once
#include "node.hpp"
// Заголовочный файл с объявлением структуры данных

namespace itis
{

  struct AATree
  {
   public:
    Node *root;


    AATree();
    explicit AATree(Node *x);
    Node *search(int x);
    void insert(int x);
    void remove(int x);
    ~AATree();
  };

}