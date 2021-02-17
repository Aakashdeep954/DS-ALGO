#include <bits/stdc++.h>
using namespace std;
#define fo(i,c) for(int(i) = 0; (i) < (c); (i)++)
#define go(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
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

void solve(){
    int number;
    cin>>number;
    int sum = 0;
    while(number>0){
        sum+=number%10;
        number/=10;
    }
    cout<<sum<<endl;
}
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}