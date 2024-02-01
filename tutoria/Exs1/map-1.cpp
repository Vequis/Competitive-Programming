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

using namespace std;

int n, candidato;
map<int, int>::iterator it;
map<int, int> votos;

int main(){_

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> candidato;
        votos[candidato]++;
    }

    int prefeito = 0;
    int maior = 0;

    for (it = votos.begin(); it != votos.end(); it++){
        int atual = (*it).sc;
        if (atual > maior){
            maior = (*it).sc;
            prefeito = (*it).fs;
        }
    }

    cout << prefeito << endl;

    return 0;
}