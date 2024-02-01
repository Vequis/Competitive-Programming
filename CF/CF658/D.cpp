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

vector<int> tams;
vi v;
vector< vector<int> > memo;

int t, n, ind, cont, siz, soma;

bool iSS(int n, int soma){

    if (soma == 0){
        return true;
    }

    if (n==0 and soma!=0){
        return false;
    }

    if (memo[n][soma] != -1 ){
        return memo[n][soma];
    }

    if (tams[n-1] > soma){
        return memo[n][soma] = iSS(n-1, soma);
    }

    return memo[n][soma] = (iSS(n-1, soma) || iSS(n-1, soma-tams[n-1]));
}

int main(){_

    cin >> t;

    for (int k=0; k<t; k++){
        cin >> n;

        memo = vector<vector<int> > (2020, vector<int>(2020, -1));

        v = vi(2*n);

        for (int i=0; i<2*n; i++){
            cin >> v[i]; 
        }

        ind = 0;
        cont = 1;
        for (int i=0; i<2*n-1; i++){
            if (v[i] > v[i+1]){
                cont++;
            } else if (v[i] < v[i+1] and v[ind] > v[i+1]){
                cont++;
            } else if (v[i] < v[i+1] and v[ind] < v[i+1]){
                tams.pb(cont);
                cont = 1;
                ind = i+1;
            }
        }

        if (cont==1) tams.pb(1);
        else tams.pb(cont);

        sort(all(tams));
        siz = sz(tams);

        soma = n;

        ind = 0 ;

        if(iSS(siz, soma)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        tams.clear();
        v.clear();

    }

    return 0;
}