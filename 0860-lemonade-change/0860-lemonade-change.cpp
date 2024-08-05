class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivecnt=0,tencnt=0;
        
        for(auto bill: bills){
            if(bill==5){
                fivecnt++;
            }
            else if(bill==10){
                tencnt++;fivecnt--;
            }
            else if(bill==20){
                if(tencnt){
                    tencnt--;
                    fivecnt--;
                }
                else{
                    fivecnt=fivecnt-3;
                }
            }
            if(fivecnt<0) return false;
        }
        return true;
    }
    
};