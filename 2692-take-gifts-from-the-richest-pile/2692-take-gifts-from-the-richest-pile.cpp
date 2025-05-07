class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq(begin(gifts),end(gifts));

        long long initialSum=0,sum=0;
        for(auto val:gifts) initialSum+=val;
        while(k--)
        {
            int maxEl=pq.top();//O(1)
            pq.pop();//O(log n)
            int currSqrt=sqrt(maxEl);

            sum+=(maxEl-currSqrt);
            pq.push(currSqrt);//O(log n)
        }
        
        return initialSum-sum;
    }
};
