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
