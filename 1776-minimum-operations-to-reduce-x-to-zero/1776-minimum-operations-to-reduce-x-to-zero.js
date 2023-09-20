/**
 * @param {number[]} nums
 * @param {number} x
 * @return {number}
 */
var minOperations = function(nums, x) {
    let target = -x, n = nums.length;
    for(let num of nums)target += num;
    if(target == 0)return n;
    let maxlen =0, cursum = 0 , left = 0;
    for(let right = 0;  right < n; right++){
      cursum+= nums[right];
      while(left<= right && cursum > target){
        cursum -= nums[left++];
      }
      if(cursum === target) maxlen = Math.max(maxlen , right - left+1);
    }
    return maxlen ? n - maxlen : -1;
};