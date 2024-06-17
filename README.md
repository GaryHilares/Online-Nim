<h1 align="center">Online Nim</h1>

<p align="center">
  <img alt="badge-lastcommit" src="https://img.shields.io/github/last-commit/GaryHilares/Online-Nim?style=for-the-badge">
  <img alt="badge-openissues" src="https://img.shields.io/github/issues-raw/GaryHilares/Online-Nim?style=for-the-badge">
  <img alt="badge-license" src="https://img.shields.io/github/license/GaryHilares/Online-Nim?style=for-the-badge">
  <img alt="badge-contributors" src="https://img.shields.io/github/contributors/GaryHilares/Online-Nim?style=for-the-badge">
  <img alt="badge-codesize" src="https://img.shields.io/github/languages/code-size/GaryHilares/Online-Nim?style=for-the-badge">
</p>

## Useful links
- [Project's Style Guide (Webkit)](https://webkit.org/code-style-guidelines/)

## What is Online Nim?
Online Nim is an online version of Nim.

### Platforms
- Cross-platform

### Dependencies
#### Development
- SFML
- GoogleTest
- CMake

## Installation and usage
To build and install Supple Crystal from source you must follow the next steps:
1. Prepare the external libraries:
   1. Get SFML 2.5.1.
        - You can look at how to get SFML [here](https://www.sfml-dev.org/tutorials/2.5/).
   2. Order the external libraries:
        1. Create a folder called `extlibs` in the root folder.
        2. Add the external libraries here. The minimal `extlibs` folder should look like this:
           ```
           | extlibs/
           |--- SFML-2.5.1/
           |------- bin/
           |------- include/
           |------- lib/
           ```
2. Build Online-Nim:
   1. Fork the repository on GitHub.
   2. Go to your fork of the repository and copy the link to clone your repository.
   3. Go to Git on your local machine and use the command `git clone (your link)`.
   4. Use CMake to generate makefiles from `CMakelists.txt`.
   5. Use the generated makefiles to build Online Nim.

After doing this, Online Nim should appear inside a folder in `build/`.

You can also install a precompiled version of Supple Crystal that comes ready to use. 

## Contributors
<p align="center"><a href="https://github.com/GaryStriving/Supple-Crystal/graphs/contributors"><img src="https://contrib.rocks/image?repo=GaryStriving/Supple-Crystal" /></a></p>

## License
This work is licensed under a [Creative Commons Attribution 4.0 International License](https://github.com/GaryHilares/Online-Nim/blob/main/LICENSE).

