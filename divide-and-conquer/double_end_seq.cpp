#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int get_sum(vector<int>& s,int a,int b) {
    return s[b]-s[a-1];
}

int max_double_end(int l,int r,vector<int>& v) {
    if (l==r) return l;

    int m = (l+r)/2;
    
    int r1 = max_double_end(l,m);
    int r2 = max_double_end(m+1,r);

    int max_sum_left = get_sum(m,m);
    for (int i = start ; i<=m-1 ; i++) {
        max_sum_left=max(max_sum_left,get_sum(prefsum,i,m));
    }

    int max_sum_right = get_sum(prefsum,m+1,m+1);
    for (int i = m+2 ; i<=stop ; i++) {
        max_sum_right=max(max_sum_right,get_sum(prefsum,m+1,i));
    }

    int r3 = max_sum_right+max_sum_left;

    return max(r1,max(r2,r3));
}

int main () {
    int n;
    cin >> n ;
    vector<int> prefsum(n+1);
    prefsum[0] = 0;
    for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    prefsum[i] = prefsum[i-1] + x;
}

    cout << max_double_end(1,n,prefsum) << endl;
}