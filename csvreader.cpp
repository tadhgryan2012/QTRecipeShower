#include "csvreader.h"
#include "filenotfoundexception.h"
#include <iostream>
#include <filesystem>
#include <QFile>
#include <QTextStream>

namespace Util {

    csvReader::csvReader(string fileName) {
//        QFile inputFile = QFile(std::filesystem::path(fileName));
//        try {
//            if (!inputFile.open(QIODevice::ReadOnly))
//                throw fileNotFoundException();
//        } catch (fileNotFoundException e) {
//            std::cout << e.what();
//        }

//        QTextStream in(&inputFile);
//        if (in.atEnd())
//            return;
//        QString args = in.readLine();
//        while (!in.atEnd()) {
//            QString line = in.readLine();
//            string arg;
//            while (getline(line, arg, ",")) {
//            }
//        }
//        inputFile.close();
    }
}
