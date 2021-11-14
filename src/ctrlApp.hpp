#include "spectroGram.hpp"
#include "../lib/colourmanager/colourmanager.h"


class ctrlApp
{
public:
    ctrlApp();
    ~ctrlApp();

    void run();
    void update(double delta_time);
    void draw();
private:
	Uint32 wavLength;
	Uint8 *wavBuffer;
    SDL_Window   *m_window;
    SDL_Renderer *m_window_renderer;
    SDL_Event     m_window_event;
    SDL_Rect rect;
    SDL_Texture *Tile;
    spectroGram * spectrogram;
    int x_pos = 0;
    int y_pos = 0;
    int offset = 0;
    Uint32 *textureBuffer;
    float lowerRange=0;
	float upperRange=100;
	ColourManager manager{0.0,1.0};
};