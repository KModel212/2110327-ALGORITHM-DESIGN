#include <iostream>
#include <vector>

using namespace std;

int jump(int i, vector<int> &a,vector<int> &memo,vector<bool> &has) {
    if (i==1) return a[i];
    if (i==2) return a[i-1]+a[i];
    if (i==3) return max(jump(i-2,a,memo,has),jump(i-1,a,memo,has))+a[i];
    if (has[i]) return memo[i];
    int ans = max(jump(i-3,a,memo,has),max(jump(i-2,a,memo,has),jump(i-1,a,memo,has))) + a[i];
    memo[i]=ans;
    has[i]=true;
    return ans;
}

int main() {
    int n ; 
    cin >> n;
    vector<int> a(n+1),memo(n+1,-1);
    vector<bool> has(n+1,false);
    a[0]=0;
    for (int i =1 ; i <=n ; i++) {
        cin >> a[i];
    }
    cout << jump(n,a,memo,has);
}