/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include "assert.h"
using namespace std;
 /*******************************************************************************
 例题:20

 *******************************************************************************/



/*******************************************************************************
例题：144 binary tree preorder traversal

*******************************************************************************/
//递归的方式
void preorder(TreeNode* node, vector<int> &temp){
  if(node){
    temp.push_back(node->val);
    preorder(node->left, temp);
    preorder(node->right, temp);
  }
}
vector<int> preorderTraversal(TreeNode* root) {
  vector<int> result;
  if(root){
    preorder(root, result);
  }
  return result;
}
//迭代的方式-stack解决方法，使用栈改造递归算法
//先推入执行，在根位置推入三步
struct Command {
  string s;//go print
  TreeNode *node;
  Command(string s, TreeNode* node): s(s), node(node){};
};
vector<int> preorderTraversal(TreeNode* root) {
  vector<int> res;
  if(root == NULL)
    return res;
  stack<Command> stack;
  stack.push( Command("go", root) );
  while(!stack.empty()){
    Command command = stack.top();
    stack.pop();

    if(command.s == "print")
      res.push_back(command.node->val);
    else{
      assert(command.s == "go");
      if(command.node->right)
        stack.push(Command("go",command.node->right));
      if(command.node->left)
        stack.push(Command("go",command.node->left));
      stack.push(Command("print", command.node));
    }
  }

  return res;
}
/*******************************************************************************
例题： 94.binary tree inorder traversal

*******************************************************************************/
//迭代方式：
void inorder(TreeNode* node, vector<int> &res){
  if(node){
    inorder(node->left, res);
    res.push_back(node->val);
    inorder(node->right, res);
  }
}
vector<int> inorderTraversal(TreeNode* root) {
  vector<int> res;
  if(root){
    inorder(root, res);
  }
  return res;
}
//非迭代方式
struct Command {
  string s;//go print
  TreeNode *node;
  Command(string s, TreeNode* node): s(s), node(node){};
};
vector<int> inorderTraversal(TreeNode* root) {
  vector<int> res;
  if(root == NULL)
    return res;
  stack<Command> stack;
  stack.push( Command("go", root) );
  while(!stack.empty()){
    Command command = stack.top();
    stack.pop();

    if(command.s == "print")
      res.push_back(command.node->val);
    else{
      assert(command.s == "go");
      if(command.node->right)
        stack.push(Command("go",command.node->right));
      stack.push(Command("print", command.node));
      if(command.node->left)
        stack.push(Command("go",command.node->left));
    }
  }

  return res;
}

/*******************************************************************************
例题：145binary tree postorder traversal

*******************************************************************************/
struct Command {
  string s;//go print
  TreeNode *node;
  Command(string s, TreeNode* node): s(s), node(node){};
};
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> res;
  if(root == NULL)
    return res;
  stack<Command> stack;
  stack.push( Command("go", root) );
  while(!stack.empty()){
    Command command = stack.top();
    stack.pop();

    if(command.s == "print")
      res.push_back(command.node->val);
    else{
      assert(command.s == "go");
      stack.push(Command("print", command.node));
      if(command.node->right)
        stack.push(Command("go",command.node->right));
      if(command.node->left)
        stack.push(Command("go",command.node->left));
    }
  }

  return res;
}

/*******************************************************************************
例题：341.flatten nested list iterator
设计一个迭代器，遍历整个整形列表中所有整数
*******************************************************************************/



/*******************************************************************************
例题：102 binary tree lvel order traversal
二叉树的层序遍历
队列
队列进行层序遍历-广度优先遍历
对一个数进行层序遍历

方法：
  将根推入队列
  只要队列不为去front，将子节点入队
*******************************************************************************/
vector<vector<int>> levelOrder(TreeNode* root) {
  vector< vector<int>> res;
  if(root == NULL)
    return res;
  queue< pair<TreeNode*, int> > q;
  q.push( make_pair( root, 0) );

  while( !q.empty()){
    TreeNode* node = q.front().first;
    int level = q.front().second;
    q.pop();

    if( level == res.size() ){//索引小于size
      res.push_back( vector<int>() );
    }
    res[level].push_back(node->val);
    if(node->left)
      q.push( make_pair( node->left, level+1) );
    if(node->right)
      q.push( make_pair( node->right, level+1) );
  }

  return res;
}

