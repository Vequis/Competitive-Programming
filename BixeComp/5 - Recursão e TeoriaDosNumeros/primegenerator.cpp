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

int visitados[33000];
vi primos;

void crivo(){
    primos.pb(2);
    for(int i=3; i<=32000; i+=2){
        if(!visitados[i]){
            primos.pb(i);
            for(int j=i*i; j<=32000; j+=i) visitados[j] = 1;
        }
    }
}

int bb(int x){
    int ini=0, fim=primos.size(), mid;
    while(ini < fim){
        mid = ini + (fim-ini)/2;
        if(primos[mid]>=x) fim=mid;
        else ini = mid+1;
    }

    return ini;
}

int ehprimo(int x){
    if(x==1) return 0;
    if(x==2) return 1;
    if(x%2==0) return 0;
    for(int i=3; i*i<=x; i+=2){
        if(x%i==0) return 0;
    }
    return 1;
}

int main(){_

    crivo();

    int t;
    int a, b;
    
    cin >> t;
    while(t--){
        cin >> a >> b;

        for(int i=a; i<=b; i++){
            if(ehprimo(i)) cout <<i << endl;
        }

        cout << endl;
    }

    return 0;
}