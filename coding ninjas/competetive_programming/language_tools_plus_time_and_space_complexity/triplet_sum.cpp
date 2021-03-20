#include <bits/stdc++.h>
using namespace std;
#define fo(i, c) for (int(i) = 0; (i) < (c); (i)++)
#define go(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define gc getchar_unlocked
#define ll long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define EXT cout << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
int pair_sum(int arr[], int start, int n, int x)
{
    int start_pointer = start;
    int end_pointer = n - 1;
    int count = 0;
    while (start_pointer < end_pointer)
    {
        if (arr[start_pointer] + arr[end_pointer] < x)
        {
            start_pointer++;
        }
        else if (arr[start_pointer] + arr[end_pointer] > x)
        {
            end_pointer--;
        }
        else
        {
            int l = arr[start_pointer];
            int r = arr[end_pointer];
            if (l == r)
            {
                int total_elements = end_pointer - start_pointer + 1;
                count += ((total_elements - 1) * (total_elements) / 2);
                return count;
            }
            int temp_start_pointer = start_pointer + 1;
            int temp_end_pointer = end_pointer - 1;
            while (temp_start_pointer <= temp_end_pointer && arr[temp_start_pointer] == l)
            {
                temp_start_pointer++;
            }
            while (temp_end_pointer >= temp_start_pointer && arr[temp_end_pointer] == r)
            {
                temp_end_pointer--;
            }
            int total_elements_from_start = temp_start_pointer - start_pointer;
            int total_elements_from_end = end_pointer - temp_end_pointer;
            count += (total_elements_from_start) * (total_elements_from_end);
            start_pointer = temp_start_pointer;
            end_pointer = temp_end_pointer;
        }
    }

    return count;
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    fo(i, n)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int ans = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        ans += pair_sum(arr, i + 1, n, x - arr[i]);
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}