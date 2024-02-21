#include <iostream>
#include <cmath>
#include <algorithm>

class Array
{
public:
    int sizearrdef, num;

    int* arrdef = new int[100];

    Array(int f, int s)
    {
        sizearrdef = abs(f) + abs(s) + 1;

        for (int i = 0; i < sizearrdef; i++)
            std::cin >> arrdef[i];
    }

    void summary(int helpc);

    void divide(int helpc);

    void multi(int helpc);

    void tosort();

    void show()
    {
        for (int i = sizearrdef - 1; i > 0; i--)
            std::cout << arrdef[i] << " ";

        std::cout << std::endl;
    }

    void tooshow()
    {
        for (int i = 0; i < sizearrdef; i++)
            std::cout << arrdef[i] << " ";

        std::cout << std::endl;
    }

    void helper(int helpc)
    {
        for (int i = 0; i < sizearrdef; i++)
            std::cout << arrdef[i] - helpc << " ";
        for (int i = 0; i < sizearrdef; i++)
            std::cout << arrdef[i] + helpc << " ";
        for (int i = 0; i < sizearrdef; i++)
            std::cout << arrdef[i] * helpc << " ";
        for (int i = 0; i < sizearrdef; i++)
            std::cout << arrdef[i] / helpc << " ";
    }

    friend void operator*(Array f, Array s)
    {
        std::cout << "proizv = ";

        for (int i = 0; i < f.sizearrdef; i++)
            std::cout << f.arrdef[i] * s.arrdef[i] << " ";

        std::cout << std::endl;
    }

    void toohelper(int helpc)
    {
        for (int i = 0; i < sizearrdef; i++)
            std::cout << arrdef[i] - helpc * 2 << " ";
        for (int i = 0; i < sizearrdef; i++)
            std::cout << arrdef[i] + helpc * 3 << " ";
        for (int i = 0; i < sizearrdef; i++)
            std::cout << arrdef[i] * helpc * 4 << " ";
        for (int i = 0; i < sizearrdef; i++)
            std::cout << arrdef[i] / helpc * 5 << " ";
    }

    friend void operator/(Array Arr1, Array Arr2)
    {
        for (int i = 0; i < Arr1.sizearrdef; i++)
            if (Arr2.arrdef[i] == 0)
            {
                std::cout << "delenie na 0" << std::endl;

                return;
            }

        std::cout << "delenie= ";

        for (int i = 0; i < Arr1.sizearrdef; i++)
            std::cout << int(Arr1.arrdef[i] / Arr2.arrdef[i]) << " ";

        std::cout << std::endl;
    }

    friend void operator-(Array f, Array sec)
    {
        std::cout << "raznost= ";

        for (int i = 0; i < f.sizearrdef; i++)
            std::cout << f.arrdef[i] - sec.arrdef[i] << " ";

        std::cout << std::endl;
    }

    friend void operator+(Array f, Array s)
    {
        std::cout << "summa= ";

        for (int i = 0; i < f.sizearrdef; i++)
            std::cout << f.arrdef[i] + s.arrdef[i] << " ";

        std::cout << std::endl;
    }

};

int main()
{
    int first, second, help, c = -1, ind;

    std::cin >> second >> first;

    Array f(second, first);

    Array s(second, first);

    std::cin >> help;

    std::cout << "Array1= ";

    f.num = 1;

    f.tooshow();

    f.summary(help);
    f.divide(help);
    f.multi(help);
    f.tosort();

    std::cout << "Array2= ";

    s.num = 2;

    s.tooshow();

    s.summary(help);
    s.divide(help);
    s.multi(help);
    s.tosort();

    f + s;
    f - s;
    f* s;
    f / s;

    while (true)
    {
        std::cin >> c >> ind;

        if (c == 0)
            break;

        if (ind > first || ind < second)
        {
            std::cout << "Array" << c << " wrong index " << ind << std::endl;

            continue;
        }
        else
        {
            if (c == 1)
            {
                std::cout << "Array1[" << ind << "]= ";
                std::cout << f.arrdef[f.sizearrdef - first + ind - 1] << std::endl;
            }
            else
            {
                std::cout << "Array2[" << ind << "]= ";
                std::cout << s.arrdef[s.sizearrdef - first + ind - 1] << std::endl;
            }
        }
    }

    return 0;
}

void Array::summary(int helpc)
{
    std::cout << "Array" << num << "+const= ";

    for (int i = 0; i < sizearrdef; i++)
        std::cout << arrdef[i] + helpc << " ";

    std::cout << std::endl;
}

void Array::divide(int helpc)
{
    std::cout << "Array" << num << "-const= ";

    for (int i = 0; i < sizearrdef; i++)
        std::cout << arrdef[i] - helpc << " ";

    std::cout << std::endl;
}

void Array::multi(int helpc)
{
    std::cout << "Array" << num << "*const= ";

    for (int i = 0; i < sizearrdef; i++)
        std::cout << arrdef[i] * helpc << " ";

    std::cout << std::endl;
}

void Array::tosort()
{
    int* help = new int[sizearrdef];

    for (int i = 0; i < sizearrdef; i++)
        help[i] = arrdef[i];

    std::sort(help, help + sizearrdef);

    std::cout << "sort up Array" << num << "= ";

    for (int i = 0; i < sizearrdef; i++)
        std::cout << help[i] << " ";

    std::cout << std::endl << "sort down Array" << num << "= ";

    for (int i = sizearrdef - 1; i >= 0; i--)
        std::cout << help[i] << " ";

    std::cout << std::endl;

}
