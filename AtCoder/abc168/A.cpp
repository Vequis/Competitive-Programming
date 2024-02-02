#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    int sz = n%10;

    if (sz == 2 or sz== 4 or sz == 5 or sz == 7 or sz==9 ) cout << "hon" << endl;
    else if( sz==0 or sz == 1 or sz == 6 or sz ==8) cout << "pon" << endl;
    else cout << "bon" << endl;

    return 0;
}
