// HashTable, 1123 Lowest Common Ancestor of Deepest Leaves
typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
} Node;

int dfsMaxDepth(Node *node, int depth, int *maxDepthList) {
  int ld = depth, rd = depth; // left/right depth
  if (node->left)
    ld = dfsMaxDepth(node->left, depth + 1, maxDepthList);
  if (node->right)
    rd = dfsMaxDepth(node->right, depth + 1, maxDepthList);
  return maxDepthList[node->val] = ld > rd ? ld : rd;
}

Node *dfsLCA(Node *node, const int maxDepth, int *maxDepthList) {
  if (node->left) {
    if (node->right) {
      if (maxDepthList[node->left->val] == maxDepth) {
        if (maxDepthList[node->right->val] == maxDepth)
          return node;
        return dfsLCA(node->left, maxDepth, maxDepthList);
      }
      return dfsLCA(node->right, maxDepth, maxDepthList);
    }
    return dfsLCA(node->left, maxDepth, maxDepthList);
  }
  if (node->right)
    return dfsLCA(node->right, maxDepth, maxDepthList);
  return node;
}

struct TreeNode *lcaDeepestLeaves(struct TreeNode *root) {
  // maxDepthList[] uses node's val as index, this array tracks the max depth a
  // node's subtree's nodes can reach in the original tree
  int maxDepthList[1001] = {0};
  int maxDepth = dfsMaxDepth(root, 0, maxDepthList);
  // find LCA node
  return dfsLCA(root, maxDepth, maxDepthList);
}
