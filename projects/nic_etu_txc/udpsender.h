#pragma once

#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <string>


using namespace boost::asio::ip;
using namespace boost::asio;

namespace ym
{
class UDPSender
{
public:
    UDPSender(boost::asio::io_service& io_service, const std::string& message, int port);

private:
    void handle_send_to(const boost::system::error_code& error);
    void handle_timeout(const boost::system::error_code& error);

    void start_sending();
    /*
    void start_receive();
    void handle_receive(const boost::system::error_code& error,
                        std::size_t bytes_sent);
    */
    void handle_send(const std::string& message,
                     const boost::system::error_code& error,
                     std::size_t bytes_sent);

public:
    const udp::endpoint& get_endpoint() const
    {
        return endpoint_;
    }

private:
    udp::endpoint endpoint_;
    udp::socket socket_;
    deadline_timer timer_;
    std::string message_;
};




}
