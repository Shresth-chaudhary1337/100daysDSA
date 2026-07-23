class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        int n=nums.size();

        if(n<3)
            return n;

        int bits =0;
        int x=n;
        while(x>0){
            bits++;
            x>>=1; //dividing by two bit shifts

        }
        return 1<<bits;

    }

};