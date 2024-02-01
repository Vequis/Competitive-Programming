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

#define MAXN 1000000007

ll aux, soma, tam;
string st;

int main(){_
    while(cin >> st){
        tam = st.size();

        soma = 0;

        aux = 1;
        for (int i=tam-1; i>=0; i--){
            soma = ( soma + ((st[i] - 'A') * aux)%MAXN )%MAXN;

            aux = (aux*26)%MAXN;
        }

        cout << soma << endl;

        return 0;
    }
}