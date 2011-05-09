#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>


/**
  * A Product is a respresentation of the product which
  * can be selected in a view layer.
  * The information of a product are passed to the EventHandler
  * so it knows everything about a selected product.
  */
class Product : public QObject
{
    Q_OBJECT


    Q_PROPERTY(int productCode READ productCode WRITE setProductCode)
    Q_PROPERTY(float productPrice READ productPrice WRITE setProductPrice)
    Q_PROPERTY(QString productName READ productName WRITE setProductName)

public:
    explicit Product(QObject *parent = 0);

    //GETTER
    inline int productCode() { return this->m_product_code; }
    inline float productPrice() { return this->m_prodcut_price; }
    inline QString productName() { return this->m_product_name; }

    //SETTER
    inline void setProductCode( int code ) { this->m_product_code = code; }
    inline void setProductPrice( float price ) { this->m_prodcut_price = price; }
    inline void setProductName( QString name ) { this->m_product_name = name; }


signals:

public slots:

private:

    int product_code;
    int sugar_value;
    int milk_value;
    float product_price;
    int m_product_code;
    float m_prodcut_price;
    QString m_product_name;

};

#endif // PRODUCT_H
