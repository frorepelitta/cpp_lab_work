#ifndef MONEY_H
#define MONEY_H

#include <iostream>


class Money {
public:
    Money();
    Money(unsigned int rubles);
    Money(unsigned int rubles, short int kopeks);

    unsigned int GetRubles() const;
    short int GetKopeks() const;

    void SetRubles(unsigned int rubles);
    void SetKopeks(short int kopeks);

    Money add(short int kopeks);
    Money create();

    Money& operator++();
    Money operator++(int);

    Money& operator--();
    Money operator--(int);

    explicit operator unsigned int() const;
    operator double() const;

    Money operator+(int) const;
    Money operator-(int) const;
    
private:
    unsigned int rubles_ = 0; 
    short int kopeks_ = 0;

};

std::ostream&  operator<< (std::ostream& os, const Money& money);


#endif