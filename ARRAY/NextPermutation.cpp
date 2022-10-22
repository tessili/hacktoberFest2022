/*
Input : nums = [1,2,3]
Output: [1,3,2]
*/
class Solution {
public:
  
  
   // USING INBUITL FUNCTION  // T.C. = O(N)
    void nextPermutation(vector<int>& nums) 
    {
        next_permutation(nums.begin(),nums.end());
    }
  
  
  
  // USING NARAYAN'S PANDITHA'S ALGORITHM  // T.C. = O(N)  S.C. = O(1)
   void nextPermutation(vector<int>& nums) 
   {
        //next_permutation(nums.begin(),nums.end());
        int k1,k2,i,n=nums.size();
     
        for(i=n-2;i>=0;i--)     // finding the 1st index where a[i]<a[i+1]
        {
            if(nums[i]<nums[i+1]) {
                k1=i;
                break;
            }
        }
        
        if(k1<0) 
            reverse(nums.begin(),nums.end());
        else
        {
            for(i=n-1;i>k1;i--) // finding the 2nd index where a[i]<a[k1]
            {
                if(nums[i]>nums[k1]){
                    k2=i;
                    break;
                }
            }
        
            swap(nums[k1],nums[k2]);
            
            reverse(nums.begin()+k1+1,nums.end());
        }
        
        
       
    }
};
