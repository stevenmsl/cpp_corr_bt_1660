#include "solution.h"

#include <functional>
#include <queue>
#include <unordered_set>
using namespace sol1660;
using namespace std;

/* takeaways
   - do a BFS search as the invalid node's right is
     pointing to a sibling (same level) at its right
     - so we need to visit node's children from right
       to left
   - while visiting, record a node's children in a set
     if they are valid: that set will include the next
     level nodes (children)
   - check if a child is valid
     - if child->right is in the set mentioned
       above, we are done here.
*/

Node *Solution::correct(Node *root)
{
  /* for BFS */
  queue<Node *> q;
  /* to store nodes from the same level */
  unordered_set<Node *> levlNodes;

  q.push(root);
  int size = q.size();

  /* BFS */

  while (size > 0)
  {
    auto node = q.front();
    q.pop();

    /*
       - we need to build the set with
         the rightmost child in the set
         first as the invalid node's
         right will point to a right
         node at the same level per
         the question
       - visit right child first
    */
    if (node->right != nullptr)
    {
      if (levlNodes.count(node->right->right))
      {
        /*
           - remove this child node and
             we are done
        */
        node->right = nullptr;
        return root;
      }
      else
      {
        levlNodes.insert(node->right);
        q.push(node->right);
      }
    }

    /* visit left */
    if (node->left != nullptr)
    {
      if (levlNodes.count(node->left->right))
      {
        node->left = nullptr;
        return root;
      }
      else
      {
        levlNodes.insert(node->left);
        q.push(node->left);
      }
    }

    size--;
    /* visit next level */
    if (size == 0)
    {
      size = q.size();
      levlNodes.clear();
    }
  }

  return root;
}