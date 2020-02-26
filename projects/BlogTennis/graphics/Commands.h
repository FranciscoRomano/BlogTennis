#pragma once
/** Dependencies **********************************************************************************/

#include "Command.h"

/** Declarations **********************************************************************************/

template<CommandType T> class Commands {

    Command<T>* data;
    unsigned int size;
    unsigned int indx;
public:
    // destructor
    virtual ~Commands() { delete[] data; }
    // constructor
    Commands(unsigned int length) { data = new Command<T>[length]; size = length; indx = 0; };
    // push command
    void push(const Command<T>& command) { data[indx++] = command; };
    // pull command
    Command<T>& pull() { return data[--indx]; }
    // is array empty
    const bool empty() const { return indx == 0; };
    // get array length
    const unsigned int& length() const { return size; };
};

/**************************************************************************************************/