#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int value;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val)
  {
    value = val;
    left = right = nullptr;
  }
};

TreeNode *createTree()
{
  // Create nodes with values
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  root->left->left->left = new TreeNode(8);
  root->left->left->right = new TreeNode(9);
  root->left->right->left = new TreeNode(10);
  root->left->right->right = new TreeNode(11);
  root->right->left->left = new TreeNode(12);
  root->right->left->right = new TreeNode(13);
  root->right->right->left = new TreeNode(14);
  root->right->right->right = new TreeNode(15);

  root->left->left->left->left = new TreeNode(16);
  root->left->left->left->right = new TreeNode(17);
  root->left->left->right->left = new TreeNode(18);
  root->left->left->right->right = new TreeNode(19);
  root->left->right->left->left = new TreeNode(20);
  root->left->right->left->right = new TreeNode(21);
  root->left->right->right->left = new TreeNode(22);
  root->left->right->right->right = new TreeNode(23);
  root->right->left->left->left = new TreeNode(24);
  root->right->left->left->right = new TreeNode(25);
  root->right->left->right->left = new TreeNode(26);
  root->right->left->right->right = new TreeNode(27);
  root->right->right->left->left = new TreeNode(28);
  root->right->right->left->right = new TreeNode(29);
  root->right->right->right->left = new TreeNode(30);
  root->right->right->right->right = new TreeNode(31);

  return root;
}

void printTree(TreeNode *root)
{
  if (root == nullptr)
    return;

  // Use a queue to do level order traversal
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    TreeNode *current = q.front();
    q.pop();

    cout << current->value << " ";

    if (current->left != nullptr)
    {
      q.push(current->left);
    }
    if (current->right != nullptr)
    {
      q.push(current->right);
    }
  }
  cout << endl;
}

int heighOfTree(TreeNode *node)
{
  if (node == nullptr)
  {
    return 0;
  }
  // cout << node->value << " ";
  return max(heighOfTree(node->left), heighOfTree(node->right)) + 1;
}

bool resetTree(TreeNode *node, int val, TreeNode *root, TreeNode *tempParent, TreeNode *parent, TreeNode *child, int &hightChild, int &hightParent)
{
  if (node == nullptr)
    return false;

  if (node->value == val)
  {
    parent = tempParent;
    hightChild = heighOfTree(node);
    child = node;
    cout << parent->value << " " << parent->left->value;
    return true;
  }

  bool left = resetTree(node->left, val, root, node, parent, child, hightChild, hightParent);
  bool right = resetTree(node->right, val, root, node, parent, child, hightChild, hightParent);
  int tempvar = tempParent ? tempParent->value : -2;
  cout << endl << left << " " << node->value << " " << right << " " << parent->value << " " << root->value << " " << tempvar << endl;

  if (left)
  {
    node->left = tempParent;
    if(tempParent && tempParent->left == node) tempParent->left = nullptr;
    if(tempParent && tempParent->right ==node ) tempParent->right = nullptr; 
    if (node->value == root->value)
    {
      printTree(root);
      cout << endl << "paret" << parent->value << endl;
      // hightParent = heighOfTree(parent);
      return false;
    }
    return true;
  }
  
  cout << root->left->value << root->right->left->value;
  if (right)
  {
    node->right = tempParent;
    if (node->value == root->value)
    {
      if(tempParent && tempParent->left == node) tempParent->left = nullptr;
      if(tempParent && tempParent->right ==node ) tempParent->right = nullptr; 
      printTree(root);
      cout << endl  << "paret" << parent->value << endl;
      // hightParent = heighOfTree(root);
      return false;
    }
    return true;
  }

  return false;
}

int main()
{
  TreeNode *root = createTree();
  cout << "Level order traversal of the tree:" << endl;
  TreeNode *parent, *tempParent, *child;
  int hightChild, hightParent;
  resetTree(root, 14, root, tempParent, parent, child, hightChild, hightParent);
  cout << endl << "heighOfTree: " << hightChild << " " << hightParent;

  return 0;
}
