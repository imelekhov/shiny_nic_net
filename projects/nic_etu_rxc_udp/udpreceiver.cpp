#include "udpreceiver.h"
#include <boost/bind.hpp>

ym::UDPReceiver::UDPReceiver(boost::asio::io_service &io_service,
                         int port)
    : endpoint_(udp::v4(), port)
    , socket_(io_service)
{
    boost::system::error_code error;
    socket_.open(boost::asio::ip::udp::v4(), error);

    boost::asio::socket_base::reuse_address option(true);
    socket_.set_option(option);
    socket_.bind(endpoint_);

    socket_.async_receive_from(
                boost::asio::buffer(data_, max_length), endpoint_,
                boost::bind(&ym::UDPReceiver::handle_receive_from, this,
                  boost::asio::placeholders::error,
                  boost::asio::placeholders::bytes_transferred));

    std::cout << "endpoint: " << endpoint_ << std::endl;
    std::cout << "Listening..." << std::endl;
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





    /*
    if (!error)
    {
        boost::array<char, 45> buf;
        size_t len = socket_.receive_from(boost::asio::buffer(buf), endpoint_);
        std::cout << "Received data:" << "\n";
        std::cout.write(buf.data(), len);
        std::cout << std::endl;
    }
    */
}
