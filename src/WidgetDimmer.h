#ifndef WIDGET_DIMMER_H_
#define WIDGET_DIMMER_H_

#include "application.h"

class WidgetDimmer : public WidgetBaseClass
{
    public:
        WidgetDimmer(uint8_t ucItem = 0);
        ~WidgetDimmer();
        void begin(void (*UserCallBack)(void) = NULL);
        uint8_t getLightBrightness(void);
        void displayLightStatus(uint8_t ucVal);
        void displayIllumination(float ucVal);
        void controlLight(uint8_t ucPin, uint8_t ucVal);

    private:
        char pCmdSwitchTopic[64];
        char pDataStatusTopic[64];
        char pDataIlluminationTopic[64];
        uint8_t _brightness = 0;
        uint8_t _Item = 0;

        void (*_EventCb)(void);
        void widgetBaseCallBack(uint8_t *payload, uint32_t len);
};

#endif
