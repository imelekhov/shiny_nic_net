#pragma once

namespace ym
{

namespace service_state
{
enum State
{
    Init,
    Started,
    Stopped,
//    Terminated,
    Resumed,
    UDPfailed
};
} // end of namespace service_state
} // end of namespace ym
