#include <bits/stdc++.h>
using namespace std;
#define fo(i, c) for (int(i) = 0; (i) < (c); (i)++)
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

void ans(int arr[], int size, int x, int output[], int currInd, int &k)
{
    if (currInd == size)
    {
        return;
    }
    if (arr[currInd] == x)
    {
        output[k++] = currInd;
    }

    ans(arr, size, x, output, currInd + 1, k);
}

int allIndexes(int arr[], int size, int x, int output[])
{
    int k = 0;
    ans(arr, size, x, output, 0, k);
    return k;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    fo(i, n)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int output[n];
    int size = allIndexes(arr, n, x, output);
    fo(i, size)
    {
        cout << output[i] << " ";
    }
}