

#include "IMU_I2C.h"
#include <unistd.h>
#include "UBX_UART.h"

int main() {
    // IMU_I2C deviceIMU;
    // while(1)
    // {
    //   usleep(10000);
    //   deviceIMU.print_Data();
    // }
    
    GNSS G;
    G.SetupNTRIP();
    G.FindPORT();
    G.OpenUART(115200);
    G.Run();

    return 0;
}


