#include <iostream>
#include <vector>

using namespace std;

int bino(int n,int k,vector<vector<int>> &memo) {
    if (n==k || k==0) return 1;
    if (memo[n][k]>-1){
        return memo[n][k];
    }
    int ans = bino(n-1,k-1,memo) + bino(n-1,k,memo);
    memo[n][k]=ans;
    return ans;

}

int main() {
    int n,k;
    cin >> n >> k;
    vector<vector<int>> memo(n+1,vector<int>(k+1,-1));
    cout << bino(n,k,memo);
}