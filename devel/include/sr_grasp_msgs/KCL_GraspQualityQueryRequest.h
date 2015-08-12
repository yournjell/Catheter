// Generated by gencpp from file sr_grasp_msgs/KCL_GraspQualityQueryRequest.msg
// DO NOT EDIT!


#ifndef SR_GRASP_MSGS_MESSAGE_KCL_GRASPQUALITYQUERYREQUEST_H
#define SR_GRASP_MSGS_MESSAGE_KCL_GRASPQUALITYQUERYREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <sr_grasp_msgs/KCL_ContactStateStamped.h>
#include <geometry_msgs/PointStamped.h>

namespace sr_grasp_msgs
{
template <class ContainerAllocator>
struct KCL_GraspQualityQueryRequest_
{
  typedef KCL_GraspQualityQueryRequest_<ContainerAllocator> Type;

  KCL_GraspQualityQueryRequest_()
    : contacts()
    , centre_of_mass()  {
    }
  KCL_GraspQualityQueryRequest_(const ContainerAllocator& _alloc)
    : contacts(_alloc)
    , centre_of_mass(_alloc)  {
    }



   typedef std::vector< ::sr_grasp_msgs::KCL_ContactStateStamped_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::sr_grasp_msgs::KCL_ContactStateStamped_<ContainerAllocator> >::other >  _contacts_type;
  _contacts_type contacts;

   typedef  ::geometry_msgs::PointStamped_<ContainerAllocator>  _centre_of_mass_type;
  _centre_of_mass_type centre_of_mass;




  typedef boost::shared_ptr< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> const> ConstPtr;

}; // struct KCL_GraspQualityQueryRequest_

typedef ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<std::allocator<void> > KCL_GraspQualityQueryRequest;

typedef boost::shared_ptr< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest > KCL_GraspQualityQueryRequestPtr;
typedef boost::shared_ptr< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest const> KCL_GraspQualityQueryRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace sr_grasp_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sr_grasp_msgs': ['/home/catheter/catheter_position/src/sr_grasp_msgs/msg', '/home/catheter/catheter_position/devel/share/sr_grasp_msgs/msg'], 'shape_msgs': ['/opt/ros/indigo/share/shape_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/indigo/share/trajectory_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'object_recognition_msgs': ['/opt/ros/indigo/share/object_recognition_msgs/cmake/../msg'], 'octomap_msgs': ['/opt/ros/indigo/share/octomap_msgs/cmake/../msg'], 'moveit_msgs': ['/opt/ros/indigo/share/moveit_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'pcl_msgs': ['/opt/ros/indigo/share/pcl_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7353b724a179abac3eefe1f9bfdd9185";
  }

  static const char* value(const ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7353b724a179abacULL;
  static const uint64_t static_value2 = 0x3eefe1f9bfdd9185ULL;
};

template<class ContainerAllocator>
struct DataType< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sr_grasp_msgs/KCL_GraspQualityQueryRequest";
  }

  static const char* value(const ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sr_grasp_msgs/KCL_ContactStateStamped[] contacts\n\
geometry_msgs/PointStamped centre_of_mass\n\
\n\
================================================================================\n\
MSG: sr_grasp_msgs/KCL_ContactStateStamped\n\
# All 3D vectors are referenced in the fingertip core center\n\
\n\
Header header					# stamp\n\
geometry_msgs/Vector3 tangential_force  	# tangential force (local shear force)\n\
geometry_msgs/Point  contact_position		# contact position\n\
geometry_msgs/Vector3 contact_normal      	# contact normal\n\
float64 Fnormal					# amplitude of normal force (along normal)\n\
float64 Ltorque					# amplitude of local torque (around normal)\n\
\n\
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
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PointStamped\n\
# This represents a Point with reference coordinate frame and timestamp\n\
Header header\n\
Point point\n\
";
  }

  static const char* value(const ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.contacts);
      stream.next(m.centre_of_mass);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct KCL_GraspQualityQueryRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sr_grasp_msgs::KCL_GraspQualityQueryRequest_<ContainerAllocator>& v)
  {
    s << indent << "contacts[]" << std::endl;
    for (size_t i = 0; i < v.contacts.size(); ++i)
    {
      s << indent << "  contacts[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::sr_grasp_msgs::KCL_ContactStateStamped_<ContainerAllocator> >::stream(s, indent + "    ", v.contacts[i]);
    }
    s << indent << "centre_of_mass: ";
    s << std::endl;
    Printer< ::geometry_msgs::PointStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.centre_of_mass);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SR_GRASP_MSGS_MESSAGE_KCL_GRASPQUALITYQUERYREQUEST_H