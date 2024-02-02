#include <iostream>
#include <vector>

using namespace std;

int main(){

    int t;
    cin >> t;

    for (int i=0; i<t; i++){

        int n;
        cin >> n;

        vector<int> V1;
        vector<int> V2;

        for (int j=0; j<n; j++){
            int num;
            cin >> num;
            V1.push_back(num);
        }

        int tam = n-1;
        int ok = true;
        while(ok){
            ok = false;

            int tamtemp = tam;
            V2.push_back(V1[0]);
            for (int j=1; j<n-1; j++){  
                if (V1[j] > min(V1[j-1], V1[j+1]) and V1[j] < max(V1[j-1], V1[j+1])){
                    //Apagar o V1[j];
                    // ok = true;
                    tam--;
                } else {
                    V2.push_back(V1[j]);
                }
            }
            V2.push_back(V1[tamtemp]);
        }

        cout << V2.size() << endl;
        for (int i=0; i<V2.size(); i++) {
            cout << V2[i] << " ";
        }
        cout << endl;
    }


}