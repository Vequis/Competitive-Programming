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

int a, b, c;

double heron(){
    double p = a+b+c;
    p /=2;

    double area = p*(p-a)*(p-b)*(p-c);
    return sqrt(area);
}

double rel(){
    return 27*(a*a + b*b - (c*c))*(a*a + b*b - (c*c))*(-(a*a) + b*b + c*c)*(-(a*a) + b*b + c*c)*(a*a - (b*b) + c*c)*(a*a - (b*b) + c*c);
}

int main(){_

    cin >> a >> b >> c;

    cout << heron() << endl;
    cout << heron()*heron()*heron()*heron()*heron()*heron()*4*4*4*4*4*4 << endl;
    cout << rel() << endl;

    if(rel() <=  heron()*heron()*heron()*heron()*heron()*heron()*4*4*4*4*4*4) cout << "Da certo" << endl;
    else cout << "Deu errado, CHUPA LUCIOT" << endl;

    return 0;
}