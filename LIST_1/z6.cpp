#include <iostream>
#include <cmath>

double miejsce_zerowe(double (*f)(double), double a, double b) {
    int kroki = 0;
    double c;
    while (b - a > 1e-10) {
        c = (a + b) / 2.0;
        double fc = f(c);
        if (fc == 0.0) break;
        else if (f(a) * fc < 0) b = c; //metoda bisekcji, sprawdzam w której części przedziału jest miejsce zerowe, jeśli a i c mają różne znaki to znaczy że jest w przedziale a,c
        else a = c; //a jest na minusie więc biorąc pod uwagę że c < b to naturalnie podmianka
        kroki++;
    }
    std::cout << "Kroki: " << kroki << std::endl;
    return (a + b) / 2.0;
}

double f(double x) {
    return sin(x) - 0.5;
}
double g(double x) {
    return sin(x);
}
double h(double x) {
    return x * x - 2;
}

int main() {
    std::cout << "f(x) w (0, 2): " << miejsce_zerowe(f, 0, 2) << std::endl;
    std::cout << "g(x) w (-4, -1): " << miejsce_zerowe(g, -4, -1) << std::endl;
    std::cout << "g(x) w (4, 8): " << miejsce_zerowe(g, 4, 8) << std::endl;
    std::cout << "h(x) w (0, 15): " << miejsce_zerowe(h, 0, 15) << std::endl;
    std::cout << "h(x) w (-15, 0): " << miejsce_zerowe(h, -15, 0) << std::endl;
    return 0;
}