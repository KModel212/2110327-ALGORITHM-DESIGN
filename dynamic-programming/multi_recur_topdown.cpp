#include <iostream>
#include <vector>
using namespace std;

int multi(int n,int k, vector<int> &a, vector<vector<int>> &b, vector<int> &memo) {
    if (n<=0) {
        return 0;
    }
    if (n>0&&n<=k) {
        return a[n-1];
    }
    if (memo[n]!=-1) return memo[n];
    long long ans = 0;
    for (int i =0 ; i < b[n-k-1].size() ; i ++) {
        ans= (ans+(multi(n-b[n-k-1][i],k,a,b,memo)%32717))%32717;
    }
    memo[n]=ans;
    return ans;
}

int main() {
  ios::sync_with_stdio(false);
cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> a(k);
    vector<vector<int>> b(n-k);
    vector<int> memo(n+1,-1);
    for (int i =0 ; i < k ; i++) {
        cin >> a[i];
    }
    for (int i = 0 ; i <n-k; i ++) {
        int p;
        cin >> p;
        b[i].resize(p);
        for (int j = 0 ; j <p ; j++) {
            cin >> b[i][j];
        }

    }
    for (int i = 1; i <= n; i++)
        cout << multi(i,k,a,b,memo) << " ";
}