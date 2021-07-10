#include "spectroGram.hpp"

spectroGram::spectroGram()
{

    SDL_Init(SDL_INIT_AUDIO);

    // load WAV file

    SDL_AudioSpec wavSpec;

    SDL_LoadWAV("../src/a_.wav", &wavSpec, &wavBuffer, &wavLength);

    std::cout << "Number of samples: " << wavSpec.samples << std::endl;
    std::cout << "Freq: " << wavSpec.freq << std::endl;
    std::cout << "Channels: " << wavSpec.channels << std::endl;

    std::cout << "Size [bits]: " << 8 * wavLength << std::endl;

    int16_t *stream16 = (int16_t *)wavBuffer;

    //int16_t dataOut[1024];

    real_type *dataOut = new real_type[WINDOW_SIZE];

    for (size_t i = 0; i < (wavLength / 2); i++)
    {
        std::cout << "stream of " << i << " = " << stream16[i] << std::endl;
    }

    for (int i = 0; i < WINDOW_SIZE; i++)
    {
        double multiplier = 0.5 * (1 - cos(2 * PI * i / 1023));
        dataOut[i] = multiplier * stream16[i];
    }

    const char *error = NULL; // error description

    auto nt = WINDOW_SIZE;

    typedef complex_type *ComplexArray1D;

    ComplexArray1D out_fft_p = new complex_type[nt];

    auto b = simple_fft::FFT(dataOut, out_fft_p, nt, error);

    std::vector<float> single_log_magnitude;

    float max_value = 0;

    
    while (0)
    {
        /* code */
    }
 

    for (int i = 0; i < WINDOW_SIZE; i++)
    {
        single_log_magnitude.push_back( std::log10(std::sqrt((out_fft_p[i].real() * out_fft_p[i].real()) + (out_fft_p[i].imag() * out_fft_p[i].imag()))) );
        //std::cout << "magnit" << log_magnitude[i] << std::endl;
        if (single_log_magnitude[i] > max_value)
        {
            max_value = single_log_magnitude[i];
        }
    }

    //Normalization

        for (int i = 0; i < WINDOW_SIZE; i++)
    {
        single_log_magnitude[i] = std::round( (single_log_magnitude[i]/max_value)*255 );
        std::cout << "magnit" << single_log_magnitude[i] << std::endl;
    }



    if (SDL_AUDIO_ISFLOAT(wavSpec.format))
    {
        printf("floating point data\n");
    }
    else
    {
        printf("integer data\n");
    }

    printf("%d bits per sample\n", (int)SDL_AUDIO_BITSIZE(wavSpec.format));

}

std::vector<std::vector<float>> spectroGram::get_log_magnitude()
{
    return log_magnitude;
}