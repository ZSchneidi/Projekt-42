#ifndef BASE_H
#define BASE_H
#include <QObject>

/**
  * The Base class provides types and other definitions that are used in
  * different contexts of the application.
  *
  */


class Base : public QObject
{
    Q_OBJECT

public:
    Base();



	/**
      *
      */
    enum Log_state {
		LS_Active,
		LS_Restricted,
		LS_Inactive
		};

    Q_ENUMS(Product_state)
    enum Product_state {
        Selected,
        Canceled,
        Bought,
        Served,
        Error
        };

    Q_ENUMS(Media_states)
    enum Media_states {
        Init_Media
        };
};

#endif // BASE_H
