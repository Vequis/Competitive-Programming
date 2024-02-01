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

signed main(){_

    string s;
    int resp = 0;
    while(cin >> s) {
        
        int minr = 0;
        int ming = 0;
        int minb = 0;
        if (s == "Game") {
            int pos = 1;

            string aux;
            cin >> aux;

            int id = 0;
            for(int i = 0; i < sz(aux) - 1; i++) {
                id*=10;
                id += aux[i] - '0';
            }

            string numb = ".";
            string color = ";";

            while(color[sz(color) - 1] == ';' or color[sz(color) - 1] == ',') {

                cin >> numb;
                cin >> color;

                int cont = 0;

                for(int i = 0; i < sz(numb); i++) {
                    cont*=10;
                    cont += numb[i] - '0';
                }

                
                if (color[0] == 'r') minr = max(minr, cont);
                if (color[0] == 'g') ming = max(ming, cont);
                if (color[0] == 'b') minb = max(minb, cont);
            

                // if ((color[0] == 'r' and cont > 12) || (color[0] == 'g' and cont > 13) || (color[0] == 'b' and cont > 14)) pos = 0;
            }

            if (minr == INF) minr = 0;
            if (ming == INF) ming = 0;
            if (minb == INF) minb = 0;

            cout << minr << ' ' << ming << ' ' <<minb;

            int power = minr*ming*minb;

            resp += power;
            cout << power << endl;
            // if (pos) resp += id;

        }
    }

    cout << resp << endl;

    return 0;
}
