
var groupThePeople = function(arr) {
       let ans = [];
       let group = {};
       for(let i =0; i< arr.length; i++){
           const size = arr[i];
           if(!group[size]){
               group[size] = [];
           }
           group[size].push(i);
           if(group[size].length === size){
               ans.push([...group[size]]);
               group[size] = [];
           }

       }
    return ans;    
};