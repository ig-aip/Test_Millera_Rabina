#ifndef BASECOMMANDS_H
#define BASECOMMANDS_H
#include "QTextEdit"
#include "QLineEdit"
#include "vector"
#include "QChar"
#include "cmath"
#include "ALG_CONSTANTS.h"
#include "fileinput.h"

class baseCommands
{
    QString str = "";
public:
    baseCommands();

    void viewArrayInText(QTextEdit * field, std::vector<long long> keys);
    void viewArrayInText(QTextEdit * field, std::vector<std::unique_ptr<long long[]>>& pVector);
    QString& viewArrayInText(std::vector<std::unique_ptr<long long[]>>& pVector);

    int getLustNumberFromText(QString text);

    void inputTextToFile(QString& text, FileInput& file);
};

#endif // BASECOMMANDS_H
