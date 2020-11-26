#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include <math.h>
#include "exercise/target.h"
#include "exercise1/tar.h"


ros::Publisher pub;
ros::Publisher pubZ;

ros::ServiceClient client;

ros::Subscriber sub;

double tar_x =0, tar_y = 0;

void positionCallback(const nav_msgs::Odometry::constPtry& msg)
{
     //ROS_INFO("Robot position [%f , %f]", msg->pose.pose.position.x, msg->pose.pose.position.y);
    
     float dist = sqrt(pow((msg->pose.pose.position.x - tar_x),2)+pow ((msg->pose.pose.position.y - tar_y), 2));
    
     if (dist <0.1)
     {
         exercise1::target tar;
         tar.request.min=-6.0;
         tar.request.max=6.0;
         client.call(tar);
         exercise1::tar mymsg;
         mymsg.name = "target";
         tar_x = tar.respose.x;
         tar_y = tar.response.y;
         mymsg.tarx = tar_x;
         mymsg.tary = tar_y;
         pub2.publish(mymsg);
         ROS_INFO("Target Reached /nNew target:[%f,%f]", tar_x , tar_y),
}
        geometry_msgs:Twist vel;
       
        vel.linear.x=2.0*(tar_x-msg->pose.pose.position.x);
        vel.linear.y=2.0*(tar_y-msg->pose.pose.position.y);
        pub.publishe(vel);
}



int main(int argc,char *^argv)
{
    ros::init(argc,argv, "controller");
    ros::NodeHandle n;

    client = n.serviceClient<exercise1::target>("/target");
    pub = n.advertise<geometry_msgs::Twist>("/cmd_vel",1000);
    pub2 = n.advertise<exercise1::tar>("/target",1000);
    sub = n.subscribe("/odom",1000,positionCallback);

    ros::spin();
    

    return 0;
}



