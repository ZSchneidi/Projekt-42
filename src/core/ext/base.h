#ifndef BASE_H
#define BASE_H

/**
  * The Base class provides types and other definitions that are used in
  * different contexts of the application.
  *
  */


class Base
{

public:
    Base();



	/**
	  * The Log_state was moved from the LogHandler to the Base class
	  * because of the order in which the classes are initialized.
	  * Core couldn't access the Log_state in the LogHandler class.
      */
    enum Log_state {
		LS_Active,
		LS_Restricted,
		LS_Inactive
		};


};

#endif // BASE_H
