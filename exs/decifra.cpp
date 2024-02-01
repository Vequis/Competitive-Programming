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
#define MAX (1<<10) //2^10 = 1024

using namespace std;

map<int,char> mp;
char c;

int main(){_



    for (int i=0; i<26; i++){
        cin >> c;
        mp[i] = c;
    }

    string s;

    cin >> s;

    for (int i=0; i<sz(s) ;i++){
        cout << mp[s[i] - 'a'];
    }
    cout << endl;

    return 0;
}