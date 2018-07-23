#include <iostream>
#include <vector>
#include "math.h"
#include "limits.h"
using namespace std;
//5. Longest Palindromic Substring
string longestPalindrome(string s) {
    if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
      if (s.size() - i <= max_len / 2) break;
      int j = i, k = i;
      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      i = k+1;
      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      int new_len = k - j + 1;
      if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
}
//自己实现
//关于临界条件有了进一步认识
  string longestPalindrome(string s) {
      if(s.empty()) return "";
      int len = s.size();
      if(len == 1)
          return s;
      int min_string = 0, max_len = 1;
      for(int i = 0; i < len;){
          int lhs = i, rhs = i;
          while(rhs < len -1 && s[rhs] == s[rhs+1]) rhs++;
          i = rhs + 1;
          while(rhs < len - 1 && lhs > 0 && s[rhs + 1] == s[lhs - 1]){
              ++ rhs;
              -- lhs;
          }
          int new_len = rhs - lhs + 1;
          if( new_len > max_len) {
              min_string = lhs;
              max_len = new_len;
          }
      }
      cout<<min_string<<" "<<max_len<<endl;
      return s.substr(min_string, max_len);
  }
  
//6.ZigZag Conversion
    string convert(string s, int nRows) {
        if(nRows == 1)return s;
        int len = s.size(), k = 0, interval = (nRows<<1)-2;
        string res(len, ' ');
        for(int j = 0; j < len ; j += interval)//处理第一行
            res[k++] = s[j];
        for(int i = 1; i < nRows-1; i++)//处理中间行
        {
            int inter = (i<<1);
            for(int j = i; j < len; j += inter)
            {
                res[k++] = s[j];
                inter = interval - inter;
            }
        }
        for(int j = nRows-1; j < len ; j += interval)//处理最后一行
            res[k++] = s[j];
        return res;
    }

//8. string to integer(atoi)
    int toInt(char p) {
        return p-'0';
    }
    int myAtoi(string str) {
        int len = str.size();
        if(len == 0)
            return 0;
        int index = 0;
        while(index < len && str[index] == ' ')
            index ++;
        long long res = 0;
        bool minus = false;
        if( str[index] == '-' ) {
            minus = true;
            index ++;
        }
        else if(str[index] == '+'){
            index ++;
        }
        while( index < len && str[index] >= '0' && str[index] <= '9'){
            if(minus)
                res = -toInt(str[index]) + res*10;  
            else
                res = toInt(str[index])+ res*10;
            if( res > INT_MAX){
                res = INT_MAX;
                break;
            }
            else if(res < INT_MIN){
                res = INT_MIN;
                break;
            }
            index ++;
        }
        return res;
    }
//38.count and say
    string countAndSay(int n) {
        string res = "";
        string tmp = "";
        if(n <= 0)
            return res;
        res += "1"; 
        int count = 0;
        int index = 2;
        for(;index <= n; index ++) {
            
            for( int i = 0; i < res.size(); i ++){
                count = 1;
                while(i < res.size() && res[i] == res[i+1]){
                    count ++;
                    i ++;
                }
                tmp += to_string(count) + res[i];
            }
            res = tmp;
            tmp = "";
        }
        return res;
    }

// 58.Length of Last Word
    int lengthOfLastWord(string s) {
        if( s.empty())
            return 0;
        int len = s.size();
        int index = 0;
        int count = 0;
        int count1 = 0;
        while(index < len){
            count = 0;
            while(index < len && s[index] != ' '){
                index ++;
                count ++;
            }
            if(count != 0)
                count1 = count;
            index ++;
        }
        if(count == 0)
            count = count1;
        return count;
    }
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
       int index = 0;
       int len = 0;
       while(index < s.size()){
            if(s[index ++] != ' ')
                ++ len;
            else if (index < s.size() && s[index] != ' '){
                len = 0;
            }
       } 
       return len;
    }
// 67.Add Binary
// 没做出来
    string addBinary(string a, string b) {
        int i = a.size() -1 ;
        int j = b.size() -1 ;
        int c = 0;
        string res = "";
        while(i >= 0 || j >= 0 || c==1) {
            c += i>=0 ? a[i --] - '0' : 0;
            c += j>=0 ? b[j --] - '0' : 0;
            res = char(c%2 + '0') + res;
            c /= 2;
        }
        return res;
    }
//93.Restore IP Address
//1. 首位字符为0, 则只能取一位
//2. 首位不为零, 长度>=2, 可以取2位
//3. 首位不为0, 长度>=3, 并且取三位得到的整数<256, 则可取三位
    void DFS(string s, string str, int k)  
    {  
        if(s.size()==0 && k==4) return ans.push_back(str.substr(0, str.size()-1));  
        if(s.size()==0 || k== 4) return;  
        for(int i = 1; i <= min(3, (int)s.size()); i++)  
        {  
            int val = stoi(s.substr(0,i));  
            if(val >=0 && val <= 255)  
                DFS(s.substr(i), str+s.substr(0,i)+".", k+1);  
            if(s[0] == '0') break;  
        }  
    }  
    vector<string> restoreIpAddresses(string s) {  
        if(s.size()==0) return ans;  
        DFS(s, "", 0);  
        return ans;  
    }   
    vector<string> ans;  

