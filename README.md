# CPPND: Capstone Project "Spectrogram"

This is a a repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

This Capstone Project is meant to show mine ability to exploit what I learned throughout Udacity C++ Nanodegree program. A detailed list of the Capstone Project Rubric addressed points is available [here](#rubric-points-addressed).

Since I am keen on signal processing I developed a C++ application wjich generates a graphic spectrogram of the sound of the italian vowel "a". Some theoretical backgrounds and code structure description can be found [here](theoretical-background-and-code-structure).

The output spectrogram is compared with the one provided by a professional software (Audacity).

Currently the application only support a basic spectral analysis of the above-mentioned sound sample, [future plans](#future-plans) will be considering the introduction of new features. Code has been structured to support a potential evolution in the features list of the program.

## Theoretical background and code structure

In speech, the vocal tract resonant frequencies are called formants. We can see them as the peaks in a spectrum. With vowels, the frequencies of the formants determine which vowel you hear and, in general, are responsible for the differences in quality among different periodic sounds. At any one point in time (as with spectra) there may be any number of formants, but for speech the most informative are the first three, appropriately referred to as F1, F2, and F3 [R1].

The formants can be easily identified throuhout a spectrogram of the sound signal. A spectrogram is a visual representation of the spectrum of frequencies of a signal as it varies with time. When applied to an audio signal, spectrograms are sometimes called sonographs, voiceprints, or voicegrams. When the data are represented in a 3D plot they may be called waterfalls. [R2]

In a spectrogram, time is depicted on the x-axis while frequency on the y-axis. Intensity is represented by the relative 
darkness of the frequencies shown. The formants (resonant frequencies; the loudest) are the darker bands that correspond to the 
peaks in the spectra [R1].

In my case, the spectrogram of the vowel italian sound "a" obtained by Audacity software is:







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
