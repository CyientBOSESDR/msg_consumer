#include "msg_consumer_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

    The following class functions are for the base class for the component class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/

msg_consumer_base::msg_consumer_base(const char *uuid, const char *label) :
    Component(uuid, label),
    ThreadedComponent()
{
    setThreadName(label);

    loadProperties();

    message_in = new MessageConsumerPort("message_in");
    message_in->setLogger(this->_baseLog->getChildLogger("message_in", "ports"));
    addPort("message_in", message_in);
}

msg_consumer_base::~msg_consumer_base()
{
    message_in->_remove_ref();
    message_in = 0;
}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void msg_consumer_base::start() throw (CORBA::SystemException, CF::Resource::StartError)
{
    Component::start();
    ThreadedComponent::startThread();
}

void msg_consumer_base::stop() throw (CORBA::SystemException, CF::Resource::StopError)
{
    Component::stop();
    if (!ThreadedComponent::stopThread()) {
        throw CF::Resource::StopError(CF::CF_NOTSET, "Processing thread did not die");
    }
}

void msg_consumer_base::releaseObject() throw (CORBA::SystemException, CF::LifeCycle::ReleaseError)
{
    // This function clears the component running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    Component::releaseObject();
}

void msg_consumer_base::loadProperties()
{
    addProperty(Component_Members,
                Component_Members_struct(),
                "Component_Members",
                "",
                "readwrite",
                "",
                "external",
                "message");

}



