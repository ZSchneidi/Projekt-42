#include "product.h"

Product::Product(QObject *parent) :
    QObject(parent)
{
	this->product_code = 0;
	this->sugar_value = 0;
	this->milk_value = 0;
	this->product_price = 0.0;
	this->m_prodcut_price = 0;
	this->m_product_code = 0;
	this->m_product_name = "";

}

