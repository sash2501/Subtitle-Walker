#ifndef SUBPARSER_H
#define SUBPARSER_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>

class SubParser : public QMainWindow
{
    Q_OBJECT

public:
    SubParser(QWidget *parent = nullptr);
    ~SubParser();
    void ParseSRT(QString filePath);
    void ParseSSA(QString filePath);
    double strToTime(QString str);
};
#endif // SUBPARSER_H
