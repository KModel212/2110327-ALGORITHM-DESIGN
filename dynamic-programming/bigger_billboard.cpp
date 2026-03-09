#include <iostream>
#include <vector>

using namespace std;

int bill(int n,vector<int> &c, vector<int> &memo) {
    if (n==1) return c[n];
    if (n==2) return max(c[2],c[1]);
    if (n==3) return max(c[3],max(c[2],c[1]));
    if (memo[n]!=-1) return memo[n];
    int ans = max((bill(n-3,c,memo)+c[n]),max(bill(n-2,c,memo),(bill(n-1,c,memo))));
    memo[n]=ans;
    return ans;
}

int main() {
    int n;
    cin >> n ;
    vector<int> memo(n+1,-1);
    vector<int> c(n+1);
    for (int i = 1 ; i <n+1 ; i++) {
        cin >> c[i];
    }
    cout << bill(n,c,memo);

}