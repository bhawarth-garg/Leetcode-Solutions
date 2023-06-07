class Solution {
public:
    string toDecimal(int num)
    {
        string s="";
        while(num)
        {
            s+= to_string(num%2);
            num/=2;
        }
        return s;
        
    }
    int minFlips(int a, int b, int cnum) {
        
        string x,y,z;
        int c=0;
        
        x= toDecimal(a);
        y= toDecimal(b);
        z= toDecimal(cnum);
        cout<<x<<" "<<y
<<" "<<z;        
        for(int i=1;i<=32;i++)
        {
            if(i>=x.length())
                x+='0';
            if(i>=y.length())
                y+='0';
            if(i>=z.length())
                z+='0';
        }
        
        for(int i=0;i<32;i++)
        {
            if(z[i]=='1' && x[i]=='0' && y[i]=='0')
                c++;
            else if(z[i]=='0')
            {
                if(x[i]=='1' && y[i]=='1')
                    c+=2;
                else if(x[i]=='1' || y[i]=='1')
                    c++;
            }
        }
        return c;
    }
};