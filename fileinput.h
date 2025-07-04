#ifndef FILEINPUT_H
#define FILEINPUT_H
#include "QFile"
#include "QTextStream"

class FileInput
{
    QFile file;
public:
    FileInput(const QString& filePath);
    ~FileInput();

    void restart();

    void message(const QString& str);
};

#endif // FILEINPUT_H
