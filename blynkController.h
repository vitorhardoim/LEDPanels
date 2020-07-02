BLYNK_WRITE(V1)   //Escolhe o painel painel
{
  numero = param.asInt() - 2;
}

BLYNK_WRITE(V2) // Brilho
{
  blynkBright = param.asInt();
}

BLYNK_WRITE(V3)   //Cor RGB
{
  r = param[0].asInt();
  g = param[1].asInt();
  b = param[2].asInt();

  cor = rgb2hsv_approximate(CRGB(r, g, b));
}

BLYNK_WRITE(V4)  //on  - off
{
  onButton = param.asInt();
  if (onButton) {
    startingSequence = 1;
  }
}

BLYNK_WRITE(V5) // velocidade
{
  velocidade = param.asInt();
}
