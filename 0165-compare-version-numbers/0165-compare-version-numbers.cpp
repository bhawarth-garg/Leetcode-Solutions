class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        vector<string> v1, v2;
        int n1= version1.size(), n2= version2.size();

        for(int i=0;i<n1;i++)
        {
            string str="";
            while(i<n1 && version1[i]!='.')
            {
                str+=version1[i];
                i++;
            }
            int j=0, s=str.length() ;
            while(str[j]=='0')
                j++;
            v1.push_back(str.substr(j,s-j));
        }
        for(int i=0;i<n2;i++)
        {
            string str="";
            while(i<n2 && version2[i]!='.')
            {
                str+=version2[i];
                i++;
            }
            int j=0, s=str.length() ;
            while(str[j]=='0')
                j++;
            v2.push_back(str.substr(j,s-j));
        }
        for(int i=0;i<v1.size();i++)
        {
            cout<<v1[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<v2.size();i++)
        {
            cout<<v2[i]<<" ";
        }
        cout<<endl;

        int n= max(v1.size(), v2.size());

        while(v1.size()<n)
            v1.push_back("");
        while(v2.size()<n)
            v2.push_back("");

        for(int i=0;i<n;i++)
        {
            if(v1[i].length()==v2[i].length())
            {
                if(v1[i]>v2[i])
                    return 1;
                else if(v2[i]>v1[i])
                    return -1;
            }
            else if(v1[i].length()>v2[i].length())
                return 1;
            else if(v2[i].length()>v1[i].length())
                return -1;
        }
        
        return 0;
        

        


    }
};