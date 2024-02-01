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

set<ii> cj;
set<ii>::iterator it;
int n, x, y;

//x0 x1 i0 i1 j0 j1 y0 Variaveis proibidas --> NÃO USE ISSO

int main(){_

    int n;
    cin >> n;

    for (int i=n-1;i >=0; i--){
        cin >> x >> y;
        cj.insert({x,y});
        //cj.insert(ii(x,y));
    }

    for (it = cj.begin(); it!=cj.end(); it++){
        ii par = (*it);
        cout << par.fs << " " << par.sc << endl;
    }

    return 0;
}