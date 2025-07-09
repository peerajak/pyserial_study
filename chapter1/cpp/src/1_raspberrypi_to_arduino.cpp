#include <libserial/SerialPort.h>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

constexpr const char* const SERIAL_PORT_2 = "/dev/ttyACM0" ;

/**
 * @brief This example reads the contents of a file and writes the entire 
 *        file to the serial port one character at a time. To use this
 *        example, simply utilize TestFile.txt or another file of your
 *        choosing as a command line argument.
 */
int main(int argc, char** argv)
{   
    using namespace LibSerial ;
    SerialPort serial_port ;

    try
    {
        // Open the Serial Port at the desired hardware port.
        serial_port.Open(SERIAL_PORT_2) ;
    }
    catch (const OpenFailed&)
    {
        std::cerr << "The serial port did not open correctly." << std::endl ;
        return EXIT_FAILURE ;
    }

    serial_port.SetBaudRate(BaudRate::BAUD_115200) ;
    serial_port.SetCharacterSize(CharacterSize::CHAR_SIZE_8) ;
    serial_port.SetFlowControl(FlowControl::FLOW_CONTROL_NONE) ;
    serial_port.SetParity(Parity::PARITY_NONE) ;
    serial_port.SetStopBits(StopBits::STOP_BITS_1) ;

    // Read characters from the input file and write them to the serial port. 
    std::cout << "Writing to the serial port." << std::endl ;
    
    while (true) 
    {
        std::string s("rasp cpp string\n");
        std::stringstream message_stream;
        message_stream << s;
        try{
            serial_port.Write(message_stream.str());
            std::cout<<"WRITING TO ARDUINO:"<<message_stream.str();
        }
        catch (...){
            std::cerr<< "Something went wrong while sending the message "
                                    << message_stream.str() << " to the port " << SERIAL_PORT_2;
            return 1;
        }


        sleep(1);
    }

    // Successful program completion.
    std::cout << "The example program successfully completed!" << std::endl ;
    return 0 ;
}