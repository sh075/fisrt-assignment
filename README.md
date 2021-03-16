# fisrt-assignment
a pakage for research track course
## Table of Contents
1.General Info 
2.Algorithm
3.Content of Package 
4.How to run the code
## General info
!The assignment is to control a holonomic robot in 2d space with a simple 2d simulator.
## Algorithm
-*1.Set a random target in the interval [-6.0, 6.0]
-*2.Check the distance between target and robot position
-*3.IF distance is larger than 0.1 -> update x,y speed value -> Go to step 2.
-*4.Else -> Go to step 1.
## content of package
## node
15.1.First node: (assignment1)
16.ROS publisher: publishing the robot speed
17.ROS subscriber: subscribe for robot position
18.ROS client: receiving a random target
19.Second node: (project1)
20.ROS server: Service Server replys to the client with a random target
## Costum service
22.Random_Target service: return two random positions between [-6.0, 6.0]
## How to run the code
24.1. After git clone, move repository to /home/
25.2.Add the line 'source /home/my_ros_ws/devel/setup.bash' in your .bashrc file.
26.3.Change the directory to the workspace /home/my_ros_ws/
27.4.Build the packages 'catkin_make'
28.5.Refresh 'rospack profile'
29.6.Run the simulator
30.$ roscore &
31.$ rosrun stage_ros stageros $(rospack find assignment1)/world/exercise.world
32.7.Run the service node
33.$ rosrun project1 project1
34.8.Run the First node
35.$ rosrun assignment1 assignment1
