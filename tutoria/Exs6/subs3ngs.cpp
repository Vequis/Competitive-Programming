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

vi v(3);
string s;
char c, soma;
ll ans = 0;

int main(){_

    v[0] = 1;
    while(cin >> c){
        if (c>='0' and c<='9'){
            soma = (soma + (c-'0'))%3;
            ans+=v[soma];
            v[soma]++;
        } else {
            v.clear();
            v = vi(3);
            soma = 0;
            v[0] = 1;
        }
    }

    cout << ans << endl;

    return 0;
}