/*******************************************************************************
例题：107
从底层到上层的节点
队列进行层序遍历
//将vector翻转
*******************************************************************************/
vector<vector<int>> levelOrder(TreeNode* root) {
  vector< vector<int>> res;
  if(root == NULL)
    return res;
  queue< pair<TreeNode*, int> > q;
  q.push( make_pair( root, 0) );

  while( !q.empty()){
    TreeNode* node = q.front().first;
    int level = q.front().second;
    q.pop();

    if( level == res.size() ){//索引小于size
      res.push_back( vector<int>() );
    }
    res[level].push_back(node->val);
    if(node->left)
      q.push( make_pair( node->left, level+1) );
    if(node->right)
      q.push( make_pair( node->right, level+1) );
  }
  vector< vector<int>> result;
  for(int i = res.size() - 1; i >= 0; i--)
    result.push_back(res[i]);
  return result;
}
/*******************************************************************************
例题：103 binary tree zigzag level order traversal
进行层序遍历，按照之字形返回多有节点
队列进行层序遍历
最后对偶数层进行翻转
之字形，树的处理
*******************************************************************************/
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  vector< vector<int>> res;
  if(root == NULL)
    return res;
  queue< pair<TreeNode*, int> > q;
  q.push( make_pair( root, 0) );

  while( !q.empty()){
    TreeNode* node = q.front().first;
    int level = q.front().second;
    q.pop();

    if( level == res.size() ){//索引小于size
      res.push_back( vector<int>() );
    }
    res[level].push_back(node->val);
    if(node->left)
      q.push( make_pair( node->left, level+1) );
    if(node->right)
      q.push( make_pair( node->right, level+1) );
  }
  //进行单独翻转
  for(int i = 1; i < res.size(); i += 2){
    reverse(res[i].begin(), res[i].end());
  }
  return res;
}
/*******************************************************************************
例题：199 binary tree right side view
站在一棵二叉树右侧，返回可以看见的节点
队列进行层序遍历
*******************************************************************************/
vector<int> rightSideView(TreeNode* root) {
  vector<int> res;
  if(root == NULL)
    return res;
  queue< pair<TreeNode*, int> > q;
  q.push( make_pair( root, 0) );

  while( !q.empty()){
    TreeNode* node = q.front().first;
    int level = q.front().second;
    q.pop();

    if( level == res.size() ){//索引小于size
      res.push_back( node->val);
    }
    res[level] = node->val;
    if(node->left)
      q.push( make_pair( node->left, level+1) );
    if(node->right)
      q.push( make_pair( node->right, level+1) );
  }
  return res;
}


/*******************************************************************************
例题：279 perfect squarrs
BFS和图的最短路径

问题：
  没有解怎么办
  是否可能没有解
贪心算法不可用
解法：
  对整个问题建模
  整个问题转化为一个图论问题
  如果x与y相差一个完全平方数，则链接一条边。
  得到一个无权图。
  无权图中从n到0的最短路径
*******************************************************************************/
int numSquares(int n){
  assert(n>0);
  queue< pair<int ,int>> q;
  q.push( make_pair(n, 0));
  vector<bool> visited(n+1, false);
  visited[n] = true;
  while( !q.empty()){
    int num = q.front().first;
    int step  = q.front().second;
    q.pop();

    if(num == 0)
      return step;
    for(int i = 1; num - i*i >= 0; i++){
      int a = num - i*i;
      if(a == 0)
        return step+1;
      if(!visited[a]){
        q.push( make_pair( num - i*i, step + 1));
        visited[a] = true;
    }
  }

}

/*******************************************************************************
例题：127 word ladder
给出两个单词，从beginword到endword最短变换路径
未解决
*******************************************************************************/
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
  int distance = 0;
  queue<string,int> q;
  q.push(make_pair(beginWord, 0));
  while(!q.empty()){
    string str = q.front().first;
    int num = q.front().second;
    q.pop();

    for(int i = 0; i < str.size(); i++){
      for(char j = 'a'; j <= 'z'; j++){
        if(j == str[i])
          continue;
        char tem = str[i];
        str[i] = j;
        if(str == end)
          return num+1;
        if(find(wordList.begin(), wordList.end(), str)){
          q.push(str);
          wordList.erase(str);
        }
        str[i] = tem;
      }
    }
  }
  return 0;
}
/*******************************************************************************
例题：126 Word Ladder II
给出两个单词，从beginword到endword最短变换路径，并输出最短路径
*******************************************************************************/

