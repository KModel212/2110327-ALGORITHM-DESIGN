#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void wtfmatrix(vector<vector<int>> &v, int a, int b,int 
top,int bottom,int left,int right) {

    if (a==0) {
        v[0][0] = b ;return;
    } 

    if (a==1) {
        v[top][left] =b;
        v[top][right-1]=b-1;
        v[bottom-1][left]=b+1;
        v[bottom-1][right-1]=b;
        return;
    }

    int mid_row = (top + bottom) / 2;
    int mid_col = (left + right) / 2;

    wtfmatrix(v,a-1, b, top, mid_row, left, mid_col);
    wtfmatrix(v,a-1, b+1, mid_row, bottom, left, mid_col);
    wtfmatrix(v,a-1, b-1, top, mid_row, mid_col, right);
    wtfmatrix(v,a-1, b, mid_row, bottom, mid_col, right);
}

int main() {
    int a,b;
    cin >> a >> b;
    vector<vector<int>> v(1 << a , vector<int>(1 << a ));
    wtfmatrix(v ,a ,b ,0 ,1 << a ,0 ,1 << a);
    for (int i =0 ; i < v.size() ; i++) {
        for (int j =0 ; j < v.size(); j++) {
            cout << v[i][j] << " " ;
        }
        cout << endl;
    }
}