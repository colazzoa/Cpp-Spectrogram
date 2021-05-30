#include "ctrlApp.hpp"

ctrlApp::ctrlApp()
{

    SDL_Init(SDL_INIT_AUDIO);

	// load WAV file

	SDL_AudioSpec wavSpec;


	SDL_LoadWAV("../src/test.wav", &wavSpec, &wavBuffer, &wavLength);
	
	
    std::cout << wavLength << std::endl;

    m_window = SDL_CreateWindow("SDL2 Window",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                680, 480,
                                0);

    if(!m_window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_window_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(!m_window_renderer)
    {
        std::cout << "Failed to get window's surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
}

ctrlApp::~ctrlApp()
{
    SDL_FreeWAV(wavBuffer);
	SDL_Quit();
    SDL_DestroyRenderer(m_window_renderer);
    SDL_DestroyWindow(m_window);
}

void ctrlApp::run()
{
    bool keep_window_open = true;
    while(keep_window_open)
    {
        while(SDL_PollEvent(&m_window_event) > 0)
        {
            switch(m_window_event.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
        }

        update(1.0/60.0);
        draw();
    }
}

void ctrlApp::update(double delta_time)
{

}

void ctrlApp::draw()
{
    SDL_RenderClear(m_window_renderer);

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 10;
    rect.w = 10;
    rect.h = 10;

    SDL_SetRenderDrawColor(m_window_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_window_renderer, &rect);

    SDL_SetRenderDrawColor(m_window_renderer, 0, 0, 0, 255);

    //SDL_RenderPresent(m_window_renderer);


    //SDL_Rect rect;
    rect.x = 0;
    rect.y = 20;
    rect.w = 10;
    rect.h = 10;

    SDL_SetRenderDrawColor(m_window_renderer, 255, 0, 255, 255);
    SDL_RenderFillRect(m_window_renderer, &rect);

    SDL_SetRenderDrawColor(m_window_renderer, 0, 0, 0, 255);

    SDL_RenderPresent(m_window_renderer);
}



