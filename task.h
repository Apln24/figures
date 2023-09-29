#ifndef TASK_H_SENTRY
#define TASK_H_SENTRY
#include <vector>

enum
{
    MAX_FLOAT_RAND_NUM = 100,
    MAX_INT_RAND_NUM = 1600
};

enum figure_type
{
    ELLIPSE, CIRCLE, HELIX, FIG_AMOUNT
};

class Ellipse
{
protected:
    double r, r2;
public:
    Ellipse(double a, double b);
    virtual std::vector<double> GetPoint(double t) const;
    virtual std::vector<double> GetDerivative(double t, bool& res) const;
    virtual figure_type GetType() const {return ELLIPSE;};
    virtual std::vector<double> GetRadii() const;
};

class Circle : public Ellipse
{
public:
    Circle(double r) : Ellipse(r, r) {};
    figure_type GetType() const {return CIRCLE;};
};

class Helix : public Circle
{
    double h;
public:
    Helix(double r, double a_h) : Circle(r), h(a_h) {};
    std::vector<double> GetPoint(double t) const;
    std::vector<double> GetDerivative(double t, bool& res) const;
    figure_type GetType() const {return HELIX;};
};
#endif
