class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        //TC: log base numExchange(numBottles)
        if(numBottles<numExchange) return numBottles;
        int dBottle=numBottles;
        int emptyBottles=numBottles;
        while(emptyBottles>=numExchange)
        {
            int extraFullBottles=emptyBottles/numExchange;
            int remainingBottles=emptyBottles%numExchange;
            dBottle+=extraFullBottles;
            emptyBottles=extraFullBottles+remainingBottles;
        }
        return dBottle;
    }
};