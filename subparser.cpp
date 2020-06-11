 #include "subparser.h"

SubParser::SubParser(QWidget *parent)
    : QMainWindow(parent)
{
}

SubParser::~SubParser()
{
}

void SubParser::ParseSRT(QString filePath)
{
    QString start,end,comment;
    QString timeLine;
    int index =0, turn = 0,r=0;
    double startPos =0,endPos=0 ;
    
    /*
     * turn = 0 -> Add subtitle number
     * turn = 1 -> Add string to timeLine
     * turn > 1 -> Add string to completeLine
     */
    if (filePath.isEmpty())
        return;
    QFile srtFile(filePath);
    if (!srtFile.exists() || !srtFile.open(QIODevice::ReadOnly)){
        qDebug() << " Failed attempt on opening " << filePath;
        return;
    }
    QTextStream stream(&srtFile);
    QString line;
    qDebug() << " correct file  " << filePath;
    //SRT PARSING STARTS HERE
    while (stream.readLineInto(&line)) {
        line = line.simplified();
        qDebug() << " begin  " << line;
        if (line.compare("")){
            if (!turn){
                index=atoi(line.toStdString().c_str());
                turn++;
                continue;
            }
            if (line.contains("-->")){
                timeLine += line;
                QStringList srtTime;
                srtTime = timeLine.split(' ');
                start = srtTime[0];
                end = srtTime[2];
            }
            else{
                r++;
                if (comment != "")
                    comment += " ";
                if (r == 1)
                    comment+= line;
                else
                    comment = comment + "\r" +line;
            }
            turn++;
        }
        else {
            turn = 0;
            qDebug() << index << startPos << endPos << comment << "\n";
            //addSubtitle(index,startPos,endPos,comment));
            comment = timeLine = "";
            r = 0;
        }
    }
}

double SubParser::strToTime(QString str)
{
    
}