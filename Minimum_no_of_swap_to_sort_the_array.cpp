#include<bits/stdc++.h>
using namespace std;

int func(vector<int> arr)
{
	int n=arr.size(),cnt1=0,cnt2=0;
	unordered_map<int,int>mp;
	vector<int>s=arr,t=arr;
	sort(s.begin(), s.end());
	for(int i=0;i<n;i++) mp[arr[i]]=i;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=s[i])
		{
			int idx = mp[s[i]];
			swap(arr[i],arr[idx]);
			mp[arr[i]]=i;
			mp[arr[idx]]=idx;
			cnt1++;
		}
	}
	arr=t;
	sort(s.begin(), s.end(),greater<int>());
	for(int i=0;i<n;i++) mp[arr[i]]=i;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=s[i])
		{
			int idx = mp[s[i]];
			swap(arr[i],arr[idx]);
			mp[arr[i]]=i;
			mp[arr[idx]]=idx;
			cnt2++;
		}
	}
	if(cnt1<cnt2)
		return cnt1;
	return cnt2;
}
int main()
{
	int n;
	cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	cout<<func(v);
	return 0;
}