const MOD = 1e9 + 7;
memo = {}
function helper(n){
    if(n===1)return 1;
    if (memo[n]){
        return memo[n];
    }
    memo[n] = (helper(n-1) )*((2*n -1)*n) % MOD;
    return memo[n];
}
var countOrders = function(n) {
    return helper(n);
}