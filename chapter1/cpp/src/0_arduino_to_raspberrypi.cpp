#include <libserial/SerialPort.h>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <unistd.h>

constexpr const char* const SERIAL_PORT_1 = "/dev/ttyACM0" ;


int main()
{
    using namespace LibSerial ;
    SerialPort serial_port ;

    try {
        serial_port.Open(SERIAL_PORT_1) ;
    }
    catch (const OpenFailed&){
        std::cerr << "The serial port did not open correctly." << std::endl ;
        return EXIT_FAILURE ;
    }
    serial_port.SetBaudRate(BaudRate::BAUD_115200) ;
    serial_port.SetCharacterSize(CharacterSize::CHAR_SIZE_8) ;
    serial_port.SetFlowControl(FlowControl::FLOW_CONTROL_NONE) ;
    serial_port.SetParity(Parity::PARITY_NONE) ;
    serial_port.SetStopBits(StopBits::STOP_BITS_1) ;
    while(!serial_port.IsDataAvailable()) {
        usleep(1000) ;
    }

    // Specify a timeout value (in milliseconds).
    size_t ms_timeout = 1000 ;
    while(true){

        std::string message;
        try{
            serial_port.ReadLine(message);
            std::cout <<"RETRUN FROM ARDUINO:"<< message << std::flush ;
        }
        catch (const ReadTimeout&)
        {
            std::cerr << "\nThe ReadByte() call has timed out." << std::endl ;
        }
    }

    // // Wait a brief period for more data to arrive.
    usleep(1000) ;

    // Successful program completion.
    std::cout << "The example program successfully completed!" << std::endl ;
    return EXIT_SUCCESS ;
}