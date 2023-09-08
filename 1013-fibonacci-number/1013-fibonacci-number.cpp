class Solution {
public:
    int fib(int N) {
       return round(pow((1 + sqrt(5)) / 2, N) / sqrt(5)); 
    }
};