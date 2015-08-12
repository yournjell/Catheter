// Generated by gencpp from file sr_grasp_msgs/ForceControlFeedback.msg
// DO NOT EDIT!


#ifndef SR_GRASP_MSGS_MESSAGE_FORCECONTROLFEEDBACK_H
#define SR_GRASP_MSGS_MESSAGE_FORCECONTROLFEEDBACK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>

namespace sr_grasp_msgs
{
template <class ContainerAllocator>
struct ForceControlFeedback_
{
  typedef ForceControlFeedback_<ContainerAllocator> Type;

  ForceControlFeedback_()
    : current_state(0.0)
    , normal()
    , tangential()  {
    }
  ForceControlFeedback_(const ContainerAllocator& _alloc)
    : current_state(0.0)
    , normal(_alloc)
    , tangential(_alloc)  {
    }



   typedef double _current_state_type;
  _current_state_type current_state;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _normal_type;
  _normal_type normal;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _tangential_type;
  _tangential_type tangential;




  typedef boost::shared_ptr< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct ForceControlFeedback_

typedef ::sr_grasp_msgs::ForceControlFeedback_<std::allocator<void> > ForceControlFeedback;

typedef boost::shared_ptr< ::sr_grasp_msgs::ForceControlFeedback > ForceControlFeedbackPtr;
typedef boost::shared_ptr< ::sr_grasp_msgs::ForceControlFeedback const> ForceControlFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace sr_grasp_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sr_grasp_msgs': ['/home/catheter/catheter_position/src/sr_grasp_msgs/msg', '/home/catheter/catheter_position/devel/share/sr_grasp_msgs/msg'], 'shape_msgs': ['/opt/ros/indigo/share/shape_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/indigo/share/trajectory_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'object_recognition_msgs': ['/opt/ros/indigo/share/object_recognition_msgs/cmake/../msg'], 'octomap_msgs': ['/opt/ros/indigo/share/octomap_msgs/cmake/../msg'], 'moveit_msgs': ['/opt/ros/indigo/share/moveit_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'pcl_msgs': ['/opt/ros/indigo/share/pcl_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c2c88f3d072d22e6edb0af4767beecd3";
  }

  static const char* value(const ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc2c88f3d072d22e6ULL;
  static const uint64_t static_value2 = 0xedb0af4767beecd3ULL;
};

template<class ContainerAllocator>
struct DataType< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sr_grasp_msgs/ForceControlFeedback";
  }

  static const char* value(const ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# Feedback\n\
# State shows what the node is currently doing.\n\
float64 current_state #current normal force\n\
geometry_msgs/Vector3 normal #current normal direction\n\
geometry_msgs/Vector3 tangential #current tangential direction\n\
\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.current_state);
      stream.next(m.normal);
      stream.next(m.tangential);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ForceControlFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sr_grasp_msgs::ForceControlFeedback_<ContainerAllocator>& v)
  {
    s << indent << "current_state: ";
    Printer<double>::stream(s, indent + "  ", v.current_state);
    s << indent << "normal: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.normal);
    s << indent << "tangential: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.tangential);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SR_GRASP_MSGS_MESSAGE_FORCECONTROLFEEDBACK_H
