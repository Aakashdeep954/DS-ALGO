#include <bits/stdc++.h>
using namespace std;
#define fo(i,c) for(int(i) = 0; (i) < (c); (i)++)
#define go(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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


void swap(int arr[],int j){
    int temp = arr[j];
    arr[j] = arr[j+1];
    arr[j+1] = temp;
}
void bubble_sort(int arr[],int size){
    fo(i,size-1){
        fo(j,size-i-1){
            if(arr[j]>arr[j+1]){
                swap(arr,j);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin>>n;
    int arr[n];
    fo(i,n){
        cin>>arr[i];
    }
    bubble_sort(arr,n);
    fo(i,n){
        cout<<arr[i]<<endl;
    }
}