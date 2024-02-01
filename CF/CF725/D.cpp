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

vi primos;
int visitados[1123456], a, b, k;

int conta, contb;

void crivo(){
    primos.pb(2);
    for (int i=3; i<=32000; i+=2){
        if(!visitados[i]){
            primos.pb(i);
            for(int j=i*i; j<=32000; j+=i) visitados[j] = 1;
        }
    }
}

int mdc(int a, int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return mdc(b, a%b);
}

int main(){_

    crivo();

    int t;

    cin >> t;

    while(t--){
        cin >> a >> b >> k;
        int i=0;

        if(k==1){
            if(a==b) cout << "NO" << endl;
            else if (max(a,b)%min(a,b) == 0) cout << "YES" << endl;
            else cout << "NO" << endl;

            continue;
        }

        if(a!=1){
            conta=0;
            
            i=0;

            while(a!=1 and i<sz(primos)){
                while(a%primos[i]==0){
                    conta++;
                    a/=primos[i];
                }
                i++;
            }

            if(a!=1) conta++;
        } else conta=0;

        if(b!=1){
            i=0;
            contb=0;

            while(b!=1 and i<sz(primos)){
                while(b%primos[i]==0){
                    contb++;
                    b/=primos[i];
                }
                i++;
            }

            if(b!=1) contb++;
        } else contb=0;

        // cout << conta << ' '<< contb << endl;

        if(conta + contb<k){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
