class Solution {
public:
    int trailingZeroes(int n) {
        
        int c2=0, c5=0 , num;
        for(int i=2;i<=n;i++)
        {
            num=i;
            if(i%2==0)
            {
                c2+= log2(i);
            }
            while(num>0 && num%5==0)
            {
                c5++;
                num/=5;
                
                // c5+= (int)((double)log2(i)/(double)log2(5));
                // cout<<i<<" "<<c5<<"  ";
            }
        }
        
        // cout<<c2<<" "<<c5;
        
        return (int) min(c2, c5);
        
    }
};