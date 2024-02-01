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

int distx, disty;
int maxx, minx, maxy, miny;

int k;

set<int> posx;
set<int> posy;

map<int, int> fx;
map<int, int> fy;

int consider() {
    if (distx == disty) {

        int r = 0;

        int flagx = 0;
        int flagy = 0;

        int distax;
        int distay;

        if (fx[minx] < fx[maxx]) {
            r += fx[minx];

            posx.erase(minx);
            int prox = *posx.begin();

            distax = abs(prox - minx);
        } else {
            flagx=1;
            r += fx[maxx];

            posx.erase(maxx);
            int prox = *posx.rbegin();

            int distax = abs(prox - maxx);
        }

        if (fy[miny] < fy[maxy]) {
            r += fy[miny];

            posx.erase(miny);
            int prox = *posy.begin();

            distay = abs(prox - miny);
        } else {
            flagy=1;
            r += fy[maxy];

            posy.erase(maxy);
            int prox = *posy.rbegin();

            int distay = abs(prox - maxy);
        }

        int dist = min(distax, distay);

        if (r*dist > k) {
            int q = k/r;

            distx-=q;
            disty-=q;
            return -1;
        } else {
            k-=r*dist;
            if (flagx) {
                fx[maxx - dist] += fx[maxx];
                maxx -= dist;
                posx.insert(maxx);
            } else {
                fx[minx + dist] += fx[minx];
                minx += dist;
                posx.insert(minx);
            }

            if (flagy) {
                fy[maxy - dist] += fy[maxy];
                maxy -= dist;
                posy.insert(maxy);
            } else {
                fy[miny + dist] += fy[miny];
                miny += dist;
                posy.insert(miny);
            }

            distx -= dist;
            disty-=dist;
            return r;
        }

        // cout << r << ' ' << '*' << endl;

    } else if (distx > disty) { 
        if (fx[minx] < fx[maxx]) {
            int r = fx[minx];

            posx.erase(minx);
            int prox = *posx.begin();

            int dist = abs(prox - minx);

            if (r*dist > k or dist > abs(distx - disty)) {
                int q = min(k/r, abs(distx - disty));

                if (q > abs(distx - disty)) {
                    q = abs(distx - disty);
                    k-=r*q;
                    fx[minx + q] += r;
                    minx+=q;
                    distx-=q;
                    return r;
                } else {
                    distx-=q;
                    return -1;
                }
            } else {
                k-=r*dist;
                fy[minx + dist] += r;
                minx += dist;
                distx-=dist;
                return r;
            }
        } else {
            int r = fx[maxx];

            posx.erase(maxx);
            int prox = *posx.rbegin();

            int dist = abs(prox - maxx);

            if (r*dist > k or dist > abs(distx - disty)) {
                int q = k/r;

                if (q > abs(distx - disty)) {
                    q = abs(distx - disty);
                    k-=r*q;
                    fx[maxx - q] += r;
                    maxx-=q;
                    distx-=q;
                    return r;
                } else {
                    distx-=q;
                    return -1;
                }
            }else {
                k-=r*dist;
                fy[maxx - dist] += r;
                maxx -= dist;
                distx-=dist;
                return r;
            }
        }
    } else {
        if (fy[miny] < fy[maxy]) {
            int r = fy[miny];

            posy.erase(miny);
            int proy = *posy.begin();

            int dist = abs(proy - miny);

            if (r*dist > k or dist > abs(distx - disty)) {
                int q = k/r;

                if (q > abs(distx - disty)) {
                    q = abs(distx - disty);
                    k-=r*q;
                    fy[miny + q] += r;
                    miny+=q;
                    disty-=q;
                    return r;
                } else {
                    disty-=q;
                    return -1;
                }
            } else {
                k-=r*dist;
                fy[miny + dist] += r;
                miny += dist;
                disty-=dist;
                return r;
            }
        } else {
            int r = fy[maxy];

            posy.erase(maxy);
            int proy = *posy.rbegin();

            int dist = abs(proy - maxy);

            if (r*dist > k or dist > abs(distx - disty)) {
                int q = k/r;

                if (q > abs(distx - disty)) {
                    q = abs(distx - disty);
                    k-=r*q;
                    fy[maxy - q] += r;
                    maxy-=q;
                    disty-=q;
                    return r;
                } else {
                    disty-=q;
                    return -1;
                }
            }else {
                k-=r*dist;
                fy[maxy - dist] += r;
                maxy -= dist;
                disty-=dist;
                return r;
            }
        }
    }
}

signed main(){_

    int n;
    cin >> n;

    cin >> k;

    minx = INF;
    miny = INF;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        minx = min(x, minx);
        maxx = max(x, maxx);
        miny = min(y, miny);
        maxy = max(y, maxy);
        posx.insert(x);
        posy.insert(y);

        fx[x]++;
        fy[y]++;
    }

    distx = maxx - minx;
    disty = maxy - miny;

    // cout << *posx.rbegin() << endl;
    // posx.erase(maxx);
    // cout << *(posx.rbegin()) << endl;

    // for (int x : posx) cout << x << ' ';
    // cout << endl;

    // cout << '1' << maxx << ' ' << maxy << endl;

    while((distx != 0 and disty != 0) and consider() != -1) {
        cout << distx << ' ' << disty << endl;
    }
    cout << distx << ' ' << disty << endl;

    cout << max(distx, disty) << endl;

    return 0;
}
