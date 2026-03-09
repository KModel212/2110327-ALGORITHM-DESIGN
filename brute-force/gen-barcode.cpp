#include <iostream>
#include <vector>
using namespace std;

void combi(int white,int datacount,int cur_w,int len,vector<int>& data){
    if (len < datacount ) {
        if (len-cur_w<datacount-white) {
        data[len]=0;
        combi(white,datacount,cur_w,len+1,data);
        }
        if (cur_w<white) {
        data[len]=1;
        combi(white,datacount,cur_w+1,len+1,data);
        }
    } else {
        for (auto i : data) {
            cout << i ;
        }
        cout << endl;
    }
}

int main(){
    int a,b;
    cin >> a >> b;
    vector<int> v(b);
    combi(a,b,0,0,v);
}