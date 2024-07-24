class Solution {
    static bool compare(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b)
    {
        if(a.first!=b.first)
        {
            return a.first<b.first;
        }
        else
        {
            return a.second.second<b.second.second;
        }
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,pair<int,int>>>v;
        int i=0;
        for(auto val:nums)
        {
            int num=val,ans=0,pow=1;
            while(num>0)
            {
                int ld=mapping[num%10];
                ans+=(ld*pow);
                pow*=10;
                num/=10;
            }
            if(val==0) v.push_back({mapping[0],{val,i}});
            else v.push_back({ans,{val,i}});
            i++;
        }
        
        sort(v.begin(),v.end(),compare);
        
        vector<int>ans;
        for(auto val:v)
        {
            //cout<<val.first<<" "<<val.second.second<<endl;
            ans.push_back(val.second.first);      
        }
        return ans;
    }
};