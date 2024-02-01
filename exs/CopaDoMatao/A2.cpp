#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
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
#define int long long // -> solu��o divina 
#define PI 4*atan(1)
#define double long double

using namespace std;

double dist(double x1, double y1,double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

double ang(double x1, double y1,double x2, double y2)
{
    if((x2-x1) == 0)
    {
        if (y2 - y1 >= 0)
        {
            return PI/2;
        }
        else
        {
            return PI + PI/2;
        }
    }

    if((x2-x1) > 0)
    {
        return atan((y2-y1)/(x2-x1));
    }

    else
    {
        //cout << "aqui";
        //cout << y2 - y1 << x2 - x1 <<" dchao \n";
        return atan((y2-y1)/(x2-x1)) + PI;
    }
}

double g(double a) {
    if (a > 2*PI)
    {
        return a - 2*PI;
    }	
    if (a < 0)
    {
        return a + 2*PI;
    }
    return a;
}

int x[112345], y[112345];
double d[112345];
int n,i,j;
double a_chao;
double a;
double xp;
double yp;

signed main(){_
    cin >> n;
    
    for (i = 0; i < n;i++) {
        cin >> x[i];
        cin >> y[i];
    }

    for (i = 0; i < n;i++) {
        
        a_chao = ang(x[(i)%n],y[(i)%n],x[(i+1)%n],y[(i+1)%n]);
        for (j = 0; j < n;j++)
        {
            a = ang(x[(i+j)%n],y[(i+j)%n],x[(i+j+1)%n],y[(i+j+1)%n]);
            //cout << abs(a - a_chao) << "\n";
            if( g(g(a)-g(a_chao)) >= (PI/2)) {
                break;
            }

            d[i] += dist(x[(i+j)%n],y[(i+j)%n],x[(i+j+1)%n],y[(i+j+1)%n]);
        }	
    }
    
    for (i = 0; i < n;i++)
    {
        cout << fixed;
        cout << setprecision(10) << d[i];
        cout << "\n";
    }
    return 0;
}