/*******************************************************************************
例题：347 Top k frequent elments
优先队列题，优先队列也是队列，寻找队列中最大最小值进行出队。
基于堆进行实现
给定一个非数组，返回前k个出现频率醉倒的元素
使用map很简单，进行排序取前k个元素，时间复杂度，o(nlogn)

瓶颈在排序过程中，使用优先队列
使用优先队列，进行维护，时间复杂度o(nlogk)
*******************************************************************************/
vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> freq;
  for(int i = 0; i<nums.size(); i++)
    freq[nums[i]] ++;
  assert(k <= freq.size());

  priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
  for(unordered_map<int, int>::iterator iter = freq.begin(); iter != freq.end(); iter++){
    if(pq.size() == k ){
      //int num = pq.top().second;
      if(pq.top().second < iter->second){
          pq.pop();
          pq.push(make_pair(iter->first, iter->second));
      }
    }
    else
      pq.push(make_pair(iter->first, iter->second));
  }
  //return vector<int>(pq.begin(), pq.end());
  vector<int> res;
  while(!pq.empty()){
    res.push_back(pq.top().first);
    pq.pop();
  }
  return res;
}


/*******************************************************************************
例题：23 merge k sorted lists
难度：hard
有k个有序数组麻将他们归并为一个有序数组
*******************************************************************************/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*******************************************************************************
例题：104 maximum depth of bunaty tree
传入二叉树返回最大深度
*******************************************************************************/
int maxDepth(TreeNode* root) {
    if(root == NULL)
        return 0;
    int maxleft = maxDepth(root->left);
    int maxright = maxDepth(root->right);
    return max(maxleft, maxright) + 1;
}


