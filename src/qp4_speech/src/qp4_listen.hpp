#ifndef QP4_LISTEN_HPP_
#define QP4_LISTEN_HPP_

#include <ros/ros.h>
#include <ros/package.h>
#include <std_msgs/String.h>
#include <qp4_msgs/RobotCommand.h>
#include <qp4_msgs/ModeCommand.h>
#include <qp4_msgs/QuestionCommand.h>

#include <stdio.h>      /* puts */
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */


class Qp4Listen {
	public:
		Qp4Listen();

	private:
		ros::NodeHandle node;
		ros::Subscriber sub;
		ros::Publisher pub;

		void publishCommand(const std::string str);
		void chatterCallback(const std_msgs::String::ConstPtr& msg);
};


#endif /* QP4_LISTEN_HPP_ */
