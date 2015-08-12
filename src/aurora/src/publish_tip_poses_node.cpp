#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>
#include "geometry_msgs/PoseArray.h"

/// This node publishes the tip poses considering that we have 3 markers on a 2 segment robot.
/// Markers are placed in the rigid parts: base of seg 1, tip of seg 1, tip of seg 2
int main (int argc, char** argv)

{
    ros::init(argc,argv,"publish_tip_poses");

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

        // using module_base instead of the Marker4, as currently Marker4 is not exactly placed at the segment base.
        listener.waitForTransform("/module_1_base","/module_1_tip", now, ros::Duration(1.0));
        listener.lookupTransform("/module_1_base","/module_1_tip",now,transform);
        // Average translation and rotation for both markers
        v=transform.getOrigin();
        q=transform.getRotation();
        
        pose.position.x=v.getX();
        pose.position.y=v.getY();
        pose.position.z=v.getZ();
        pose.orientation.x=q.getX();
        pose.orientation.y=q.getY();
        pose.orientation.z=q.getZ();
        pose.orientation.w=q.getW();
        module_tip_pub.publish(pose);

        //Add the pose to the pose array
        tip_pose_array.poses.push_back(pose);

        // using module_base instead of the Marker4, as currently Marker4 is not exactly placed at the segment base.
        listener.waitForTransform("/module_2_base","/module_2_tip", now, ros::Duration(1.0));
        listener.lookupTransform("/module_2_base","/module_2_tip",now,transform);
        v=transform.getOrigin();
        q=transform.getRotation();

        pose.position.x=v.getX();
        pose.position.y=v.getY();
        pose.position.z=v.getZ();
        pose.orientation.x=q.getX();
        pose.orientation.y=q.getY();
        pose.orientation.z=q.getZ();
        pose.orientation.w=q.getW();
        module_tip_pub_2.publish(pose);
        ROS_DEBUG("Publish tip_2 pose");

        //Add the pose to the pose array
        tip_pose_array.poses.push_back(pose);

        // Publish the pose array
        tip_array_pub.publish(tip_pose_array);

        } catch(tf::TransformException ex) {
            ROS_ERROR("%s", ex.what());
        }
    rate.sleep();
    }
}
