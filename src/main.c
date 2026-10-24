#include "utils.h"
#define SCREEN_SIDE 720

const int horizontal_x1 = (SCREEN_SIDE / 2) - (SCREEN_SIDE / 4);
const int horizontal_x2 = (SCREEN_SIDE / 2) + (SCREEN_SIDE / 4);
const int horizontal_Len = (horizontal_x2) - (horizontal_x1);
const int vertical_y1 = (SCREEN_SIDE / 2) - (SCREEN_SIDE / 4);
const int vertical_y2 = (SCREEN_SIDE / 2) + (SCREEN_SIDE / 4);
const float vertical_Len = (vertical_y2) - (vertical_y1);

int main(void)
{
    CheckSDLInit();
    TTF_Init();

    SDL_Window *myWindow = SDL_CreateWindow("Bar Diagram", SCREEN_SIDE, SCREEN_SIDE, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(myWindow, NULL);
    TTF_TextEngine * engine = TTF_CreateRendererTextEngine(renderer);
    TTF_Font * font = TTF_OpenFont("/home/joshua/Documents/Customization/Inter,Roboto/Roboto/Roboto-Italic-VariableFont_wdth,wght.ttf", 24);
    TTF_Text * text = TTF_CreateText(engine, font, "Pokemon",7);

    CheckWindowInit(myWindow);

    char * classes[] = {"Gen1", "Gen2", "Gen3", "Gen4", "Gen5", "Gen6"};
    int pokemonCount[] = {151, 100, 135, 107, 156, 72};
    int classCount = sizeof(pokemonCount) / 4;

    int greaterNum = ReturnGreaterNumber(pokemonCount, sizeof(pokemonCount) / 4);
    int barWidth = round(horizontal_Len / classCount);
    int barSpace = (int)(barWidth * 0.2);
    int initialSpace = 0;
    float unit = vertical_Len / greaterNum;

    printf("%d\n", classCount);

    bool running = true;
    while (running) {
        SDL_RenderPresent(renderer);
        SDL_Event event;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderLine(
            renderer,
            horizontal_x1,
            (SCREEN_SIDE / 2) + (SCREEN_SIDE / 4),
            horizontal_x2 + (barSpace * classCount),
            (SCREEN_SIDE / 2) + (SCREEN_SIDE / 4)
        );

        SDL_RenderLine(
            renderer,
            (SCREEN_SIDE / 2) - (SCREEN_SIDE / 4),
            vertical_y1,
            (SCREEN_SIDE / 2) - (SCREEN_SIDE / 4),
            vertical_y2
        );

        for (int item = 0; item < classCount; item++)
        {
            if(item == 0)
                initialSpace = barSpace;

            int totalSpace = (item * (barWidth + barSpace));
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_FRect rect = {(horizontal_x1 + totalSpace + initialSpace), (horizontal_x2), barWidth, (-(pokemonCount[item] * unit))};
            SDL_RenderFillRect(renderer, &rect);
        }
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        SDL_Delay(16);
    }

    Cleanup(text, font, renderer, myWindow);
    return 0;
}
