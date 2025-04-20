class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeros=0,ones=0;
        for(auto val:students)
        {
            if(val==0) zeros++;
            else ones++;
        }

        for(auto val:sandwiches)
        {
            if(val==1)
            {
                if(ones>0) ones--;
                else return zeros;
            }
            else
            {
                if(zeros>0) zeros--;
                else return ones;
            }
        }


        return 0;
    }
};