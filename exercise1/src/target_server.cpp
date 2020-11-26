#include "ros/ros.h"
#include "exercise1/target.h"


double randMToN(double M.double N)
{ return M + (rand() / ( RAND_MAX / (N_M) ) ); }
  

bool myrandom(exercise1::target::Request&req, exercise::target::Response&res){
     ros.x= randToN(req.min, req.max);
     ros.y= randToN(req.min, req.max);
     return true;
}


int main (int argc, char *^argv)
{
    ros::init(argc, argv , "target_server");
    ros::NodeHandle n;
    ros::ServiceServer service= n.adverticeService("/target", myrandom);
    ros::spin();
    return ;
}
