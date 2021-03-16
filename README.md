# fisrt-assignment
a pakage for research track course
## Table of Contents
- 1.General Info 
- 2.Algorithm
- 3.Content of Package 
- 4.How to run the code
## General info
The assignment is to control a holonomic robot in 2d space with a simple 2d simulator.
## Algorithm
-  Set a random target in the interval [-6.0, 6.0]
-  Check the distance between target and robot position
-  IF distance is larger than 0.1 -> update x,y speed value -> Go to step 2.
-  Else -> Go to step 1.
## content of package
## node
First node: (assignment1)
```
ROS publisher: publishing the robot speed
```
ROS client: receiving a random target
```
Second node: (project1)
```
ROS server: Service Server replys to the client with a random target
## Costum service
Random_Target service: return two random positions between [-6.0, 6.0]
## How to run the code
```
After git clone, move repository to /home/
```
Add the line 'source /home/my_ros_ws/devel/setup.bash' in your .bashrc file.
```
Change the directory to the workspace /home/my_ros_ws/
```
Build the packages 'catkin_make'
```
Refresh 'rospack profile'
```
Run the simulator
```
$ roscore &
```
$ rosrun stage_ros stageros $(rospack find assignment1)/world/exercise.world
```
Run the service node
```
$ rosrun project1 project1
```
Run the First node
```
$ rosrun assignment1 assignment1
