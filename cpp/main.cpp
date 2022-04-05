#include <iostream>
#include "ossie/ossieSupport.h"

#include "msg_consumer.h"
int main(int argc, char* argv[])
{
    msg_consumer_i* msg_consumer_servant;
    Component::start_component(msg_consumer_servant, argc, argv);
    return 0;
}

