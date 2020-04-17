# SMART_Wire

<!-- PROJECT SHIELDS -->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


<!-- PROJECT LOGO -->

<br />
<p align="center">
  <a href="https://github.com/Lotiq/SMART_Wire">
    <img src="images/logo.jpg" alt="Logo" width="100" height="100">
  </a>

  <h3 align="center">SMART_Wire</h3>

  <p align="center">
   Use Shape Memory wires with ease!
    <br />
    <a href="https://github.com/Lotiq/SMART_Wire"><strong>Explore the docs »</strong></a>
   <br />
    <br />
    <a href="https://github.com/Lotiq/SMART_Wire">View Demo</a>
    ·
    <a href="https://github.com/Lotiq/SMART_Wire/issues">Report Bug</a>
    ·
    <a href="https://github.com/Lotiq/SMART_Wire/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Applications and Capabilities](#applications-and-capabilities)
  * [Vision](#vision)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
  * [Quick Start](#quick-start)
* [Usage](#usage)
* [Community Examples](#community-examples)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Contact](#contact)
* [Acknowledgements](#acknowledgements)



<!-- ABOUT THE PROJECT -->
## About The Project

Shape Memory Alloy Resistance Tracking (S.M.A.R.T.) library for Arduino, which currently uses DPM8600 series power converter to activate NiTi-based wires. This library was made for individuals without an extensive technical background or experience with Shape Memory materials. This library is made to be versatile and straightforward enough to accomadate many of hobbyists' projects. Additionally, information on the wires, applications and fabrication techniques for SMA-based projects are given below.


### Applications and Capabilities

This library can be used for quick and easy prototypes for those who are generally unfamiliar with NiTi-based alloys and how to activate them electronically (see [Community Examples](##community-examples)). It is capable of estimating current versus time relationship for wire activation in a given environment. Theoretically, this library can work with different wire brands (including, but not limited to Flexinol, Nitinol and BioMetal) of different shapes, length and thicknesses as long as their behaviour is similar to NiTi-based wires. The library relies on and iteratively studies the resistance changes because of the phase transformations (Austenite <-> Martensite), which it uses for estimating the relationship between time and constant current. This library is **not** precise or advanced enough to be used in commercial sector in its current form, however it is being constantly improved. 

The set of functions given in this library can control wire (2-60 Ohm) contraction generally within the range of 1 to 10 seconds. Other functions for more control over the wire are work in progress. The library currently uses DPM8600 series power converter as a controllable current source and ease of use, however this could change in the future.

### Vision

The goal of this project is to create a set of tools (information, breakout boards, electronic setups, libraries etc.) that would be simple and accessible enough for beginners to start using various NiTi wires in their projects, without having to learn much about how those wires work.


<!-- GETTING STARTED -->
## Getting Started

To get started you need to have the equipment and a library described below.

### Prerequisites

* Requires DPM8605, DPM8608 or any other DPM8600 series **TTL** (not RS-485) power converter. Connect Arduino serial to the power converter.
* [DPM8600 power converter](https://github.com/Lotiq/DPM8600) library to be installed.

### Installation

1. Clone or Download the repo
    - If downloaded, open the compressed file into a folder
2. Insert the folder into the main Arduino/libraries folder
3. Add DPM8600 and SMART_Wire libraries into your project

### Quick Setup
Here I want to link a [video](https://vimeo.com/407255823/9682c160d5) of a 4 min quick guide of how to get started with the library. This video is work in progress and will be regularly updated


## Usage

Using Shape Memory wires could be very easy if you are familiar with both fabrication and library tools. Links below collect and summarise important information in a few key topics.

* [Full documentation](https://github.com/Lotiq/SMART_Wire/blob/master/SMART_Wire.h) of the library's functions
* [Useful information](https://github.com/Lotiq/SMART_Wire/blob/master/information/usefulinfo.md) on NiTi-based alloys and what to know before you buy
* [Fabrication tips & tricks](https://github.com/Lotiq/SMART_Wire/blob/master/information/fabrication.md) on making your own pieces.


<!-- USAGE EXAMPLES -->
## Community Examples

Please contact me if you wish to add to add your S.M.A.R.T. Wire project to the list


<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/Lotiq/SMART_Wire/issues) for a list of proposed features (and known issues).


<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Timothy Lobiak - [linked-in](http://linkedin.com/in/timothy-lobiak-045792151) - timothylobiak@gmail.com


<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements
* [Best README Template](https://github.com/othneildrew/Best-README-Template)
* [Dequin Sun](https://github.com/DeqingSun)





<!-- MARKDOWN LINKS & IMAGES -->
[contributors-shield]: https://img.shields.io/github/contributors/Lotiq/SMART_Wire.svg?style=flat-square
[contributors-url]: https://github.com/Lotiq/SMART_Wire/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Lotiq/SMART_Wire.svg?style=flat-square
[forks-url]: https://github.com/Lotiq/SMART_Wire/network/members
[stars-shield]: https://img.shields.io/github/stars/Lotiq/SMART_Wire.svg?style=flat-square
[stars-url]: https://github.com/Lotiq/SMART_Wire/stargazers
[issues-shield]: https://img.shields.io/github/issues/Lotiq/SMART_Wire.svg?style=flat-square
[issues-url]: https://github.com/Lotiq/SMART_Wire/issues
[license-shield]: https://img.shields.io/github/license/Lotiq/SMART_Wire.svg?style=flat-square
[license-url]: https://github.com/Lotiq/SMART_Wire/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/timothy-lobiak-045792151