#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <list>

using namespace std;

namespace Util {
    class csvReader {
    private:
        string fileName;
        list<list<string>> data;
    public:
        csvReader(string);
    };
}
#endif // CSVREADER_H
