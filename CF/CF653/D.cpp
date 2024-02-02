#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> r;

int main(){

    r.resize(1000000000);   
    long long int t;
    cin >> t;

    for (int i=0; i<t; i++){
        long long int n, k;
        cin >> n >> k;
        long long int x = 0;

        for(int j=0; j<n; j++){
            long long int num;
            cin >> num;
            r[num%k]++;
        }

        long long int cont = 0;
        bool ok = false;

        long long int ultimo = 0;
        while (!ok){
            ok = true;
            for (int j=k-1; j>0; j--){
                if (r[j] > 0){
                    ok = false;
                    if (x<=k-j) {
                        cont+= k-j -x+1;
                        x = k-j+1;
                        r[j]--;
                        if (x==k){ 
                            x = 0;
                            ultimo = 0;
                            break;
                        }
                    }
                }
            }
            if (x){
                cont += k-x;
                ultimo = k-x;
                x=0;
            }
        }
        cont-=ultimo;
        cout << cont << endl;
    }

    return 0;
}