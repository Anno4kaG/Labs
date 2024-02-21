#include <iostream>
#include <cmath>
#include <iomanip>

class Array
{
public:

    typedef double
        value_type;
    typedef double*
        iterator;
    typedef const double*
        const_iterator;
    typedef double&
        reference;
    typedef const double&
        const_reference;
    typedef std::size_t
        size_type;

    reference operator[](size_type index);

    const_reference operator[](size_type index) const;


    Array(const size_type n);

    Array(const Array& a);

    Array(iterator f, iterator sec);

    ~Array()
    {
        delete[]p;
    }

    size_type capacity() const
    {
        return sizetdef;
    }

    Array& operator=(const Array&);

    iterator begin()
    {
        return p;
    }

    const_iterator begin() const
    {
        return p;
    }

    iterator end()
    {
        return p + cc;
    }

    const_iterator end() const
    {
        return p + cc;
    }

    size_type size() const
    {
        return cc;
    }

    void newsizefunc(size_type newsize);

    void swap(Array& other);

    void assign(const value_type& v);

    void push_back(const value_type& v);

    void push_backnew(const value_type& v);

    void push_backdef(const value_type& v);

    void pop_back()
    {
        p[cc - 1] = 0;
        cc--;
    }

    void clear()
    {
        cc = 0;
    }

    void display()
    {
        for (int i = 0; i < cc; i++)
        {
            std::cout.precision(3);
            std::cout << std::fixed << p[i] << " ";
        }

        std::cout << '\n';
    }

private:
    static const size_type min = 10;

    value_type* p;

    size_type cc;

    size_type sizetdef;

};

double findsum(const Array& a);

double findaverage(const Array& a);

void task(Array& a);

void Array::push_back(const value_type& v)
{
    if (cc == sizetdef)
        newsizefunc(sizetdef * 2);

    p[cc++] = v;
}

void taskdefnew(Array& a)
{
    float help = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 0)
        {
            help = a[i];
            break;
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        if ((int)a[i] % 2 == 0)
            (a.begin())[i] = (a.begin())[i] * help;
    }
}

void Array::push_backnew(const value_type& v)
{
    if (cc == sizetdef)
        newsizefunc(sizetdef * 2);

    p[cc++] = v;
}

void Array::push_backdef(const value_type& v)
{
    if (cc == sizetdef)
        newsizefunc(sizetdef * 2);

    p[cc++] = v;
}

void tasknewdef(Array& a)
{
    float help = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 0)
        {
            help = a[i];
            break;
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        if ((int)a[i] % 2 == 0)
            (a.begin())[i] = (a.begin())[i] * help;
    }
}



void Array::newsizefunc(size_type newsize)
{
    value_type* snew = new value_type[newsize];

    for (size_type i = 0; i < cc; ++i)
        snew[i] = p[i];

    delete[] p;

    p = snew;
    sizetdef = newsize;
}

void tasknew(Array& a)
{
    float help = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 0)
        {
            help = a[i];
            break;
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        if ((int)a[i] % 2 == 0)
            (a.begin())[i] = (a.begin())[i] * help;
    }
}

double& Array::operator[](size_type index)
{
    if (index < cc)
        return p[index];
}

const double& Array::operator[](size_type index) const
{
    if (index < cc)
        return p[index];
}

Array::Array(iterator f, iterator sec)
{
    if (f < sec)
    {
        sizetdef = (f - sec);

        p = new value_type[sizetdef];

        for (int i = 0; i < sizetdef; ++i)
            p[i] = *(f + i);

        cc = sizetdef;
    }
}

void taskdef(Array& a)
{
    float help = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 0)
        {
            help = a[i];
            break;
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        if ((int)a[i] % 2 == 0)
            (a.begin())[i] = (a.begin())[i] * help;
    }
}



Array::Array(const size_type n)
{
    sizetdef = n;

    p = new value_type[n];

    cc = 0;
}

int main()
{
    double el, sum = 0, aver = 0;

    int sizemain, helpc = 1;

    std::cin >> sizemain;

    Array arr(sizemain);

    for (int i = 0; i < sizemain; i++)
    {
        std::cin >> el;

        arr.push_back(el);
    }
    std::cout << arr.size() << '\n';
    arr.display();
    sum = findsum(arr);
    aver = findaverage(arr);
    arr.push_back(sum);
    arr.push_back(aver);
    arr.display();
    task(arr);
    arr.display();
    while (true)
    {
        std::cin >> helpc;

        if (helpc == 0)
            break;

        else
        {
            switch (helpc)
            {
            case 1:
                std::cin >> el;

                arr.push_back(el);
                std::cout << "+:" << arr.size() << '\n';
                arr.display();
                sum = findsum(arr);
                aver = findaverage(arr);

                arr.push_back(sum);
                arr.push_back(aver);

                arr.display();
                task(arr);

                arr.display();

                break;
            case 2:
                arr.pop_back();
                std::cout << "-:" << arr.size() << '\n';
                arr.display();
                sum = findsum(arr);
                aver = findaverage(arr);
                arr.push_back(sum);
                arr.push_back(aver);
                arr.display();
                task(arr);
                arr.display();
                break;
            }
        }
    }
    return 0;
}

double findsum(const Array& a)
{
    double sum = 0;

    for (int i = 0; i < a.size(); i++)
        sum += a[i];

    return sum;
}

double findaverage(const Array& a)
{
    double aver = findsum(a) / a.size();

    return aver;
}

void task(Array& a)
{
    float help = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 0)
        {
            help = a[i];
            break;
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        if ((int)a[i] % 2 == 0)
            (a.begin())[i] = (a.begin())[i] * help;
    }
}
