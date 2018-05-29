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
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
    }