/*******************************************************************************
例题：111 minimum depth of binary tree

所谓底层节点就是到最底层无子节点的节点。
*******************************************************************************/
int minDepth(TreeNode *root) {
    if(!root) return 0;
    if(!root->left) return 1 + minDepth(root->right);
    if(!root->right) return 1 + minDepth(root->left);
    return 1+min(minDepth(root->left),minDepth(root->right));
}
//广度优先遍历
//有问题？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
// int minDepth(TreeNode *root) {
//     if(root == NULL) return 0;
//     queue<TreeNode*> q;
//     queue.push(root);
//     int len = 0;
//     while(!q.empty()){
//         TreeNode* node = q.front();
//         if(node->left) q.push(node->left);
//         if(node->right) q.push(node->right);
//         q.pop();
//
//         if(node->left == NULL && node->right == NULL)
//             return i;
//
//     }
// }
/*******************************************************************************
例题：226 invert binary tree
反转一棵二叉树
*******************************************************************************/
TreeNode* invertTree(TreeNode* root) {
    if( root == NULL )
        return NULL;

    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;
}
/*******************************************************************************
例题：100same tree
采用递归方式判断两个二叉树是否相同
*******************************************************************************/
// bool isSameTree(TreeNode* p, TreeNode* q) {
//     if( p == NULL && q == NULL)
//         return true;
//     if( p == NULL || q == NULL)
//         return false;
//
//     if(p->val != q->val)
//         return false;
//     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//
// }
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL || q == NULL) return p == q;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q)
        return true;
    else if (p && q)
        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right,q->right));
    else
        return false;
}
/*******************************************************************************
例题：101 symmetric tree
判断二叉树是否左右对称
*******************************************************************************/
bool helper(TreeNode* p, TreeNode* q){
    if( p==NULL || q==NULL) return p==q;

    if(p->val != q->val )
        return false;
    return helper(p->left, q->right) && helper(p->right, q->left);
}
bool isSymmetric(TreeNode* root) {
        if( root == NULL )
            return true;
        return helper(root->left, root->right);
}
/*******************************************************************************
例题：222
给定一颗完全二叉树，求完全二叉树的节点个数
完全二叉树：除了最后一层， 所有层的节点数达到了最大，与此同时，最后一层的所有节点都在最左侧（堆使用完全二叉树）
满二叉树：所有层的节点数达到最大
递归非常简单，但是会堆溢出
*******************************************************************************/
//时间复杂度超时
int countNodes(TreeNode* root) {
    if(root == NULL)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

int countNodes(TreeNode* root){
    if(root == NULL)
        return 0;

    int hl = 0, hr = 0;
    TreeNode* l = root, * r = root;
    while(l){
        hl++;
        l = l->left;
    }
    while(r){
        hr ++;
        r = r->right;
    }
    if(hl == hr)
        return pow(2, hr) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
/*******************************************************************************
例题：110 balanced binary tree
平衡二叉树：每一个节点的左右子树的高度差不超过1
判断一棵二叉树是平衡二叉树
*******************************************************************************/
int countNodes(TreeNode* node){
    if(node == NULL )
        return 0;
    return max(countNodes(node->left), countNodes(node->right))+1 ;
}
bool isBalanced(TreeNode* root) {
    if(root == NULL)
        return true;
    if(abs(countNodes(root->left) - countNodes(root->right))>1 )
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
/*******************************************************************************
例题：112 path sum
给出一颗二叉树以及一个数组sum，判断在这颗二叉树上是否存在一条从根到叶子的路径，其路径上
的所有节点和为sum

注意递归终止条件!!!
*******************************************************************************/
bool hasPathSum(TreeNode* root, int sum) {
    if(root == NULL)
        return false;

    if(root->left == NULL && root->right == NULL)//注意终止条件
        return sum == root->val;

    if(hasPathSum(root->left, sum - root->val))
        return true;
    if(hasPathSum(root->right, sum - root->val))
        return true;

    return false;
}

/*******************************************************************************
例题：404 sum of left leaves
求一颗二叉树所有左叶子的和
为左节点，且不存在左右子节点，即为要求的左叶子
*******************************************************************************/
int sumOfLeftLeaves(TreeNode* root) {
    if(root == NULL)
        return 0;
    if(root->left && root->left->left == NULL && root->left->right == NULL)
        return root->left->val + sumOfLeftLeaves(root->right);
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

/*******************************************************************************
例题：257 ninary tree paths
终止条件与递归过程
*******************************************************************************/
//to_string 将整形转换为字符串类型
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;



}

/*******************************************************************************
例题：113 path sum 2

*******************************************************************************/



/*******************************************************************************
例题：129 sum root to leaf numbers

*******************************************************************************/




/*******************************************************************************
例题：437 path sum III
对于一棵树，对于一个路径，和为一个target值，路径不一定为头结点，尾节点为叶子结点。
*******************************************************************************/
int pathSum(TreeNode* root, int sum){
    if(root == NULL)
        return 0;

    int res = 0;
    res += findPath(root, sum);
    res += pathSum(root->left, sum);
    res += pathSum(root->right, sum);
    return res;
}

int findPath(TreeNode* root, int sum){

    if(root == NULL)
        return 0;
    int res = 0;
    if(root->val == sum)
        res += 1;
    res += findPath(root->left, sum - root->val);
    res += findPath(root->right, sum - root->val);
    return res;
}
/*******************************************************************************
例题：235 lowest common ancestor of a ninary search tree
对于一个节点：如果一个大于node，一个小于node，则本节点就是最小公共祖先
如果p、q一个大于一个小于就可以写代码
*******************************************************************************/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if( root == NULL || p == NULL || q == NULL)
        return NULL;
    if(p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    if(p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    return root;
}


/*******************************************************************************
例题：98 Validate Binary Search Tree

*******************************************************************************/
// bool isValidBST(TreeNode* root) {
//     if(root == NULL)
//         return true;
//
//     if( root ->left == NULL && root->right == NULL)
//         return true;
//     TreeNode* left = findLeft(root->left);
//     TreeNode* right = findRight(root->right);
//     if(left == NULL && right == NULL)
//         return true;
//     else if(left == NULL)
//         if(right->val <= root->val)
//             return false;
//     else if(right == NULL)
//         if(left->val >= root->val)
//             return false;
//     else
//         if( left->val >= root->val || right->val <= root->val)
//             return false;
//     return isValidBST(root->left) && isValidBST(root->right);
// }
// TreeNode* findLeft(TreeNode* root){
//     if(root == NULL){
//         return NULL;
//     }
//     if(root->right)
//         return findLeft(root->right);
//     return root;
// }
// TreeNode* findRight(TreeNode* root){
//     if(root == NULL)
//         return NULL;
//     if(root->left)
//         return findRight(root->left);
//     return root;
// }
//每次传入最大值，最小值，进行比较，结果不正确，就进行返回，
//注意：每次比较前判断当前节点是否为NULL
bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){//设置最大值，最小值，每次进行记录，传入下一次比较
    if(root == NULL)
        return true;
    if(minNode && minNode->val >= root->val || maxNode && maxNode->val <= root->val)//知道了符号优先级
        return false;
    return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
}

bool isValidBST(TreeNode* root) {
    if(root == NULL)
        return true;
    return isValid(root, NULL, NULL);
}

/*******************************************************************************
例题：450 delete node in a bst

*******************************************************************************/
TreeNode* deleteNode(TreeNode* root, int key) {

}


/*******************************************************************************
例题：108 convert sorted array to binary search tree
给定一个有序数组，将其转换成一颗二分搜索树
*******************************************************************************/



/*******************************************************************************
例题：230  Kth smallest element in a bst

*******************************************************************************/



/*******************************************************************************
例题：236 lowest common ancestor of a binary tree
LCA问题
*******************************************************************************/



/*******************************************************************************
---------------------------------动态规划---------------------------------------
例题：70 climbing stairs
动态规划问题-爬台阶
转换成求n-1阶台阶
      求n-2阶台阶
时间复杂度:o(n)
*******************************************************************************/
int climbStairs(int n) {
    int result = 0;
    if( n <= 2)
        result = n;
    int step2 = 1;
    int step1 = 2;

    for(int i = 3; i <= n; i++){
        result = step1 + step2;
        step2 = step1;
        step1 = result;
    }
    return result;
}
/*******************************************************************************
例题： 120 Triangle
注：每一步只能移动到相邻格子中
空间复杂度:o(n)
时间复杂度:o(n^2)
*******************************************************************************/
// 由于我们在公式里需要递归求解子问题，那么我们不妨反过来想一下，先求解子问题，然后再解决父问题。即，从下往上求解最小路径和。我们可以发现如下规律，当我们求解minimum[i][j]时，我们会用到minimum[i+1][j]和minimum[i+1][j+1]，但是当求解完所有minimum[i]之后minimum[i+1]就没有用处了。既然如此，我们是否可以复用同一个空间来存储minimum的值呢？答案是可以的。进一步观察发现，存储最后一行的每个数字的最小路径和需要n个空间>，因此至少我们需要n个空间，这也是题目里给出O（n）的空间复杂度的原因；之后存储倒数第二行时，我们只需要前面的n-1个空间……以此类推，第一行只需要一个空间来存储最小路径和，这也正是我们要求解的结果。
int minimumTotal(vector<vector<int> > &triangle) //这题其实就是DP的用法
{
    vector<int> mini(triangle[triangle.size()-1]);
    for ( int i = triangle.size() - 2; i>= 0 ; --i )
        for ( int j = 0; j < triangle[i].size() ; ++ j )
            mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
    return mini[0];
}
/*******************************************************************************
例题：64 minimum path sum
note：每一步只能左移或者下移
*******************************************************************************/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int lenRow = grid.size();
        int lenCol = grid[0].size();
        vector< vector<int>> dp(lenRow - 1, vector<int>(lenCol, 0));
        //dp[lenRow-1][lenCol-1] = grid[lenRow-1][lenCol-1];

        for(int i = lenRow-1; i >= 0; i--) {
            for(int j = lenCol-1; j >= 0; j--) {
                if(i == lenRow-1) {
                    if(j == lenCol-1)
                        dp[i][j] = grid[i][j];
                    else
                        dp[i][j] = grid[i][j]+dp[i][j+1];
                }
                else if(j == lenCol-1) {
                    dp[i][j] = dp[i+1][j] + grid[i][j];
                }
                else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
};


/*******************************************************************************
例题：343
拆分数字使得和最大
*******************************************************************************/
//自顶向下 配合记忆化搜索的方法
class Solution {
private:
    vector<int> dp;
    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }
    int doIntegerBreak(int n) {
        if( 1 == n ){
            return 1;
        }
        if(dp[n] != -1)
            return dp[n];
        int res = -1;
        for( int i = 1; i <= n-1; i ++) {
            // i + (n-i)
            res = max3(res, i*(n-i), i*doIntegerBreak(n-i));
        }
        dp[n] = res;
        return res;
    }
public:
    int integerBreak(int n) {
        assert( n >= 2);
        dp = vector<int>(n+1, -1);
        return doIntegerBreak(n);
    }
};
//推出以下方法
//自底向上方式
//时间复杂度O(n^2)
class Solution {
private:
        int max3(int a, int b, int c){
            return max(max(a, b), c);
        }
        vector<int> dp;
public:
    int integerBreak(int n) {
        assert(n>1);
        dp = vector<int>(n+1, -1);

        for( int i = 2; i <= n; i ++){
            for(int j = 1; j < i; j ++){
                dp[i] = max3(dp[i], j*(i-j), j*dp[i-j]);
            }
        }

        return dp[n];
    }
};
/*******************************************************************************
例题：279 perfect squares

*******************************************************************************/
//动态规划解法
//记忆化搜索的方式
class Solution {
private:
    vector<int> dp;
    //对n进行分解，最少两个
    int doNumSquares(int n){
        if( n==1 )
            return 1;
        if( dp[n] != -1)
            return dp[n];
        int res = n;
        for(int i = 1; i*i <= n; i++){
            if(i * i == n){
                dp[n] = 1;//直接平方和，返回1
                return dp[n];
            }
            else {
                res = min(res,doNumSquares(n-i*i)+1);
            }
        }
        dp[n] = res;
        return dp[n];
    }
public:
    int numSquares(int n) {
        assert(n>0);
        dp = vector<int>( n+1, -1);
        
        return doNumSquares(n);
    }
};
//自下而上的迭代方式
//计算过程要1-n全部计算，考虑中间
class Solution {
private:
    vector<int> dp;
public:
    int numSquares(int n) {
        assert(n>0);
        dp = vector<int>( n+1, n);
        
        for(int i = 1; i <= n; i++){//计算1-n
            for(int j = 1; j*j <= i; j++){
                if ( j*j == i){
                    dp[i] = 1;
                    break;
                }
                else {
                    dp[i] = min(dp[i], dp[i-j*j] + 1);
                }
            }
        }
        return dp[n];
    }
};
//图结构也可解

/*******************************************************************************
例题：91 Decode ways
未解决？？？？？？？？？？？？？
*******************************************************************************/
//递归结构？重叠子问题？动态规划
class Solution {
private:
    map<string, int> dp;
    int doNumDecodings(string& s){
        int tmp = stoi(s);
        if(tmp>=1 && tmp<=9)
            return 1;
        if(dp[s] != 0)
            return dp[s];
        //对s进行分拆最少拆两份
        int res = 0;
        for(int i = 1; i<s.size(); i++){
            res = dp[s.substr(0,i)]+dp[s.substr(i)];
        }
        if(tmp>=1 && tmp<=24)
            res += 1;
        dp[s] = res;
        return res;
    }
public:
    int numDecodings(string s) {
        int len = s.size(); 
        assert(len>0);
        //dp = map<string><int>(len+1, "");

        return doNumDecodings(s);
    } 
};
/*******************************************************************************
例题：62 Unique Paths

*******************************************************************************/
//从顶向下，记忆化搜索
class Solution {
private:
    vector<vector<int>> dp;
    int doUniquePaths(int m, int n){
        if( m == 1 || n == 1)
            return 1;
        if(dp[m][n] != 0)
            return dp[m][n];
        dp[m][n] = doUniquePaths(m-1, n) + doUniquePaths(m, n-1);
        return dp[m][n];
    }
public:
    int uniquePaths(int m, int n) {
        assert( m >0 && n > 0);
        dp = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        return doUniquePaths(m ,n);
    }
};

//自下向上进行搜索
//行列分别多出1，所有行、列为1的方法只有一进行复制即可。
class Solution {
private:
    vector<vector<int>> dp;
public:
	int uniquePaths(int m, int n) {
		assert( m>0 && n>0);
		dp = vector< vector<int>>(m+1, vector<int>(n+1, 0));
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				if( i == 1 || j == 1){
					dp[i][j] = 1;
					continue;
				}else{
					dp[i][j] = dp[i-1][j]+dp[i][j-1];
				}
			}
		}
		return dp[m][n];
	} 
};
/*******************************************************************************
例题：63 Unique Paths II
加入障碍物
*******************************************************************************/
//加入限制
//不需要加入多余数组，对所有情况进行判断
class Solution {
private:
    vector<vector<int>> dp;    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
        assert(m>0);
        int n = obstacleGrid[0].size();
        assert(n>0);
		dp = vector< vector<int>>(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }else if( i == 0 & j > 0){
					dp[i][j] = dp[i][j-1];
				}else if( j == 0 & i > 0){
					dp[i][j] = dp[i-1][j];
				}else if(i == 0 & j== 0){
                    dp[i][j] = 1;
                }else {
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
			}
		}
		return dp[m][n];        
    }\\};

