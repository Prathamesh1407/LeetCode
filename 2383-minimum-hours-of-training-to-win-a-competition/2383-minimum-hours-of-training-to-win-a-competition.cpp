class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans=0;
        for(int i=0;i<energy.size();i++)
        {
            if(initialEnergy<=energy[i])
            {
                int diff=energy[i]-initialEnergy+1;
                initialEnergy+=diff;
                ans+=diff;
            }
            if(initialExperience<=experience[i])
            {
                int diff=experience[i]-initialExperience+1;
                initialExperience+=diff;
                ans+=diff;
            }
            initialEnergy-=energy[i];
            initialExperience+=experience[i];
        }        
        return ans;
        
    }
};