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

string s;

int main(){_

    cin >> s;

    for (int i=1; i<sz(s); i++){

        if(s[i] == s[i-1]) {
            if(i==sz(s)-1) s[i] = (char)('a' + (s[i-1]-'a'+1)%26);
            else if (s[i+1] == 'a' + (s[i-1]-'a' + 1)%26) s[i] = (char)('a' + (s[i-1]-'a'+2)%26);
            else s[i] = (char)('a' + (s[i-1]-'a'+1)%26);
        }
    }

    cout << s << endl;

    return 0;
}