#include "spectroGram.hpp"


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
    spectroGram * spectrogram;
    int idx = 0;
};