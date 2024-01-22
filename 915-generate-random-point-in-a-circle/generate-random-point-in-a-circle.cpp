class Solution {
public:
    double radius, x_center, y_center;
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    double random(){
        return (double)rand() / RAND_MAX;
    }
    vector<double> randPoint() {
        double angle = random() * 2 * M_PI;
        double constR = sqrt(random())*radius;
        return { x_center + constR*cos(angle), y_center + constR*sin(angle)};

    }
};

