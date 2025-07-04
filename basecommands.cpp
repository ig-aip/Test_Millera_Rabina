#include "basecommands.h"
#include "iostream"
#include "QVector"
baseCommands::baseCommands() {}


void baseCommands::viewArrayInText(QTextEdit * field, std::vector<long long> keys){
    if(!field){ return; }

    QString localStr = "";
    for(int i = 0; i < keys.size(); ++i){
        str += QString("%1 ").arg(keys[i]);
    }
    field->setText(localStr);
}


void baseCommands::viewArrayInText(QTextEdit * field, std::vector<std::unique_ptr<long long[]>>& pVector){
    if(!field){ return; }

    QString localStr = "";
    for(int i = 0; i < pVector.size(); ++i){
        for(int j = 0; j < MAX_COUNT_PTR; ++j)
        {
            if(j % 100 == 0){ str += '\n'; }
            if(pVector[i][j] == 0){ break;}
            str += QString("%1 ").arg(pVector[i][j]);

        }
    }
    field->setText(localStr);
}

QString& baseCommands::viewArrayInText( std::vector<std::unique_ptr<long long[]>>& pVector){
    str = "";
    for(int i = 0; i < pVector.size(); ++i){
        for(int j = 0; j < MAX_COUNT_PTR; ++j)
        {
            if(j % 100 == 0){ str += '\n'; }
            if(pVector[i][j] == 0){ break;}
            str += QString("%1 ").arg(pVector[i][j]);
        }
    }
    return str;
}

int baseCommands::getLustNumberFromText(QString text){
    std::vector<int> numbers;
    int result = 0;


    for(QChar c: text){
        if(c.digitValue() >= 0){
            result = result * 10 + c.digitValue();
        }
    }

    return result;
}


void baseCommands::inputTextToFile(QString& text, FileInput& file){
    file.message(text);
}
