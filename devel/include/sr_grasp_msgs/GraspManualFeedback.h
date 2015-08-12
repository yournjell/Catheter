// Generated by gencpp from file sr_grasp_msgs/GraspManualFeedback.msg
// DO NOT EDIT!


#ifndef SR_GRASP_MSGS_MESSAGE_GRASPMANUALFEEDBACK_H
#define SR_GRASP_MSGS_MESSAGE_GRASPMANUALFEEDBACK_H


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
struct GraspManualFeedback_
{
  typedef GraspManualFeedback_<ContainerAllocator> Type;

  GraspManualFeedback_()
    : state(0)  {
    }
  GraspManualFeedback_(const ContainerAllocator& _alloc)
    : state(0)  {
    }



   typedef uint8_t _state_type;
  _state_type state;


    enum { SEARCHING = 0u };
     enum { SELECTING = 1u };
     enum { GRABBING = 2u };
     enum { RELEASING = 3u };
 

  typedef boost::shared_ptr< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct GraspManualFeedback_

typedef ::sr_grasp_msgs::GraspManualFeedback_<std::allocator<void> > GraspManualFeedback;

typedef boost::shared_ptr< ::sr_grasp_msgs::GraspManualFeedback > GraspManualFeedbackPtr;
typedef boost::shared_ptr< ::sr_grasp_msgs::GraspManualFeedback const> GraspManualFeedbackConstPtr;

// constants requiring out of line definition

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a975d832f370307d65c54c1449117d0d";
  }

  static const char* value(const ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa975d832f370307dULL;
  static const uint64_t static_value2 = 0x65c54c1449117d0dULL;
};

template<class ContainerAllocator>
struct DataType< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sr_grasp_msgs/GraspManualFeedback";
  }

  static const char* value(const ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# Feedback\n\
# State shows what the node is currently doing.\n\
uint8 SEARCHING=0\n\
uint8 SELECTING=1\n\
uint8 GRABBING=2\n\
uint8 RELEASING=3\n\
uint8 state\n\
\n\
";
  }

  static const char* value(const ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct GraspManualFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sr_grasp_msgs::GraspManualFeedback_<ContainerAllocator>& v)
  {
    s << indent << "state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.state);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SR_GRASP_MSGS_MESSAGE_GRASPMANUALFEEDBACK_H
