#include <iostream>
#include <vector>
#include <queue>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define LL long long
#define par pair<LL, LL>

using namespace std;

priority_queue<LL, vector<LL>, greater<LL> > menor;
priority_queue<par, vector<par>, greater<par> > fila;
LL n, k, x, i;

int main()
{_
    while (cin >> n >> k && n)
    {
        for (i = 1; i <= k; i++)
        {
            cin >> x;
            fila.push(make_pair(i, x));
            menor.push(x);
        }

        cout << menor.top();

        for (i = k + 1; i <= n; i++)
        {
            cin >> x;
            menor.push(x);
            while (!menor.empty() && menor.top() == fila.top().second) 
                menor.pop();

            cout << ' ' << menor.top();
            fila.push(make_pair(fila.top().first + k, x));
            fila.pop();
        }

        while (!fila.empty()) fila.pop();
        
        while (!menor.empty()) menor.pop();
        cout << endl;
    }

    return 0;
}