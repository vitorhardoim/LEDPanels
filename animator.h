#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

class Animator {
  public:
    int LEDsPerPanel;
    int numPanels;
    int totalLEDs;
    //CRGB panels[numPanels];
    CRGB *leds;
    int *panelBrightness;

    Animator(int nLedsPerPanel, int nPanels) {
      LEDsPerPanel = nLedsPerPanel;
      numPanels = nPanels;
      totalLEDs = numPanels * LEDsPerPanel;
      leds = new CRGB[totalLEDs];
      panelBrightness = new int[numPanels];
    }

    //Buildup everything required by fastLED lib
    void startAnimator() {
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, totalLEDs);
    }

    //Updates color and brightness of a panel
    void updatePanelColor(int panel, int r = -1, int g = -1, int b = -1) {
      for(int i = panel * LEDsPerPanel; i < panel * LEDsPerPanel + (LEDsPerPanel - 1); i++ ){
       if(r != -1){
        leds[i].setRGB(r,g,b);
       }
       leds[i].fadeLightBy(panelBrightness[panel]);
      }
    }

    //#####  ANIMATIONS  #####

    //Fades towards a bright level
      void fade(int brightness, int panel) {
      if (brightness > panelBrightness[panel]) {
        if  (panelBrightness[panel] < 255) {
          panelBrightness[panel]++;
        }
      }
      else {
        if  (panelBrightness[panel] > 0) {
          panelBrightness[panel]--;
        }
      }
      updatePanelColor(panel);
      }
};
