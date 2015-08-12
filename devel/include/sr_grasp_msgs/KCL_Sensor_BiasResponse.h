// Generated by gencpp from file sr_grasp_msgs/KCL_Sensor_BiasResponse.msg
// DO NOT EDIT!


#ifndef SR_GRASP_MSGS_MESSAGE_KCL_SENSOR_BIASRESPONSE_H
#define SR_GRASP_MSGS_MESSAGE_KCL_SENSOR_BIASRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace sr_grasp_msgs
{
template <class ContainerAllocator>
struct KCL_Sensor_BiasResponse_
{
  typedef KCL_Sensor_BiasResponse_<ContainerAllocator> Type;

  KCL_Sensor_BiasResponse_()
    : reply(false)  {
    }
  KCL_Sensor_BiasResponse_(const ContainerAllocator& _alloc)
    : reply(false)  {
    }



   typedef uint8_t _reply_type;
  _reply_type reply;




  typedef boost::shared_ptr< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> const> ConstPtr;

}; // struct KCL_Sensor_BiasResponse_

typedef ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<std::allocator<void> > KCL_Sensor_BiasResponse;

typedef boost::shared_ptr< ::sr_grasp_msgs::KCL_Sensor_BiasResponse > KCL_Sensor_BiasResponsePtr;
typedef boost::shared_ptr< ::sr_grasp_msgs::KCL_Sensor_BiasResponse const> KCL_Sensor_BiasResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace sr_grasp_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sr_grasp_msgs': ['/home/catheter/catheter_position/src/sr_grasp_msgs/msg'], 'shape_msgs': ['/opt/ros/indigo/share/shape_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/indigo/share/trajectory_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'object_recognition_msgs': ['/opt/ros/indigo/share/object_recognition_msgs/cmake/../msg'], 'octomap_msgs': ['/opt/ros/indigo/share/octomap_msgs/cmake/../msg'], 'moveit_msgs': ['/opt/ros/indigo/share/moveit_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'pcl_msgs': ['/opt/ros/indigo/share/pcl_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "06d4f276c51f7469624c6fbcbf0e7869";
  }

  static const char* value(const ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x06d4f276c51f7469ULL;
  static const uint64_t static_value2 = 0x624c6fbcbf0e7869ULL;
};

template<class ContainerAllocator>
struct DataType< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sr_grasp_msgs/KCL_Sensor_BiasResponse";
  }

  static const char* value(const ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
bool reply\n\
\n\
";
  }

  static const char* value(const ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.reply);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct KCL_Sensor_BiasResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sr_grasp_msgs::KCL_Sensor_BiasResponse_<ContainerAllocator>& v)
  {
    s << indent << "reply: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.reply);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SR_GRASP_MSGS_MESSAGE_KCL_SENSOR_BIASRESPONSE_H