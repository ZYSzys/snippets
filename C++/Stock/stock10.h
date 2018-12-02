//
//  stock10.hpp
//  First
//
//  Created by 章贝贝 on 7/26/17.
//  Copyright © 2017 章贝贝. All rights reserved.
//

#ifndef stock10_h
#define stock10_h

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() {total_val = shares * share_val;}
public:
    Stock();
    Stock(const std::string &co, long n = 0, double pr = 0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show()const;
    const Stock & topval(const Stock &s)const;
};

/*
Stock::Stock()
{
    std::cout << "Default constructor called\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string &co, long n, double pr)
{
    std::cout << "Constructor using " << co << " called\n";
    company = co;
    if(n < 0)
    {
        std::cout << "Number of shares can't be negative; " << company << "shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

Stock::~Stock()
{
    std::cout << "Bye, " << company << "!\n";
}

void Stock::buy(long num, double price)
{
    if(num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. " << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if(num < 0)
    {
        cout << "Numbers of shares sold can't be negative. " << "Transaction is aborted.\n";
    }
    else if(num > shares)
    {
        cout << "You can't sell more than you have!"
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()const
{
    using std::cout;
    using std::ios_base;
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    cout << "Company: " << company << "  Shares: " << shares << "\n";
    cout << "  Share prices: $" << share_val;
    cout.precision(2);
    cout << " Total Worth: $" << total_val << '\n';
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock & Stock::topval(const Stock &s)const
{
    if(s.total_val > total_val)
    {
        return s;
    }
    else
    {
        return *this;
    }
}
*/

#endif /* stock10_hpp */
