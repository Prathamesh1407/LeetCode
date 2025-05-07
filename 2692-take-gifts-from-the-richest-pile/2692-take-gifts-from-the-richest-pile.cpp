class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq(begin(gifts),end(gifts));

        long long initialSum=0,sum=0;
        for(auto val:gifts) initialSum+=val;
        while(k--)
        {
            int maxEl=pq.top();
            pq.pop();
            int currSqrt=sqrt(maxEl);

            sum+=(maxEl-currSqrt);
            pq.push(currSqrt);
        }
        cout<<initialSum<<" "<<sum;
        return initialSum-sum;
    }
};