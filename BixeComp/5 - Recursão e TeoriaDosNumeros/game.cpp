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
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
// #define int long long -> solução divina?

using namespace std;

vi primos, resp;
int visitados[1100];

void crivo(){
    primos.pb(2);
    for(int i=3; i<1010; i+=2){
        if(!visitados[i]){
            primos.pb(i);
            for (int j=i*i; j<=1010; j+=i) visitados[j]=1;
        }
    }
}

int main(){_

    crivo();

    int n;
    cin >> n;
    int i=0;

    while(primos[i]<=n){
        int atual = primos[i];
        while(atual <= n){
            resp.pb(atual);
            atual*=primos[i];
        }
        i++;
    }


    cout << sz(resp) << endl;
    for(int x : resp) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}