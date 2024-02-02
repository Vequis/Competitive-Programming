#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    int leitura,maior;
    maior = 0;

    for (int i=0;i<n;i++){
        cin >> leitura;
        nums[leitura]++;
    }

    for (int i=1;i<=12;i++){
        if (nums[i]>maior) maior = nums[i];
    }

    for (int i=1;i<=12;i++){
        if (nums[i]==maior) cout << i << " ";
    }
    cout << endl;
    return 0;
}
