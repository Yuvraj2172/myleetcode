class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int pos =0;
        while(n){
            ans+= (n&1)<<(31-pos);
            n=n>>1;
            pos++;
        }
        return ans;
    }
};