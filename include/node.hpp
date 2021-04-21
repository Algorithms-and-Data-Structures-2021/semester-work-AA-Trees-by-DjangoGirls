#pragma once

namespace itis
{
  struct Node
  {
   public:
    int data;
    int lvl;
    Node *left_child;
    Node *right_child;


    explicit Node(int node_key)
    {
      this->data = node_key;
      this->left_child = nullptr;
      this->right_child = nullptr;
      this->lvl = 1;
    }

  };
}  // namespace itis