/*******************************************************************************
例题：198 rob

*******************************************************************************/
//时间复杂度：o(n^2)
class Solution {
private:
    vector<int> dp;
    int doRob(vector<int>& nums, int index){
        int len = nums.size();
        if(index>len)
            return 0;
        if(dp[index] != -1)
            return dp[index];
        //[0...n)
        int res = 0;
        for( int i = index; i < len; i++){
            res = res + nums[i] + doRob(nums, i+2);
        }
        dp[index] = res;
        return res;
    }
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        assert(len>0);
        dp = vector<int>(len, -1);
        return doRob(nums, 0); 
    }
};
//自底向上的方式实现
class Solution {
private:
    vector<int> dp;
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n ==0)//对0进行判断，最后返回数组就有可能数组越界问题。
            return 0;
        dp = vector<int>(n, 0);
        //dp[n-1] = nums[n-1];
        for( int i = n-1; i >= 0; i --) {
            for( int j = i; j < n; j ++){
                dp[i] = max(dp[i], nums[j] + (j+2 < n ? dp[j+2]: 0));
            }
        }
        return dp[0];
    }
};

/*******************************************************************************
例题：213 house robber II

*******************************************************************************/
//case1：去掉最后一家
//case2：去掉第一家
//特殊考虑：数组长度为1的情况
#include <iostream>
using namespace std;
class Solution {
private:
    vector<int> dp;
    //[lhs,rhs]
    int doRob(vector<int>& nums, int lhs, int rhs){
        if(rhs<lhs)
            return 0;
        if(dp[lhs] != -1)
            return dp[lhs];
        int res = 0;
        for(int i = lhs; i <= rhs; i ++){
            res = max(res, nums[i] + doRob(nums, i+2, rhs));
        }
        dp[lhs] = res;
        return res;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n ==1 ) {
            return nums[0];
        }
        dp = vector<int>(n, -1);
        //[l,r]
        int max1 = doRob(nums, 0, n-2);
        dp = vector<int>(n, -1);
        int max2 = doRob(nums, 1, n-1);
        return max(max1, max2);
    }
};
//自顶向下

