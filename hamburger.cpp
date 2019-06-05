#include<bits/stdc++.h>
using namespace std;
int main()
{
	char bur[1000];
	long long int br=0,sr=0,cr=0,ba=0,sa=0,ca=0,money=0,m=0,b=0,s=0,c=0,flag=0,bp=0,sp=0,cp=0,mid=0,high=0,low=0,ans=0,i=0;
	cin>>bur;
	for(i=0;i<strlen(bur);i++)
	{
		if(bur[i]=='B')
			br++;         //required burger
		if(bur[i]=='S')
			sr++;			//requied sausage
		if(bur[i]=='C')
			cr++;         //required cheesee
	}
	cin>>ba>>sa>>ca;     //input available burger sausage pizza
	cin>>bp>>sp>>cp;	//price of each burger sausage pizza
	cin>>m;				//total money
	high=10000000000009;      
	low=0; ans=0;
	while(low<=high)
	{
		long long bc=0,sc=0,cc=0;
		money=m;
		mid=(low+high)/2;
		//cout<<mid<<endl;
		b=br*mid; //burger needed for mid no of hamburger
		s=sr*mid; //sausage needed for mid no of hamburger
		c=cr*mid; //cheese needed for mid no of hamburger
		if(b>=ba)
			bc=b-ba;  //required burger 
		if(s>=sa)
			sc=s-sa; // required sausage
		if(c>=ca)
			cc=c-ca;  // required cheese
		if(((bc*bp)+(sc*sp)+(cc*cp))<=money)
		{
			if(mid>ans)
				ans=mid;
			low=mid+1;
		}
		else
		{	
			high=mid-1;
		}

	}
	cout<<ans;
	return 0;
}