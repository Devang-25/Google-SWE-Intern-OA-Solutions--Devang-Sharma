// Devang Sharma- Google Developers Group, Singapore

/*

Approach:
(1) Convert the array element like -->greater than K with 1 ,smaller than K with -1,equal to K with 0 (To Easily check numbers wrt K)
(2) Find min subarray length with sum equal to cumulative sum of new array (LC-209 Modified- Sliding Window/ Two Pointer)
(3) Ans= v.size()-minsubarraylength

*/

#include<bits/stdc++.h>
using namespace std;

// Min Subarray With Given Sum- Two Pointer Approach
// Leetcode-209 (Modified)

int minsubrray(vector<int> v,int sum)
{
    int curr=0;    
    int j=0;
    
    map<int,int> mp;
    int result=INT_MAX;
    
    for(int i=0;i<v.size();i++)
    {
        curr+=v[i];
        mp[curr]=i;

        if(mp.find(curr-sum)!=mp.end())
        {
            result=min(result,i-mp[curr-sum]);
        }
        
        else if(curr-sum==0)
        
        {
            result=min(result,i+1);
        }
    }
    
    return result;
    
}


int main()
{

    //Author: Devang
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin>>t;

    while (t--)
    {
        int n,k;
        cin>>n>>k;
    vector<int> v(n,0);
    vector<int> temp;
    int sum=0;
    int i=0;

    for (i=0;i<n;++i)
    cin>>v[i];

    for(int i=0;i<v.size();i++)
    {
        if(v[i]>k)
        {
            temp.push_back(1);
        }
        
        else if (v[i]<k)
        {
            temp.push_back(-1);
        }
        
        else
        {
            temp.push_back(0);
        }
        
        sum+=temp.back();
    }
    
    int result=minsubrray(temp,sum);
    cout<<v.size()-result<<endl;
    }

    return 0;    
}