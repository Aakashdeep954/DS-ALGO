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
typedef string str;

//---------------------------------------pair----------------------------------------------------//
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<int, str> pistr;
//---------------------------------------pair----------------------------------------------------//

//--------------------------------------vector---------------------------------------------------//
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<vl> vvl;

typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

typedef vector<str> vstr;
typedef vector<pistr> vpistr;
typedef vector<vstr> vvstr;
//---------------------------------------vector---------------------------------------------------//

//------------------------------------unordered_map-----------------------------------------------//
typedef unordered_map<int,int> umapii;
typedef unordered_map<ll,ll> umapll;
typedef unordered_map<int,vi> umapivi;

typedef unordered_map<str,int> umapstri;
typedef unordered_map<int,str> umapistr;
//------------------------------------unordered_map-----------------------------------------------//

//----------------------------------------map-----------------------------------------------------//
typedef map<int,int> mapii;
typedef map<ll,ll> mapll;
//----------------------------------------map-----------------------------------------------------//

//----------------------------------------set-----------------------------------------------------//
typedef set<int> sei;
typedef set<ll> sel;
//----------------------------------------set-----------------------------------------------------//

//----------------------------------execution time------------------------------------------------//
#define EXT cout << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
//----------------------------------execution time------------------------------------------------//


void solve(){
    int n;
    cin>>n;
    int arrival[n];
    fo(i,n){
        cin>>arrival[i];
    }
    int departure[n];
    fo(i,n){
        cin>>departure[i];
    }
    umapii m;
    fo(i,n){
        m[arrival[i]]=departure[i];
    }
    int max=0;
    sort(arrival,arrival+n);
    fo(i,n){
        int j = i-1;
        int max_sofar=1;
        while(j>=0){
            if(m[arrival[j]]>=m[arrival[i]]){
                max_sofar++;
            }
            j--;
        }
        if(max<max_sofar){
            max=max_sofar;
        }
    }
    cout<<max<<endl;
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