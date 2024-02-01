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

string s, soma, resp;
int cont[26], resp=0;

int main(){_

    cin >> s;
    for (int i=0; i<s.size(); i++) resp^(s[i]);
    
    cin >> s;
    for (int i=0; i<s.size(); i++) cont[s[i]-'A']++;

    cin >> s;
    for (int i=0; i<s.size(); i++) cont[s[i]-'A']--;

    for (int i=0; i<26; i++){
        if (cont[i]){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}