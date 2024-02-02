#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> divs;

int main(){

    int a,b,c,d;
    cin >> a >> b >> c >> d;

    for (int i=2; i<=sqrt(c); i++){
        if (c%i==0){
            if (i%a==0 and i%b!=0 and d%i!=0){
                divs.push_back(i);
            }

            int num = c/i;

            if (num%a==0 and num%b!=0 and d%num!=0){
                divs.push_back(num);
            }
        }
    }

    sort(divs.begin(), divs.end());

    if (divs.size()){
        cout << divs[0] << endl;
    } else {
        cout << "-1" << endl;
    }

   return 0;
}