#ifndef QP4_SAY_HPP_
#define QP4_SAY_HPP_

#include <ros/ros.h>
#include "ros/package.h"
#include <std_msgs/String.h>

#include <iostream>

#include <sound_play/sound_play.h>

class Qp4Say {
	public:
		Qp4Say();

	private:
		ros::NodeHandle node;
		ros::Subscriber sub;
		ros::Subscriber cmd;
		ros::Subscriber mode;
		ros::Subscriber qry;
		ros::Publisher pub;

		void verbalize(const std::string sentence, unsigned int time);
		void chatterCallback(const std_msgs::String::ConstPtr& msg);
};


#endif /* QP4_SAY_HPP_ */
