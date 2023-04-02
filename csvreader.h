#ifndef CSVREADER_H
#define CSVREADER_H

#include <QStringList>
#include <QList>
#include <QString>

namespace Util {
    class csvReader {
    private:
        QString fileName;
        QList<QStringList> data;
    public:
        csvReader(std::string);
        void readFile();
        QList<QStringList> getData();
        void writeData(const QList<QStringList>&);
        template <class T> void printOut(T&);
    };
}
#endif // CSVREADER_H
