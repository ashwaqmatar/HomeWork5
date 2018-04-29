
#include <iostream>

#include "CircularInt.hpp"

int moduloC(int min ,int max ,int val){
    int result = val%(max - min + 1) + (min - 1);
    if(result < 0){
        result += max;
    }
    return result;
}


//***constructors***
CircularInt::CircularInt(int b , int e){
    min = b;
    max = e;
    
    current = b;
}

CircularInt::CircularInt(int b , int e ,int c){
    min = b;
    max = e;
    
    current = c;
}


CircularInt::CircularInt(const CircularInt &ci){
    min = ci.min;
    max = ci.min;
    
    current = ci.current;
}

std::ostream& operator<<(std::ostream& os, CircularInt const &circ)  
{  
    os << circ.getCurrent();  
    return os;  
} 

CircularInt& CircularInt::operator++(){
    setCurrent((this->getCurrent() + 1)%max);
    return *this;
}
CircularInt& CircularInt::operator++(int i){
    CircularInt result(*this);
     ++(*this);           
    return result;  
}




/*** ADDITION FUNCS***********************************************
 * CLASS + CLASS
 * CLASS + INT
 * INT + CLASS
 * +CLASS
 * 
 */

CircularInt operator+(const CircularInt& arg1,const CircularInt& arg2){
    CircularInt c = CircularInt(arg1.min , arg1.max , moduloC(arg1.min,arg1.max,arg1.current + arg2.current));
    return c;
}

CircularInt operator+(const CircularInt& arg1,const int& int2){
    CircularInt c = CircularInt(arg1.min , arg1.max , moduloC(arg1.min,arg1.max,arg1.current + int2));
    return c;
}

CircularInt operator+(const int& int1,const CircularInt& arg2){
    CircularInt c = CircularInt(arg2.min , arg2.max , moduloC(arg2.min,arg2.max,arg2.current + int1));
    return c;
}

/*** SUBTRACTION FUNCS***********************************************
 * 
 * CLASS - CLASS
 * CLASS - INT
 * INT -CLASS
 * -CLASS
 * 
 */
CircularInt operator-(const CircularInt &c1, const CircularInt &c2){
	CircularInt tmp = CircularInt(c1.getmin() , c1.getmax() , moduloC(c1.getmin(),c1.getmax(),(c1.getCurrent()- c2.current)));
    CircularInt &c =  tmp;
	return tmp;
}


CircularInt operator-(const CircularInt &c1, const int &int2){
	CircularInt tmp = CircularInt(c1.getmin() , c1.getmax() , moduloC(c1.getmin(),c1.getmax(),(c1.getCurrent()- int2)));
    CircularInt &c =  tmp;
	return tmp;
}

CircularInt operator-(const int &arg1, const CircularInt &arg2)
{
	CircularInt tmp = CircularInt(arg2.getmin() , arg2.getmax() , moduloC(arg2.getmin(),arg2.getmax(),(arg1 - arg2.getCurrent())));
    CircularInt &c =  tmp;
	return tmp;
}


CircularInt operator-(const CircularInt & c)
{
	//TOMER: ASK
	CircularInt tmp = CircularInt(c.getmin() , c.getmax() , moduloC(c.min,c.max,( c.getmax() - c.getCurrent())));
    CircularInt &ci =  tmp;
	return tmp;
}






/*** SUBTRACTION FUNCS***********************************************
 * 
 * CLASS * CLASS
 * CLASS * INT
 * INT * CLASS
 * *CLASS
 * 
 */
CircularInt operator*(const CircularInt &c1, const CircularInt &c2){
	CircularInt tmp = CircularInt(c1.getmin() , c1.getmax() , moduloC(c1.getmin(),c1.getmax(),(c1.getCurrent() * c2.current)));
    CircularInt &c =  tmp;
	return tmp;
}


CircularInt operator*(const CircularInt &c1, const int &int2){
	CircularInt tmp = CircularInt(c1.getmin() , c1.getmax() , moduloC(c1.getmin(),c1.getmax(),(c1.getCurrent() * int2)));
    CircularInt &c =  tmp;
	return tmp;
}

