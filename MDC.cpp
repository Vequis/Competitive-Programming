#include <iostream>

using namespace std;

int mdc(int a, int b) {
    if (a<b) return mdc(b,a);
    if (b==0) return a;
    return mdc(b,a%b);
}

int main(){
    int a,b;
    cin >> a >> b;

    cout << "O mdc entre " << a << " e " << b << " eh " << mdc(a,b);
    return 0; 
}