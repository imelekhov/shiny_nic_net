#pragma once

#include <stdexcept>
#include <QWidget>
#include <QString>

namespace ym
{
class base_error : public std::runtime_error
{
public:
    explicit base_error(const QString& message = QString())
        : std::runtime_error(message.toLocal8Bit().data())
        , message_(message)
    {}

    ~base_error() throw() {}

public:
    const QString& message() const
    {
        return message_;
    }

private:
    QString message_;
};


class widget_error : public base_error
{
public:
    explicit widget_error(QWidget* widget,
                         const QString& message = QString())
        : base_error(message)
        , widget_(widget)
    {}

    ~widget_error() throw() {}

public:
    QWidget* widget() const
    {
        return widget_;
    }

private:
    QWidget* widget_;
};

} // end of namespace ym
