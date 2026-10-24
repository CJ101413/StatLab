#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdbool.h>
#include <math.h>

void Cleanup(TTF_Text * text, TTF_Font * font, SDL_Renderer * renderer, SDL_Window * myWindow);

int ReturnGreaterNumber(int * numbers, int nLen);

bool CheckSDLInit();

bool CheckWindowInit(SDL_Window * myWindow);