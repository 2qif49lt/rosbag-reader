#include "bag_rdr.hpp"
#include <numeric>
#include <cstdio>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

#include <sensor_msgs/CompressedImage.h>


int main(int argc, char** argv)
{
	bag_rdr bag;
	bool bret = bag.open("e:\\camera1.bag");
	std::cout << "bret " << bret << std::endl;
	uint32_t c = 0;

	for (bag_rdr::message msg : bag.get_view().with_topics({ "/camera1/surround_view_cam/image_raw/compressed" })) {
		sensor_msgs::CompressedImage image;

		if (msg.to(image)) {
			std::cout << msg.topic().data() << " " << msg.stamp.secs << "." << msg.stamp.nsecs << " " << image.format << " " << ++c << std::endl;
			std::stringstream ss;
			ss << msg.stamp.secs << "." << msg.stamp.nsecs << ".jpg";

			std::fstream fs(ss.str(), std::ios_base::binary | std::ios_base::trunc | std::ios_base::out);
			fs.write((char*)image.data.data(), image.data.size());

		}
		else
			std::cout << msg.stamp.to_double() << " " << msg.topic().data() << " " << msg.md5.data() << std::endl;

	}

	return 0;
}

