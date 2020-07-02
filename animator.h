#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

class Animator {
  public:
    int LEDsPerPanel;
    int numPanels;
    int totalLEDs;
    CRGB panels[numPanels];
    CRGB *leds;
    int panelBrightness[numPanels];

    Animator(int nLedsPerPanel, int nPanels) {
      LEDsPerPanel = nLedsPerPanel;
      numPanels = nPanels;
      totalLEDs = numPanels * LEDsPerPanel;
      leds = new CRGB[totalLEDs];
    }

    //Buildup everything required by fastLED lib
    void startAnimator() {
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, totalLEDs);
    }

    //Updates color and brightness of a panel
    void updatePanelColor(int panel, CHSV color) {
      leds(panel * LEDsPerPanel, panel * LEDsPerPanel + (LEDsPerPanel - 1)) = color;
    }

    //#####  ANIMATIONS  #####

    //Fades towards a bright level
    /*
      void fade(int brightness, int panelNumber, int hue, int sat) {
      if (brightness > panelBrightness[panelNumber]) {
        if  (panelBrightness[panelNumber] < 255) {
          panelBrightness[panelNumber]++;
        }
      }
      else {
        if  (panelBrightness[panelNumber] > 0) {
          panelBrightness[panelNumber]--;
        }
      }
      updatePanelColor(panelNumber, CHSV( hue, sat, panelBrightness[panelNumber]));
      }
      /**/
};