CircularInt operator*(const int &arg1, const CircularInt &arg2)
{
	CircularInt tmp = CircularInt(arg2.getmin() , arg2.getmax() , moduloC(arg2.getmin(),arg2.getmax(),(arg1 * arg2.getCurrent())));
    CircularInt &c =  tmp;
	return tmp;
}


CircularInt operator*(const CircularInt & c)
{
	//TOMER: ASK
	CircularInt tmp = CircularInt(c.getmin() , c.getmax() , moduloC(c.min,c.max,( c.getCurrent() * c.getCurrent())));
    CircularInt &ci =  tmp;
	return tmp;
}

/*** DIVISION FUNCS***********************************************
 * CLASS / CLASS
 * CLASS / INT
 * INT / CLASS
 * 
 */
CircularInt operator/(const CircularInt &c1, const CircularInt &c2){
    // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).
    bool flag = true;
    int i = c1.min;
    for( ; i <= c1.max && flag ;i++ ){
        if(moduloC(c1.min,c1.max,i * c2.current)== c1.current)
            flag = false;
    }
    if(!flag){
        //c.current = i - 1;                                        // since i was incremented last stage
        CircularInt c = CircularInt(c1.min,c1.max,(i-1));
        return c; // call the first one
    }
    else{
        throw (std::string)"No Answer";
    }
    
}
CircularInt operator/(const CircularInt &c1, const int &int2){
        // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).
    bool flag = true;
    int i = c1.min;
    for( ; i <= c1.max && flag ;i++ ){
        if(moduloC(c1.min,c1.max,i * int2)== c1.current)
            flag = false;
    }
    if(!flag){
        //c.current = i - 1;                                        // since i was incremented last stage
        CircularInt c = CircularInt(c1.min,c1.max,(i-1));
        return c; // call the first one
    }
    else{
        throw (std::string)"No Answer";
    }
}
CircularInt operator/(const int &int1, const CircularInt &c2){
        // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).
    bool flag = true;
    int i = c2.min;
    for( ; i <= c2.max && flag ;i++ ){
        if(moduloC(c2.min,c2.max,i * c2.current)== int1)
            flag = false;
    }
    if(!flag){
        //c.current = i - 1;                                        // since i was incremented last stage
        CircularInt c = CircularInt(c2.min,c2.max,(i-1));
        return c; // call the first one
    }
    else{
        throw (std::string)"No Answer";
    }
}

//END OF / **********




/**
 * += int
 * += Class
 * *= int
 * *= Class
 * /= int
 * -= int
 */ 

CircularInt& CircularInt::operator+=(const int& rhs){
    setCurrent(moduloC(min,max,(this->getCurrent()+rhs)));
    return *this;
}

CircularInt& CircularInt::operator+=(const CircularInt &i){
    setCurrent(moduloC(min,max,(this->getCurrent()+i.current)));
    return *this;
}

CircularInt& CircularInt::operator*=(const int& i){
    
    int j = std::abs(i);
    CircularInt c = CircularInt(min,max,current);
    while(j > 1){
        c.setCurrent((c+c).getCurrent());               
        j--;
    }
    if(j == 0){
        c.setCurrent(0);
    }
    
    setCurrent(moduloC(min,max,c.getCurrent()));
    return *this; 
}


CircularInt& CircularInt::operator*=(const CircularInt &i){
    
    int j = std::abs(i.current);
    CircularInt c = CircularInt(min,max,current);
    while(j > 1){
        c.setCurrent((c+c).getCurrent());               
        j--;
    }
    if(j == 0){
        c.setCurrent(0);
    }
    
    setCurrent(moduloC(min,max,c.getCurrent()));
    return *this; 
}


