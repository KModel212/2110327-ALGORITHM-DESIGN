#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int count(int n,int k, vector<int> &memo) {
    if (n==0 || k==0) return 1;
    if (memo[n]!=-1) return memo[n];
    if (n<k) {
        int ans = (1+count(n-1,k,memo))%100000007;
        memo[n]=ans;
        return ans;
    } 
    int ans = (count(n-1,k,memo) + count(n-k,k,memo))%100000007;
    memo[n]=ans;
    return ans;
}

int main() {
    int n,k ;
    cin >> n >> k;
    vector<int> memo(n+1,-1);
    cout << count(n,k,memo);
}