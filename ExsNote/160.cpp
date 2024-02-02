#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string strGab,strRes;
    cin >> strGab >> strRes;
    int nota=0;

    for (int i=0;i<n;i++) {
        if (strGab[i]==strRes[i]) nota++;
    }

    cout << nota << endl;
    return 0;
}
