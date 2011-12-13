#include <iostream>
#include <fstream>
#include "pcl/io/pcd_io.h"
#include "pcl/point_types.h"

int main (int argc, char** argv)
{
    std::string infile_name, outfile_name;
    std::ofstream output_file;
    sensor_msgs::PointCloud2 cloud_blob;
    pcl::PointCloud<pcl::PointXYZ> cloud;
    
    if (argc != 3){
        std::cout << "Must specify infile and outfile names" << std::endl;
        return (-1);
    }
    infile_name = argv[1];
    outfile_name = argv[2];
    
    std::cout << "Reading from: " << infile_name << std::endl << "Writing to: " << outfile_name << std::endl;
    
    if (pcl::io::loadPCDFile (infile_name, cloud_blob) == -1)
        {
        std::cerr << "Couldn't read file: " << std::endl;
        return (-1);
        }
    std::cout << "Loaded " << cloud_blob.width * cloud_blob.height << " data points from "<< infile_name << " with the following fields: " << pcl::getFieldsList (cloud_blob) << std::endl;

    // Convert to the templated message type
    pcl::fromROSMsg (cloud_blob, cloud);

    // write to file
    output_file.open(outfile_name.c_str());
    if (output_file.is_open()) { 
        for (size_t i = 0; i < cloud.points.size (); ++i) {
            output_file << cloud.points[i].x << " " << cloud.points[i].y << " " << cloud.points[i].z << "\n";
        }
        output_file.close();
    } else {
        std::cerr << "Unable to open file for output: " << outfile_name << std::endl;
    }
    return (0);
}
