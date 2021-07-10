#include <SDL.h>
#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include "../lib/simple_fft/fft_settings.h"
#include "../lib/simple_fft/fft.h"

#define PI 3.14

#define WINDOW_SIZE 512

class spectroGram
{
public:
    spectroGram();
    ~spectroGram();
    std::vector<std::vector<float>> get_log_magnitude();
    //void run();
    
private:
	Uint32 wavLength;
	Uint8 *wavBuffer;
    std::vector<std::vector<float>> log_magnitude;
    
};



