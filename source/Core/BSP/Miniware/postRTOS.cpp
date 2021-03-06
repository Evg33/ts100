#include "BSP.h"
#include "FreeRTOS.h"
#include "I2C_Wrapper.hpp"
#include "QC3.h"
#include "Settings.h"
#include "cmsis_os.h"
#include "fusbpd.h"
#include "main.hpp"
#include "power.hpp"
#include "stdlib.h"
#include "task.h"

// Initialisation to be performed with scheduler active
void postRToSInit() {
#ifdef POW_PD
  if (usb_pd_detect() == true) {
    // Spawn all of the USB-C processors
    fusb302_start_processing();
  }
#endif
}
