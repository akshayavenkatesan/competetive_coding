#include<bits/stdc++.h>
using namespace std;
bool check(long long int a[], long long int n, long long int k,long long int h)
{
	long long int sum=0;
	for(long long int i=0;i<n;i++)
	{
		if(a[i]<=k)
		{
			sum = sum +1;
			//cout<<sum<<endl;

		}
		else
		{
			sum = sum +(a[i]/k) +1;
			//cout<<sum<<endl;
		}
	}

	if( sum <= h)
		return true;
	
	return false;

}
long long int main()
{
	long long int t;
	cin>>t;
	while(t>0)
	{
		long long int ans=0;
		long long int n,h,a[100],low,high,mid;
		cin>>n>>h;
		for(long long int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		low=1;
		high =1000000;
		
		while(low<=high)
		{

			mid = (low+high)/2;

			if(check(a,n,mid,h))
			{
				ans = mid;
				high= mid-1;
			}
			else
			{
				low = mid+1;

			}
		}
		cout<<ans<<endl;


		t--;
	}

	return 0;
}