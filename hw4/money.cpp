#include "money.h"

Money::Money() {}
Money::Money(unsigned int rubles): rubles_(rubles) {}
Money::Money(unsigned int rubles, short int kopeks): rubles_(rubles), kopeks_(kopeks){}



unsigned int Money::GetRubles() const{
    return this->rubles_;
}


short int Money::GetKopeks() const{
    return this->kopeks_;
}


void Money::SetRubles(unsigned int rubles) {
    this->rubles_ = rubles;
}


void Money::SetKopeks(short int kopeks) {
    this->kopeks_ = kopeks;
}


Money Money::add(short int kopeks) {
    Money dengi = *this;
    int total_money = dengi.kopeks_ + kopeks;
    dengi.rubles_ += total_money / 100;
    dengi.kopeks_ = total_money % 100;
    return dengi;
}


Money Money::create() {
    int rubles;
    short int kopeks;
    std::cout << "Введите количество рублей - " << std::endl;
    std::cin >> rubles;
    if (std::cin.fail() || rubles < 0) {
        std::cout << "Ошибка ввода " << std::endl;
        return Money();
    }


    std::cout << "Введите количество копеек - " << std::endl;
    std::cin >> kopeks;
    if (std::cin.fail() || kopeks < 0) {
        std::cout << "Ошибка ввода " << std::endl;
        return Money();
    }

    Money new_money(rubles);
    new_money = new_money.add(kopeks);
    std::cout << "Созданный экзепляр класса Деньги - " << new_money << std::endl;
    return new_money;
}


Money& Money::operator++() {
    if(this->kopeks_ < 99) {
        this->kopeks_ += 1;
    }else {
        this->rubles_ += 1;
        this->kopeks_ = 0;
    }
    return *this;
}


Money Money::operator++(int) {
    Money temp = *this;
    ++(*this);
    return temp;


}


Money& Money::operator--() {
    if(this->kopeks_ > 0) {
        this->kopeks_ -= 1;
    }else if(this->rubles_ > 0) {
        this->rubles_ -= 1;
        this->kopeks_ = 99;
    }

    return *this;
}


Money Money::operator--(int) {
    Money temp = *this;
    --(*this);
    return temp;
}


Money::operator unsigned int() const {
    return this->rubles_;
}


Money::operator double() const {
    return this->kopeks_ / 100.0;
}


Money Money::operator+(int kopeks) const {
    if(kopeks < 0) {
        return *this;
    }
    Money temp = *this;
    temp = temp.add(kopeks);

    return temp;
}


Money Money::operator-(int kopeks) const {
    if (kopeks<0) {
        return *this;
    }
    Money temp = *this;

    unsigned int total_temp = temp.rubles_  * 100 + temp.kopeks_;

    if(kopeks > total_temp) {
        std::cout << "Ошибка вычитания" << std::endl;
        return temp;
    }
    total_temp -= kopeks;

    temp.rubles_ = total_temp / 100;
    temp.kopeks_ = total_temp % 100;

    return temp;
}


std::ostream&  operator<< (std::ostream& os, const Money& money) {
    return os << money.GetRubles() << " " << money.GetKopeks();
}