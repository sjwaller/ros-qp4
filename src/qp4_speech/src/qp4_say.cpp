#include "qp4_say.hpp"

Qp4Say::Qp4Say(){
	sub = node.subscribe("say", 1000, &Qp4Say::chatterCallback, this);
	pub = node.advertise<sound_play::SoundRequest>("robotsound", 1000);  
	sleep(1);
	verbalize("QP 4 Speech engine ready ...",1);  

	sleep(4);		
	verbalize("Waiting for your commands ...",1);  
	ROS_INFO("Speech engine ready ...");	
}

void Qp4Say::verbalize(const std::string sentence, unsigned int time)
{
	sound_play::SoundRequest m;
	m.sound = sound_play::SoundRequest::SAY;
	m.command = sound_play::SoundRequest::PLAY_ONCE;
	m.arg = sentence;
	m.volume = 1;
	pub.publish(m);
}
		
void Qp4Say::chatterCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("I heard: [%s]", msg->data.c_str()); 
	verbalize(msg->data.c_str(),1);  
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "qp4_say");
	Qp4Say s;
	ros::spin();
}


