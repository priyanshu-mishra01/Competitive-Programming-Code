#include<bits/stdc++.h>
#define int long long int
using namespace std;

int power(int n)
{
	int res = 1, base = 2, mod = (int)1e9 + 7;
        while (n > 0) {
            if (n % 2 == 1)
                res = res * base % mod;
            base = base * base % mod;
            n >>= 1;
        }
    return res;
}
int32_t main()
{
    int n = 10000;
    cout<<power(n)<<endl;
    return 0;
}