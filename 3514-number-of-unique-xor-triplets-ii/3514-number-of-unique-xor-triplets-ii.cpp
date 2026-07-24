class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        const int MAX=2048;

        vector<bool>one(MAX,false);
        vector<bool>two(MAX,false);
        vector<bool>three(MAX,false);

        for(int num:nums)
            one[num]=true;

        for(int x=0;x<MAX;x++){
            if(!one[x])
                continue;
            for(int num:nums){
                two[x^num]=true;
            }
        }
        for(int x=0;x<MAX;x++){
            if(!two[x])
                continue;

        for(int num:nums){
            three[x^num]=true;
        }
        }
        int ans=0;
        for(bool possible:three){
            if(possible)
            ans++;
        }
        return ans;
    }
};