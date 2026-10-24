#include "utils.h"

void Cleanup(TTF_Text * text, TTF_Font * font, SDL_Renderer * renderer, SDL_Window * myWindow)
{
    TTF_DestroyText(text);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(myWindow);
    SDL_Quit();
}

int ReturnGreaterNumber(int * numbers, int nLen)
{
    int greaterNumber = *numbers;

    for (int i = 0; i < nLen; i++)
    {
        if(*(numbers + i) > greaterNumber)
        {
            greaterNumber = *(numbers + i);
        }
    }
    
    return greaterNumber;
}

bool CheckSDLInit()
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}

bool CheckWindowInit(SDL_Window * myWindow)
{
    if (myWindow == NULL) {
            printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
            SDL_Quit();
            return 1;
        }

    return 0;
}