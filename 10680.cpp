#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int maxn = 1e6 + 10;
#define ll long long
int p[maxn];
void seive() {
    for(int i = 2; i < maxn; i++) p[i] = i;
    for(int i = 2; i*i < maxn; i++) {
        if(p[i] != i) continue;
        for(int j = i*i; j < maxn; j += i) {
            p[j] = i;
        }
    }
}
ll ans[maxn], cnt[maxn];
void preprocess() {
    ans[1] = 1;
    for(int i = 2; i < maxn; i++) {
        int x = i;
        ans[i] = ans[i-1];
        //printf("%d\n", i);
        while(x > 1) {
            int prime = p[x], c = 0;
            //printf("loop1\n");
            while(x % prime == 0) {
                c++, x /= prime;
            //    printf("loop2\n");
            }
            while(c > cnt[prime]) {
                ans[i] *= prime;
                cnt[prime]++;
            //    printf("loop3\n");
            }
            
            ans[i] = ans[i] % 10000000000;

        }
    }
    // for(int i = 1; i <= 10; i++) {
    //     printf("%d = %d\n", i, ans[i]);
    // }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    seive();
    preprocess();
    while(1) {
        int x;
        scanf("%d", &x);
        if(!x) break;
        assert(ans[x] != 0);
        while(ans[x] % 10 == 0) ans[x] /= 10;
        //cout << ans[x] % 10 << endl;
        printf("%lld\n", ans[x] % 10);
    }
    return 0;
}