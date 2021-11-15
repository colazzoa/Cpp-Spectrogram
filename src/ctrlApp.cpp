#include "ctrlApp.hpp"

/* Class constructor*/
ctrlApp::ctrlApp()
{
    //creat spectrogram object: wav file is loaded and processed
    spectrogram = new spectroGram();

    textureBuffer = new Uint32[TIME_AXIS_SIZE * (WINDOW_SIZE / 2)];
    memset(textureBuffer, 0, sizeof(Uint32));

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

    // Select the color for drawing. It is set to black here.
    SDL_SetRenderDrawColor(m_window_renderer, 0, 0, 0, 0);

    // Clear the entire screen to our selected color.
    SDL_RenderClear(m_window_renderer);

    Tile = SDL_CreateTexture(m_window_renderer, SDL_PIXELFORMAT_RGBA8888,
                             SDL_TEXTUREACCESS_STREAMING, TIME_AXIS_SIZE, (WINDOW_SIZE / 2));

    SDL_SetRenderTarget(m_window_renderer, Tile);

    SDL_RenderClear(m_window_renderer);
}

/*Class Destructor*/
ctrlApp::~ctrlApp()
{

    SDL_Quit();
    SDL_DestroyTexture(Tile);
    Tile = NULL;
    SDL_DestroyRenderer(m_window_renderer);
    SDL_DestroyWindow(m_window);
    delete[] textureBuffer;
}

/*Keep window opened till quit signal is received*/
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
        update();
    }
}

/* Update SDL texture and render to the screen */
void ctrlApp::update()
{
    SDL_UpdateTexture(Tile, NULL, textureBuffer, TIME_AXIS_SIZE * sizeof(uint32_t));
    SDL_RenderCopy(m_window_renderer, Tile, NULL, NULL);
    SDL_RenderPresent(m_window_renderer);
}

/* Setting each pixel in textureBuffer with proper log magnitude value */
void ctrlApp::draw()
{
    std::vector<std::vector<float>> local_log_magnitude;

    local_log_magnitude = spectrogram->get_log_magnitude();

    int ir, ib, ig, alpha;
    for (int time_idx = 0; time_idx < TIME_AXIS_SIZE; time_idx++)
    {
        for (int freq_idx = 0; freq_idx < WINDOW_SIZE / 2; freq_idx++)
        {
            Colour c = manager.getInterpolatedColour((local_log_magnitude[time_idx][freq_idx]));
            ir = c.getIntR();
            ig = c.getIntG();
            ib = c.getIntB();
            alpha = c.getAlpha();
            this->textureBuffer[(freq_idx * TIME_AXIS_SIZE) + (time_idx)] = (ir << 24) | (ig << 16) | (ib << 8) | alpha;
        }
    }
}
