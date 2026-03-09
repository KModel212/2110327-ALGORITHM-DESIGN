#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int get_sum(vector<int>& s,int a,int b) {
    return s[b]-s[a-1];
}

int mcs(int start,int stop,vector<int>& prefsum) {
    if (start==stop) return get_sum(prefsum,start,start);

    int m = (start+stop)/2;
    
    int r1 = mcs(start,m,prefsum);
    int r2 = mcs(m+1,stop,prefsum);

    int max_sum_left = get_sum(prefsum,m,m);
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


int mincs(int start,int stop,vector<int>& prefsum) {
    if (start==stop) return get_sum(prefsum,start,start);

    int m = (start+stop)/2;
    
    int r1 = mincs(start,m,prefsum);
    int r2 = mincs(m+1,stop,prefsum);

    int max_sum_left = get_sum(prefsum,m,m);
    for (int i = start ; i<=m-1 ; i++) {
        max_sum_left=min(max_sum_left,get_sum(prefsum,i,m));
    }

    int max_sum_right = get_sum(prefsum,m+1,m+1);
    for (int i = m+2 ; i<=stop ; i++) {
        max_sum_right=min(max_sum_right,get_sum(prefsum,m+1,i));
    }

    int r3 = max_sum_right+max_sum_left;

    

    return min(r1,min(r2,r3));
}

int main(){
    int n;
    cin >> n ;
    vector<int> prefsum(n+1);
    prefsum[0] = 0;
    for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    prefsum[i] = prefsum[i-1] + x;
}

   


   int normal = mcs(1, n, prefsum);
int total = prefsum[n];
int minsub = mincs(1, n, prefsum);

if (minsub == total) {
    // all numbers are negative
    cout << normal << endl;
} else {
    cout << max(normal, total - minsub) << endl;
}


}