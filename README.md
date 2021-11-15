# CPPND: Capstone Project "Spectrogram"

This is a a repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

This Capstone Project is meant to show mine ability to exploit what I learned throughout Udacity C++ Nanodegree program. A detailed list of the Capstone Project Rubric addressed points is available [here](#rubric-points-addressed).

Since I am keen on signal processing I developed a C++ application wjich generates a graphic spectrogram of the sound of the italian vowel "a". Some theoretical backgrounds and code structure description can be found [here](theoretical-background-and-code-structure).

The output spectrogram is compared with the one provided by a professional software [Audacity](https://www.audacityteam.org/download/).

Currently the application only support a basic spectral analysis of the above-mentioned sound sample, [future plans](#future-plans) will be considering the introduction of new features. Code has been structured to support a potential evolution in the features list of the program.

## Theoretical background and code structure

In speech, the vocal tract resonant frequencies are called formants. We can see them as the peaks in a spectrum. With vowels, the frequencies of the formants determine which vowel you hear and, in general, are responsible for the differences in quality among different periodic sounds. At any one point in time (as with spectra) there may be any number of formants, but for speech the most informative are the first three, appropriately referred to as F1, F2, and F3 [R1].

The formants can be easily identified throuhout a spectrogram of the sound signal. A spectrogram is a visual representation of the spectrum of frequencies of a signal as it varies with time. When applied to an audio signal, spectrograms are sometimes called sonographs, voiceprints, or voicegrams. When the data are represented in a 3D plot they may be called waterfalls. [R2]

In a spectrogram, time is depicted on the x-axis while frequency on the y-axis. Intensity is represented by the relative darkness of the frequencies shown. The formants (resonant frequencies; the loudest) are the darker bands that correspond to the peaks in the spectra [R1].

In my case, the spectrogram of the vowel italian sound "a" obtained by Audacity software is:

![image](https://user-images.githubusercontent.com/45873694/141794316-dc34df43-778f-4d2e-b9c5-1da3c7e09e97.png)

It is possibile to recognize the formants frequencies as the darker bands.

The Spectrogram produced by my C++ application follows:

![image](https://user-images.githubusercontent.com/45873694/141794593-aef224a4-eeeb-4fce-9b0a-acfbd45d30ca.png)

Despite a different colour map is possible to identify the same formants bands into the spectra.

Starting form a file .wav that contains the sound digital samples, to obtain a graphical view of the spectrogram I perfomed the following steps:

1. Load sound signal into memory: I used SDL2 library to perform this operation
2. implement windowing of sound signal to properly select input data for FFT (I implemented an Hann window in C++) 
3. Perform FFT to obtain the spectral analysis of the sound signal (I used [Simple FFT](#open-source-libraries) library properly configured)
4. Calculate log magnitude of frequency domain components (natively implemented in C++)
5. Normalize log magnitude value to obtain data that can be mapped on a colour map
6. Map normalized colour value to a specific colour map (here I exploit the library [Colourmanager](#open-source-libraries))
7. Obtain a graphical representaion of the Spectrogram: here I used SDL2 library and the SDL Texture object.

The above-mentioned algorithm has been implemented in a class structured software. All source code is into the src folder while some of the external libraries are into the lib folder.

![image](https://user-images.githubusercontent.com/45873694/141797256-0d88d49f-29f5-4371-bb77-96c2002f6f30.png)



References:

[R1](http://www.u.arizona.edu/~ohalad/Phonetics/notes/Formants%20Spectrograms%20and%20Vowels.PDF)

[R2](https://en.wikipedia.org/wiki/Spectrogram)
## Rubric Points addressed

README:
1. A README with instructions is included with the project.
2. The README indicates which project has been chosen.

Compiling & Testing:
1. The submission compiles and runs.

Loops, Functions, I/O
1. The project demonstrates an understanding of C++ functions and control structures.
2. The project accepts user input and processes the input.

Object Oriented Programming:
1. The project uses Object Oriented Programming techniques.
2. Classes use appropriate access specifiers for class members.
3. Class constructors utilize member initialization lists.
4. Classes abstract implementation details from their interfaces.
5. Classes encapsulate behavior.
6. Classes follow an appropriate inheritance hierarchy.
7. Derived class functions override virtual base class functions.

Memory Management:
1. The project makes use of references in function declarations.
2. The project uses destructors appropriately.
3. The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
4. The project follows the Rule of 5.
5. The project uses smart pointers instead of raw pointers.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Open source libraries
This program used the following external libraries:
1. SDL
   bla bla bla
2. Simple FFT
3. Colourmanager
   
## Basic Build Instructions
1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./Spectrogram.
   
## Future plans
