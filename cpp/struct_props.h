#ifndef STRUCTPROPS_H
#define STRUCTPROPS_H

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

*******************************************************************************************/

#include <ossie/CorbaUtils.h>
#include <CF/cf.h>
#include <ossie/PropertyMap.h>

struct Component_Members_struct {
    Component_Members_struct ()
    {
    }

    static std::string getId() {
        return std::string("Component_Members");
    }

    static const char* getFormat() {
        return "sf";
    }

    std::string String;
    float Float;
};

inline bool operator>>= (const CORBA::Any& a, Component_Members_struct& s) {
    CF::Properties* temp;
    if (!(a >>= temp)) return false;
    const redhawk::PropertyMap& props = redhawk::PropertyMap::cast(*temp);
    if (props.contains("String")) {
        if (!(props["String"] >>= s.String)) return false;
    }
    if (props.contains("Float")) {
        if (!(props["Float"] >>= s.Float)) return false;
    }
    return true;
}

inline void operator<<= (CORBA::Any& a, const Component_Members_struct& s) {
    redhawk::PropertyMap props;
 
    props["String"] = s.String;
 
    props["Float"] = s.Float;
    a <<= props;
}

inline bool operator== (const Component_Members_struct& s1, const Component_Members_struct& s2) {
    if (s1.String!=s2.String)
        return false;
    if (s1.Float!=s2.Float)
        return false;
    return true;
}

inline bool operator!= (const Component_Members_struct& s1, const Component_Members_struct& s2) {
    return !(s1==s2);
}

#endif // STRUCTPROPS_H
