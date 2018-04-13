////#include <stdio.h>
////#include <string>
////#include <iostream>
////#include <vector>
////#include <sstream>
////using namespace std;
////vector<vector<string> > NumPrint = {{"66666", "6...6", "6...6", "6...6", "66666"}
////                                   ,{"....6", "....6", "....6", "....6", "....6"}
////                                   ,{"66666", "....6", "66666", "6....", "66666"}
////                                   ,{"66666", "....6", "66666", "....6", "66666"}
////                                   ,{"6...6", "6...6", "66666", "....6", "....6"}
////                                   ,{"66666", "6....", "66666", "....6", "66666"}
////                                   ,{"66666", "6....", "66666", "6...6", "66666"}
////                                   ,{"66666", "....6", "....6", "....6", "....6"}
////                                   ,{"66666", "6...6", "66666", "6...6", "66666"}
////                                   ,{"66666", "6...6", "66666", "....6", "....6"}};
//////vector<vector<string> > NumPrint;
//////string s1[] = {"66666", "6...6", "6...6", "6...6", "66666"};
//////vector<string> t1(s1, s1+5);
//////string s2[] = {"....6", "....6", "....6", "....6", "....6"};
//////vector<string> t2(s2, s2+5);
//////string s3[] =
////
////void printRes(long long res);
////void split(string s, string delim, vector<long long>& num, vector<string>& op);
////long long calculate(vector<long long>& num, vector<string>& op);
////
////void split(string s, string delim, vector<long long>& num, vector<string>& op){
////    int last = 0;
////    int index = s.find_first_of( delim, last);
////    while( index != string::npos){
////        string str = s.substr( last, index-last);
////        stringstream strIn;
////        strIn << str;
////        long long llNum;
////        strIn >> llNum;
////        // cout << llNum << endl;
////        num.push_back( llNum);
////        op.push_back( s.substr(index, 1));
////        last = index+1;
////        index = s.find_first_of( delim, last);
////    }
////    if( index - last){
////        string str = s.substr( last, index-last);
////        stringstream strIn;
////        strIn << str;
////        long long llNum;
////        strIn >> llNum;
////        // cout << llNum << endl;
////        num.push_back( llNum);
////    }
////}
////
////long long calculate(vector<long long>& num, vector<string>& op){
////    for(int i = 0; i < op.size(); i++){
////        if( op[i] == "*"){
////            num[i+1] = num[i] * num[i+1];
////            num[i] = -1;
////        }
////    }
////
////    for( int i = 0; i < num.size()-1; i++){
////        if( num[i] == -1) continue;
////        else{
////            if( op[i] == "+"){
////                int j = i;
////                while( num[i+1] == -1) i++;
////                num[i+1] += num[j];
////            }else if( op[i] == "-"){
////                int j = i;
////                while( num[i+1] == -1) i++;
////                num[i+1] = num[j] - num[i+1];
////            }else{
////                continue;
////            }
////        }
////    }
////    return num[num.size()-1];
////}
////
////void printRes(long long res){
////    string result;
////    stringstream ss;
////    ss << res;
////    ss >> result;
////    for( int i = 0; i < 5; i++){
////        for( int j = 0; j < result.size(); j++){
////            if( j == result.size()-1)
////                cout << NumPrint[result[j]-'0'][i] << endl;
////            else cout << NumPrint[result[j]-'0'][i] + "." ;
////        }
////    }
////}
////
////int main(){
////    int n;
////    scanf("%d", &n);
////    while( n--){
////        string s;
////        cin >> s;
////        vector<long long> num;
////        vector<string> op;
////        string delim = "+-*";
////        split( s, delim, num, op);
////        // for( auto i : num)
////        //     cout << i << ends;
////        // cout << endl;
////        // for( auto i : op)
////        //     cout << i<< ends;
////        long long res = calculate(num, op);
////        cout << res << endl;
////        printRes(res);
////    }
////    return 0;
////}
////#include <iostream>
////using namespace std;
//////int doMethod
////int main(){
////	int in = 0;
////	cin >> in;
////
////	int length1 = 1;
////	int length2 = 1;
////	int sum = 0;
////    if(in % 2 == 0){
////        while( length1 < in){
////            if(2 * length1 <= in){
////                length2 = length1;
////                length1 = 2*length1;
////            }
////            else{
////                length1 = length1 + length2;
////            }
////            sum ++;
////        }
////    }
////    else{
////        sum =  in-1;
////    }
////   	cout<<sum;
////	system("PAUSE");
////}
//
//
//
//
////#include <iostream>
////#include <vector>
////using namespace std;
////
////int main(){
////    int n = 0;
////    int m = 0;
////    vector<int> res;
////    int a = 0;
////    while(cin >> a){
////        res.push_back(a);
////    }
////    cout<<1/n;
////    return 0;
////
////}
//
////#include <iostream>
////#include <algorithm>
////#include <vector>
////#include <string.h>
////using namespace std;
////int dp[111111];
////int main() {
////     memset(dp, 0, sizeof(dp));
////     vector<int> v;
////     dp[0] = 1;
////     int n, k, h;
////     cin >> n >> k >> h;
////     int ma = -111;
////     int x;
////     for (int i = 0; i < n; i++) {
////      scanf("%d", &x);
////      v.push_back(x);
////      ma = max(ma, x);
////     }
////     ma = ma + 111;
////     sort(v.begin(), v.end());
////     for (int i = 0; i < ma; i++) {
////      int u = i - h;
////      vector<int>::iterator index1 = lower_bound(v.begin(), v.end(), u);
////      if (index1 == v.end()) {
////       continue;
////      }
////      for (vector<int>::iterator j = index1; *j < i && j != v.end(); j++) {
////       int t = i - *j;
////       if (*j - t >= 0)
////        dp[i] = max(dp[i], dp[*j - t]);
////      }
////     }
////     int ans;
////     for (int i = 111111; i >= 0; i--) {
////      if (dp[i] == 1) {
////       ans = i;
////       break;
////      }
////     }
////     cout << ans << endl;
////     return 0;
////}
//
////#include <bits/stdc++.h>
//#include <stdio.h>
//#include<iostream>
//#include <stack>
//#include <limits>
//#define ll long long
//
//using namespace std;
//
//const int MAX = 1e3+10;
//
//
//char a0[5][5] = {{'6', '6', '6', '6', '6'},
//				 {'6', '.', '.', '.', '6'},
//				 {'6', '.', '.', '.', '6'},
//				 {'6', '.', '.', '.', '6'},
//				 {'6', '6', '6', '6', '6'}};
//char a1[5][5] = {{'.', '.', '.', '.', '6'},
//				 {'.', '.', '.', '.', '6'},
//				 {'.', '.', '.', '.', '6'},
//				 {'.', '.', '.', '.', '6'},
//				 {'.', '.', '.', '.', '6'}};
//
//char a2[5][5] = {{'6', '6', '6', '6', '6'},
//				 {'.', '.', '.', '.', '6'},
//				 {'6', '6', '6', '6', '6'},
//				 {'6', '.', '.', '.', '.'},
//				 {'6', '6', '6', '6', '6'}};
//char a3[5][5] = {{'6', '6', '6', '6', '6'},
//				 {'.', '.', '.', '.', '6'},
//				 {'6', '6', '6', '6', '6'},
//				 {'.', '.', '.', '.', '6'},
//				 {'6', '6', '6', '6', '6'}};
//
//char a4[5][5] = {{'6', '.', '.', '.', '6'},
//				 {'6', '.', '.', '.', '6'},
//				 {'6', '6', '6', '6', '6'},
//				 {'.', '.', '.', '.', '6'},
//				 {'.', '.', '.', '.', '6'}};
//
//char a5[5][5] = {{'6', '6', '6', '6', '6'},
//				 {'6', '.', '.', '.', '.'},
//				 {'6', '6', '6', '6', '6'},
//				 {'.', '.', '.', '.', '6'},
//				 {'6', '6', '6', '6', '6'}};
//
//char a6[5][5] = {{'6', '6', '6', '6', '6'},
//				 {'6', '.', '.', '.', '.'},
//				 {'6', '6', '6', '6', '6'},
//				 {'6', '.', '.', '.', '6'},
//				 {'6', '6', '6', '6', '6'}};
//
//char a7[5][5] = {{'6', '6', '6', '6', '6'},
//				 {'.', '.', '.', '.', '6'},
//				 {'.', '.', '.', '.', '6'},
//				 {'.', '.', '.', '.', '6'},
//				 {'.', '.', '.', '.', '6'}};
//
//char a8[5][5] = {{'6', '6', '6', '6', '6'},
//				 {'6', '.', '.', '.', '6'},
//				 {'6', '6', '6', '6', '6'},
//				 {'6', '.', '.', '.', '6'},
//				 {'6', '6', '6', '6', '6'}};
//
//char a9[5][5] = {{'6', '6', '6', '6', '6'},
//				 {'6', '.', '.', '.', '6'},
//				 {'6', '6', '6', '6', '6'},
//				 {'.', '.', '.', '.', '6'},
//				 {'6', '6', '6', '6', '6'}};
//
//
//char ans[MAX][MAX], s[MAX];
//
//
//ll solve(int len){
//
//	stack<ll> S;
//	stack<char> T;
//
//	ll  x = 0ll, sign = 1ll;
//
//	for (int i = 0; i<len;){
//		if (s[i] == '+' || s[i] == '-'){
//			S.push(x);
//			T.push(s[i]);
//			i++;
//			x = 0;
//			continue;
//		}
//
//		if (s[i] == '*'){
//
//			int j = i+1;
//			ll y = 0;
//			while (j < len && s[j] != '+' && s[j] != '-'){
//				y = y * 10ll +  1ll*(s[j]-'0');
//				j++;
//			}
//
//			x = x * y;
//			i = j;
//
//			continue;
//		}
//
//		x = x*10ll + 1ll*(s[i] - '0');
//		i++;
//	}
//
//	while (!S.empty()){
//		char t = T.top();
//		T.pop();
//		ll y  = S.top();
//		S.pop();
//
//		if (t == '+'){
//			x = x + y;
//		}else{
//			x = y - x;
//		}
//	}
//
//	return x;
//}
//
//void print_res(int x){
//
//	if (x == 0ll){
//		for (int i = 0; i<5; i++){
//			for (int j = 0; j<5; j++){
//				printf("%c", a0[i][j]);
//			}
//			printf("\n");
//		}
//		return;
//	}
//
//	int a[100], cnt = 0;
//
//	while (x != 0){
//		a[cnt++] = x % 10;
//		x = x / 10;
//	}
//
//	for (int i = 0, j = cnt-1; i<j; i++, j--){
//		swap(a[i], a[j]);
//	}
//
//	for (int i = 0; i<cnt; i++){
//		if (a[i] == 0){
//			for (int j = 0; j<5; j++){
//				for (int k = i*5; k<i*5+5; k++){
//					ans[j][k] = a0[j][k-i*5];
//				}
//			}
//		}else if(a[i] == 1){
//			for (int j = 0; j<5; j++){
//				for (int k = i*5; k<i*5+5; k++){
//					ans[j][k] = a1[j][k-i*5];
//				}
//			}
//		}else if (a[i] == 2){
//			for (int j = 0; j<5; j++){
//				for (int k = i*5; k<i*5+5; k++){
//					ans[j][k] = a2[j][k-i*5];
//				}
//			}
//		}else if (a[i] == 3){
//			for (int j = 0; j<5; j++){
//				for (int k = i*5; k<i*5+5; k++){
//					ans[j][k] = a3[j][k-i*5];
//				}
//			}
//
//		}else if (a[i] == 4){
//			for (int j = 0; j<5; j++){
//				for (int k = i*5; k<i*5+5; k++){
//					ans[j][k] = a4[j][k-i*5];
//				}
//			}
//		}else if (a[i] == 5){
//			for (int j = 0; j<5; j++){
//				for (int k = i*5; k<i*5+5; k++){
//					ans[j][k] = a5[j][k-i*5];
//				}
//			}
//		}else if (a[i] == 6){
//			for (int j = 0; j<5; j++){
//				for (int k = i*5; k<i*5+5; k++){
//					ans[j][k] = a6[j][k-i*5];
//				}
//			}
//		}else if (a[i] == 7){
//			for (int j = 0; j<5; j++){
//				for (int k = i*5; k<i*5+5; k++){
//					ans[j][k] = a7[j][k-i*5];
//				}
//			}
//		}else if (a[i] == 8){
//			for (int j = 0; j<5; j++){
//				for (int k = i*5; k<i*5+5; k++){
//					ans[j][k] = a8[j][k-i*5];
//				}
//			}
//		}else{
//			for (int j = 0; j<5; j++){
//				for (int k = i*5; k<i*5+5; k++){
//					ans[j][k] = a9[j][k-i*5];
//				}
//			}
//		}
//
//	}
//	for (int i = 0; i<5; i++){
//		for (int j = 0; j<cnt*5; j++){
//			printf("%c", ans[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main(int argc, char const *argv[])
//{
//	/* code */
//
//	int n;
//	while (scanf("%d", &n) != EOF){
//		while(n--){
//			scanf("%s", s);
//
//			int len = strlen(s);
//
//			int res = solve(len);
//
//			print_res(res);
//
//
//		}
//	}
//	return 0;
//}


