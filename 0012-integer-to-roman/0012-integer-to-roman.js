/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    let ans ="";
    const helper = [[1000,"M"] , [900,"CM"] , [500,"D"] , [400,"CD"] , [100, "C"] , [90,"XC"] , [50,"L"] , [40,"XL"],[10,"X"] , [9,"IX"] , [5,"V"] , [4,"IV"] , [1,"I"]];
    for(let i=0; i < helper.length ;i++){
        while(num>= helper[i][0]){
            ans += helper[i][1];
            num -= helper[i][0];
        }
    }
return ans;
};