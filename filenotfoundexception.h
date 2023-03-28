#ifndef FILENOTFOUNDEXCEPTION_H
#define FILENOTFOUNDEXCEPTION_H

#include <string>
#include <stdexcept>

using namespace std;

class fileNotFoundException : public runtime_error {
public:
    fileNotFoundException();
    fileNotFoundException(string);
};

#endif // FILENOTFOUNDEXCEPTION_H
