#include <algorithm>
#include <cmath>
#include <cassert>
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <memory>
#include "figures.h"

double get_random(int max = MAX_FLOAT_RAND_NUM)
{
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(0, max);
    return dis(e);
}

int get_random_num(int max = MAX_INT_RAND_NUM)
{
    return rand() % max;
}

void init(std::vector<std::shared_ptr<Ellipse>>& f)
{
    std::cout << "INIT" << std::endl;
    int fig_amount = get_random_num();
    std::cout << "Amount of figures: " << fig_amount << std::endl;
    for(int i = 0; i < fig_amount; i++) {
        int current_figure = get_random_num(FIG_AMOUNT);
        int n, n2;
        switch (current_figure) {
        case ELLIPSE:
            n = get_random_num();
            n2 = get_random_num();
            if (n == n2)
                continue;
            f.push_back(std::make_shared<Ellipse>(n, n2));
            break;
        case CIRCLE:
            f.push_back(std::make_shared<Circle>(get_random_num()));
            break;
        case HELIX:
            f.push_back(std::make_shared<Helix>(get_random_num(), 
                        get_random_num()));
            break;
        }
    }
}

void print_vector(const std::vector<double> v)
{
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

void print_figure(const std::shared_ptr<Ellipse>& figure)
{
    figure_type type = figure->GetType();
    switch (type) {
    case ELLIPSE:
        std::cout << "Ellipse:" << std::endl;
        break;
    case CIRCLE:
        std::cout << "Circle:" << std::endl;
        break;
    case HELIX:
        std::cout << "Helix:" << std::endl;
        break;
    case FIG_AMOUNT:
        std::cout << "Something wrong...." << std::endl;
    }
}

bool sort_by_radii(const std::shared_ptr<Circle>& a,
                    const std::shared_ptr<Circle>& b)
{
    return (a->GetRadii()[0] < b->GetRadii()[0]);
}

int main() {
    std::vector<std::shared_ptr<Ellipse>> figures;
    srand(time(nullptr));
    init(figures);
    for(int i = 0; i < figures.size(); i++) {
        bool res;
        print_figure(figures[i]);
        std::cout << "Coordinates: ";
        print_vector(figures[i]->GetPoint(M_PI / 4));
        std::cout << "Derivative: ";
        std::vector<double> tmp = figures[i]->GetDerivative(M_PI / 4,
                                                            res);
        if (res)
            print_vector(tmp);
        else
            std::cerr << "Division by zero is detected" << std::endl;
    }
    std::vector<std::shared_ptr<Circle>> circles;
    for(int i = 0; i < figures.size(); i++) {
        if (figures[i]->GetType() == CIRCLE)
            circles.push_back(
                    std::dynamic_pointer_cast<Circle>(figures[i])
                            );
    }
    std::sort(circles.begin(), circles.end(), sort_by_radii);
    int radii_sum;
    for(int i = 0; i < circles.size(); i++) {
        int tmp = circles[i]->GetRadii()[0];
        radii_sum += tmp;
    }
    std::cout << std::endl << "Radii sum: " << radii_sum << std::endl;
    return 0;
}
