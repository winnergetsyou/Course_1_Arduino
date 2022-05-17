//First, include all the required header file
#include<ros.h>
#include<std_msgs/String.h>
#include"Arduino.h"

//create a node handle object
ros::NodeHandle object;


// Defining Subscriber topic name and Subscriber_call_back_function
void subscribe_function(const std_msgs::String& msg_1)
{
  String msg= msg_1.data;
  String top="top";
  if (msg==top)
  {digitalWrite(3,HIGH);}
  if (msg=="bottom")
  {digitalWrite(4,HIGH);}
  if (msg=="left")
  {digitalWrite(5,HIGH);}
  if (msg=="right")
  {digitalWrite(6,HIGH);}
  }
  
ros::Subscriber<std_msgs::String> sub("topic_2", &subscribe_function);


// Defining Publisher topic name and message variables

std_msgs::String msg3_top,msg4_bottom,msg5_right,msg6_left;
ros::Publisher arduino_publish_topic3("arduino_publish_topic3", &msg3_top);
ros::Publisher arduino_publish_topic4("arduino_publish_topic5", &msg4_bottom);
ros::Publisher arduino_publish_topic5("arduino_publish_topic6", &msg5_right);
ros::Publisher arduino_publish_topic6("arduino_publish_topic7", &msg6_left);

void setup() {
  // put your setup code here, to run once: 
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

  object.initNode();
  object.advertise(arduino_publish_topic3);
  object.advertise(arduino_publish_topic4);
  object.advertise(arduino_publish_topic5);
  object.advertise(arduino_publish_topic6);
  object.subscribe(sub);
}

void loop() {
  // put your main code here, to run repeatedly:
  msg3_top.data = digitalRead(3);
  msg4_bottom.data = digitalRead(4);
  msg5_right.data = digitalRead(5);
  msg6_left.data = digitalRead(6);

  arduino_publish_topic3.publish(&msg3_top);
  arduino_publish_topic4.publish(&msg4_bottom);
  arduino_publish_topic5.publish(&msg5_right);
  arduino_publish_topic6.publish(&msg6_left);
  
  object.spinOnce();
  delay(500);
}
