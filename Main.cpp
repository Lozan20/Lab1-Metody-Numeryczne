#include <iostream>

double potega(double podstawa, double wykladnik)
{
    if ((wykladnik == 0) || (podstawa == 1)) return 1;
    if (podstawa == 0) return 0;

    double temp = podstawa;

    for (int i = 0; i < wykladnik - 1; i++)
    {
        podstawa = podstawa * temp;
    }
    return podstawa;
}

double metoda_newtona(double stopien, double wartosc, double a)
{
    return (((stopien - 1.0) * wartosc + a / (potega(wartosc, stopien - 1.0))) / stopien);
}

double pierwiastek(int stopien, double wartosc)
{
    double a = wartosc;
    double temp = metoda_newtona(stopien, wartosc, a);

    while (abs(wartosc - temp) > 0.0001)
    {
        temp = wartosc;
        wartosc = metoda_newtona(stopien, wartosc, a);
        std::cout << wartosc << std::endl;
    }

    return wartosc;
}

int main()
{
    std::cout << pierwiastek(4, 36);
}
