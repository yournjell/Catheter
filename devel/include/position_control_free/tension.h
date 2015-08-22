// Generated by gencpp from file position_control_free/tension.msg
// DO NOT EDIT!


#ifndef POSITION_CONTROL_FREE_MESSAGE_TENSION_H
#define POSITION_CONTROL_FREE_MESSAGE_TENSION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace position_control_free
{
template <class ContainerAllocator>
struct tension_
{
  typedef tension_<ContainerAllocator> Type;

  tension_()
    : header()
    , tension1(0.0)
    , tension2(0.0)
    , tension3(0.0)
    , tension4(0.0)  {
    }
  tension_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , tension1(0.0)
    , tension2(0.0)
    , tension3(0.0)
    , tension4(0.0)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _tension1_type;
  _tension1_type tension1;

   typedef double _tension2_type;
  _tension2_type tension2;

   typedef double _tension3_type;
  _tension3_type tension3;

   typedef double _tension4_type;
  _tension4_type tension4;




  typedef boost::shared_ptr< ::position_control_free::tension_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::position_control_free::tension_<ContainerAllocator> const> ConstPtr;

}; // struct tension_

typedef ::position_control_free::tension_<std::allocator<void> > tension;

typedef boost::shared_ptr< ::position_control_free::tension > tensionPtr;
typedef boost::shared_ptr< ::position_control_free::tension const> tensionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::position_control_free::tension_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::position_control_free::tension_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace position_control_free

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'position_control_free': ['/home/catheter/catheter_position/src/position_control_free/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::position_control_free::tension_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::position_control_free::tension_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::position_control_free::tension_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::position_control_free::tension_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::position_control_free::tension_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::position_control_free::tension_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::position_control_free::tension_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ea2612eb28a51adb81061f0a39210bc4";
  }

  static const char* value(const ::position_control_free::tension_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xea2612eb28a51adbULL;
  static const uint64_t static_value2 = 0x81061f0a39210bc4ULL;
};

template<class ContainerAllocator>
struct DataType< ::position_control_free::tension_<ContainerAllocator> >
{
  static const char* value()
  {
    return "position_control_free/tension";
  }

  static const char* value(const ::position_control_free::tension_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::position_control_free::tension_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
float64 tension1\n\
float64 tension2\n\
float64 tension3\n\
float64 tension4\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::position_control_free::tension_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::position_control_free::tension_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.tension1);
      stream.next(m.tension2);
      stream.next(m.tension3);
      stream.next(m.tension4);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct tension_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::position_control_free::tension_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::position_control_free::tension_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "tension1: ";
    Printer<double>::stream(s, indent + "  ", v.tension1);
    s << indent << "tension2: ";
    Printer<double>::stream(s, indent + "  ", v.tension2);
    s << indent << "tension3: ";
    Printer<double>::stream(s, indent + "  ", v.tension3);
    s << indent << "tension4: ";
    Printer<double>::stream(s, indent + "  ", v.tension4);
  }
};

} // namespace message_operations
} // namespace ros

#endif // POSITION_CONTROL_FREE_MESSAGE_TENSION_H
