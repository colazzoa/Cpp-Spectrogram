#include "spectroGram.hpp"
#include "../lib/colourmanager/colourmanager.h"

#define TIME_AXIS_SIZE 1024

class ctrlApp
{
public:
    ctrlApp();
    ~ctrlApp();
    void run();
    void update();
    void draw();
private:
	Uint32 wavLength;
	Uint8 *wavBuffer;
    SDL_Window   *m_window;
    SDL_Renderer *m_window_renderer;
    SDL_Event     m_window_event;
    SDL_Texture *Tile;
    spectroGram * spectrogram;
    Uint32 *textureBuffer;
	ColourManager manager{0.0,1.0};
};