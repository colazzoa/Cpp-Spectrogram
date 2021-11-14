#include "ctrlApp.hpp"

ctrlApp::ctrlApp()
{

    rect.x = 0;
    rect.y = 0;
    rect.w = 1;
    rect.h = 1;

    spectrogram = new spectroGram();

    textureBuffer = new Uint32[1024 * 512];
    memset(textureBuffer, 0, sizeof(Uint32));

    draw();

    m_window = SDL_CreateWindow("Spectrogram of italian 'a' vowel sound",
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
    SDL_SetRenderDrawColor(m_window_renderer, 0, 0, 0, 0);

    // Clear the entire screen to our selected color.
    SDL_RenderClear(m_window_renderer);

    Tile = SDL_CreateTexture(m_window_renderer, SDL_PIXELFORMAT_RGBA8888,
                             SDL_TEXTUREACCESS_STREAMING, 1024, 512);

    SDL_SetRenderTarget(m_window_renderer, Tile);
    //SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(m_window_renderer);


}

ctrlApp::~ctrlApp()
{

    SDL_Quit();
    SDL_DestroyTexture(Tile);
    Tile = NULL;
    SDL_DestroyRenderer(m_window_renderer);
    SDL_DestroyWindow(m_window);
    delete[] textureBuffer;
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

        //draw();
        update(1.0 / 60.0);
    }
}

void ctrlApp::update(double delta_time)
{
    SDL_UpdateTexture(Tile, NULL, textureBuffer, 1024 * sizeof(uint32_t));
    SDL_RenderCopy(m_window_renderer, Tile, NULL, NULL);
    SDL_RenderPresent(m_window_renderer);
    //SDL_RenderClear(m_window_renderer);

    x_pos+= 32;

    if (1024 == x_pos)
    {
        x_pos = 0;
        offset++;
    }
}

void ctrlApp::draw()
{

    int nx = 1024;
    int ig,ib,ir,alpha;



    std::vector<std::vector<float>>  local_vect;

    local_vect = spectrogram->get_log_magnitude();
   

    //std::cout << "ib " << ib << std::endl;
    for (int idx = 0; idx < 1024; idx++)
    {
        for (int idx2 = 0; idx2 < WINDOW_SIZE/2; 
        idx2++)
        {
            Colour c = manager.getInterpolatedColour((local_vect[idx][idx2]));
            ir = c.getIntR();
            ig = c.getIntG();
            ib = c.getIntB();
            alpha = c.getAlpha();
            //this->textureBuffer[(idx2 * nx) + (idx)] = 0xFF000000 | (ir << 16) | (ib << 8) | ig;
            this->textureBuffer[(idx2 * nx) + (idx)] = (ir << 24) | (ig << 16) | (ib << 8) | alpha ;
        }
    
    }

     std::cout << "End draw() " << std::endl;
}
