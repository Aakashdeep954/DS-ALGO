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
    int arr[n];
    fo(i,n){
        cin>>arr[i];
    }
    umapivi mapof_visited;
    fo(i,n){
        mapof_visited[arr[i]].pb(0);
        mapof_visited[arr[i]].pb(i);
    }
    int start_index;
    int len_max=0;
    fo(i,n){
        if(mapof_visited[arr[i]][0]!=1){
        int len_sofar=0;
        int prev_element = arr[i]-1;
        while(mapof_visited.find(prev_element)!=mapof_visited.end()){
            len_sofar++;
            mapof_visited[prev_element][0]=1;
            prev_element--;
        }
        
        int next_element = arr[i]+1;
        while(mapof_visited.find(next_element)!=mapof_visited.end()){
            len_sofar++;
            mapof_visited[next_element][0]=1;
            next_element++;
        }
        if(len_max<len_sofar){

            len_max=len_sofar;
            start_index=mapof_visited[prev_element+1][1];

        }
        else if(len_max==len_sofar){
            if(start_index>mapof_visited[prev_element+1][1]){
                start_index=mapof_visited[prev_element+1][1];
            }
        }
    }
    }
    cout<<arr[start_index]<<" "<<arr[start_index]+len_max<<endl;
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