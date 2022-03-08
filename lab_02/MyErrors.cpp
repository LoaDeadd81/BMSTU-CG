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