#include <iostream>
#include <vector>
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

int main(){
    string str;
    int num;
    while(cin>>str){
        num=NumOfPalindromeSubSequence(str);
        cout<<num<<endl;
    }
    return 0;
}


//京东笔试
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int countStep(int M, int x, int y){
    //vector< vector<vector<int>>> dp;
    for(int i = 0; i < 8; i++){
        if(1 < x < 7 && 1 < y < 7){
            vector<int> dpTmp;
            dpTmp.push_back(vector<int>(x-2));
            dpTmp.push_back(vector<int>(y+1));
            dp.push_back(dpTmp);
        }
    }

}
int main()
{
	int M = 0;
    int x = 0, y = 0;
    cin >> M;
    cin>>x>>y;
    int res = countStep(M, x , y);
    cout<<res<<endl;
    return 0;
}

//象棋
#include <iostream>
#include <vector>

using namespace std;

int update(vector<vector<vector<int>>>& dp, int i, int j, int k) {
    int ans = 0;
    if (i + 1 < 9) {
        if (j + 2 < 9) ans = (dp[k - 1][i + 1][j + 2] + ans) % 1000000007;
        if (j - 2 >= 0) ans = (dp[k - 1][i + 1][j - 2] + ans) % 1000000007;
    }
    if (i + 2 < 9) {
        if (j + 1 < 9) ans = (dp[k - 1][i + 2][j + 1] + ans) % 1000000007;
        if (j - 1 >= 0) ans = (dp[k - 1][i + 2][j - 1] + ans) % 1000000007;
    }
    if (i - 1 >= 0) {
        if (j + 2 < 9) ans = (dp[k - 1][i - 1][j + 2] + ans) % 1000000007;
        if (j - 2 >= 0) ans = (dp[k - 1][i - 1][j - 2] + ans) % 1000000007;
    }
    if (i - 2 >= 0) {
        if (j + 1 < 9) ans = (dp[k - 1][i - 2][j + 1] + ans) % 1000000007;
        if (j - 1 >= 0) ans = (dp[k - 1][i - 2][j - 1] + ans) % 1000000007;
    }
    return ans;
}

int main() {
    int M;
    cin>>M;
    vector<vector<vector<int>>> dp(M + 1, vector<vector<int>>(9, vector<int>(9, 0)));
    dp[0][0][0] = 1;
    for (int k = 1; k <= M; k++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                dp[k][i][j] = update(dp, i, j, k);
            }
        }
    }
    int x, y;
    cin>>x>>y;
    cout<<dp[M][x][y]<<endl;
    return 0;
}