/*******************************************************************************
例题：337 house robber III

*******************************************************************************/



/*******************************************************************************
例题：309 best time to buy and sell stock with cooldown

*******************************************************************************/



/*******************************************************************************
例题：0-1背包问题
leetcode 没有专门的问题
记忆化搜索空间-二维数组
*******************************************************************************/
//自上而下记忆化搜索
//二维数组
//F(n,c)将n个物品放入容量为C的背包中,前提是每个物品只有一件
//[0,index]
vector< vector<int>> dp;
int bestValue(const vector<int> &w, const vector<int> &v, int index, int c){
    if( index < 0 || c <= 0)//index 为0时有值
        return 0;
    if( dp[index][c] != -1)
        return dp[index][c];
    int res = 0;
    res = bestValue(w, v, index-1, c);
    if( w[index] <= c){
        res = max(res, v[index] + bestValue(w, v, index-1, c-w[index]));
    }
    dp[index][c] = res;
    return res;
}
//可以多申请空间
int knapsack01(const vector<int> &w, const vector<int> &v, int C){
    assert(w.size() == v.size());
    int n = w.size();
    dp = vector< vector<int>>(n ,vector<int>(C+1,-1));
    return bestValue(w, v, n-1, C);
}

//自底向上的求解背包问题
//二维数组解决问题
int knapsack01(const vector<int> &w, const vector<int> &v, int C){
    assert( w.size() == v.size());
    int n = w.size();
    if( n==0)
        return 0 ; 
    dp = vector< vector<int>>(n, vector(C+1), 0);
    //F(0,x) //index代表索引
    // 排除index=0，的元素，但是index更大的元素也可能是0
    for(int i = 1; i<=c; i++){
        dp[0][i] = (i>=w[0]?v[0]:0);
    }
    for(int i = 1; i < n; i ++){
        for(int j = 0; j <= C; j++){
            dp[i][j] = dp[i-1][j];
            if(w[i] <= j){
                dp[i][j] = max(dp[i][j], v[i]+dp[i-1][j-w[i]]); 
            }
        }
    }
    return dp[n-1][C];
}
//简化空间复杂度
//只需要两行空间
int knapsack01(const vector<int> &w, const vector<int> &v, int C){
    assert( w.size() == v.size());
    int n = w.size();
    if( n==0)
        return 0 ; 
    dp = vector< vector<int>>(2, vector(C+1), 0);
    //F(0,x) //index代表索引
    // 排除index=0，的元素，但是index更大的元素也可能是0
    for(int i = 1; i<=c; i++){
        dp[0][i] = (i>=w[0]?v[0]:0);
    }
    for(int i = 1; i < n; i ++){
        for(int j = 0; j <= C; j++){
            dp[i%2][j] = dp[(i-1)%2][j];
            if(w[i] <= j){
                dp[i%2][j] = max(dp[i%2][j], v[i]+dp[(i-1)%2][j-w[i]]); 
            }
        }
    }
    return dp[(n-1)][C];
}
//继续简化空间
//采用一行空间,可以优化空间，又能优化时间
int knapsack01(const vector<int> &w, const vector<int> &v, int C){
    assert( w.size() == v.size());
    int n = w.size();
    if( n==0)
        return 0 ; 
    dp = vector<int>(C+1), 0);
    //F(0,x) //index代表索引
    // 排除index=0，的元素，但是index更大的元素也可能是0
    for(int i = 1; i<=c; i++){
        dp[i] = (i>=w[0]?v[0]:0);
    }
    for(int i = 1; i < n; i ++){
        for(int j = C; j >= w[i]; j--){
            dp[j] = max(dp[j], v[i]+dp[j-w[i]]); 
        }
    }
    return [C];
}
/*******************************************************************************
例题：416 
典型背包问题，在n个物品中选出一定物品，填满sum/2的背包
*******************************************************************************/
//F(n,C)
//F(n,C)=F(i-1,C) || F(i-1, C-w(i))
//时间复杂度：o(n*(sum/2)= o(n*sum)
//记忆化搜索过程

