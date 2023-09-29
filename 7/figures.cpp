#include <cmath>
#include "figures.h"

Ellipse::Ellipse(double a, double b)
{
    r = a;
    r2 = b;
}

std::vector<double> Ellipse::GetPoint(double t) const
{
    std::vector<double> point;
    double x, y;
    const double z = 0;
    x = r * cos(t);
    y = r2 * sin(t);
    point.push_back(x);
    point.push_back(y);
    point.push_back(z);
    return point;
}

std::vector<double> Ellipse::GetDerivative(double t,
                                            bool& res) const
{
    res = true;
    std::vector<double> derivative;
    double x, y, tmp;
    const double z = 0;
    x = r * -1 * sin(t);
    tmp = r2 * cos(t);
    if (x == 0) {
        res = false;
        return derivative;
    }
    y = tmp / x;
    derivative.push_back(x);
    derivative.push_back(y);
    derivative.push_back(z);
    return derivative;
}

std::vector<double> Ellipse::GetRadii() const
{
    std::vector<double> res;
    res.push_back(r);
    res.push_back(r2);
    return res;
}

std::vector<double> Helix::GetPoint(double t) const
{
    std::vector<double> point;
    double x, y, z;
    x = r * cos(t);
    y = r2 * sin(t);
    z = h * t;
    point.push_back(x);
    point.push_back(y);
    point.push_back(z);
    return point;
}

std::vector<double> Helix::GetDerivative(double t, bool& res) const
{
    res = true;
    std::vector<double> derivative;
    double x, y, z, tmp;
    x = r * -1 * sin(t);
    tmp = r2 * cos(t);
    if (x == 0) {
        res = false;
        return derivative;
    }
    y = tmp / x;
    z = 1;
    derivative.push_back(x);
    derivative.push_back(y);
    derivative.push_back(z);
    return derivative;
}

