#include "qp4_listen.hpp"

Qp4Listen::Qp4Listen(){
	sub = node.subscribe("recognizer/output", 10, &Qp4Listen::chatterCallback, this);
	pub = node.advertise<std_msgs::String>("say", 10);
	sleep(1);
	
	ROS_INFO("Listening for commands ...");	
}
	

void Qp4Listen::publishCommand(const std::string str)
{
	std_msgs::String msg;
	msg.data = str;
	pub.publish(msg);
	sleep(5);
}

void Qp4Listen::chatterCallback(const std_msgs::String::ConstPtr& msg)
{

	if (msg->data == qp4_msgs::RobotCommand::START_LISTENING)
	{
		publishCommand("Listening for commands");
	}	
	else if (msg->data == qp4_msgs::RobotCommand::STOP_LISTENING)
	{
		publishCommand("I've finished listening");
	}
 	else if (msg->data == qp4_msgs::RobotCommand::GO_TO_SLEEP)
	{
		publishCommand("Time to go to sleep");
	}
 	else if (msg->data == qp4_msgs::RobotCommand::WAKE_UP)
	{
		publishCommand("I've finished listening");
	}
	else if (msg->data == qp4_msgs::RobotCommand::MOVE_FORWARD)
	{
		publishCommand("I'm moving forward");
	}
	else if (msg->data == qp4_msgs::RobotCommand::MOVE_BACKWORD)
	{
		publishCommand("I'm moving backward");
	}
	else if (msg->data == qp4_msgs::RobotCommand::MOVE_LEFT)
	{
		publishCommand("I'm moving left");
	}
	else if (msg->data == qp4_msgs::RobotCommand::MOVE_RIGHT)
	{
		publishCommand("I'm moving right");
	}
	else if (msg->data == qp4_msgs::RobotCommand::TURN_LEFT)
	{
		publishCommand("About to turn left");
	}
	else if (msg->data == qp4_msgs::RobotCommand::TURN_RIGHT)
	{
		publishCommand("About to turn right");
	}
	else if (msg->data == qp4_msgs::RobotCommand::MOVE_FASTER)
	{
		publishCommand("I'm moving faster");
	}
	else if (msg->data == qp4_msgs::RobotCommand::SPEED_UP)
	{
		publishCommand("I'm speeding up");
	}
	else if (msg->data == qp4_msgs::RobotCommand::MOVE_SLOWER)
	{
		publishCommand("I'm moving slower");
	}
	else if (msg->data == qp4_msgs::RobotCommand::SLOW_DOWN)
	{
		publishCommand("I'm slowing down");
	}
	else if (msg->data == qp4_msgs::RobotCommand::QUARTER_SPEED)
	{
		publishCommand("Setting motors to quarter speed");
	}
	else if (msg->data == qp4_msgs::RobotCommand::HALF_SPEED)
	{
		publishCommand("Setting motors to half speed");
	}
	else if (msg->data == qp4_msgs::RobotCommand::FULL_SPEED)
	{
		publishCommand("Setting motors to full speed");
	}
	else if (msg->data == qp4_msgs::RobotCommand::CANCEL)
	{
		publishCommand("Cancelling current action");
	}
	else if (msg->data == qp4_msgs::RobotCommand::STOP)
	{
		publishCommand("Stop command acknowledged");
	}
	else if (msg->data == qp4_msgs::RobotCommand::ABORT)
	{
		publishCommand("Aborting");
	}
	else if (msg->data == qp4_msgs::RobotCommand::PANIC)
	{
		publishCommand("Remember ... Life is ten percent what you experience and ninety percent how you respond to it");
	}
	else if (msg->data == qp4_msgs::RobotCommand::HELP)
	{
		int r = 1 + (rand() % (int)(6 - 1 + 1));
		switch(r)
	    {
			case 1:
				publishCommand("Be true to yourself.");
				break;
			case 2:	
				publishCommand("Help others.");
				break;
			case 3:		
				publishCommand("Build a shelter against a rainy day.");
				break;
			case 4:
				publishCommand("Make each day a masterpiece.");
				break;
			case 5:	
				publishCommand("Drink deeply from good books.");
				break;
			case 6:		
				publishCommand("Make friendship a fine art. Build a shelter against a rainy day.");
				break;
		}
	}
	else if (msg->data == qp4_msgs::RobotCommand::TURN_OFF)
	{
		publishCommand("Switching all systems off. Goodbye");
	}
	else if (msg->data == qp4_msgs::RobotCommand::SHUT_DOWN)
	{
		publishCommand("Shutting all systems down");
	}
	else if (msg->data == qp4_msgs::ModeCommand::AUTONOMOUS)
	{
		publishCommand("Switching to autonomous mode. Watch out!");
	}
	else if (msg->data == qp4_msgs::ModeCommand::DEMO)
	{
		publishCommand("I will now perform a demonstration of my abilities. I hope you like it!");
	}
	else if (msg->data == qp4_msgs::QuestionCommand::WHAT_NAME)
	{
		publishCommand("My name is QP 4.");
	}
	else if (msg->data == qp4_msgs::QuestionCommand::WHAT_SPECS)
	{
		publishCommand("I am built using Lynx Motion brackets and High tech HS 645 servo motors.");
		publishCommand("My brain is controlled by an oh droid computer.");
		publishCommand("I have two gigabytes of memory.");
		publishCommand("I run the ROS operating system.");
	}
	else if (msg->data == qp4_msgs::QuestionCommand::HOW_OLD)
	{
		publishCommand("I am still a baby. In fact, I am not even sure that is correct?");
	}
	else if (msg->data == qp4_msgs::QuestionCommand::WHAT_TIME)
	{
		time_t rawtime;
		struct tm * timeinfo;
		char buffer [80];
		time (&rawtime);
		timeinfo = localtime (&rawtime);
		strftime (buffer,80,"The time is %I:%M%p.",timeinfo);
		publishCommand(buffer);
	}
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "qp4_listen");
	Qp4Listen l;
	ros::spin();
}