class Solution {
private:
    //0-不能实现，1-可以实现，-1-未查询
    vector< vector<int>> dp;
    int tryPartition(vector<int>& nums, int index, int sum){
        if(sum < 0 || index < 0)
            return 0;
        if(sum == 0 )
            return 1;
        if(dp[index][sum] != -1)
            return dp[index][sum];
        dp[index][sum] = (tryPartition(nums, index-1, sum)==1 || tryPartition(nums, index-1, sum-nums[index]) == 1);
        return dp[index][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        assert(n>0);
        int sum = 0;
        for( int i = 0; i<n; i ++){
            sum += nums[i];
        }
        if(sum%2 != 0)
            return false;
        cout<<sum/2<<endl;
        dp = vector<vector<int>>(n, vector<int>(sum/2+1, -1));
        return tryPartition(nums, n-1, sum/2)==1;
    }
};


//自下而上的方式
//理解含义，F(n,C),将0-n个元素放入容量为C的背包中
bool canPartition(vector<int>& nums){
    vector<bool> dp1;
    int n = nums.size();
    assert(n>0);
    int sums = 0;
    for(int i = 0; i < n; i++){
        sums += nums[i];
    }
    if(sums%2 != 0)
        return false;
    int C = sums/2;
    dp1 = vector<bool>(sums/2+1,false);
    for( int i = 1; i <= sums/2; i ++){
        dp1[i] =  nums[0]==i;
    }
    for(int i = 1; i< n; i ++){
        for(int j = C; j >= nums[i]; j--){
            dp1[j] = dp1[j] || dp1[j-nums[i]];
        }
    }
    return dp1[C];
}


/*******************************************************************************
例题：322 coin change 
???????????????????????????????????
*******************************************************************************/
//先通过自上而下，记忆化搜索的方式
class Solution {
private:
    vector< vector<int>> dp;
    //[0..index]
    int doCoinChange(vector<int>& coins, int index, int amount){
        if(index < 0 || amount < 0)
            return -1;
        int res = INT_MAX;
        if(0 == amount)
            return 0;       
        if(-1 != dp[index][amount])
            return dp[index][amount];
        for( int i = 1; i <= amount/coins[index]; i++){
            // int resTmp = doCoinChange(coins, index-1, (amount-i*coins[index]));
            // if( -1 == resTmp)
            //     continue;
            // res = min(res, resTmp+i);
            for
        }
        dp[index][amount] = res;
        return res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(0 == amount)
            return 0;
        if( 0 == n)
            return -1;
        dp = vector< vector<int>>(n, vector<int>(amount,-1));
        return doCoinChange(coins, n-1, amount);

    }
};

//自底向上的方式
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};


/*******************************************************************************
例题：377

*******************************************************************************/
class Solution {
public:
    
};


/*******************************************************************************
例题：139

*******************************************************************************/



/*******************************************************************************
例题：494

*******************************************************************************/



/*******************************************************************************
例题：300

*******************************************************************************/



/*******************************************************************************
例题：376

*******************************************************************************/



/*******************************************************************************
例题: 17.letter combination of a phone number

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：

*******************************************************************************/
