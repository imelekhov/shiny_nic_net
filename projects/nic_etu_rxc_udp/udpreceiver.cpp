#include "udpreceiver.h"
#include <boost/bind.hpp>

ym::UDPReceiver::UDPReceiver(boost::asio::io_service &io_service)
    : endpoint_(udp::v4(), 777)
    , socket_(io_service)
{
}

void ym::UDPReceiver::start_service(uint16_t port)
{
    endpoint_.port(port);
    boost::system::error_code ec;

    if (socket_.is_open())
    {
        socket_.shutdown(boost::asio::ip::udp::socket::shutdown_receive, ec);
        std::cout << __func__ << ": shutdown socket: error: " << ec.message() << std::endl;
        socket_.close();
    }
    socket_.open(boost::asio::ip::udp::v4(), ec);
    std::cout << __func__ << ": open socket: error: " << ec.message() << std::endl;
    boost::asio::socket_base::reuse_address option(true);
    socket_.set_option(option);
    socket_.bind(endpoint_, ec);
    std::cout << __func__ << ": error: " << ec.message() << std::endl;

    socket_.async_receive_from(
                boost::asio::buffer(data_, max_length), endpoint_,
                boost::bind(&ym::UDPReceiver::handle_receive_from, this,
                  boost::asio::placeholders::error,
                  boost::asio::placeholders::bytes_transferred));
}

void ym::UDPReceiver::handle_receive_from(const boost::system::error_code &error,
                                          size_t bytes_rcvd)
{
    std::cout << "we're here: " << __func__ << "\n";
    if (error)
    {
            std::cout << "receive error!" << std::endl;
            return;
    }

    std::cout << "Num of bytes received: " << bytes_rcvd << "\n";

    socket_.async_receive_from(
              boost::asio::buffer(data_, max_length), endpoint_,
              boost::bind(&ym::UDPReceiver::handle_receive_from, this,
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));


    std::cout << "message: " << data_ << "\n";
}
