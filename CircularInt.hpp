#define EXERCISE4_0_CIRCULARINT_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// static int count
class CircularInt{
    public:
        CircularInt(int min, int max);
        CircularInt(int min , int max , int current);
        CircularInt(const CircularInt &ci);
        
        // getter + setter
        int getCurrent() const;
        int getmin() const;
        int getmax() const;
        void setCurrent(int);
        
        //overloading operators 
        
        friend std::ostream& operator<<(std::ostream& os, CircularInt const &circ) ;
        
        CircularInt& operator++(int);
        CircularInt& operator++();
        
              // operator +
         friend CircularInt operator+(const CircularInt& arg1,const CircularInt& arg2);
        friend CircularInt operator+(const CircularInt& arg1,const int& int2);
        friend CircularInt operator+(const int& int1,const CircularInt& arg2);
        CircularInt& operator+();
        
             // operator -
        friend CircularInt operator-(const CircularInt &c1, const CircularInt &c2);
        friend CircularInt operator-(const CircularInt &c1, const int &int2);
        friend CircularInt operator-(const int &c1, const CircularInt &c2);
        friend CircularInt operator-(const CircularInt & c);
        
           // operator *
        friend CircularInt operator*(const CircularInt &c1, const CircularInt &c2);
        friend CircularInt operator*(const CircularInt &c1, const int &int2);
        friend CircularInt operator*(const int &c1, const CircularInt &c2);
        friend CircularInt operator*(const CircularInt & c);
        
       
        //operator +=
         CircularInt& operator+=(const int& rhs);
        CircularInt& operator+=(const CircularInt &i);
        
        //operator *=
        CircularInt& operator*=(const int& i);
        CircularInt& operator*=(const CircularInt &i);
        
        // operator /=
         CircularInt& operator/=(const int& int2);
        CircularInt& operator/=(const CircularInt other);
        
        // operator -=
        CircularInt& operator-=(const int& rhs);
        
        //operator /
        friend CircularInt operator/(const CircularInt &c1, const CircularInt &c2);
        friend CircularInt operator/(const CircularInt &c1, const int &int2);
        friend CircularInt operator/(const int &int1, const CircularInt &c2);
        
        // operator ==
           friend bool operator==(const CircularInt& arg1,const CircularInt& arg2);
        friend bool operator==(const int& arg1,const CircularInt& arg2);
        friend bool operator==(const CircularInt& arg1,const int& arg2);
        
        // operator !=
        friend bool operator!=(const CircularInt& arg1,const CircularInt& arg2);
        friend bool operator!=(const int& arg1,const CircularInt& arg2);
        friend bool operator!=(const CircularInt& arg1,const int& arg2);
        
        // operator <
        friend bool operator<(const CircularInt& arg1,const CircularInt& arg2);
        friend bool operator<(const int& arg1,const CircularInt& arg2);
        friend bool operator<(const CircularInt& arg1,const int& arg2);
        
        //operator >
        friend bool operator>(const CircularInt& arg1,const CircularInt& arg2);
        friend bool operator>(const int& arg1,const CircularInt& arg2);
        friend bool operator>(const CircularInt& arg1,const int& arg2);
        
         CircularInt  & operator= (const CircularInt & other);

    private:
        int min,max,current;
};