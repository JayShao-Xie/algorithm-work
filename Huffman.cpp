#include<stdio.h>
#include<queue>
#include<vector>
using namespace std; 
#define ll long long
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        priority_queue<ll, vector<ll>, greater<ll> >q;
        ll res = 0;
        for (int i = 1; i <= n; ++i) {
            ll x;
            scanf("%lld", &x);
            q.push(x);
        }
        while (1) {
            ll a = q.top();
            q.pop();
            if (q.empty())break;
            ll b = q.top();
            q.pop();
            res += a + b;
            q.push(a + b);
        }
        printf("%lld\n", res);
    }
}
