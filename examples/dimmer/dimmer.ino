/*
************************************************************************
* 作者:  IntoRobot Team    
* 版本:  V1.0.0
* 日期:  03-30-15
************************************************************************
功能描述：
平台下发亮度等级，终端可通过PWM调节灯泡亮度

所需器件:
1、MOS驱动模块
2、LED灯泡

*/

/*该头文件引用由IntoRobot自动添加.*/
#include <WidgetDimmer.h>

WidgetDimmer dimmer;

void DimmerCb(void)
{
    //用PWM引脚，调节PWM的占空比即可调节灯泡亮度
    dimmer.controlLight(A0,(uint8_t)(dimmer.getLightBrightness()*255/10));
}

void setup() 
{
// put your setup code here, to run once.
    dimmer.begin(DimmerCb);
}

void loop() 
{
// put your main code here, to run repeatedly.
    dimmer.displayIllumination(100); //上送光照强度值
    delay(2000);
}
