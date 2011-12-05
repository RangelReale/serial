#include <string>
#include <iostream>

#include "serial.h"

inline void readDataCallback(std::string readData) {
    std::cerr << "Serial: Read " << readData.length() << " bytes." << " > " << readData << std::endl;
}

int main(int argc, char **argv)
{
    if(argc < 2) {
        std::cerr << "Usage: test_serial <serial port address>" << std::endl;
        return 0;
    }
    std::string port(argv[1]);
    
    serial::Serial serial(port, 115200, 250);
    
    std::cout << "Is the serial port open?";
    if(serial.isOpen())
        std::cout << " Yes." << std::endl;
    else
        std::cout << " No." << std::endl;
    
    // set up serial port for continuous reading
    serial.setReadCallback(readDataCallback);
    //serial.setTimeoutMilliseconds(2000);
    //std::cout << serial.getTimeoutMilliseconds()<<std::endl;
    serial.startContinuousRead(20);

    int count = 0;
    while ((count >= 0)&&(count<20)) {
        int bytes_wrote = serial.write("Testing.");
        boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
        count++;
        std::cout << "count: " << count << std::endl;
    }

    serial.stopContinuousRead();
    serial.close();

    return 0;
}
