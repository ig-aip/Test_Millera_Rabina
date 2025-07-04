#include "fileinput.h"

FileInput::FileInput(const QString& filePath) {
    file.setFileName(filePath);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
}

FileInput::~FileInput(){
    if(file.isOpen()){ file.close();}
}

void FileInput::restart(){
    if(file.isOpen()){
        file.close();
        file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    }
}

void FileInput::message(const QString& str){
    if(!file.isOpen()){ qWarning("file not open"); }
    QTextStream out(&file);
    out <<str << '\n';

    out.flush();

}
