#include "subparser.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SubParser parse;
    QString filePath= "Thor.ass";
    if (filePath.contains(".srt")){
        qDebug()<< "srt File";
        parse.ParseSRT(filePath);
    }
    return a.exec();
} 
