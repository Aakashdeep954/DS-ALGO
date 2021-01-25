#include <iostream>
using namespace std;
#include "solution.h"

int totalSum(int **arr, int n)
{
    //Write your code here
   
    int sum=0;
    
    for(int j=0;j<n;j++){
        sum = sum+arr[0][j];
    }
    
      for(int j=1;j<n;j++){
        sum = sum+arr[j][n-1];
    }
    
      for(int j=n-2;j>=0;j--){
        sum = sum+arr[n-1][j];
    }
    
      for(int j=1;j<n-1;j++){
        sum = sum+arr[j][0];
    }
    
    int i=1;
    int j=1;
    while(i!=n-1 && j!=n-1 && n>1){
        sum = sum + arr[i][j];
        i++;
        j++;
    }
    
    i=1;
    j=n-2;
    
     while(i!=n-1 && j!=n-1 && n>1){
        sum = sum + arr[i][j];
        i++;
        j--;
    }
    if(n%2!=0){
        sum = sum-arr[n/2][n/2];
    }
    return sum;
    
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int** arr = new int*[n];

		for (int i = 0; i < n; i++)
		{
			arr[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
        
        cout << totalSum(arr, n) << endl; 
	}
}
