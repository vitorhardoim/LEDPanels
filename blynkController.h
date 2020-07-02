#include <BlynkSimpleEsp8266.h>

class BlynkController{
  public:
    int panel;
    int brightness;
    CHSV HSV;
    int startButton;
    int speedVar;

    BLYNK_WRITE(V1)   //Escolhe o painel painel
    {
      panel = param.asInt() - 2;
    }
    
    BLYNK_WRITE(V2) // Brilho
    {
      brightness = param.asInt();
    }
    
    BLYNK_WRITE(V3)   //Cor RGB
    {
      HSV = rgb2hsv_approximate(CRGB(param[0].asInt(), param[1].asInt(), param[2].asInt()));
    }
    
    BLYNK_WRITE(V4)  //on  - off
    {
      startButton = param.asInt();
    }

    BLYNK_WRITE(V5) // velocidade
    {
      speedVar = param.asInt();
    }
};
