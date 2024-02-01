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

string s;
char c;

int main(){_

    cin >> s;

    int tam = s.size();

    if (s[tam-1] == 's'){
        cout << s << "es" << endl;
    } else {
        cout << s << "s" << endl;
    }

    return 0;
}