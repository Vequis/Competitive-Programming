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

using namespace std;

int expo(int a, int b){
    ll atual = a, resp = 1;

    while(b>0){
        if (b%2) resp = (resp*atual)%MODN;
        b/=2;
        atual = (atual*atual)%MODN;
        // cout << resp << ' ' << atual << endl;
    }

    int resposta = resp;
    return resposta;
}

int a, b;

int main(){_

    int t;

    cin >> t;

    while (t--){
        cin >> a >> b;
        cout << expo(a,b) << endl;
    }

    return 0;
}