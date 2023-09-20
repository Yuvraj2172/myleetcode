/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    if(s.length!== t.length)return false;
    const mp1 = [256];
    const mp2 = [256];
    for(let i =0; i<s.length; i++){
      if(mp1[s.charAt(i)]!== mp2[t.charAt(i)])return false;
      mp1[s.charAt(i)] = i+1;
      mp2[t.charAt(i)] = i+1;
    }
    return true;
};