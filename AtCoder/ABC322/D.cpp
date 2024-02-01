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

int a[4][4];
int b[4][4];
int c[4][4];

bool verify(int atransy, int atransx, int btransy, int btransx, int ctransy, int ctransx) {
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int d, e, f;
            if (i - atransy < 0 or j - atransx < 0) d = 0;
            else d = a[i-atransy][j-atransx];
            if (i - btransy < 0 or j - btransx < 0) e = 0;
            else e = b[i-btransy][j-btransx];
            if (i - ctransy < 0 or j - ctransx < 0) f = 0;
            else f = c[i-ctransy][j-ctransx];

            if (!d and !e and !f) return 0;
        }
    }

    return 1;
}

bool verifyAll() {
    int resp = 0;
    for(int i1 = 0; i1 < 4; i1++) {
        for(int i2 = 0; i2 < 4; i2++) {
            for(int i3 = 0; i3 < 4; i3++) {
                for(int i4 = 0; i4 < 4; i4++) {

                    for(int i5 = 0; i5 < 4; i5++) {

                        for(int i6 = 0; i6 < 4; i6++) {
                            // if (verify(i1, i2, i3, i4, i5, i6)) {
                            //     cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << i4 << ' ' << i5 << ' ' << i6 << endl;
                            // }
                            resp = resp or verify(i1, i2, i3, i4, i5, i6);
                        } 
                    } 
                } 

            } 

        }        
    }

    return resp;
}

void rotate(int n) {
    if(n==1) {
        for(int i=0; i<4; i++){
            for(int j=i+1; j<4; j++)
                swap(a[i][j], a[j][i]);
            }

        //Reversing each row of the matrix
        for(int i=0; i<4; i++){
            for(int j=0; j<4/2; j++){
                swap(a[i][j], a[i][4-j-1]);
            }
        }

    } else if (n==2) {
        for(int i=0; i<4; i++){
            for(int j=i+1; j<4; j++)
                swap(b[i][j], b[j][i]);
            }

        //Reversing each row of the matrix
        for(int i=0; i<4; i++){
            for(int j=0; j<4/2; j++){
                swap(b[i][j], b[i][4-j-1]);
            }
        }
    } else {
        for(int i=0; i<4; i++){
            for(int j=i+1; j<4; j++)
                swap(c[i][j], c[j][i]);
            }

        //Reversing each row of the matrix
        for(int i=0; i<4; i++){
            for(int j=0; j<4/2; j++){
                swap(c[i][j], c[i][4-j-1]);
            }
        }
    }
}

void adjustBorders(int n) {
    if (n == 1) {
        int var[4][4];
        int clr = 0;

        int just0 = 1;
        while(just0) {
            for(int i = 0; i < 4; i++) {
                if (a[clr][i] == 1) {
                    just0 = 0;
                }
            }

            if (just0) clr++;
        }

        if(clr != 0) {
            for(int i = 0; i < 4 - clr; i++) {
                for (int j = 0; j < 4; j++) {
                    a[i][j] = a[i+clr][j];
                }
            }

            for(int i = 4 - clr; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    a[i][j] = 0;
                }
            }
        }


        clr = 0;

        just0 = 1;
        while(just0) {
            for(int i = 0; i < 4; i++) {
                if (a[i][clr] == 1) {
                    just0 = 0;
                }
            }

            if (just0) clr++;
        }

        if(clr != 0) {
            for(int i = 0; i < 4 - clr; i++) {
                for (int j = 0; j < 4; j++) {
                    a[j][i] = a[j][i+clr];
                }
            }

            for(int i = 4 - clr; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    a[j][i] = 0;
                }
            }
        }



    } else if (n==2) {
        int clr = 0;

        int just0 = 1;
        while(just0) {
            for(int i = 0; i < 4; i++) {
                if (b[clr][i] == 1) {
                    just0 = 0;
                }
            }

            if (just0) clr++;
        }

        if(clr != 0) {
            for(int i = 0; i < 4 - clr; i++) {
                for (int j = 0; j < 4; j++) {
                    b[i][j] = b[i+clr][j];
                }
            }

            for(int i = 4 - clr; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    b[i][j] = 0;
                }
            }
        }


        clr = 0;

        just0 = 1;
        while(just0) {
            for(int i = 0; i < 4; i++) {
                if (b[i][clr] == 1) {
                    just0 = 0;
                }
            }

            if (just0) clr++;
        }

        if(clr != 0) {
            for(int i = 0; i < 4 - clr; i++) {
                for (int j = 0; j < 4; j++) {
                    b[j][i] = b[j][i+clr];
                }
            }

            for(int i = 4 - clr; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    b[j][i] = 0;
                }
            }
        }
    } else {
        int clr = 0;

        int just0 = 1;
        while(just0) {
            for(int i = 0; i < 4; i++) {
                if (c[clr][i] == 1) {
                    just0 = 0;
                }
            }

            if (just0) clr++;
        }

        if(clr != 0) {
            for(int i = 0; i < 4 - clr; i++) {
                for (int j = 0; j < 4; j++) {
                    c[i][j] = c[i+clr][j];
                }
            }

            for(int i = 4 - clr; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    c[i][j] = 0;
                }
            }
        }


        clr = 0;

        just0 = 1;
        while(just0) {
            for(int i = 0; i < 4; i++) {
                if (c[i][clr] == 1) {
                    just0 = 0;
                }
            }

            if (just0) clr++;
        }

        if(clr != 0) {
            for(int i = 0; i < 4 - clr; i++) {
                for (int j = 0; j < 4; j++) {
                    c[j][i] = c[j][i+clr];
                }
            }

            for(int i = 4 - clr; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    c[j][i] = 0;
                }
            }
        }
    }
}

signed main(){_

    int cnta = 0;
    for(int i = 0; i < 4; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < 4; j++) {
            a[i][j] = (s[j] == '#');
            cnta+= (s[j] == '#');
        }
    }

    int cntb = 0;
    for(int i = 0; i < 4; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < 4; j++) {
            b[i][j] = (s[j] == '#');
            cntb+= (s[j] == '#');
        }
    }

    int cntc = 0;
    for(int i = 0; i < 4; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < 4; j++) {
            c[i][j] = (s[j] == '#');
            cntc+= (s[j] == '#');
        }
    }

    if (cnta + cntb + cntc != 16) {
        cout << "No" << endl;
        return 0;
    }

    adjustBorders(1);
    adjustBorders(2);
    adjustBorders(3);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {

                if(verifyAll()) {
                    // cout << i << ' ' << j << ' ' << k << endl;
                    cout << "Yes" << endl;
                    return 0;
                }

                rotate(3);
                adjustBorders(3);
            }
            rotate(2);
            adjustBorders(2);
        }
        rotate(1)  ;
        adjustBorders(1);
    }
    
    cout << "No" << endl;

    return 0;
}
