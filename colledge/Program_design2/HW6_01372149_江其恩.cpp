#include <bits/stdc++.h>
using namespace std;
class shape {
    private:
        double width, height;
    public:
        virtual double area() = 0;
        shape(double w, double h) : width(w), height(h) {}
        ~shape() {}
    protected:
        double getWidth() {
            return width;
        }
        double getHeight() {
            return height;
        }
};
class rectangle : public shape {
    public:
        rectangle(double w, double h) : shape(w, h) {}
        double area() {
            return getWidth() * getHeight();
        }
};
class triangle : public shape {
    public:
        triangle(double b, double h) : shape(b, h) {}
        double area() {
            return 0.5 * getWidth() * getHeight();
        }
};

int main (){
    rectangle rect(10.5, 2);
    triangle tri(6.4, 8.6);
    cout << rect.area() << endl;
    cout << tri.area() << endl;
    return 0;
}