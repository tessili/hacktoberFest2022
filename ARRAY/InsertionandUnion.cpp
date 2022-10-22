
class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m) 
    {
        set<int >s;
        for(int i=0;i<n;i++)
        s.insert(a[i]);
        
        for(int i=0;i<m;i++)
        s.insert(b[i]);
        
        return s.size();        
    }    // used sets as in the set every value is unique 
    int doIntersection(int a[], int n, int b[], int m)  
    {
        unordered_set<int >s;
        int ctr;
        for(int i=0;i<n;i++)
        s.insert(a[i]);
        for(int i=0;i<m;i++)
        {
            if(s.find(b[i])!=s.end())
            {
                 ctr++;
                 s.erase(b[i]);
            }
        }
        return ctr;        
    }
};    // used onoredered set as all the operations takes O(1) and it's faster to search for a element