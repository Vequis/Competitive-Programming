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

int visitados[1000008];

void crivo(int n){
    for (int i=2; i<=n; i++){
        if (visitados[i] == 0){
            if ((long long)i*i > n) continue;
            for (int j=i*i; j<=n; j+=i) visitados[j] = 1;
        }
    }
}

int q , x, y;
vi psa; 

int main(){_

    crivo(1000008);

    cin >> q;
    psa = vi(1000008);

    psa[0] = 0;
    psa[1] = 0;
    psa[2] = 0;
    visitados[1] = 1;
    visitados[0] = 1;


    for (int i=3; i<=1000001; i++){
        psa[i] = psa[i-1];
        if (visitados[i] == 0 and (visitados[i-2] == 0 or visitados[i+2]==0) ){
            psa[i]++;
        }
    }

    for (int i=0; i<q; i++){
        cin >> x >> y;
        cout << psa[max(x,y)] - psa[min(x,y) - 1] << endl;
    }

    return 0;
}