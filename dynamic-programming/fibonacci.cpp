#include <iostream>
#include <vector>

using namespace std;

int fibo(int n,vector<int> &m) {
    if (n==0) return 0;
    if (n==1) return 1;
    if (m[n]>0) {
        return m[n];
    }
    int ans = fibo(n-1,m)+fibo(n-2,m);
    m[n]=ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> memo(n+1,0);
    cout << fibo(n,memo) ;
}