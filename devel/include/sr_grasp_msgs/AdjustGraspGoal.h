// Generated by gencpp from file sr_grasp_msgs/AdjustGraspGoal.msg
// DO NOT EDIT!


#ifndef SR_GRASP_MSGS_MESSAGE_ADJUSTGRASPGOAL_H
#define SR_GRASP_MSGS_MESSAGE_ADJUSTGRASPGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <shape_msgs/Mesh.h>
#include <geometry_msgs/PoseStamped.h>

namespace sr_grasp_msgs
{
template <class ContainerAllocator>
struct AdjustGraspGoal_
{
  typedef AdjustGraspGoal_<ContainerAllocator> Type;

  AdjustGraspGoal_()
    : objects()
    , poses()  {
    }
  AdjustGraspGoal_(const ContainerAllocator& _alloc)
    : objects(_alloc)
    , poses(_alloc)  {
    }



   typedef std::vector< ::shape_msgs::Mesh_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::shape_msgs::Mesh_<ContainerAllocator> >::other >  _objects_type;
  _objects_type objects;

   typedef std::vector< ::geometry_msgs::PoseStamped_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::PoseStamped_<ContainerAllocator> >::other >  _poses_type;
  _poses_type poses;




  typedef boost::shared_ptr< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> const> ConstPtr;

}; // struct AdjustGraspGoal_

typedef ::sr_grasp_msgs::AdjustGraspGoal_<std::allocator<void> > AdjustGraspGoal;

typedef boost::shared_ptr< ::sr_grasp_msgs::AdjustGraspGoal > AdjustGraspGoalPtr;
typedef boost::shared_ptr< ::sr_grasp_msgs::AdjustGraspGoal const> AdjustGraspGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d970b0fd49ae912c6672fca43139b13a";
  }

  static const char* value(const ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd970b0fd49ae912cULL;
  static const uint64_t static_value2 = 0x6672fca43139b13aULL;
};

template<class ContainerAllocator>
struct DataType< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sr_grasp_msgs/AdjustGraspGoal";
  }

  static const char* value(const ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# Grasp an object.\n\
# Goal\n\
shape_msgs/Mesh[] objects\n\
geometry_msgs/PoseStamped[] poses\n\
\n\
================================================================================\n\
MSG: shape_msgs/Mesh\n\
# Definition of a mesh\n\
\n\
# list of triangles; the index values refer to positions in vertices[]\n\
MeshTriangle[] triangles\n\
\n\
# the actual vertices that make up the mesh\n\
geometry_msgs/Point[] vertices\n\
\n\
================================================================================\n\
MSG: shape_msgs/MeshTriangle\n\
# Definition of a triangle's vertices\n\
uint32[3] vertex_indices\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
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
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.objects);
      stream.next(m.poses);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct AdjustGraspGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sr_grasp_msgs::AdjustGraspGoal_<ContainerAllocator>& v)
  {
    s << indent << "objects[]" << std::endl;
    for (size_t i = 0; i < v.objects.size(); ++i)
    {
      s << indent << "  objects[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::shape_msgs::Mesh_<ContainerAllocator> >::stream(s, indent + "    ", v.objects[i]);
    }
    s << indent << "poses[]" << std::endl;
    for (size_t i = 0; i < v.poses.size(); ++i)
    {
      s << indent << "  poses[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::PoseStamped_<ContainerAllocator> >::stream(s, indent + "    ", v.poses[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SR_GRASP_MSGS_MESSAGE_ADJUSTGRASPGOAL_H