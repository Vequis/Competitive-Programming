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

int t, n;
char c;

string aux, ent;

int solve(string s){
    int sze= sz(s);

    if (s=="01" or s=="10") return 0;

    c = s[0];
    aux = "";
    for (int i=1; i<sze; i++){
        if(s[i] == c){
            aux=aux+c;
        }
        c=s[i];
    }

    if (aux=="") return 0;
    return 1+solve(aux);
}

int main(){_

    cin >> t;

    for (int i=0; i<t; i++){
        cin >> n;
        cin >> ent;
        cout << solve(ent) << endl;
    }

    return 0;
}