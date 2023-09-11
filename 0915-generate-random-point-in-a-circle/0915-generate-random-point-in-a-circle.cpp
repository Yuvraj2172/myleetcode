class Solution {
    double r, xc, yc;

public:
    Solution(double r, double xc, double yc) {
        this->r = r; this->xc = xc; this->yc = yc;
    }
    double random(){
        return (double) rand() / RAND_MAX;
    }
    vector<double> randPoint() {
        double angle = random()*2*M_PI;
        double constR = sqrt(random()) * r;
        return {xc + constR*cos(angle), yc + constR*sin(angle)};


    }
};
