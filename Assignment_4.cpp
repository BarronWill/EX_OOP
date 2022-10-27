#include <iostream>
#include <fstream>
#include <algorithm>
// __gdc(x,y)
using namespace std;

class Fraction
{
	private:
		int numerator;
        int denominator;
	public:
        Fraction();												    // Constructor with no argument
        Fraction(int numerator, int denominator);				    // Constrcutor with argument
        double operator ++ ();                                      // obj++
        Fraction operator * (Fraction& x);                          // obj1 * obj2
        friend istream& operator >> (istream &, Fraction& );   	    // Operator >> to extract data from file to var    
        friend ostream& operator << (ostream &, const Fraction& );  // Operator << to put program's data into the file
};

Fraction::Fraction()
{
	numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int nm, int dn)
{
	numerator = nm, denominator = dn;
}

Fraction Fraction::operator * (Fraction& x)
{
	Fraction frc;
	int num = numerator * x.numerator;
    int denm = denominator * x.denominator;
	int gcd = __gcd(num,denm);                  // __gdc(x,y): a template used to find 
                                                // the greates common division                          
	frc.numerator = num/gcd, frc.denominator = denm/gcd;
	return frc;
}

double Fraction::operator ++ ()
{
	return (double)numerator/denominator;
}

istream& operator >> (istream &in, Fraction& fr)
{
	cout << "\nNumerator: ";
	in >> fr.numerator;
	cout << "Denominator: ";
	in >> fr.denominator;
	return in; 
}

ostream& operator << (ostream &out, const Fraction& fr)
{
	out << fr.numerator << "/" << fr.denominator << endl;
	return out;
}

main()
{
	ofstream file ("Fraction.txt", ios::out);
	Fraction f1,f2;
	cout << "Fraction 1: ";  cin >> f1;
    cout << "Fraction 2: ";  cin >> f2;
    //file << f1 <<endl;
    //file << f2 <<endl;
	file << "Result: ";
	cout << f1 * f2;
	file.close();
}

// Bonus
 
/*  template <typename Number>
    Number GCD(Number u, Number v) {
        while (v != 0) {
            Number r = u % v;
            u = v;
            v = r;
        }
        return u;
    }*/