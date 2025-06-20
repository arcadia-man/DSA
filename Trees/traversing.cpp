#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  TreeNode *left;
  TreeNode *right;
  int val;

  TreeNode()
  {
    left = NULL;
    right = NULL;
    val = 0;
  }
};

TreeNode *buildTreePreOrder(vector<int> &ve, int left, int right)
{
  if (left > right)
  {
    return NULL;
  }
  TreeNode *node = new TreeNode();
  node->val = ve[left];
  int mid = (left + right) / 2;
  node->left = buildTreePreOrder(ve, left + 1, mid);
  node->right = buildTreePreOrder(ve, mid + 1, right);
  return node;
};

TreeNode *buildTreePostOrder(vector<int> &ve, int left, int right)
{
  if (left > right)
  {
    return NULL;
  }
  TreeNode *node = new TreeNode();
  node->val = ve[right];
  int mid = (left + right) / 2;
  node->left = buildTreePostOrder(ve, left, mid - 1);
  node->right = buildTreePostOrder(ve, mid, right - 1);
  return node;
};

TreeNode *buildTreeInOrder(vector<int> &ve, int left, int right)
{
  if (left > right)
  {
    return NULL;
  }
  int mid = (left + right) / 2;
  TreeNode *node = new TreeNode();
  node->val = ve[mid];
  node->left = buildTreeInOrder(ve, left, mid - 1);
  node->right = buildTreeInOrder(ve, mid + 1, right);
  return node;
}

void printPreOrder(TreeNode *node)
{
  if (node)
  {
    cout << node->val << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
  }
};

void printPostOrder(TreeNode *node)
{
  if (node)
  {
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->val << " ";
  }
};

void printInOrder(TreeNode *node)
{
  if (node)
  {
    printInOrder(node->left);
    cout << node->val << " ";
    printInOrder(node->right);
  }
};

void printLevelOrder(TreeNode *node)
{
  queue<TreeNode *> q;

  if (node)
  {
    q.push(node);
    q.push(NULL);
  }

  while (!q.empty())
  {
    if (q.front())
    {
      cout << q.front()->val << " ";
      if (q.front()->left)
        q.push(q.front()->left);
      if (q.front()->right)
        q.push(q.front()->right);
      q.pop();
    }
    else
    {
      q.pop();
      if (!q.empty())
        q.push(NULL);
      cout << endl;
    }
  }
}

int heighOfTree(TreeNode* node){
  if(node == NULL){
    return 0;
  }
  return (heighOfTree(node->left), heighOfTree(node->right)) + 1;
}



int main()
{
  vector<int> ve = {12, 45, 3, 29, 8, 19, 34, 27, 5, 14, 39, 1, 50, 23, 7};
  // With the give single array we can only make the Balanced Tree
  // To make non balanced tree we need to have the two array of either of traversal
  TreeNode *preTree = buildTreePreOrder(ve, 0, ve.size() - 1);
  printPreOrder(preTree);
  cout << endl;
  printLevelOrder(preTree);
  cout << endl;
  TreeNode *postTree = buildTreePostOrder(ve, 0, ve.size() - 1);
  printPostOrder(postTree);
  cout << endl;
  printLevelOrder(postTree);
  cout << endl;
  TreeNode *inTree = buildTreeInOrder(ve, 0, ve.size() - 1);
  printInOrder(inTree);
  cout << endl;
  printLevelOrder(inTree);
  cout << endl;
  
  cout<< "Height of tree: " << heighOfTree(inTree) << endl;
  return 0;
}
