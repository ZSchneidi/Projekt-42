#include "product.h"

Product::Product(QObject *parent) :
    QObject(parent)
{

	this->m_prodcut_price = 0;
	this->m_product_code = 0;
	this->m_product_name = "";

}

