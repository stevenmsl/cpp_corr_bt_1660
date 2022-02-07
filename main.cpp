#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1660;

Node *testFixture1()
{
  auto tree = new Node(1);
  tree->right = new Node(3);
  /* invalid node */
  tree->left = new Node(2);
  tree->left->right = tree->right;

  return tree;
}

Node *testFixture2()
{
  auto tree = new Node(8);
  tree->right = new Node(1);
  tree->right->left = new Node(9);
  tree->right->right = new Node(4);
  tree->right->right->left = new Node(5);
  tree->right->right->right = new Node(6);

  tree->left = new Node(3);
  tree->left->left = new Node(7);
  /* invalid node */
  tree->left->left->right = tree->right->right;
  tree->left->left->left = new Node(2);

  return tree;
}

void test1()
{
  cout << "Test 1 - node 2 should be removed" << endl;
  auto fixture = testFixture1();
  Solution sol;
  auto tree = sol.correct(fixture);
  cout << "result - use debugger to verify" << endl;
}

void test2()
{
  cout << "Test 2 - node 7 should be removed" << endl;
  auto fixture = testFixture2();
  Solution sol;
  auto tree = sol.correct(fixture);
  cout << "result - use debugger to verify" << endl;
}

main()
{
  test1();
  test2();
  return 0;
}