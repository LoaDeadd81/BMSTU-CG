#include "myerrors.h"

Error::Error(QString message) : message(message) {}

QString Error::get_message()
{
    return message;
}

FigureError::FigureError(QString message) : Error(message)
{

}

InputError::InputError(QString message) : Error(message)
{

}

TriangleNotExist::TriangleNotExist(QString message) : FigureError(message)
{

}
