#pragma once

#include <stdint.h>

namespace ym
{

struct execution_config
{
    execution_config(uint16_t thread_in_pool, uint16_t port_input, uint32_t port_output)
        : thread_in_pool(thread_in_pool)
        , port_input(port_input)
        , port_output(port_output)
    {
        // TODO: check the input parameters
    }

    uint16_t thread_in_pool;
    uint16_t port_input;
    uint16_t port_output;
};

} // end of namespace ym
