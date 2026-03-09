#include <iostream>
#include <vector>

using namespace std;

int inverse(int a[],int start,int stop) {
    
    if (start==stop) return 0;

    int m = (start+stop)/2;

    int r1=inverse(a,start,m);
    int r2=inverse(a,m+1,stop);

    int r3=0;

    

    return r1+r2+r3;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++) {
        int x;
        cin >> x;
        a[i]=x;
    }
    cout << inverse(a,0,n-1) << endl;
}