class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>>mapping=
        {{"I",1},{"IV",4},{"V",5},{"IX",9},{"X",10},{"XL",40},{"L",50},{"XC",90},{"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000}};
        string ans="";
        int i=12;
        while(num!=0 && i>=0)
        {
            if(num/mapping[i].second!=0)
            {
                int count=num/mapping[i].second;
                cout<<mapping[i].first;
                while(count--)
                {
                    ans+=mapping[i].first;
                }
                num%=mapping[i].second;
            }
            i--;
        }
        return ans;
        
    }
};