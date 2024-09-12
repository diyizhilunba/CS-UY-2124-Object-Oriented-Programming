/*
  rec07.cpp
  CS2124
  Implement the class Rational, so that the following program works.
 */

#include <iostream>
using namespace std;

int greatestCommonDivisor(int x, int y);

// Put your Rational class here.
class Rational {
    friend ostream& operator<<(ostream& os, const Rational& rat) {
        if(rat.denominator != 1) {
            os << rat.numerator << "/" << rat.denominator;
        }
        else {
            os << rat.numerator;
        }
        return os;
    }
    friend istream& operator>>(istream& is, Rational& rat) {
        string input;
        is >> input;

        string num_string,den_string;
        int split = input.find("/");
        if(split != -1){
        num_string = input.substr(0,split);
        den_string = input.substr(split+1,input.length());

        rat.numerator = stoi(num_string);
        rat.denominator = stoi(den_string);
        int com_div = greatestCommonDivisor(rat.numerator,rat.denominator);
        rat.numerator /= com_div;
        rat.denominator /= com_div;
            if(rat.denominator < 0) {
                rat.numerator *= -1;
                rat.denominator *= -1;
            }
        }
        else {
            rat.numerator = stoi(input);
            rat.denominator = 1;
        }
        return is;
    }
    friend  bool operator==(const Rational& lhs, const Rational& rhs);
    friend  bool operator<(const Rational& lhs, const Rational& rhs);
public:
    //Constructors:
    Rational(const string& str) {
        string num_string,den_string;
        int split = str.find("/");
        if(split != -1) {
            num_string = str.substr(0,split);
            den_string = str.substr(split+1,str.length());

            numerator = stoi(num_string);
            denominator = stoi(den_string);
            int com_div = greatestCommonDivisor(numerator,denominator);
            numerator /= com_div;
            denominator /= com_div;
            if(denominator < 0) {
                numerator *= -1;
                denominator *= -1;
            }
        }
        else {
            numerator = stoi(str);
            denominator = 1;
        }
    }
    Rational(){}
    //Copy Constructor: remind const
    Rational(const Rational& rhs) {
        denominator = rhs.denominator;
        numerator = rhs.numerator;
    }
    Rational(int num,int den = 1):numerator(num),denominator(den) {

    }

    //Operators:
    Rational& operator +=(const Rational& rhs);
    Rational& operator++();
    Rational operator ++(int dummy);
    Rational& operator =(const Rational& rhs);
    explicit operator bool() const;

private:
    int numerator;
    int denominator;
};

// Any functions that are not members and not friends should have
// prototypes here and their definitions after main.

Rational& operator+(const Rational& lhs, const Rational& rhs);

Rational& operator--(Rational& lhs);
Rational operator--(Rational &lhs,int dummy);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);






int main()
{
    Rational a, b;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;
    cout << a << "\n";
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "b: ";
    cin >> b;
    cout << b << "\n";
    const Rational one = 1;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;	// Implement as member
    cout << "a = " << a << endl;
    
    // Implement + as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;
    
    // How does this manage to work?
    // It does NOT require writing another == operator. 
    cout << "1 == one: " << boolalpha << (1 == one) << endl;

    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;

    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;

    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;

    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // But some compiler vendors might let it...  Is your compiler
    // doing the right thing? Why shouldn't it compile?
    //cout << "a-- -- = " << (a-- --) << endl;
    cout << "a = " << a << endl;


    // Should report that 1 is true
    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    } 

    // Should report that 0 is false
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    } 

    cout << "Comparisons\n";
    Rational twoFifths(2, 5);
    Rational threeHalves(3, 2);
    Rational minusFive(-5);
    cout << twoFifths << " < " << threeHalves << " : " 
         << (twoFifths < threeHalves) << endl;
    cout << twoFifths << " <= " << 1 << " : " << (twoFifths <= 1) << endl;
    cout << threeHalves << " < " << twoFifths << " : "
         << (threeHalves < twoFifths) << endl;
    cout << threeHalves << " > " << threeHalves << " : "
         << (threeHalves > threeHalves) << endl;
    cout << threeHalves << " >= " << threeHalves << " : "
         << (threeHalves >= threeHalves) << endl;
    cout << minusFive << " >= " << threeHalves << " : "
         << (minusFive >= threeHalves) << endl;

}

int greatestCommonDivisor(int x, int y)
{
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    if(lhs.denominator == rhs.denominator && lhs.numerator == rhs.numerator) {
        return true;
    }

        return false;

}
bool operator<(const Rational& lhs, const Rational& rhs) {
    bool positive;
    if(lhs.numerator * rhs.denominator < lhs.denominator * rhs.numerator) {
        positive = true;
    }
    else
        positive = false;
    if(lhs.numerator > 0 && rhs.numerator > 0)
        return positive;
    if(lhs.numerator > 0 && rhs.numerator < 0)
        return false;
    if(lhs.numerator < 0 && rhs.numerator > 0)
        return true;
    if(lhs.numerator < 0 && rhs.numerator < 0)
        return !positive;
}
Rational &Rational::operator+=(const Rational &rhs) {
    denominator *= rhs.denominator;
    numerator = numerator * rhs.denominator + denominator * rhs.numerator;
    int gcd = greatestCommonDivisor(denominator,numerator);
    denominator /= gcd;
    numerator /= gcd;
    if(denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    return *this;
}
Rational &Rational::operator=(const Rational &rhs) {
    if(denominator != rhs.denominator || numerator != rhs.numerator) {
        denominator = rhs.denominator;
        numerator = rhs.numerator;
    }
}

Rational &Rational::operator++() {
    numerator += denominator;
    return *this;
}
Rational Rational::operator++(int dummy) {
    Rational temp = *this;
    ++*this;
    return temp;
}


// Any functions that are not members and not friends should have
// their definitions here...
Rational& operator+(const Rational& lhs, const Rational& rhs) {//Why we cannot just use Rational lhs and modify the copy?
    Rational temp = lhs;
    return temp += rhs;
}

Rational& operator--(Rational& lhs) {
    lhs += -1;
    return lhs;
}
Rational operator--(Rational &lhs,int dummy) {
    Rational temp = lhs;
    lhs += -1;
    return temp;
}
bool operator!=(const Rational& lhs, const Rational& rhs) {
    if(lhs == rhs)
        return false;
    else {
        return true;
    }
}
bool operator<=(const Rational& lhs, const Rational& rhs)
{
    if(lhs == rhs || lhs < rhs) {
        return true;
    }

    return false;

}
bool operator>(const Rational& lhs, const Rational& rhs) {
    if(lhs <= rhs) {
        return false;
    }

    return true;

}
bool operator>=(const Rational& lhs, const Rational& rhs) {
    if(lhs < rhs) {
        return false;
    }
    return true;
}

Rational::operator bool() const {
        return (*this != Rational(0));

}


