#pragma once
/** Dependencies **********************************************************************************/

#include "Color.h"

/** Declarations **********************************************************************************/

class Colorbuffer
{
    Color* data;
    unsigned int length;
public:

    // destructor
    virtual ~Colorbuffer();

    // constructor
    Colorbuffer(const unsigned int& length);

    // Color* cast operator
    operator Color* ();
};

/**************************************************************************************************/