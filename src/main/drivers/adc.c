#include <stdbool.h>
#include <stdint.h>

#include "platform.h"
#include "system.h"

#include "accgyro.h"

#include "adc.h"

adc_config_t adcConfig[ADC_CHANNEL_COUNT];
volatile uint16_t adcValues[ADC_CHANNEL_COUNT];

extern int16_t debug[4];

uint16_t adcGetChannel(uint8_t channel)
{
#if 1
    if (adcConfig[0].enabled) {
        debug[0] = adcValues[adcConfig[0].dmaIndex];
    }
    if (adcConfig[1].enabled) {
        debug[1] = adcValues[adcConfig[1].dmaIndex];
    }
    if (adcConfig[2].enabled) {
        debug[2] = adcValues[adcConfig[2].dmaIndex];
    }
    if (adcConfig[3].enabled) {
        debug[3] = adcValues[adcConfig[3].dmaIndex];
    }
#endif
    return adcValues[adcConfig[channel].dmaIndex];
}
