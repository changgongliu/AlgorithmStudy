#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
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

int main() {
   Solution tmp = Solution();
   int n = 4, k = 2;
   tmp.combine(n, k);
   return 0;
}