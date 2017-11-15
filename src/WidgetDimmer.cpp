#include "WidgetDimmer.h"


WidgetDimmer::WidgetDimmer(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pCmdSwitchTopic,0,sizeof(pCmdSwitchTopic));
    memset(pDataStatusTopic,0,sizeof(pDataStatusTopic));
    memset(pDataIlluminationTopic,0,sizeof(pDataIlluminationTopic));
    sprintf(pCmdSwitchTopic,"channel/dimmer_%d/cmd/switch",_Item);
    sprintf(pDataStatusTopic,"channel/dimmer_%d/data/status",_Item);
    sprintf(pDataIlluminationTopic,"channel/dimmer_%d/data/illumination",_Item);
}

WidgetDimmer::~WidgetDimmer()
{

}

void WidgetDimmer::begin(void (*UserCallBack)(void))
{
    _EventCb=UserCallBack;
    IntoRobot.subscribe(pCmdSwitchTopic, NULL, this);
}

uint8_t WidgetDimmer::getLightBrightness(void)
{
    return _brightness;
}

void WidgetDimmer::displayLightStatus(uint8_t ucVal)
{
    IntoRobot.publish(pDataStatusTopic,ucVal);
}

void WidgetDimmer::displayIllumination(float ucVal)
{
    IntoRobot.publish(pDataIlluminationTopic,ucVal);
}

void WidgetDimmer::controlLight(uint8_t ucPin, uint8_t ucVal)
{
    pinMode(ucPin,OUTPUT);
    analogWrite(ucPin, ucVal);
    displayLightStatus(ucVal);
}

void WidgetDimmer::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
    SerialUSB.println((char *)payload);
    
    _brightness = payload[0];
    _EventCb();
}

