#include<bits/stdc++.h>
using namespace std;
long long int n,m,i,p[300009],b[300009],low,high,mid,ans=999999;
int flag=0;
int main()
{

	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>b[i];
		if( b[i]<b[i-1] && i!=0)
				flag=1;
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	low=0;
	high=m-1;
	
	while(low<=high){
		flag=0;
		mid=(low+high)/2;
		for( i=0;i<n;i++)
		{
			p[i]=b[i];
		}
		
		if(p[0]+mid>=m)
				p[0]=0;
		for(i=1;i<n;i++){
				if(p[i]>p[i-1]){
					if((p[i]+mid)%m>=p[i-1]&&(p[i]+mid)%m<=p[i]){
						p[i]=p[i-1];
				}
				}
				else if(p[i]<p[i-1]){
					if((p[i]+mid)%m<p[i-1]&&(p[i]+mid)<p[i-1]){
						flag=1;
						low=mid+1;
						break;
					}
					else
						p[i]=p[i-1];
				}
		}
		if(flag==0){
				high=mid-1;
				if(mid<ans && mid>0)
				{
					ans = mid;
				}
				
			}
	}
	cout<<ans;
	

	return 0;
}