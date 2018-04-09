#include <iostream>
#include <vector>
#include <string>
using namespace std;

int NumOfPalindromeSubSequence(string str){
    int len=str.length();
    vector<vector<int> > dp(len,vector<int>(len));

    for(int j=0;j<len;j++){
        dp[j][j]=1;
        for(int i=j-1;i>=0;i--){
            dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            if(str[i]==str[j])
                dp[i][j]+=1+dp[i+1][j-1];
        }
    }
    return dp[0][len-1];
}

int main()
{
    string str;
    int num;
    while(cin>>str){
        num=NumOfPalindromeSubSequence(str);
        cout<<num<<endl;
    }
    return 0;
}