#ifndef ERROR_NEW_HPP
#define ERROR_NEW_HPP

#include <exception>
#include <string>

class DefaultException : public std::exception
{
public:
    explicit DefaultException() = default;
    explicit DefaultException(const char *message);

    const char *what() const noexcept override;

protected:
    std::string message_;
};

DefaultException::DefaultException(const char *message) : message_(message) {}

const char *DefaultException::what() const noexcept
{
    return "DefaultException";
}


#endif // ERROR_NEW_HPP
