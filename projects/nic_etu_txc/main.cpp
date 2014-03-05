#include <boost/program_options.hpp>
#include <boost/lexical_cast.hpp>

#include <iostream>
#include <string>
#include "udpsender.h"


namespace
{
    enum Status
    {
        SUCCESS            = 0,
        COMMAND_LINE_ERROR = 1,
        UNKNOWN_ERROR      = 2
    };
} // end of anonymous namespace

int main(int argc, char *argv[])
{
    try
    {
        std::string message;
        int port = 0;

        namespace po = boost::program_options;
        po::options_description description("Options");
        description.add_options()
                ("help,h", "Print help message")
                ("message,m", po::value<std::string>(&message)->required(), "message to server")
                ("port,p", po::value<int>(&port)->required(), "port number");

        po::variables_map vm;

        try
        {
            po::store(po::parse_command_line(argc, argv, description), vm);

            if (vm.count("help"))
            {
                std::cout << "UDP sender datagram as a test tool for NIC server" << std::endl;
                std::cout << "Command line arguments: " << description << std::endl;

                return SUCCESS;
            }

            if (vm.count("port"))
            {
                port = vm["port"].as<int>();
            }

            if (vm.count("message"))
            {
                message = vm["message"].as<std::string>();
            }

            std::cout << "message: " << message.c_str() << std::endl;
            std::cout << "port   : " << port << std::endl;

        }
        catch(const boost::program_options::required_option& err)
        {
            std::cerr << "ERROR: " << err.what() << std::endl;
            return COMMAND_LINE_ERROR;
        }
        catch(const boost::program_options::error& e)
        {
            std::cerr << "ERROR: " << e.what() << std::endl;
            return COMMAND_LINE_ERROR;
        }

        boost::asio::io_service io_service;
        ym::UDPSender sender(io_service, message, port);
        std::cout << "endpoint = " << sender.get_endpoint() << "\n";
        io_service.run();
        (void)sender; // suppress warning about unused variable
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return SUCCESS;
}
