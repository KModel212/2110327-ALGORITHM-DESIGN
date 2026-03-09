#include <iostream>
#include <vector>

using namespace std;

int cut(int length,int a,int b, int c,vector<int> &memo) {
    if (length < 0) return -1e9;
    if (length==0) return 0;
    if (memo[length]!=-1) return memo[length];
    int ans = max(cut(length-a,a,b,c,memo),max(cut(length-b,a,b,c,memo),cut(length-c,a,b,c,memo)))+1;
    memo[length]=ans;
    return ans;
}

int main() {
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<int> memo(n+1,-1);
    cout << cut(n,a,b,c,memo);
}