#include <iostream>
using namespace std;

int recur(int x,int times){
    if () return times;
    int a = recur((x+1)%16777216,times+1);
    int b = recur((x*2)%16777216,times+1);
    return min(a,b);
}
int main(){
    int x;
    cin >> x;
    cout << recur(x,0);
}