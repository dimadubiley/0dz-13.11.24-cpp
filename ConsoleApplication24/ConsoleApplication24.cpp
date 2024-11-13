#include<iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()
    {
        cout << "Construct\n";
        x = y = 0;
    }
    Point(int x1, int y1)
    {
        cout << "Construct by 2 param\n";
        x = x1;
        y = y1;
    }
    void Init()
    {
        x = rand() % 10;
        y = rand() % 10;
    }
    void Init(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    void Output()
    {
        cout << "X: " << x << "\tY: " << y << endl;
    }

    Point operator+(const Point& b)
    {
        return Point(x + b.x, y + b.y);
    }
    Point operator+(int a)
    {
        return Point(x + a, y + a);
    }
    Point& operator+=(int a)
    {
        x += a;
        y += a;
        return *this;
    }
    Point& operator+=(const Point& b)
    {
        x += b.x;
        y += b.y;
        return *this;
    }
    Point operator-(int a)
    {
        return Point(x - a, y - a);
    }
    Point operator*(int a)
    {
        return Point(x * a, y * a);
    }
    Point operator/(int a)
    {
        if (a == 0)
        {
            cout << "Division = 0\n";
            return *this;
        }
        return Point(x / a, y / a);
    }
    Point& operator++()
    {
        x += 10;
        y += 10;
        return *this;
    }
    Point operator++(int)
    {
        Point temp = *this;
        x += 10;
        y += 10;
        return temp;
    }
    Point& operator--()
    {
        x -= 10;
        y -= 10;
        return *this;
    }
    Point operator--(int)
    {
        Point temp = *this;
        x -= 10;
        y -= 10;
        return temp;
    }

    int GetX() {return x;}
    int GetY() {return y;}
    void SetX(int a) {x = a;}
    void SetY(int a) {y = a;}
};

Point operator+(int a, Point b) { return Point(b.GetX() + a, b.GetY() + a); }
Point operator-(int a, Point b) { return Point(a - b.GetX(), a - b.GetY()); }
Point operator/(int a, Point b)
{
    if (b.GetX() == 0 || b.GetY() == 0)
    {
        cout << "Division = 0\n";
        return b;
    }
    return Point(a / b.GetX(), a / b.GetY());
}

int main()
{
    srand(unsigned(time(0)));

    Point a(1, 2);
    Point b(3, 4);

    Point c = ++a;
    c.Output();
    a.Output();

    Point d = a++;
    d.Output();
    a.Output();

    Point e = a + b;
    e.Output();

    Point f = a + 10;
    f.Output();

    Point g = 10 + a;
    g.Output();

    Point h = 100 - a;
    h.Output();

    Point i = a * 10;
    i.Output();

    Point j = 100 / a;
    j.Output();

    Point k = --a;
    k.Output();

    Point l = a--;
    l.Output();

    a += 10;
    a.Output();

    a += b;
    a.Output();
}
