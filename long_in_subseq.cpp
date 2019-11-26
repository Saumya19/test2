#include<bits/stdc++.h>
using namespace std;

int _lis( int arr[], int n, int *max_ref)
{
	if (n == 1)
		return 1;

	int res, max_end = 1;

	for (int i = 1; i < n; i++)
	{
		res = _lis(arr, i, max_ref);
		if (arr[i-1] < arr[n-1] && res + 1 > max_end)
			max_end = res + 1;
	}

	if (*max_ref < max_end)
	*max_ref = max_end;

	return max_end;
}

int lis(int arr[], int n)
{
	int max = 1;

	_lis( arr, n, &max );

	return max;
}

int main()
{
	int n;
	cout<<"enter number of element\n";
	cin>>n;
	int a[n];
	cout<<"elements\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<lis(a,n);

	return 0;
}
