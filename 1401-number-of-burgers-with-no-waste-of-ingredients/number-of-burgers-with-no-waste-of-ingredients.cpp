class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        int j, s;
        j=s=0;
         vector<int> v;

        while(t>0 && c>0 && t>2*c)
        {
            t-=4;
            c-=1;
            j++;
        }
        if(t==2*c)
        {
            s=c;
        }
        else
            return v;
        v.push_back(j);
        v.push_back(s);


        return v;
        

        
    }
};