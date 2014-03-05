#pragma once

#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <string>


using namespace boost::asio::ip;
using namespace boost::asio;

namespace ym
{
class UDPReceiver
{
public:
    UDPReceiver(boost::asio::io_service& io_service,
                int port);

private:
    void handle_receive_from(const boost::system::error_code& error,
                            size_t bytes_rcvd);

private:
    udp::endpoint endpoint_;
    udp::socket socket_;
    enum { max_length = 12 };
    char data_[max_length];
};




}
