#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <stdlib.h>
#include <string.h>

using namespace std;

namespace CoBox {

#define THROW _GLIBCXX_USE_NOEXCEPT

/**
 * @brief The Base Exception class
 */
class Exception : public exception
{
public:
    Exception() THROW
    {
        mpMessage = NULL;
    }

    Exception(const char *msg) THROW
    {
        size_t msglen = strlen(msg) + strlen(this->TAG) + 2 + 1;
        mpMessage = (char*)malloc(msglen);
        strcat(mpMessage, this->TAG);
        strcat(mpMessage, ": ");
        strcat(mpMessage, msg);
    }

    virtual ~Exception() THROW
    {
        if (mpMessage != NULL && mpMessage != this->TAG)
        {
            free (mpMessage);
            mpMessage = NULL;
        }
    }

    virtual const char* what() const THROW
    {
        if (mpMessage != NULL)
            return mpMessage;
        else
            return this->TAG;
    }

protected:
    static const char* TAG;

protected:
    char *mpMessage;
};

/**
 * @brief The IndexOutOfBoundsException class
 */
class IndexOutOfBoundsException : public Exception
{
public:
    IndexOutOfBoundsException() THROW
    {
        mpMessage = NULL;
    }

    IndexOutOfBoundsException(const char *msg) THROW
    {
        size_t msglen = strlen(msg) + strlen(this->TAG) + 2 + 1;
        mpMessage = (char*)malloc(msglen);
        strcat(mpMessage, this->TAG);
        strcat(mpMessage, ": ");
        strcat(mpMessage, msg);
    }

    ~IndexOutOfBoundsException() THROW
    {
        if (mpMessage != NULL && mpMessage != this->TAG)
        {
            free (mpMessage);
            mpMessage = NULL;
        }
    }

protected:
    static const char* TAG;
};

/**
 * @brief The NullPointerException class
 */
class NullPointerException : public Exception
{
public:
    NullPointerException() THROW
    {
        mpMessage = NULL;
    }

    NullPointerException(const char *msg) THROW
    {
        size_t msglen = strlen(msg) + strlen(this->TAG) + 2 + 1;
        mpMessage = (char*)malloc(msglen);
        strcat(mpMessage, this->TAG);
        strcat(mpMessage, ": ");
        strcat(mpMessage, msg);
    }

    ~NullPointerException() THROW
    {
        if (mpMessage != NULL && mpMessage != this->TAG)
        {
            free (mpMessage);
            mpMessage = NULL;
        }
    }

protected:
    static const char* TAG;
};

}

#endif // EXCEPTION_H
