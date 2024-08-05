class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        
        for(auto val:bills)
        {
            if(val==5) five++;
            else if(val==10)
            {
                //We have to give the change of 5
                ten++;
                if(five) five--;
                else return 0;
            }
            else
            {
                //means 20 We have to give the change of 15
                //5+5+5 or 10+5
                
                if(five && ten)
                {
                    five--;
                    ten--;
                }
                else if(five>=3)
                {
                    five-=3;
                }
                else return 0;
                
            }
        }
        return 1;
    }
    
};