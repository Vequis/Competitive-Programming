#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()
#define fs first
#define sc second
#define ii pair<int, int>
#define vii vector<ii>
#define endl '\n'
#define ll long long int

using namespace std;

int vagaoFrente, n; //Eu poderia ter criado uma stack, adicionando de n á 1. Mas criar esse contador funciona de forma semelhante
vector<int> ordemSaida;
stack<int> estacaoa;
int num;

int main(){_
    cin >> n;

    while (n!=0){
        ordemSaida = vi(n);

        while(1){
            for (int i=0; i<n; i++){
                cin >> num;
                ordemSaida[i] = num;
                
                if (i==0 and num == 0){
                    cout << endl;
                    break;
                }
            }

            if (num==0) break;

            bool ok = true; 
            vagaoFrente = 1;
            for (int i=0; i<n; i++){
                num = ordemSaida[i];

                // cout << "*" << num << endl;

                if (!estacaoa.empty() and estacaoa.top() == num){
                    estacaoa.pop();
                    continue;
                } else if (vagaoFrente == num){
                    vagaoFrente++;
                    continue;
                } else {
                    if (vagaoFrente <=n) {
                        estacaoa.push(vagaoFrente);
                        vagaoFrente++;
                        i--;    
                    } else {
                        ok = false;
                        break;
                    }    
                }

                if(!ok) break;
            }

            if (ok) cout << "Yes" << endl;
            else cout << "No" << endl;

            ordemSaida.clear();
            while(!estacaoa.empty()) estacaoa.pop();
        
        }

        cin >> n;
    }

    return 0;
}