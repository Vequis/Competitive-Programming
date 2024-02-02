#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int x,y,n;

    for (int i=0; i<t;i++){
        cin >> x >> y >> n ;
        // if (n+y>=x){
            int num;
            num = n%x;
            // if (num>y){
            //     cout << num-y + n << endl;
            // } else {
            //     cout << n - (y-num) << endl;
            // }
            int resp = n-num+y;
            if (resp>n){
                cout << resp-x << endl;
            } else {
                cout << n -num + y << endl;
            }
    }

    return 0;

}