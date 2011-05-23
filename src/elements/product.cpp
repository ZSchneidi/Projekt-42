#include "product.h"

Product::Product(QObject *parent) :
    QObject(parent)
{

    this->m_product_price = 0;
	this->m_product_code = 0;
	this->m_product_name = "";
    this->m_product_desc = "";
    this->m_product_ingred = "";
    this->m_product_img = "";
    this->measurable = false;

}

