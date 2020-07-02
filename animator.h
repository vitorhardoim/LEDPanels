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
    CHSV *panelHSV;
    //int *panelBrightness;

    Animator(int nLedsPerPanel, int nPanels) {
      LEDsPerPanel = nLedsPerPanel;
      numPanels = nPanels;
      totalLEDs = numPanels * LEDsPerPanel;
      leds = new CRGB[totalLEDs];
      panelHSV = new CHSV[numPanels];
      //panelBrightness = new int[numPanels];
    }

    //Buildup everything required by fastLED lib
    void startAnimator() {
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, totalLEDs);
    }

    //Updates color and brightness of a panel
    void updatePanelColor(int panel, CHSV HSV) {
      for(int i = panel * LEDsPerPanel; i < panel * LEDsPerPanel + (LEDsPerPanel - 1); i++ ){
        leds[i] = HSV;
      }
    }

    //#####  ANIMATIONS  #####

    //Fades towards a bright level
      void fade(int panel,int brightness) {
      if (brightness > panelHSV[panel].val) {
        if  (panelHSV[panel].val < 255) {
          panelHSV[panel].val++;
        }
      }
      else {
        if  (panelHSV[panel].val > 0) {
          panelHSV[panel].val--;
        }
      }
      updatePanelColor(panel, panelHSV[panel]);
      }
};
