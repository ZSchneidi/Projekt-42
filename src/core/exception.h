#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>


/*Exceptions*/


class eUnsetPointer : public std::exception
{
    public: virtual const char* what() const throw() {return "Access to unset Pointer.";}
};

class eUnsetObject : public std::exception
{
    public: virtual const char* what() const throw() {return "Access to uninitialized object.";}
};

class eUnexpAttrValue : public std::exception
{
    public: virtual const char* what() const throw() {return "Found unexpected attribute value.";}
};

class UnkownProductExpetion : public std::exception
{
public:

    explicit UnkownProductExpetion();

    int product_code;

    virtual const char* what() const throw() {return "unknown product";}
};

#endif // EXCEPTION_H
