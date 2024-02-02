#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int soma=0;
    int var;

    for (int i=1;i <=n;i++) {
        cin >> var;
        soma+=var;
    }

    cout << soma << endl;

    return 0;
}
