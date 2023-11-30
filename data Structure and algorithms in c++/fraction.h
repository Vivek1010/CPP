#include "bits/stdc++.h"
using namespace std;

class fraction
{
private:
    int denominator;
    int numirator;

public:
    fraction(int denominator, int numirator)
    {
        this->denominator = denominator;
        this->numirator = numirator;
    }
    void add(fraction const &f2)
    {
        //
        double lcm = numirator * f2.numirator;
        denominator = denominator * f2.numirator + f2.denominator * numirator;
        numirator = numirator * f2.numirator;
        simplify();
    }
    void printF()
    {
        cout << denominator << "/" << numirator << endl;
    }

    void simplify()
    {
        int gcd = __gcd(denominator, numirator);
        denominator = denominator / gcd;
        numirator = numirator / gcd;
    }
    fraction operator*(fraction const &f2)
    {
        fraction f3{this->denominator * f2.denominator, this->numirator * f2.numirator};
        f3.simplify();
        return f3;
    }
    bool operator==(fraction const &f2) const
    {
        return ((this->denominator == f2.denominator) && (this->numirator && f2.numirator));
    }

    fraction operator++()
    {
        this->denominator = this->denominator + numirator;
        simplify();
        return *this;
    }
};