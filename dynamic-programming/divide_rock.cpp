#include <iostream>
#include <vector>

using namespace std;

int div(int n,int k,vector<vector<int>> &mem) {
    if (n<k) return 0;
    if (n==k) return 1; 
    if (k<=0) return 0 ;
    if (mem[n][k]!=-1) return mem[n][k];
    long long ans = ((k*div(n-1,k,mem))%1997 + (div(n-1,k-1,mem))%1997)%1997;
    mem[n][k]=ans;
    return ans;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<vector<int>> mem(n+1,vector<int>(k+1,-1));
    cout << div(n,k,mem);
}