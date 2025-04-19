class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string>s;
        s.insert("0 0");
        int x=0,y=0;
        string temp="";
        for(auto val:path)
        {
            if(val=='N') y++;
            else if(val=='E') x++;
            else if(val=='W') x--;
            else y--;
            temp=to_string(x)+' '+to_string(y);
            if(s.find(temp)!=s.end()) return true;
            s.insert(temp);

        }

        return 0;
    }
};