# leetcode
## string
1. 5.Longest Palindromic Substring
    - 以相同元素为参考点，进行++，--操作。
    - 关于边界条件，涉及到++，--的要在边界条件之前。
2. 6.ZigZag Conversion
    - 仔细分析，首行和末未行与中间行的区别
    - 发现规律进行解决
3. 8.string to integer(atoi)
    - 考虑周全就行，对于正负、超过范围、非符合字符进行判断
4. 38. count and say
    1. 思路：题意实在太难理解了，尤其是英文又不好，只能参看下别人的资料，理解下规则。终于理解，题意是n=1时输出字符串1；n=2时，数上次字符串中的数值个数，因为上次字符串有1个1，所以输出11；n=3时，由于上次字符是11，有2个1，所以输出21；n=4时，由于上次字符串是21，有1个2和1个1，所以输出1211。依次类推，写个countAndSay(n)函数返回字符串。
5. 58.Length of Last Word 
    1. 考虑全面-对index进行处理一定要判断是否越界，问题考虑周全
    2. 此题需要考虑的是，最后几个都是空格可能导致count=0，显然不符合题目要求
6. 67.Add Binary
    1. 从字符串尾开始加，过程中对加和值进行求余和求除进行字符串的堆积
7. 93.Restore IP Address
    1. 首位字符为0, 则只能取一位
    2. 首位不为零, 长度>=2, 可以取2位
    3. 首位不为0, 长度>=3, 并且取三位得到的整数<256, 则可取三位
8. 49. Group Anagrams
    1. 对整个进行排序，在对每一个分别排序，插入哈希表中
## array
1. 769.max chunks to make sorted 
    - arr will have length in range [1, 10].
    - arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
## 递归回溯
1. 526. Beautiful Arrangement
    1. 
## 深度优先
1. Leetcode 417. Pacific Atlantic Water Flow
    1. 分别处理每个海洋，从海洋边缘（每个海洋两条边）开始，一步步的搜索，即从连接海洋的地方还是搜索，哪些节点的高度高于等于自身（反过来就是可以从那里流到自己），如果是，就标记为true，就这样不断搜索下去。最后所有标记为true的位置就是可以流到对应的海洋。 
    2. 找这两个矩阵，同为true的输出，就是都能流到两个海洋的位