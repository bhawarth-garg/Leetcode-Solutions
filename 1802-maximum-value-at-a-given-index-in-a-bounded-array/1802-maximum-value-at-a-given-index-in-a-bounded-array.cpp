class Solution {
public:
    bool isPossible(int mid, int sum, int n1, int n2)
    {
        long long temp= (long long)mid*(long long)(mid+1)/2;
        if(mid<=n1)
        {
            temp+= (long long)(n1-mid+1);
        }
        else
        {
            temp-= 1ll *(mid-n1-1)*(mid-n1)/2;
        }
        if(temp>sum)
            return false;

        temp+= (long long)(mid-1)*(long long)(mid)/2;
        if(mid<=n2)
        {
            temp+= (long long)(n2-mid+1);
        }
        else
        {
            temp-= 1ll *(mid-n2-1)*(mid-n2)/2;
        }

        return sum>=temp;
    }
    int maxValue(int n, int index, int maxSum) {
         int low= 1, up= maxSum;
         int ans=0;
         while(low<=up)
         {
            int mid= low+ (up-low)/2;

            if(isPossible(mid, maxSum, index, n-index-1))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                up=mid-1;
            }
         }

         return ans;
    }
};