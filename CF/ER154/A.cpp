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
#define int long long

using namespace std;

vi primos;
int vetor[10000];

bool primo(int n) {
    if (n/10 == n%10) return false;
    for(int i = 0; i < sz(primos); i++) {
        if (primos[i] == n) return true;
        else if (primos[i] > n) return false;
    }
}


void crivo(int n) {
    int ind = 2;
    while(ind<=n){
        if (vetor[ind] == 0) { //elemento == 0 => elemento é primo
            vetor[ind] = 1; //Mostra que o elemento é composto
            int var = floor(n/ind);

            primos.push_back(ind);

            for (int i=ind*ind; i<=var*ind; i+=ind){
                vetor[i] = 1;
            }
        }

        ind++;
    }
}

signed main(){_

    int t;
    cin >> t;

    crivo(200);

    while(t--) {
        string s;
        cin >> s;

        int resp = (s[0] - '0');
        resp*=10;
        resp+=1;

        while(!primo(resp)) resp++;

        cout << resp << endl;
    }

    return 0;
}
