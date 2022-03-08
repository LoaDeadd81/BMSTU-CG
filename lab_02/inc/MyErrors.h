#ifndef MYERRORS_H
#define MYERRORS_H

#include <exception>

#include <QString>

class Error : public std::exception
{
private:
    QString message;
public:
    Error(QString message);
    QString get_message();
};

class LineError : public Error
{
public:
    LineError(QString message);
};
#endif
