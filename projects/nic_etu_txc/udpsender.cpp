#include "udpsender.h"
#include <boost/bind.hpp>

ym::UDPSender::UDPSender(boost::asio::io_service &io_service,
                         const std::string &message,
                         int port)
    : endpoint_(udp::v4(), port)
    , socket_(io_service, endpoint_)
    , timer_(io_service)
    , message_(message)
{
    boost::asio::socket_base::reuse_address option(true);
    socket_.set_option(option);
    socket_.async_send_to(boost::asio::buffer(message_), endpoint_,
                          boost::bind(&ym::UDPSender::handle_send_to, this,
                                      boost::asio::placeholders::error));
}

void ym::UDPSender::handle_send_to(const boost::system::error_code &error)
{
    if (!error)
    {
        std::cout << "we're here: " << __func__ << ": no error" << "\n";
        timer_.expires_from_now(boost::posix_time::seconds(1));
        timer_.async_wait(
                    boost::bind(&ym::UDPSender::handle_timeout, this,
                                boost::asio::placeholders::error));
    }
    else
    {
        std::cout << "we're here: " << __func__ << ": something went wrong" << "\n";
    }

}

void ym::UDPSender::handle_timeout(const boost::system::error_code &error)
{
    if (!error)
    {
        std::cout << "we're here: " << __func__ << ": no error! Message: " << message_.c_str() << "\n";
        socket_.async_send_to(
                    boost::asio::buffer(message_), endpoint_,
                    boost::bind(&ym::UDPSender::handle_send_to, this,
                                boost::asio::placeholders::error));
    }
    else
    {
        std::cout << "we're here: " << __func__ << ": something went wrong" << "\n";
    }

}
