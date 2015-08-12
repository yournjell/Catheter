#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>
#include "geometry_msgs/PoseArray.h"

/// This node publishes the tip poses considering that we have 3 markers on a 2 segment robot.
/// Markers are placed in the rigid parts: base of seg 1, tip of seg 1, tip of seg 2
/// We use the 4th makre Marke4 that is not attached to the robot, to specify the orientation we want for the xyz axis
/// (e.g. to align x with the first chamber of the robot etc)
int main (int argc, char** argv)

{
    ros::init(argc,argv,"marker_calibration_node");

    ros::NodeHandle n;
    geometry_msgs::PoseStamped new_pose;
    tf::TransformListener listener ;
    tf::TransformBroadcaster br;
    tf::StampedTransform transform;
    tf::StampedTransform transform_2;
    ros:: Rate rate(40.0);
    std::vector<ros::Publisher> new_poses;

    ros::Publisher module_tip_pub = n.advertise<geometry_msgs::Pose>("pose_1_tip", 1000);
    ros::Publisher module_tip_pub_2 = n.advertise<geometry_msgs::Pose>("pose_2_tip", 1000);

    ros::Publisher tip_array_pub = n.advertise<geometry_msgs::PoseArray>("flexible_module_poses", 1000);

    ros::Time now;
    while (n.ok())
    {
        tf::Quaternion q;
        tf::Vector3 v;

        try
        {
        geometry_msgs::Pose pose;
        geometry_msgs::PoseArray tip_pose_array;
        
        // For the first segment base
        listener.waitForTransform("/Marker4","/Marker1", now, ros::Duration(1.0));
        listener.lookupTransform("/Marker4","/Marker1",now,transform);
                q.setRPY(0, 0, 0);
        transform.setRotation(q);
        
        br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "Marker4", "module_1_base_marker"));


        listener.waitForTransform("/Marker1","/module_1_base_marker", now, ros::Duration(1.0));
        listener.lookupTransform("/Marker1","/module_1_base_marker",now,transform);
        v=transform.getOrigin();
        q=transform.getRotation();
        
        pose.position.x=v.getX();
        pose.position.y=v.getY();
        pose.position.z=v.getZ();
        pose.orientation.x=q.getX();
        pose.orientation.y=q.getY();
        pose.orientation.z=q.getZ();
        pose.orientation.w=q.getW();
        
        ROS_INFO_STREAM("Marker1 to module_1_base_marker tf (copy this in the right tf in the static tf xml) : " << pose.position.x << " "
                                                                                                                << pose.position.y << " "
                                                                                                                << pose.position.z << " "
                                                                                                                << pose.orientation.x << " "
                                                                                                                << pose.orientation.y << " "
                                                                                                                << pose.orientation.z << " "
                                                                                                                << pose.orientation.w);
        ROS_INFO_STREAM("Marker1 to module_1_base_marker tf: " << pose);
        
        

        // For the first segment tip
        listener.waitForTransform("/module_1_base_marker","/Marker2", now, ros::Duration(1.0));
        listener.lookupTransform("/module_1_base_marker","/Marker2",now,transform);

        q.setRPY(0, 0, 0);
        transform.setRotation(q);
        
        br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "module_1_base_marker", "module_1_tip_marker"));


        listener.waitForTransform("/Marker2","/module_1_tip_marker", now, ros::Duration(1.0));
        listener.lookupTransform("/Marker2","/module_1_tip_marker",now,transform);
        v=transform.getOrigin();
        q=transform.getRotation();
        
        pose.position.x=v.getX();
        pose.position.y=v.getY();
        pose.position.z=v.getZ();
        pose.orientation.x=q.getX();
        pose.orientation.y=q.getY();
        pose.orientation.z=q.getZ();
        pose.orientation.w=q.getW();
        
        ROS_INFO_STREAM("Marker2 to module_1_tip_marker tf (copy this in the right tf in the static tf xml) : " << pose.position.x << " "
                                                                                                                << pose.position.y << " "
                                                                                                                << pose.position.z << " "
                                                                                                                << pose.orientation.x << " "
                                                                                                                << pose.orientation.y << " "
                                                                                                                << pose.orientation.z << " "
                                                                                                                << pose.orientation.w);
        ROS_INFO_STREAM("Marker2 to module_1_tip_marker tf: " << pose);
        
        
        // For the second segment tip
        listener.waitForTransform("/module_1_base_marker","/Marker3", now, ros::Duration(1.0));
        listener.lookupTransform("/module_1_base_marker","/Marker3",now,transform);

        tf::Quaternion q;
        q.setRPY(0, 0, 0);
        transform.setRotation(q);
        
        br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "module_1_base_marker", "module_2_tip_marker"));


        listener.waitForTransform("/Marker3","/module_2_tip_marker", now, ros::Duration(1.0));
        listener.lookupTransform("/Marker3","/module_2_tip_marker",now,transform);
        v=transform.getOrigin();
        q=transform.getRotation();
        
        pose.position.x=v.getX();
        pose.position.y=v.getY();
        pose.position.z=v.getZ();
        pose.orientation.x=q.getX();
        pose.orientation.y=q.getY();
        pose.orientation.z=q.getZ();
        pose.orientation.w=q.getW();
        
        ROS_INFO_STREAM("Marker3 to module_2_tip_marker tf (copy this in the right tf in the static tf xml) : " << pose.position.x << " "
                                                                                                                << pose.position.y << " "
                                                                                                                << pose.position.z << " "
                                                                                                                << pose.orientation.x << " "
                                                                                                                << pose.orientation.y << " "
                                                                                                                << pose.orientation.z << " "
                                                                                                                << pose.orientation.w);
        ROS_INFO_STREAM("Marker3 to module_2_tip_marker tf: " << pose);
        } catch(tf::TransformException ex) {
            ROS_ERROR("%s", ex.what());
        }
    rate.sleep();
    }
}
