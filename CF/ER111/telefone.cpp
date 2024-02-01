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

map<char, int> mp;

signed main(){_

    mp['A'] = 2;
    mp['B'] = 2;
    mp['C'] = 2;
    mp['D'] = 3;
    mp['E'] = 3;
    mp['F'] = 3;
    mp['G'] = 4;
    mp['H'] = 4;
    mp['I'] = 4;
    mp['J'] = 5;
    mp['K'] = 5;
    mp['L'] = 5;
    mp['M'] = 6;
    mp['N'] = 6;
    mp['O'] = 6;
    mp['P'] = 7;
    mp['Q'] = 7;
    mp['R'] = 7;
    mp['S'] = 7;
    mp['T'] = 8;
    mp['U'] = 8;
    mp['V'] = 8;
    mp['W'] = 9;
    mp['X'] = 9;
    mp['Y'] = 9;
    mp['Z'] = 9;

    string s;
    cin >> s;

    for(int i=0; i<sz(s); i++){
        if(s[i] >= 'A' && s[i] <='Z') cout << mp[s[i]];
        else if (s[i] >='a' && s[i]<='z') cout << mp[s[i] -'a' + 'A'];
        else cout << s[i];
    }

    cout << endl;

    return 0;
}
