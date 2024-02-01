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
#define int long long // -> solução divina

using namespace std;

int pos[9];

int fat9 = 362880;
string s;
int entrada[112345];
int indmin;

signed main(){_

    for(int i=0; i<9; i++) pos[i] =  i+1;

    int atual = 1;
    int soma = 0;

    int resp = INT_MAX;

    cin >> s;

    for(int i=0; i<sz(s); i++){
        entrada[i] = (s[i] - '0');
    }

    for(int i=1; i<=fat9; i++){
        soma = 0;
        atual = 1;

        next_permutation(pos, pos+9);

        // cout << i << endl;   

        for(int j=0; j<sz(s); j++) {
            soma+=abs(pos[entrada[j] - 1] - atual);
            atual = pos[entrada[j] - 1];
        }

        if (resp >= soma){
            indmin = i;
        }

        if(soma + sz(s) == 86){
            for(int j = 0; j<9; j++) cout << pos[j] << ' ';
            cout << endl;
        }
        resp = min(resp, soma);

    }

    // for(int i=1; i<=fat9; i++){

    //     next_permutation(pos, pos+9);

    //     if(i == indmin){
    //         for(int j = 0; j<9; j++) cout << pos[j] << ' ';
    //         break;
    //     }
    // }
    // cout << endl;
    cout << resp + sz(s) << endl;

    return 0;
}
