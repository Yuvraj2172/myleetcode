/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let i = n;
    return function() {
        let t = i;
        i++;
        return t;    
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */