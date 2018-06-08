#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution1 {
private:
    vector<vector<int> > ans;
    void generateCombine(const int& n, int k, vector<int>& p, int index) {
        if(k == 0 & index <= n+1) {
            ans.push_back(p);
            return;
        }
        for(int i = index; i <= n; ++i) {
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
int main() {
   Solution tmp = Solution();
   int n = 1;
   int i = (1<<10);
   cout<<(1<<10)<<endl;
   tmp.work(n);
   return 0;
}