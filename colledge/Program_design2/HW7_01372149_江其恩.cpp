#include <bits/stdc++.h>
using namespace std;
class Car {
    private:
        static int speed_limit;
    public:
        int speed;
        Car(int s) : speed(s) {}
        void checkSpeed() {
            if(speed > speed_limit) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
        void getLimit(int lt) {
            speed_limit = lt;
        }
};
int Car::speed_limit = 0; 
int main() {
    int speed_limit;
    cin >> speed_limit;
    int speed_car1, speed_car2;
    cin >> speed_car1 >> speed_car2;
    Car car1(speed_car1), car2(speed_car2);
    car1.getLimit(speed_limit);
    car1.checkSpeed();
    car2.checkSpeed();
    return 0;
}