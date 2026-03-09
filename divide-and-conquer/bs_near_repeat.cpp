#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestbs(vector<int> &v,int q,int start,int stop) {
    if (start==stop) return v[start] <= q ? start : -1;
    int m = (start+stop)/2;
    if (v[m] <= q) {
        int right = largestbs(v,q,m+1,stop);
        return (right == -1 ? m : right);
    }
    else return largestbs(v,q,start,m);
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<int>v(n);
    for (int i=0;i<n;i++) {
        int x;
        cin >> x;
        v[i]=x;
    }
    while (m--) {
        int y;
        cin >> y;
        cout << largestbs(v,y,0,v.size()-1) << endl;
    }
}