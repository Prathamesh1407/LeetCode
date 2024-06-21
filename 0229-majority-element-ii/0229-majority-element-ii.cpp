class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int c1=0,c2=0,el1=INT_MIN,el2=INT_MIN;
        int n=v.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(c1==0 && v[i]!=el2)
            {
                c1=1;
                el1=v[i];
            }
            else if(c2==0 && v[i]!=el1)
            {
                c2=1;
                el2=v[i];
            }
            else if(v[i]==el1) c1++;
            else if(v[i]==el2) c2++;
            else
            {
                c1--;
                c2--;
            }
        }
        c1=c2=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==el1) c1++;
            if(v[i]==el2) c2++;
        }
        int mini=(n/3)+1;
        if(c1>=mini) ans.push_back(el1);
        if(c2>=mini) ans.push_back(el2);
        //2 log 2
        if(ans.size()==2) sort(ans.begin(),ans.end());
        return ans;
    }
};