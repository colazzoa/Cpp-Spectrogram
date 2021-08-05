#include "ctrlApp.hpp"



ctrlApp::ctrlApp()
{

    rect.x = 0;
    rect.y = 0;
    rect.w = 1;
    rect.h = 1;

    spectrogram = new spectroGram();

    m_window = SDL_CreateWindow("SDL2 Window",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                1024, 512,
                                0);

    if (!m_window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_window_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!m_window_renderer)
    {
        std::cout << "Failed to get window's surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

            // Select the color for drawing. It is set to red here.
        SDL_SetRenderDrawColor(m_window_renderer, 255, 255, 255, 255);

        // Clear the entire screen to our selected color.
        SDL_RenderClear(m_window_renderer);
}

ctrlApp::~ctrlApp()
{
    
    SDL_Quit();
    SDL_DestroyRenderer(m_window_renderer);
    SDL_DestroyWindow(m_window);
}

void ctrlApp::run()
{
    bool keep_window_open = true;
    while (keep_window_open)
    {
        while (SDL_PollEvent(&m_window_event) > 0)
        {
            switch (m_window_event.type)
            {
            case SDL_QUIT:
                keep_window_open = false;
                break;
            }
        }

        draw();
        update(1.0 / 60.0);

    }
}

void ctrlApp::update(double delta_time)
{
    idx++;
    //std::cout << "idx " << idx << std::endl;
    rect.y++;
    if (idx == 512)
    {
        idx = 0;
        rect.y = 0;
        idx2++;
        rect.x+=1;
        //SDL_RenderPresent(m_window_renderer);
    }
}

void ctrlApp::draw()
{
    

    
    SDL_SetRenderDrawColor(m_window_renderer, 0, spectrogram->get_log_magnitude()[idx2][idx], 0,0);
    SDL_RenderFillRect(m_window_renderer, &rect);
    
    SDL_RenderPresent(m_window_renderer);
    //SDL_RenderClear(m_window_renderer);
    
/*
 if (idx2 == ( spectrogram->get_log_magnitude().size() - 1 ))
    {
         //SDL_RenderPresent(m_window_renderer);
         return true;

    }
*/

    
}
