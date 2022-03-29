#include "MyErrors.h"

Error::Error(QString message) : message(message)
{

}

QString Error::get_message()
{
    return message;
}

LineError::LineError(QString message) : Error(message)
{

}

InputError::InputError(QString message) : Error(message)
{

}

FigureError::FigureError(QString message) : Error(message)
{

}

Chill::Chill(QString message) : Error(message)
{

}