// 131 Palindrome Partitioning
class Solution {
private:
    vector<vector<string>> ans;
    void DFS(string s, vector<string> str) {
        if(s.size() == 0) {
            ans.push_back(str);
            return;
        }
        for( int i = 0; i < s.size(); ++i) {
            str.push_back(s.substr(i,i));
            DFS(s.substr(i), str);
            while(i < s.size()-1 && s[i] == s[i+1]) {
                str.push_back(s.substr(i,i+1));
                DFS(s.substr(i), str);
                ++ i;
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        if(s.empty()) return ans;
        vector<string> str;
        DFS(s, str);
        return ans;
    }    
};
//49. Group Anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if (strs.empty())
        return vector<vector<string> >();
    int len = strs.size();
    //将字符串数组按照字典顺序排序
    sort(strs.begin(), strs.end());
    //存储结果
    vector<vector<string> > ret;
    //利用哈希思想构建map，将排序后相等的字符串存在相应的vector
    map<string, vector<string>> mv;
    for (int i = 0; i < len; i++)
    {
        string str = strs[i];
        sort(str.begin(), str.end());

        mv[str].push_back(strs[i]);
    }
    for (map<string, vector<string> >::iterator iter = mv.begin(); iter != mv.end(); iter++)
        ret.push_back(iter->second);
    return ret;
}
//   500 keyboard row
//方法一：
class Solution {
private:
    const unordered_set keyOne = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
    const unordered_set keyTwo = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
    const unordered_set keyThree = {'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for(auto& word : words) {
            bool f1 = true, f2 = true, f3 = true;
            for(auto& c : word) {
                if(f1) {
                   auto it = keyOne.find(toupper(c));
                    if(it == keyOne.end()) f1 = false;
                }
                if(f2) {
                    auto it = keyTwo.find(toupper(c));
                    if(it == keyTwo.end()) f2 = false;
                }
                if(f3) {
                    auto it = keyThree.find(toupper(c));
                    if(it == keyThree.end()) f3 = false;
                }                
            }  
            if(f1 || f2 || f3) {
                res.push_back(word);
            }             
        }
        return res;
    }
};
//方法一：二进制&的关系
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> dict(26);
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        for (int i = 0; i < rows.size(); i++) {
            for (auto c : rows[i]) dict[c-'A'] = 1 << i;
        }
        vector<string> res;
        for (auto w : words) {
            int r = 7;
            for (char c : w) {
                r &= dict[toupper(c)-'A'];
                if (r == 0) break;
            }
            if (r) res.push_back(w);
        }
        return res;
    }
};
//769.  
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.empty())
            return 0;
        int res = 0;
        int max_i = 0;
        for(int i = 0; i < arr.size(); i ++) {
            max_i = max(max_i, arr[i]);
            if( i == max_i) res ++;
        }
        return res;
    }
};
// 417. Pacific Atlantic Water Flow
class Solution {
private:
    vector<vector<bool>> used;
    int flag = 0;
    int square = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int flowWater(int row, int col, vector<vector<int>>& matrix, int& res) {
        if(row + col <= )    
        for(int i = 0; i < 4; i ++) {
            //move to four square
            int newRow = row + square[i][0];
            int newCol = col + square[i][1];
            if(!used[newRow][newCol]) {
                flowWater(newRow, newCol, matrix);
            }
        }            
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ans;
        if(matrix.empty())
            return ans;
        int m = matrix.size();
        int n = matrix[0].size();
        flag = 
        used = vector< vector<int>>(m+1, vector<int>(n+1, false));
        for(int i = 0; i <= m; i ++) 
            for(int j = 0; j <= n; j++)
                if(0 ==i || 0 == j)
                    used[i][j] == true;
        for(i = 1; i < m+1; i ++) {
            for(j = 1; j < n+1; j ++) {
                if(!used[i][j])
                    flowWater(i, j, matrix);
            }
        }

    
};
//844 backspace string compare
class Solution {
    public boolean backspaceCompare(String S, String T) {
        int pre1 = 0, pre2 = 0;
        int index1 = 0, index2 = 0;
        int len1 = S.size(), len2 = T.size();
        while(index1 < len1 && index2 < len2) {
            int count1 = 0, count2 = 0;
            pre1 = index1;
            while(S[index1+1] == '#') {
                count1 ++;
                index1 ++;
            }
            while(T[index2+1] == '#') {
                count2 ++;
                index2 ++;
            }
            pre1 = pre1 - count1;
            pre2 = pre2 - count2;
            if(pre1 < 0 ) 
                pre1 = 0;
            if(pre2 < 0) 
                pre2 = 0;
            if(S[pre1] == T[pre2]) {
                pre1 = index1;
                pre2 = index2;
            }
            index1 ++;
            index2 ++;
        }        
    }
}
// 14. Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {//每一次对结果进行处理，注意学习substr的使用
        if(strs.empty()) 
            return "";
        string result = strs[0];
        int index = result.size() + 1;
        for(auto words : strs) {
            if(0 == index)
                break;
            int i = 0;
            for(auto word : words) {
                if(i < result.size() && word == result[i]) {
                    i ++;
                }
                else 
                    break;
            }
            index = i;
            result = result.substr(0, i);
        }
        cout<<index<<endl;
        return result;
        
    }
};
//22. Generate Parentheses
//回溯法
class Solution {
public:
    vector<string> generateParenthesis(int n) {
         
    }
};