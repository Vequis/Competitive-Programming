// (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
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

string resp;
char c;

int main(){_

    while (cin >> c){
        if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')||(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')||(c=='y'||c=='Y')) continue;
        else if (c>='A' and c<='Z') {
            c = c-'A'+'a';
            resp+='.';
            resp+=c;
        } else{
            resp+='.';
            resp+=c;
        }
    }

    cout << resp << endl;

    return 0;
}