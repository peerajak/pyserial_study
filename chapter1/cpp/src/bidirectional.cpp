/**
 *  @example serial_port_read.cpp
 */

#include <libserial/SerialPort.h>

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <unistd.h>

constexpr const char* const SERIAL_PORT_1 = "/dev/ttyACM0" ;

/**
 * @brief This example demonstrates configuring a serial port and 
 *        reading serial data.
 */
int main(int argc, char** argv)
{
    using namespace LibSerial ;

    // Instantiate a SerialPort object.

    if (argc < 2)
    {
        // Error message to the user.
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl ;

        // Exit the program if no input file argument has been given.
        return 1 ;
    }

    // Open the input file for reading. 

    std::ifstream input_file(argv[1]);

    // Determine if the input file argument is valid to read data from.
    if (!input_file.good()) 
    {
        std::cerr << "Error: Could not open file "
                  << argv[1] << " for reading." << std::endl ;
        return 1 ;
    }
    SerialPort serial_port ;
    try
    {
        // Open the Serial Port at the desired hardware port.
        serial_port.Open(SERIAL_PORT_1) ;
    }
    catch (const OpenFailed&)
    {
        std::cerr << "The serial port did not open correctly." << std::endl ;
        return EXIT_FAILURE ;
    }

    // Set the baud rate of the serial port.
    serial_port.SetBaudRate(BaudRate::BAUD_115200) ;

    // Set the number of data bits.
    //serial_port.SetCharacterSize(CharacterSize::CHAR_SIZE_8) ;

    // Turn off hardware flow control.
    //serial_port.SetFlowControl(FlowControl::FLOW_CONTROL_NONE) ;

    // Disable parity.
    //serial_port.SetParity(Parity::PARITY_NONE) ;
    
    // Set the number of stop bits.
    //serial_port.SetStopBits(StopBits::STOP_BITS_1) ;
    

    std::cout<<"Serial Ok"<<std::endl;

    size_t ms_timeout = 5000 ;
    while(true){
        std::string message = "from raspberry pi C++.";
        serial_port.Write(message) ;
        // while (input_file){        
        //     char data_byte;      
        //     input_file.read(&data_byte, 1) ;
        //     serial_port.WriteByte(data_byte) ;
        //     serial_port.DrainWriteBuffer() ;
        //     std::cout << data_byte ;
        // }
        // Wait for data to be available at the serial port.
        // while(!serial_port.IsDataAvailable()) 
        // {
        //     usleep(1000) ;
        // }
        while(true){     
            char data_byte;
            try{              
                serial_port.ReadByte(data_byte, ms_timeout) ;
                std::cout << data_byte << std::flush ;
            }
            catch (const ReadTimeout&){
                std::cerr << "\nThe ReadByte() call has timed out." << std::endl ;
            }
        }
    }

    // Successful program completion.
    std::cout << "The example program successfully completed!" << std::endl ;
    return EXIT_SUCCESS ;
}