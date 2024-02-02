#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[10];
    string leitura;

    for (int i=0;i<10;i++){
        nums[i]=0;
    }

    for (int i=0;i<n;i++){
        cin >> leitura;
        for (int j=0;j<leitura.size();j++){
            nums[(int)(leitura[j]-'0')]++;
        }
    }

    for (int i=0;i<10;i++){
        cout << i << " - " << nums[i] << endl;
    }

    return 0;
}
