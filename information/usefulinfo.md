## Table of Contents

* [Introduction](#introduction)
    * [Target Audience](#target-audience)
    * [Terminology](#terminology)
* [Shape Memory vs Super Elasticity](#shape-memory-vs-super-elasticity)
* [One Way vs Two Way Memory](#one-way-vs-two-way-memory)
* [SMAs vs Other Actuators](#smas-vs-other-actuators)
* [Manufacturers and Confusion](#manufacturers-and-confusion)
* [Shape Variations](#shape-variations)
* [Wire Training](#wire-training)
* [Advice On Projects](#advice-on-projects)
* [Resources](#resources)

## Introduction

Shape Memory Alloys (SMAs) - are special alloys of metals which exhibit physical changes upon undergoing phase transformations during heating and cooling. The most common and popular alloy type that is used these days is Nickel-Titanium (NiTi for short). There are numerous [manufacturers](#manufacturers-and-confusion) that make such alloys, which because of slight differences in composition and manufacturing techniques result in different end products. Thus, it is important to fully understand what you are looking for and know all the confusing details about such alloys. This page is meant to cover some of the important, but often ignored details and options that you have when selecting Shape Memory Wires.

### Target Audience

This information was written for individuals who want to get started with Shape Memory (SM) wires and incorporate them into their projects or anything that doesn't require advanced knowledge or special composions of SM alloys. Hobbyist, artists and simply those who heard of but never dealt with Nitinol, Flexinol or other types of wires are welcome to read this guide to avoid mistakes and hardship working with SMAs.

### Terminology

* Shape Memory Alloys (SMAs) - a general term for metallic alloys that have a shape memory property.
* Nickel-Titanium (NiTi) - one of the SMAs, which exhibits [shape memory and super elasticity properties](#shape-memory-vs-super-elasticity). ***Not to be confused*** with Nitinol (brand).
* Nitinol (**Ni**ckel **Ti**tanium **N**aval **O**rdnance **L**abratory) - a specific composition that was first discovered in Naval Ordnance Labratory (hence the name). Although often interchangeably used with Nickel-Titanium, Nitinol is product on the market, and is better to be referred to as a brand name.
* Flexinol - another variation of NiTi produced by Dynalloy, which exhibits Two Way memory and acts similar to a muscle. Usually the most popular choice among hobbyists.
* Activation temperature - temperature at which the Shape Memory alloy starts undergoing phase transformation and therefore changing its shape.

## Shape Memory vs Super Elasticity

Shape memory and super elasticity are closely related properties. Think of super elasticity as shape memory being constantly active. No matter what you do the material goes back to original shape, hence the name super elastic, i.e. it doesn't break, but restores the shape. In more rigorous terms, super elasticity is achieved by bringing activation temperature to below the temperature of the environment it is in, so that the environment holds the material activated at all times.

For the purpose of creative projects and actuation of moving components **super elasticity is not a desired property**, and when buying NiTi alloys you should always check that activation temperature is higher than the temperature of the environment it is going to be in. Additionally, the higher the activation temperature relative to the environment the faster the material would cool back to the original phase. Hence, there is a tradeoff where high activation temperature has faster cooling, but also takes more energy to be activated.

## One Way vs Two Way Memory

There are two main types of Shape Memory wires, the ones that exhibit change only when the High Temperature (HT) transformation phase is reached and the ones that perform motion on both High Temperature and Low Temperature (LT) transformations. For instance, Flexinol, is a Two Way Shape Memory (TWSM) wire, because it contracts when heated to a certain temperature and relaxed and extends when cooled. Most available nitinol, however, comes as One Way Shape Memory (OWSM) where it restores its pre-trained shape upon heating, but doesn't go back when cooled. TWSM is usually more expensive and requires complex manufacturing and training techniques, as well as being more sensitive to overheating and can be damaged. Depending on your application you might want to use either OWSM or TWSM, however something to keep in mind is that OWSM requires some sort of mechanisms to restore it back, as it can only change shape in one direction. On the other hand, some of the One Way wires (most of commercially available Nitinol) can be [trained](#wire-training) to unique shapes.

## SMAs vs Other Actuators

Another imporant topic for discussion is when should and shouldn't use SMAs. quite simply, if you can get away with other actuators such as pulleys, motors or other - I would recommend using them, as SMAs are not as reliable when not used under extremely precise and monitored conditions.

In bullet-point form I would summarize it as such:

You should use SMAs if:

* You are constrained in physical space
* You want to achieve organic motion
* You need quiet motion

You also **have to** keep this in mind when using SMAs
* You are fine with the wire heating the surroundings to high temperatures
* The wire is electrically ensulated and is not shorting itself
* It might take time to fabricate the pieces that involve the wires

In **ANY** other situation, I would recommend **against** working with SMAs, and use motors, pulleys or something else.


## Manufacturers and Confusion

There are numerous manufacturers of NiTi SMAs and they don't do a great job explaining the differences of their product to others. Among popular products are Nitinol, Flexinol and BioMetal. Although they all based of NiTi alloy, their characteristics are different because of differences in training and composition. And although some might say they are all the same, this is only partially true, as each of them still has a unique property. Thus, it is important to decide which wires to select for your project. 

Generally, most hobbyists use Flexinol wires, as they have clear instructions on how to be used and examples of people using them for flapping wings, smocking fabric, and making artificial plants. Alternatively, some use Nitinol wires and train them for specific shapes, however this is less common. BioMetal wires are much less common among tinkerers due to higher price range and high-precision applications. 

## Shape Variations

There are different shapes and sizes of SMAs. Some of the most common shapes are helical springs and plain straight wires. Other, less known are torsion and flat springs. For beginners I would recommend using helical springs or straight wires, as both are quite common and easy to get.

The diameter of the wire matters a lot. As in most electronics applications such wires are activated through resistive heating and resistance of the wire depends a lot on the thickness with thinner wires being more resistive and usually requiring higher voltage power supply. Thicker wires, on the other hand have very small resistance, and therefore usually require a lot more current at lower voltage for the same length. Flexinol wires are one of the type which are supplied with a datasheet which includes recommended current.Therefore, they are easier to get started with, although [SMART_Wire library](https://github.com/Lotiq/SMART_Wire) can deduce the required current for almost any NiTi wire.

## Wire Training

Flexinol wires come pre-trained and overheating those wires might reduce their SM properties. This is usually true for most TWSM wires - they come pre-trained and are easier to damage by overheating. On the other hand, OWSM wires don't necessarily come pre-trained. In some cases you can get raw Nitinol which doesn't have a particular shape, but rather whatever shape it was extruded in. In some cases you might need to re-train their remembered shape. Most NiTi wires are trained in a 510C (950F) environment (note: **this is not activation temperature**, but rather training temperature which is much higher) and need to be fixed in place while being trained, as they would exhibit superelastic property mentioned earlier and try to change their shape, when the environment is hotter than the activation temperature. The necessary time for the wire to heat up depends on wire thickness, with thinner wires needing about 30s - 1min and thicker ones up to 20 mins. After this part is finished, the wire should be quenched (cold water could be used). 

Although training could be performed with a help of blowtorch and plyers, the uneven heating of the wire can create spot overheating and permanently damage remove SM properties. Small kilns are a great option as they provide uniform heating and the temperature could be regulated. In order to fix the wire in place several techniques could be used. First, wire could be casted into [mould of sand and plaster](https://www.youtube.com/watch?v=V9quSyg8oj4&t=1s) that could be dried out and crushed after. Alternatively, a perforated sheet of high temperature resistance material can be used with screws to pin down the wire at required places.

## Advice On Projects

For most beginner projects 0.008" or 0.005" Flexinol wires would be sufficient. Both of those wire thicknesses have decent pulling properties, while at the same time having good resistivity for most power supplies to be relatively easily be activated over a length of 5-100cm. Additionally, those wires are not super thin, so crimping wouldn't be as difficult as with thinner wires. As for crimping, you would probably want to get different crimps, ideally only slightly bigger than both the SM wire and regular electric wire to crimp them together. The topic of crimping and everthing else related to fabrication is covered more thoroughly in fabrication page.

Additionally, in case you need a custom piece or train wire to certain specification and would like to outsource the work I would recommend contacting [Kellogg Research Labs](https://www.kelloggsresearchlabs.com). I am not affiliated with Kellogg Research Labs but stayed in close touch and used their services for some of my tests.

The final remark is that I would recommend against training of wires before you get comfortable enough understanding all the key concepts. 

## Resources

1. [Muscle Wires Book](https://www.amazon.com/Muscle-Wires-Project-Book-3-133/dp/1879896133) - a useful, although a little outdated resource of Flexinol-based projects and information on SM wires.
2. [Dynalloy](https://www.dynalloy.com/index.php) - Flexinol manufacturer
3. [Robotshop](https://www.robotshop.com/en/catalogsearch/result/?q=flexinol&order=relevance&dir=desc) - Flexinol seller in the US