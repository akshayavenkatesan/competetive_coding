#include<bits/stdc++.h>
using namespace std;

long long n , m , found , i , j , k[105] , x , c , visited[105];
vector<int>v[105];
vector<int>g[105];

void depthfirstsearch(long long a)
{
	visited[a]=1;
	for(auto p = g[a].begin();p!=g[a].end();++p)
	{
		if(!visited[*p]){
			depthfirstsearch(*p);
		}
	}
}

int main()
{
	cin>>n>>m;
	found=0;
	for(i=1;i<=n;i++){
		cin>>k[i];
		for(j=1;j<=k[i];j++){
			cin>>x;
			v[i].push_back(x);
			found = x;
		}
	}

	if(found==0)
		cout<<n;
	else
	{
		c=0;
		for(i=1;i<=n;i++)
		{
			if(k[i]==0)
			{
				v[i].push_back(found); 
				++c;
			}
			sort(v[i].begin(),v[i].end());
		}

		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				vector<long long>g1(v[i].size()+v[j].size());
				vector<long long>::iterator en; 
				if((set_intersection(v[i].begin(),v[i].end(),v[j].begin(),v[j].end(),g1.begin()) - g1.begin())>0)
				{
					g[i].push_back(j);
					g[j].push_back(i);
				}			
			}
		}

		for(i=1;i<=n;i++)
		{
			visited[i]=0;
		}

		for(i=1;i<=n;i++)
		{
			if(!visited[i])
			{
				depthfirstsearch(i);
				++c;
			}
		}
		cout<<c-1;
	}
	return 0;
}