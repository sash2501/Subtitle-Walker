#include "subparser.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SubParser parse;
    QString filePath= "path_to_sub_file";
    if (filePath.contains(".srt")){
        qDebug()<< "srt File";
        parse.ParseSRT(filePath);
    }
    else if (filePath.contains(".ass")){
        qDebug()<< "ass File";
        parse.ParseSSA(filePath);
    }
    return a.exec();
} 
