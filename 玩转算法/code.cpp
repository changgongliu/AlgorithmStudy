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
#include "limits.h"
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
#include "assert.h"
    const string lettersMap[10] = {
        "",     //0
        "",      //1
        "abc",   //2
        "def",   //3
        "ghi",   //4
        "jkl",   //5
        "mno",   //6
        "pqrs",  //7
        "tuv",   //8
        "wxyz",  //9
    };
    vector<string> res;
    //tmp 表示[0..index-1]组成的字符串
    void findCombinations(string &digits, int index, const string &tmp) {
        if( index == digits.size()){
            res.push_back(tmp);
            return;
        }
        char letter = digits[index];
        assert(letter>= '2' && letter <= '9');
        string letters = lettersMap[letter-'0'];
        for( int i = 0; i < letters.size(); i ++) {
            
            findCombinations(digits, index + 1, tmp + letters[i]);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return res;
        findCombinations(digits,0, "");
        return res;
    }


/*******************************************************************************
例题：93 resotre ip address

*******************************************************************************/
//复杂用例:010010
    vector<string> res;
    bool isValid( string s) {
        return stoi(s) < 256 ? true : false;
    }
    void doRestore(string &s, int index, const string tmp, int points) {
        if(index == s.size() && points == 4) {
            res.push_back(tmp);
            return;
        }
        string result = "";
        int top = index + 3;
        for(; index < s.size() && index < top; index ++) {
            result += s[index];
            if( points == 0) {
                doRestore(s, index + 1, result + '.', points + 1);
            }
            else if( isValid(result) && points < 3)
                doRestore(s, index + 1, tmp + result + '.', points + 1);
            else if( isValid(result) && points == 3)
                doRestore(s, index + 1, tmp + result, points + 1);
            else
                break;
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.empty()) 
            return res;
        doRestore(s, 0, "", 0);
        return res;
    }


/*******************************************************************************
例题： 46.Permutations

*******************************************************************************/
class Solution {
private:
    vector<vector<int>> ans;
    vector<bool> flag;
    //index表示str中元素个数
    void backTracking(const vector<int>& nums, vector<int>& str, int index) {
        if(index == nums.size())   {
            ans.push_back(str);
            return;
        }
        for( int i = 0; i< nums.size(); ++ i) {
            if(!flag[i]) {
                str.push_back(nums[i]);
                flag[i] = true;
                backTracking(nums, str, index ++);//问题处在index++上，先使用index，在进行++
                str.pop_back();
                flag[i] = false;
            }
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        if(nums.size() == 0)
            return ans;
        vector<int> p;
        flag = vector<bool>(nums.size(), false);
        backTracking(nums, p, 0);
        return ans;
    }
};


/*******************************************************************************
例题：47Permutation II

*******************************************************************************/
#include <map>
#include <algorithm>
class Solution {
private:
    vector<vector<int>> ans;
    vector<bool> used;
    void generatePermute(vector<int>& nums, int index, vector<int>& p) {
        if( index == nums.size()) {
            ans.push_back(p);
            return;
        }
        for( int i = 0; i < nums.size(); ++i) {
            if(!used[i]) {
                while(i < nums.size()-1 && nums[i] == nums[i+1] && !used[i+1]) {
                        ++i;
                } 
                used[i] = true;
                p.push_back(nums[i]);
                generatePermute(nums, index+1, p);

                p.pop_back();
                used[i] = false;
            }
        }
        return;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0) {
            return ans;
        }
        used = vector<bool>(nums.size(), false);
        vector<int> p;
        sort(nums.begin(), nums.end());
        generatePermute( nums, 0, p);
        return ans;
    }
};

/*******************************************************************************
例题：77 Combinations

*******************************************************************************/
class Solution {
private:
    vector<vector<int> > ans;
    void generateCombine(const int& n, int k, vector<int>& p, int index) {
        if(k == 0) {
            ans.push_back(p);
            return;
        }
        for(int i = index; i <= n-k+1; ++i) {//减去不必要的递归
            p.push_back(i);
            generateCombine(n, k-1, p, i+1);

            p.pop_back();
        }
        return;
    }
public:
    vector<vector<int> > combine(int n, int k) {
        ans.clear();
        if( n == 0 || k ==0 || k > n)
            return ans;
        vector<int> p;
        generateCombine(n, k, p, 1);
        return ans; 
    }
};


/*******************************************************************************
例题：39.Combination Sum

*******************************************************************************/
class Solution {
private:
    vector<vector<int>> ans;
    void generateCombinationSum(vector<int>& candidates, int target, vector<int>& p) {
        if(target == 0) {
             ans.push_back(p);
             return;
        }
        if( target < 0 )
            return;
        for(int i = 0; i < candidates.size() && candidates[i] <= target; ++ i) {
            if( p.size() > 0 && candidates[i] < p[p.size()-1])//进行这个判断，首先candidates是有序的
                continue;
            p.push_back(candidates[i]);
            generateCombinationSum(candidates, target-candidates[i], p);

            p.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0 || target <= 0)
            return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> p;   
        generateCombinationSum(candidates, target , p);
        return ans;
    }
};


/*******************************************************************************
例题：40.Combination Sum II

*******************************************************************************/
class Solution {
private:
    vector<vector<int>> ans;
    void generateCombinationSum(vector<int>& candidates, int target, vector<int>& p, int index) {
        if(target == 0) {
             ans.push_back(p);
             return;
        }
        if( target < 0 || index == candidates.size())
            return;
        for(int i = index; i < candidates.size() && candidates[i] <= target; ++ i) {//
            if(i > index && candidates[i] == candidates[i-1]){  //同一层不能出现相同值,只考虑当前层，已经包含了下一层所有情况，所以已经包含了这一层下一次又出现相同数的情况
                continue;  
            }
            p.push_back(candidates[i]);
            generateCombinationSum(candidates, target-candidates[i], p, i+1);

            p.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() == 0 || target <= 0)
            return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> p;   
        generateCombinationSum(candidates, target , p, 0);
        return ans;
    }
};


/*******************************************************************************
例题：216 Combination Sum III

*******************************************************************************/
class Solution {
private:
    vector<vector<int>> ans;
    void generateCombinationSum(int k, int n, vector<int>& p) {
        if(k==0 && n == 0) {
             ans.push_back(p);
             return;
        }
        if( n < 0 || k <0)
            return;
        for(int i = 1; i <= 9; ++ i) {
            if( p.size() > 0 && i <= p[p.size()-1])
               continue;
            p.push_back(i);
            generateCombinationSum(k-1, n-i, p);

            p.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k ,int n) {
        if(k <= 0 || n <= 0)
            return ans;
        vector<int> p;   
        generateCombinationSum(k, n, p);
        return ans;
    }
};


/*******************************************************************************
例题：78.Subsets 

*******************************************************************************/
//#include <vector>
//using namespace std;
class Solution {
private:
    vector<vector<int>> ans;
    void generateSubsets(const vector<int>& nums, vector<int>& p, int index) {
        //if(p.size() != 0) {
            ans.push_back(p);//将所有可能集合放入，只有在第一次时为空集
        //}
        if(index == nums.size())
            return;
        for(int i = index; i < nums.size(); ++i) {
            p.push_back(nums[i]);
            generateSubsets(nums, p, i+1);

            p.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0)
            return ans;
        
        vector<int> p;
        generateSubsets(nums, p, 0);
        return ans;
    }
};


/*******************************************************************************
例题：90.Subsets II

*******************************************************************************/
class Solution {
private:
    vector<vector<int>> ans;
    void generateSubsets(const vector<int>& nums, vector<int>& p, int index) {
        //if(p.size() != 0) {
        ans.push_back(p);//将所有可能集合放入，只有在第一次时为空集
        //}
        if(index == nums.size())
            return;
        for(int i = index; i < nums.size(); ++i) {
            if(i > index && nums[i] == nums[i-1])//此处nums[i] == nums[i-1]  与 nums[i] == nums[i+1]是不同的，执行第一个值，跳过后边的值，还是跳过第一个值，执行后边的值
                continue;
            p.push_back(nums[i]);
            generateSubsets(nums, p, i+1);

            p.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0)
            return ans;
        
        vector<int> p;
        sort(nums.begin(), nums.end());
        generateSubsets(nums, p, 0);
        return ans;
    }
};



/*******************************************************************************
例题： 401.Binary Watch

*******************************************************************************/
class Solution {
public:
vector<string> work(int k) {
    vector<string> res;
    if(k > 10) return res;
    for (int i = 0; i < (1 << 10); i++) {
        if(__builtin_popcount(i) == k) {
            int h = i >> 6;
            if(h > 11) continue;
            int m = i & ((1 << 6) - 1);
            if(m > 59) continue;
            stringstream ss;
            ss << h;
            ss << ":";
            if(m < 10) ss << "0";
            ss << m;
            string x = ss.str();
            res.push_back(x);
        }
    }
    return res;
}
   vector<string> readBinaryWatch(int num) {
        return work(num);
    }
};
//也可采用c++的bitset标准库
#include<bitset>
#include<sstream>
class Solution {
private:
    vector<string> work(int k) {
        vector<string> res;
        if(k > 10) return res;
        for (int i = 0; i < (1 << 10); i++) {
            if(bitset<10>(i).count() == k) {
                int h = i >> 6;
                if(h > 11) continue;
                int m = i & ((1 << 6) - 1);
                if(m > 59) continue;
                stringstream ss;
                ss << h;
                ss << ":";
                if(m < 10) ss << "0";
                ss << m;
                string x = ss.str();
                res.push_back(x);
            }
        }
        return res;
    }
public:
  vector<string> readBinaryWatch(int num) {
        return work(num);
    }
};


/*******************************************************************************
例题：79Word Search

*******************************************************************************/
class Solution {
private:
    int m = 0, n = 0;
    vector<vector<bool>> used;
    int square[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool isInArea(int startX, int startY) {
        return startX>=0 && startX<m && startY>=0 && startY < n;
    }
    bool isExist(vector<vector<char>>& board, string word, int index, int startX, int startY) {
        if(index == word.size() - 1)
            return board[startX][startY] == word[index];
        if(isInArea(startX, startY) && board[startX][startY] == word[index]) {
            used[startX][startY] = true;
            for( int i = 0; i < 4; ++i) {
                //四个方向进行移动
                int newX = startX + square[i][0];
                int newY = startY + square[i][1];
                if(isInArea(newX, newY) && !used[newX][newY]){
                    if(isExist(board, word, index+1, newX, newY))
                        return true;
                }
            }           
            used[startX][startY] = false;
        }
        return false; 
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || word.size() == 0)
            return false;
        m = board.size();
        assert(m>0);
        n = board[0].size();    
        used = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) {
           for(int j = 0; j < board[i].size(); ++j) {
               if(isExist(board, word, 0, i, j))
                    return true;
            } 
        }
        return false;    
    }
};


/*******************************************************************************
例题：200 number of islands

*******************************************************************************/
class Solution {
    int m = 0, n = 0;
    int suqare[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;
    bool isInArea(int x, int y) {
        return x>=0 && x < m && y >= 0 && y < n;
    }
    void searchIsland(vector<vector<char>>& grid, int startX, int startY) {
        visited[startX][startY] = true;

        for(int i = 0; i < 4; i ++) {
            int newX = startX + suqare[i][0];
            int newY = startY + suqare[i][1];
            if(isInArea(newX, newY) && !visited[newX][newY] && grid[newX][newY] == '1') {
                searchIsland(grid, newX, newY);
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int res = 0;
        if(grid.size() == 0)
            return res;
        
        m = grid.size();
        assert(m>0);
        n = grid[0].size();

        visited = vector<vector<bool>>(m ,vector<bool>(n, false));
        for( int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                if(isInArea(i, j) && grid[i][j] == '1' && !visited[i][j]) {
                    searchIsland(grid, i, j);
                    res ++;
                }
            }
        }
        return res;
    }
};


/*******************************************************************************
例题：130Surround regions

*******************************************************************************/
class Solution {
    int m = 0, n = 0;
    int suqare[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    //vector<vector<bool>> visited;
    bool isInArea(int x, int y) {
        return x>=1 && x < m-1 && y >= 1 && y < n-1;
    }
    void searchAndSolve(vector<vector<char>>& board, int startX, int startY) {
        board[startX][startY] = 'X';
    
        for(int i = 0; i < 4; i ++) {
            int newX = startX + suqare[i][0];
            int newY = startY + suqare[i][1];
            if(isInArea(newX, newY) && board[newX][newY] == 'O') {
                searchAndSolve(board, newX, newY);
            }
            else if(!isInArea(newX, newY)) {
                board[startX][startY] = 'O';
                break;
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        
        m = board.size();
        assert(m>0);
        n = board[0].size();

        //visited = vector<vector<bool>>(m ,vector<bool>(n, false));       
        for( int i = 1; i < m-1; i++) {
            for(int j = 1; j < n-1; j++){
                if(isInArea(i, j) && board[i][j] == 'O') {
                    searchAndSolve(board, i, j);
                }
            }
        }
        return;       
    }
};
//以上并不能解决问题，并且还没有找着合适的方式
class Solution {
    int m = 0, n = 0;
    int suqare[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    //vector<vector<bool>> visited;
    bool isInArea(int x, int y) {
        return x>=1 && x < m-1 && y >= 1 && y < n-1;
    }
    void changeSquareO(vector<vector<char>>& board, int startX, int startY) {
        board[startX][startY] = '%';
    
        for(int i = 0; i < 4; i ++) {
            int newX = startX + suqare[i][0];
            int newY = startY + suqare[i][1];
            if(isInArea(newX, newY) && board[newX][newY] == 'O') {
                changeSquareO(board, newX, newY);
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return;
        
        m = board.size();
        assert(m>0);
        n = board[0].size();

        //visited = vector<vector<bool>>(m ,vector<bool>(n, false));       
        for( int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O') {
                    changeSquareO(board, i, j);
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '%') board[i][j] = 'O';
            }
        }
        return;       
    }
};

/*******************************************************************************
例题： 417. Pacific Atlantic Water Flow

*******************************************************************************/



/*******************************************************************************
例题： 51 NQueens

*******************************************************************************/
class Solution {
private:
    vector<vector<string>> res;
    vector<bool> col, diag1, diag2;
    vector<string> generateString(int n, vector<int> Value) {
        vector<string> res(n, string(n, '.'));
        for(int i = 0; i < Value.size(); i ++)
            res[i][Value[i]] = 'Q';
        return res;
    }
    void putNQueens(int n, int index, vector<int>& tmp) {
        if(index == n) {
            res.push_back(generateString(n, tmp));
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!col[i] && !diag1[index+i] &&!diag2[index-i+n-1]) {
                tmp.push_back(i);
                col[i] = true;
                diag1[index+i] = true;
                diag2[index-i+n-1] = true;
                putNQueens(n, index+1, tmp);

                col[i] = false;
                diag1[index+i] = false;
                diag2[index-i+n-1] = false;
                tmp.pop_back(); 
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        if(n <= 0)
            return res;
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2*n - 1, false);
        diag2 = vector<bool>(2*n - 1, false);
        vector<int> tmp;
        putNQueens(n, 0, tmp);
        return res;
    }
};


/*******************************************************************************
例题：52 N-Queens II

*******************************************************************************/
class Solution {
private:
    int res = 0;
    vector<bool> col, diag1, diag2;
    
    void putNQueens(int n, int index, vector<int>& tmp) {
        if(index == n) {
            res ++;
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!col[i] && !diag1[index+i] &&!diag2[index-i+n-1]) {
                tmp.push_back(i);
                col[i] = true;
                diag1[index+i] = true;
                diag2[index-i+n-1] = true;
                putNQueens(n, index+1, tmp);

                col[i] = false;
                diag1[index+i] = false;
                diag2[index-i+n-1] = false;
                tmp.pop_back(); 
            }
        }
        return;
    }
public:
    int totalNQueens(int n) {
        if(n <= 0)
            return res;
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2*n - 1, false);
        diag2 = vector<bool>(2*n - 1, false);
        vector<int> tmp;
        putNQueens(n, 0, tmp);
        return res;
    }
};


/*******************************************************************************
例题：37.Sudoku Solver

*******************************************************************************/
class Solution {
private:
    vector<vector<bool>> mapRow;//表示第i行
    vector<vector<bool>> mapCol;
    vector<vector<bool>> mapArea;
    bool doSolve(vector<vector<char>>& board, int count) {
        if(count>=81)
            return true;
        for(int i = count; i < 81; i++) {
            int row = i/9;
            int col = i%9;
            if(board[row][col] != '.')
                continue;
            for(int j = 0; j < 9; j++) {
                int arg1 = row/3*3+col/3;
                if(!mapRow[row][j] && !mapCol[col][j] && !mapArea[(row/3)*3 + col/3][j]) {
                    mapRow[row][j] = true;
                    mapCol[col][j] = true;
                    mapArea[(row/3)*3+col/3][j] = true;
                    board[row][col] = j+1+'0';
                    if(doSolve(board, i+1)) 
                        return true;
                    mapRow[row][j] = false;
                    mapCol[col][j] = false;
                    mapArea[row/3*3+col/3][j] = false;
                    board[row][col] = '.';
                }
            }
            return false;
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        assert(board.size() == 9);
        assert(board[0].size() == 9);
        mapRow = vector<vector<bool>>(9, vector<bool>(9, false));
        mapCol = vector<vector<bool>>(9, vector<bool>(9, false));
        mapArea = vector<vector<bool>>(9, vector<bool>(9, false));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j]-'1';//索引从0开始
                    mapRow[i][num] = true;
                    mapCol[j][num] = true;//此处之前将j写成i，提高状态
                    mapArea[(i/3)*3+(j/3)][num] = true;
                }
           }
        }
        doSolve(board, 0);
        return;
    }
};


/*******************************************************************************
例题：

*******************************************************************************/



/*******************************************************************************
例题：35.Search Insert Position

*******************************************************************************/
class Solution {
private:
    int findOrInsert(vector<int>& nums, int target, int lhs, int rhs) {
        if(lhs >= rhs)
            return max(lhs, rhs);
        int mid = lhs + (lhs-rhs)/2;
        if(target == nums[mid])
            return mid;
        else if(target < nums[mid])
            rhs = mid-1;
        else   
            lhs = mid+1;
        findOrInsert(nums, target, lhs, rhs);
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int res = 0;
        if(nums.empty())
            return res;
        
    }
};


/*******************************************************************************
例题：435 Non-overlapping intervals

*******************************************************************************/

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
    bool compare(const Interval& x, const Interval& y) {//泛型算法要求
        if(x.end != y.end)
            return x.end < y.end;
        return x.start < y.start;
    }
public:
    //贪心算法
    //每次选最早结束的，给以后留下的空间会更大
    int eraseOverlapIntervals1(vector<Interval>& intervals) {
        if(intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int res = 1;
        int pre = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start >= intervals[pre].end) {
                ++res;
                pre= i;
            }
        }
        return intervals.size() - res;
    }
    //dynamic pragraming
    //use dynamic pragraming is too slow
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int len = intervals.size();
        vector<int> memo(len, 1);
        for( int i = 0; i < len; i++) {
            for(int j = 0; j < i; j ++) {
                if(intervals[j].end <= intervals[i].start) {
                    memo[i] = max(memo[i], memo[j]+1);
                }               
            }
        }
        int res = 0;
        for(int i = 0; i < len; i ++) {
            res = max(res, memo[i]);
        } 
        return len-res;
    }
};


/*******************************************************************************
例题：455. Assign Cookies

*******************************************************************************/
class Solution {
public:
    //greed
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if( g.empty() || s.empty())
            return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        int index = 0;
        for(int i = 0; i < g.size() && index < s.size(); i++) {
            while(index < s.size() && s[index] < g[i]) {
                index++;
                if(index == s.size())
                    break;
            }
            res++;
            index++;           
        }
        return res;
    }
};
int findContentChildren(vector<int>& g, vector<int>& s) {
    if( g.empty() || s.empty())
        return 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int res = 0;
    int index1 = 0;
    int index2 = 0;
    while(index1 < g.size() && index2 < s.size()) {
        if(s[index2] >= g[index1]) {
            index1++;
            res++;
        }//少一层else会大大加快速度
        index2++;
    }
    return res;
}

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
