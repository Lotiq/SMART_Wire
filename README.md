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
    <img src="images/logo.jpg" alt="Logo" width="160" height="160">
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
  * [What Are Shape Memory Wires](#what-are-shape-memory-wires)
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

Shape Memory Alloy Resistance Tracking (S.M.A.R.T.) library for Arduino, which currently uses DPM8600 series power converter to activate NiTi-based wires. This library was made for individuals without an extensive technical background or experience with Shape Memory (SM) materials. This library is made to be versatile and straightforward enough to accomadate many of hobbyists' projects. Additionally, information on the wires, applications and fabrication techniques for SM alloy related projects are given below.

### What Are Shape Memory Wires

Shape Memory wires are regular-looking wires that are made primarily out of Nickel-Titanium alloy in certain compositions that give them properties of essentially performing physical movement upon temperature changes. Those temperature changes and movement types are different for different wire types and brands, with most common brand being Flexinol (more discussions and examples on the [fabrication page][fabrication-page]). These wires can be used to perform different motions, and when attached to other materials can exhibit quite a bit of force on those materials deforming them. Thus, they are sometimes used instead of more common actuators such as motors. That being said, they are not so easy to work with because of the complexities associated with activating those wires electrically. 

By activation, we often refer to heating (or cooling) the wire to a certain transition temperature at which the crystalline structure changes and forces the wire to do something. Although you can heat the wire with hot water or air, it is not often useful and instead we resort to **resistive heating**. [Resistive heating](https://en.wikipedia.org/wiki/Joule_heating) is when the heat is dissipated through I<sup>2</sup>R formula. There are two main parameters here - resistance and current. And while the resistance of the wire  does change around 14% during heating, we can't alter it like we can do current. And for different wires length, sizes, types and environment around them, different amount of current (at different voltage) is required. It is extremely hard to always know exactly how much current you need to activate the wire within say 4 seconds. Therefore, the algorithm in this library runs certain tests to correlate current and time, based on certain resistance versus temperature properties.

All of that being said, however, there are two more obstacles when working with SM wires - fabrication and information. The latter one refers to getting the right information and understanding what your goals and options are and how to meet the two, which is not frequently discussed in most forums about those wires. On the other hand, you also have fabrication which can get very tricky if you are don't know what you are working with. I would **highly encourage** reading through the [Usage](#usage) section of this library and checking out the links, which would provide you with more information to get your project started right.

### Applications and Capabilities

This library can be used for quick and easy prototypes for those who are generally unfamiliar with NiTi-based alloys and how to activate them electronically (see [Community Examples](#community-examples) and [Fabrication Examples][fabrication-page]). It is capable of estimating current versus time relationship for wire activation in a given environment (using I<sup>2</sup> = X/t + Y approximation). Theoretically, this library can work with different wire brands (including, but not limited to Flexinol, Nitinol and BioMetal) of different shapes, length and thicknesses as long as their behaviour is similar to NiTi-based wires. The library relies on and iteratively studies the resistance changes because of the phase transformations (Austenite <-> Martensite), which it uses for estimating the relationship between time and constant current. This library is **not** precise or advanced enough to be used in commercial sector in its current form, however it is being constantly improved. 

The set of functions given in this library can control wire (2-60 Ohm) contraction generally within the range of 1 to 10 seconds. Other functions for more control over the wire are being developed. The library currently uses DPM8600 series power converter as a controllable current source for its ease of use, however this could change in the future.

### Vision

The goal of this project is to create a set of tools (information, breakout boards, electronic setups, libraries etc.) that would be simple and accessible enough for beginners to quickly start using various NiTi wires in their projects, without having to go through extensive research and testing.


<!-- GETTING STARTED -->
## Getting Started

To get started you need to have the equipment and a library described below.

### Prerequisites

* Requires DPM8605, DPM8608 or any other DPM8600 series **TTL** (not RS-485) power converter. Connect Arduino serial to the power converter.
* [DPM8600 power converter][DPM8600-url] library to be installed.

### Installation

1. Clone or Download the repo
    - If downloaded, open the compressed file into a folder
2. Insert the folder into the main Arduino/libraries folder and restart Arduino IDE
3. Add DPM8600 and SMART_Wire libraries into your project

### Quick Setup
Here I want to link a [video](https://vimeo.com/407255823/9682c160d5) of a 4 min quick guide of how to get started with the library. This video is work in progress and will be regularly updated.


## Usage

Using Shape Memory wires could be very easy if you are familiar with both fabrication and library tools. Links below collect and summarise important information in a few key topics.

* [Full documentation](https://github.com/Lotiq/SMART_Wire/blob/master/SMART_Wire.h) of the library's functions
* [Useful information](https://github.com/Lotiq/SMART_Wire/blob/master/information/usefulinfo.md) on NiTi-based alloys and what to know before you buy
* [Fabrication tips, tricks and examples][fabrication-page] on making your own pieces.


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

[fabrication-page]: https://github.com/Lotiq/SMART_Wire/blob/master/information/fabrication.md

[usefulinfo-page]: https://github.com/Lotiq/SMART_Wire/blob/master/information/usefulinfo.md

[DPM8600-url]: https://github.com/Lotiq/DPM8600