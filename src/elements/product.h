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
    Q_PROPERTY(QString productDesc READ productDesc WRITE setProductDesc)
    Q_PROPERTY(QString productIngred READ productIngred WRITE setProductIngred)
    Q_PROPERTY(QString productImage READ productImage WRITE setProductImage)

public:
    explicit Product(QObject *parent = 0);

    //GETTER
    inline int productCode() { return this->m_product_code; }
    inline float productPrice() { return this->m_prodcut_price; }
    inline QString productName() { return this->m_product_name; }
    inline QString productDesc() { return this->m_product_desc; }
    inline QString productIngred() { return this->m_product_ingred; }
    inline QString productImage() { return this->m_product_img; }

    //SETTER
    inline void setProductCode( int code ) { this->m_product_code = code; }
    inline void setProductPrice( float price ) { this->m_prodcut_price = price; }
    inline void setProductName( QString name ) { this->m_product_name = name; }
    inline void setProductDesc( QString desc ) { this->m_product_desc = desc; }
    inline void setProductIngred( QString ingred ) { this->m_product_ingred = ingred; }
    inline void setProductImage( QString img ) { this->m_product_img = img; }


signals:

public slots:

private:

    int m_product_code;
    float m_prodcut_price;
    QString m_product_name;
    QString m_product_desc;
    QString m_product_ingred;
    QString m_product_img;

};

#endif // PRODUCT_H
