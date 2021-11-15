#include "spectroGram.hpp"

spectroGram::spectroGram()
{
    //Using SDL library to load.wav file into memory
    SDL_Init(SDL_INIT_AUDIO);

    // load WAV file
    SDL_AudioSpec wavSpec;
    SDL_LoadWAV("../src/a_.wav", &wavSpec, &wavBuffer, &wavLength);

    //Print wav file main features
    std::cout << "Number of samples: " << wavSpec.samples << std::endl;
    std::cout << "Freq: " << wavSpec.freq << " Hz" << std::endl;
    std::cout << "Size [bits]: " << 8 * wavLength << std::endl;

    int num_samples = (8 * wavLength) / (int)SDL_AUDIO_BITSIZE(wavSpec.format);

    //Prepare input and output buffers to store frequency domain processing data
    int16_t *stream16 = (int16_t *)wavBuffer;
    real_type *dataOut = new real_type[WINDOW_SIZE];

    std::vector<float> single_log_magnitude;
    std::vector<float> half_single_log_magnitude(WINDOW_SIZE / 2, 0.0);

    float max_value = 0;

    //FFT Analysis to produce Spectrogram
    for (size_t k = 0; k < num_samples - WINDOW_SIZE; k += 1)
    {
        for (int i = 0; i < WINDOW_SIZE; i++)
        {
            float multiplier = 0.5 * (1.0 - cos(2.0 * PI * (float)i / (WINDOW_SIZE / 2 - 1.0)));
            dataOut[i] = multiplier * (float)stream16[i + k];
        }

        const char *error = NULL; // error description

        auto nt = WINDOW_SIZE;

        typedef complex_type *ComplexArray1D;

        ComplexArray1D out_fft_p = new complex_type[nt];

        //FFT using open source library Simple_FFT
        auto b = simple_fft::FFT(dataOut, out_fft_p, nt, error);

        for (int i = 0; i < WINDOW_SIZE; i++)
        {
            single_log_magnitude.push_back(std::log10(std::sqrt((out_fft_p[i].real() * out_fft_p[i].real()) + (out_fft_p[i].imag() * out_fft_p[i].imag()))));

            if (single_log_magnitude[i] > max_value)
            {
                //searching max value for normalization
                max_value = single_log_magnitude[i];
            }
        }

        //FFT shifting and selection of upper spectrum

        for (int i = 0; i < WINDOW_SIZE / 2; i++)
        {
            float tmp = single_log_magnitude[i];
            single_log_magnitude[i] = single_log_magnitude[i + (WINDOW_SIZE / 2)];
            single_log_magnitude[i + (WINDOW_SIZE / 2)] = tmp;
            half_single_log_magnitude[(WINDOW_SIZE / 2) - 1 - i] = single_log_magnitude[i + (WINDOW_SIZE / 2)];
        }

        log_magnitude.push_back(half_single_log_magnitude);
        single_log_magnitude.clear();
    }

    //Normalization
    for (int k = 0; k < log_magnitude.size(); k++)
    {
        for (int i = 0; i < WINDOW_SIZE / 2; i++)
        {
            log_magnitude[k][i] = (log_magnitude[k][i] / max_value);
        }
    }

    if (SDL_AUDIO_ISFLOAT(wavSpec.format))
    {
        printf("Wav file contains floating point data\n");
    }
    else
    {
        printf("Wav file contains integer data\n");
    }

    printf("%d bits per sample\n", (int)SDL_AUDIO_BITSIZE(wavSpec.format));
}

std::vector<std::vector<float>> spectroGram::get_log_magnitude()
{
    return log_magnitude;
}

spectroGram::~spectroGram()
{
    SDL_FreeWAV(wavBuffer);
}