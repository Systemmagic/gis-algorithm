/*#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 7;
int a[MAXN], n, ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int current = ans = a[1];
    for (int i = 2; i <= n; i++) {
        current = current > 0 ? current + a[i] : a[i];
        ans = max(ans, current);
    }

    cout << ans;
}
*/