CircularInt& CircularInt::operator/=(const int& int2){
    // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).
    bool flag = true;
    int i = min;
    for( ; i <= max && flag ;i++ ){
        if(moduloC(min,max,i * int2) == current)
            flag = false;
    }
    if(!flag){
        //c.current = i - 1;                                        // since i was incremented last stage
        CircularInt c = CircularInt(min,max,(i-1));
        return c; // call the first one
    }
    else{
        throw (std::string)"No Answer";
    }
}


CircularInt& CircularInt::operator/=(const CircularInt other){
    // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).
    int int2 = other.current;
    bool flag = true;
    int i = min;
    for( ; i <= max && flag ;i++ ){
        if(moduloC(min,max,i * int2) == current)
            flag = false;
    }
    if(!flag){
        //c.current = i - 1;                                        // since i was incremented last stage
        CircularInt c = CircularInt(min,max,(i-1));
        return c; // call the first one
    }
    else{
        throw (std::string)"No Answer";
    }
}

CircularInt& CircularInt::operator-=(const int& rhs){
    setCurrent(moduloC(min,max,(this->getCurrent()-rhs)));
    return *this;
}


/*** == FUNCS***********************************************
* CLASS == CLASS
* INT == CLASS
* CLASS == INT
*/

bool operator==(const CircularInt& arg1,const CircularInt& arg2){
    if(arg1.min == arg2.min && arg1.max == arg2.max && arg1.current == arg2.current)
        return true;
    else
        return false;
}

bool operator==(const int& arg1,const CircularInt& arg2){
    if(arg2.current - arg2.min + 1 == arg1 )
        return true;
    else
        return false;
}

bool operator==(const CircularInt& arg1,const int& arg2){
    if(arg1.current - arg1.min + 1 == arg2)
        return true;
    else
        return false;
}





/*** != FUNCS***********************************************
* CLASS != CLASS
* INT != CLASS
* CLASS != INT
*/

bool operator!=(const CircularInt& arg1,const CircularInt& arg2){
    if(arg1 == arg2)
        return false;
    else
        true;
}

bool operator!=(const int& arg1,const CircularInt& arg2){
    if(arg1 == arg2)
        return false;
    else
        true;
}

bool operator!=(const CircularInt& arg1,const int& arg2){
    if(arg1 == arg2)
        return false;
    else
        true;
}



/*** < FUNCS***********************************************
* CLASS < CLASS
* INT < CLASS
* CLASS < INT
*/

bool operator<(const CircularInt& arg1,const CircularInt& arg2){
    if(arg1.current - arg1.min < arg2.current - arg2.min)
        return true;
    else
        false;
}

bool operator<(const int& arg1,const CircularInt& arg2){
    if(arg1 < arg2.current - arg2.min)
        return true;
    else
        false;
}

bool operator<(const CircularInt& arg1,const int& arg2){
    if(arg1.current - arg1.min < arg2)
        return true;
    else
        false;
}




/*** > FUNCS***********************************************
* CLASS > CLASS
* INT > CLASS
* CLASS > INT
*/

bool operator>(const CircularInt& arg1,const CircularInt& arg2){
    if(arg1.current - arg1.min > arg2.current - arg2.min)
        return true;
    else
        false;
}

bool operator>(const int& arg1,const CircularInt& arg2){
    if(arg1 > arg2.current - arg2.min)
        return true;
    else
        false;
}

bool operator>(const CircularInt& arg1,const int& arg2){
    if(arg1.current - arg1.min > arg2)
        return true;
    else
        false;
}


/***ASSIGNMENT FUNCS***********************************************
 * int CircularInt::getBegin() const{
 */ 
CircularInt& CircularInt::operator=(const CircularInt & other)
    {
        if (this != &other) // protect against invalid self-assignment
        {
            min = other.min;
            max = other.max;
            current = other.current;
        }
        // by convention, always return *this
        return *this;
    }




//getters:
int CircularInt::getmin() const{
    return min;
}
int CircularInt::getmax() const{
    return max;
}

int CircularInt::getCurrent() const{
    return current;
}

void CircularInt::setCurrent(int newV) {
    current = newV;
}