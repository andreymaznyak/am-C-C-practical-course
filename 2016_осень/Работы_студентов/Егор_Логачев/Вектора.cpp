#include <iostream>
#include <cmath>
#include <stdexcept>
#define TEST(EXP) \
    std::cout << #EXP ": " << (EXP) << std::endl;
template< class T > 
class point3d
{
public:
 
    point3d(double _x, double _y, double _z);
    point3d(const point3d& rhs);
    
    point3d operator - (const point3d& rhs) const;
    
    friend std::ostream& operator << (std::ostream& os, const point3d& rhs);
    
protected:
    double x;
    double y;
    double z;
};
 
point3d::point3d(double _x, double _y, double _z)
    : x(_x), y(_y), z(_z) {}
    
point3d::point3d(const point3d& rhs)
    : x(rhs.x), y(rhs.y), z(rhs.z) {}
    
point3d point3d::operator - (const point3d& rhs) const
{
    return point3d(x - rhs.x, y - rhs.y, z - rhs.z);
}
 
std::ostream& operator << (std::ostream& os, const point3d& rhs)
{
    return (os << "(" << rhs.x << "; " << rhs.y << "; " << rhs.z << ")");
}
 
class vector: public point3d
{
public:
    vector(double _x, double _y, double _z);
    vector(double _x1, double _y1, double _z1,
            double _x2, double _y2, double _z2);
    vector(const vector& rhs);
    vector(const point3d& p1, const point3d& p2);
    
    vector operator + (const vector& v) const;
    vector& operator += (const vector& v);
    vector operator - () const;
    vector operator - (const vector& v) const;
    vector& operator -= (const vector& v);
    double operator * (const vector& v) const;
    double length() const;
	double operator ^ (const vector& v) const;
 
};
 
vector::vector(double _x, double _y, double _z)
    : point3d(_x, _y, _z) {}
    
vector::vector(double _x1, double _y1, double _z1,
        double _x2, double _y2, double _z2)
    : point3d(_x2 - _x1, _y2 - _y1, _z2 - _z1) {}
    
vector::vector(const vector& rhs)
    : point3d(rhs) {}
    
vector::vector(const point3d& p1, const point3d& p2)
    : point3d(p2 - p1) {}
 
vector vector::operator + (const vector& v) const
{
    return vector(x + v.x, y + v.y, z + v.z);
}
 
vector& vector::operator += (const vector& v)
{
    return (*this = *this + v);
}
 
vector vector::operator - () const
{
    return vector(-x, -y, -z);
}
 
vector vector::operator - (const vector& v) const
{
    return (*this + (-v));
}
 
vector& vector::operator -= (const vector& v)
{
    return (*this += (-v));
}
 
double vector::length() const
{
    return sqrt(x * x + y * y + z * z);
}
 
double vector::operator * (const vector& v) const
{
    return (x * v.x + y * v.y + z * v.z);
}
 
 double vector::operator ^ (const vector& v) const
{
    if((length() == 0) || (v.length() == 0))
        throw std::domain_error("NO");
        
    return (*this * v) / (length() * v. length());
}
 
int main()
{
    vector v1(45, -2, 2), v2(-86, 1, -2), v3(0, 0, 0);
    TEST(v1);
    TEST(v2);
    TEST(v3);
    TEST(v1.length());
    TEST(v2.length());
    TEST(v1 * v2);
    TEST(v1 + v3);
    TEST(v2 - v3);
    TEST(v1 ^ v2); 
    return 0;
}
