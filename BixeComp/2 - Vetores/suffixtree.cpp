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

string s;
char c;
int t;

int main(){_

    cin >> t;

    while(t--){
        cin >> s;
        c = s[s.size() - 1];
        if (c == 'o') cout << "FILIPINO" << endl;
        if (c == 'u') cout << "JAPANESE" << endl;
        if (c == 'a') cout << "KOREAN" << endl;
    }

    return 0;
}