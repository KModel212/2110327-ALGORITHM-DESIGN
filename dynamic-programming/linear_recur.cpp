#include <iostream>
#include <vector>

using namespace std;

int linear (int n, int k, vector<int> &a, vector<int> &c, vector<int> &memo) {
    if (n<k) return a[n];
    if (memo[n]>-1) return memo[n];
    int ans = 0 ;
    for (int i =1 ; i <=k;i++) {
        ans=(ans + (c[i]*linear(n-i,k,a,c,memo))% 32717 )% 32717 ;
    }
    memo[n]=ans;
    return ans;
}

int main() {
    int n,k;
    cin >> k >> n;
    vector<int> memo(n+1,-1);
    vector<int> a(k+1,-1);
    vector<int> c(k+1,-1);
    for (int i =1 ; i <= k ; i++) {
        cin >> c[i];
    }
    for (int i =0 ; i < k ; i++) {
        cin >> a[i];
    }
    cout << linear(n,k,a,c,memo);

}