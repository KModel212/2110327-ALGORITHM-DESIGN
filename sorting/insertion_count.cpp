#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> A(n);
    for (int i =0;i<n;i++) {
        int j;
        cin >> j;
        A[i]=j;
    }
    while (m--) {
        int k,res=0;
        cin >> k;
        int pos =0 ;
        for (auto x : A) {
            if (x!=k) pos++;
            else break;
        }
        for (int i=0;i<pos;i++) {
            if (A[i]>k) res++;
        }
        cout << res << endl;
    }
}