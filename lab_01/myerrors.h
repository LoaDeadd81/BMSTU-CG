#ifndef MYERRORS_H
#define MYERRORS_H

#include <exception>
#include <QString>

using namespace std;

class Error : public exception
{
private:
    QString message;
public:
    Error(QString message = "");
    QString get_message();
};

class FigureError : public Error
{
public:
    explicit FigureError(QString message = "");

};

class InputError : public Error
{
public:
    explicit InputError(QString message = "");

};

class TriangleNotExist : public FigureError
{
public:
    explicit TriangleNotExist(QString message = "");

};

#endif
