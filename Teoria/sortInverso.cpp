#include <iostream>
#include <algorithm>

using namespace std;

int func(int a, int b){
    return a>b;
}

int main() {
    int v[5] = {4,5,2,3,1};

    sort(v,v+5,func);

    for (int i=0;i<5;i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
