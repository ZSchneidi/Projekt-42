#include "exception.h"


UnkownProductExpetion::UnkownProductExpetion() :
    std::exception()
    {
    this->product_code = 0;
    }
