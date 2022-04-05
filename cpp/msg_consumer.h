#ifndef MSG_CONSUMER_I_IMPL_H
#define MSG_CONSUMER_I_IMPL_H

#include "msg_consumer_base.h"

class msg_consumer_i : public msg_consumer_base
{
	void messageReceived(const std::string &id, const Component_Members_struct &msg);
    ENABLE_LOGGING
    public:
        msg_consumer_i(const char *uuid, const char *label);
        ~msg_consumer_i();

        void constructor();

        int serviceFunction();

    protected:
};

#endif // MSG_CONSUMER_I_IMPL_H
