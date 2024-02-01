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
int siz, luck, cont, digito;

int main(){_

    cin >> s;
    siz = s.length();

    for (int i=0; i<siz; i++){
        if (s[i] == '4' or s[i] =='7') cont++;
    }

    if (cont!=0) luck=1;

    while(cont>0){
        digito = cont%10;
        cont/=10;
        if (digito != 4 and digito !=7) luck =0;
    }   

    if (luck) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}