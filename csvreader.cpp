#include "csvreader.h"
#include "filenotfoundexception.h"
#include <iostream>
#include <QTextStream>
#include <QFile>

namespace Util {
    csvReader::csvReader(std::string fileName) {
        this->fileName = QString::fromStdString(fileName);
    }

    void csvReader::readFile() {
        QFile inputFile = QFile(fileName);
        try {
            if (!inputFile.open(QIODevice::ReadWrite))
                throw fileNotFoundException();
        } catch (fileNotFoundException e) {
            std::cout << e.what();
            return;
        }
        QTextStream in(&inputFile);

        while (!in.atEnd()) {
            QStringList row = in.readLine().split(",");
            if (row.size() != 0)
                data.append(row);
        }
        inputFile.close();
    }

    QList<QStringList> csvReader::getData() {
        return data;
    }

    void csvReader::writeData(const QList<QStringList> &data) {
        QFile inputFile = QFile(fileName);
        try {
            if (!inputFile.open(QIODevice::ReadWrite))
                throw fileNotFoundException();
        } catch (fileNotFoundException e) {
            std::cout << e.what();
            return;
        }
        QTextStream stream(&inputFile);

        for (const QStringList &row : data) {
            QStringList rowData;
            for (const QString &cell : row) {
                QString newCell = cell;
                if (newCell.contains(',') || newCell.contains('"') || newCell.contains('\n'))
                    newCell = "\"" + newCell.replace("\"", "\"\"") + "\"";
                rowData.append(newCell);
            }
            stream << rowData.join(',') << "\n";
        }
        inputFile.close();
    }

    template <class T> void csvReader::printOut(T &arg) {
        std::cout << arg << std::endl;
    }
}
