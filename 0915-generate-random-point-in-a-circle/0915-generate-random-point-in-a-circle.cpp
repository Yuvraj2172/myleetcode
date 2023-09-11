class Solution {
    double R,X,Y;
public:
    Solution(double radius, double x_center, double y_center) : R(radius), X(x_center), Y(y_center) {
        srand(time(0));
    }
    double random(){
        return (double)rand() / RAND_MAX;
    }
    vector<double> randPoint() {
        vector<double> ans(2);
        double r = sqrt(random()) * R , pi = 2*M_PI * random();
        ans[0] = X + r*cos(pi);
        ans[1] = Y + r*sin(pi);
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */