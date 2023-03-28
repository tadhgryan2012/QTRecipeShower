#include "filenotfoundexception.h"

fileNotFoundException::fileNotFoundException():runtime_error("File not found"){}
fileNotFoundException::fileNotFoundException(string msg):runtime_error(msg.c_str()){}
