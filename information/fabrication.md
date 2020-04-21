<!-- These guide will eventually be moved from github -->

## Table of Contents

* [Introduction](#introduction)
    * [How It Works](#how-it-works)
* [Electrical Connections](#electrical-connections)
    * [Crimping](#crimping)
    * [Soldering](#soldering)
    * [Screwing](#screwing)
    * [Other Methods and Concluding Remarks](#other-methods-and-concluding-remarks)
* [Fabrication](#material-selection)
    * [Sewing](#sewing)
    * [Pre-tensioning](#pre-tensioning)
    * [Silicon Encasing](#silicon-encasing)
    * [Overuse and Stretching](#overuse-and-stretching)
* [Step-By-Step Guide](#step-by-step-guide)
* [Examples](#examples)
* [Resources](#resources)

## Introduction

Fabrication of Shape Memory wires into functional components is one of the most important parts when working with the wires, probably even more important than electronics. This guide will attempt at explaining some of the basics of working with NiTi wires (mostly Flexinol) and information that you should keep in mind. I will try to share some of my own experience as well as the information I found.

Before we get started I would recommend reading [useful information](https://github.com/Lotiq/SMART_Wire/blob/master/information/usefulinfo.md) about Shape Memory wires.

### How It Works

It is good practice to understand what we want to achieve when working with Shape Memory wires. In most cases we use Shape Memory wires to have create some movement, whether it is contraction, curling or change of shape. 

When working with springs we are primarily interested in contraction and folding, thus springs are most commonly used with soft fabrics. 

When working with straight Flexinol wires (also called *muscle wires*), which contract only 3-5% upon heating, we usually want to amplify this motion. This is generally achieved through attaching it to the material and putting the wire in tension. After the wire is heated, it will contract, pull on the sharp turns and curl the whole piece of material in some shape. In that case, it is important to [pre-tension](#pre-tensioning) the material to maximize the motion. 

Finally, when working with most Nitinol wires, they restore their shape when being heated. There are less applications of these wires, but they can be attached to dimensional shapes that can be damaged and returned back to the original shape.

Regardless of which wire you want to use for whichever application, the guide below covers some of the common information that you might find useful.

## Electrical Connections

Solid electrical connectiions are essential for actuating Shape Memory wires with current. If the connection is unstable or loose it will break as well as possibly damage the wire. Poor connections also increase point resistances creating spot heating. Thus, to avoid poor connections check wire's connection with a multimeter at all times. Good connections should measure very little resistance change when being moved around. 

There are 3 main methods for creating good connections:

* Crimping
* Soldering
* Screwing

There are also other  methods that are **not ideal** for electrically connecting to shape memory wire and I will later explain why:

* Copper tape
* Soldering splices

### Crimping

Crimping is a common way to electrically connect shape memory wire to a plain electrical wire. Crimping beads come in many shapes and sizes (including some of the ones I use on the image below)

![Crimping Bead Examples Image](https://github.com/Lotiq/SMART_Wire/blob/master/images/crimps.jpg)

Crimping can be very effective when done correctly. The best practice is to loop back the wire through the crimp to ensure good connection. Additionally, it is recommended to use an electrical wire which is of similar diameter to a shape memory wire, or at least comparable, because it would be harder to crimp thin and thick wires together. Although you can find different advice on crimping, these are my tips:

* Always make sure that the crimps you use are conductive and don't have coating
* Crimp using flat plyers as this way you don't damage the crimp
* Longer crimping beads are better as they provide a line of contact rather than a point, which ensures better connection
* Try to crimp SM wires with wires which are of comparable thicknesses, as they would be easier to crimp together.

If you want to find a great range of crimping beads in New York, check [Tohoshoji](http://www.tohoshoji-ny.com/hometop.html).

### Soldering 

Even before discussing the advantages and disadvantages of soldering on NiTi wires, it is important to know that most NiTi wires form a titanium oxide layer on the surface, and this layer prevents the flow of solder. Although you could use highly acidic flux to dissolve this layer to solder I don't consider this a cheap or safe by any means. The two alternatives that I found are soldering on the crimp and electroplating the wire before soldering onto it. Personally, almost every Flexinol piece that I made had been soldered on crimping beads. A lot of the manufacturers of SMAs and other sources recommend against soldering on the wires. When soldering, the temperatures on the tip of the soldering iron reach high enough temperatures to reduce or completely eliminate some of the properties of SMAs. This is particularly true for Two Way Shape Memory discussed in [useful information](https://github.com/Lotiq/SMART_Wire/blob/master/information/usefulinfo.md) about SMAs. As most common brand of NiTi alloys among hobbyists is Flexinol, and it has Two Way Shape Memory, some people recommend against soldering on it. As I mentioned before I do solder on the crimp almost all of my pieces. This method provides quick and solid connection, and if done properly is unlikely to overheat the Shape Memory wire. The main trick is to solder at **lower temperatures** and do it relatively **quick**. The other problem with soldering, however, is that because the wire expanding a little in diameter when heated (as all materials do) it eventually pushes the solder and slips out, so the longetivity of this method is lower than screwing. Crimping also helps against that, providing a secondary connection in case soldering fails. Overall, I would say this is the best DIY method to electrically connect to a Shape Memory wire.

### Screwing

Screwing is an another alternative that is most recommended in the literature, because it provides great solid cold connections. The two best options for screwing are using screw terminals or just pinning the wire down to the surface with a screw. The issue is that for smaller pieces such methods are cumbersome, take space and make the piece more rigid. However, for super thin wires, screwing could be the best option as soldering or crimping those wires would be practically impossible or useless.

### Other Methods and Concluding Remarks

Other methods which are not so great for Shape Memory wires include using copper tape and soldering splices. The problem with copper tape is that it is prone to tearing and wear and will rip off the surface you are attaching it to, or simply not provide good enough connection. Solder splice connectors could work, however it is hard to find such small sizes that would clamp on the wires well, and also the heat gun used to shrink the splice could create spot overheating inside of the wire, which is detrimental to its performance.

In conclusion, if you goal is reliability and longetivity, as well as if you are working with expensive wires, i would recommend trying screw terminals to connect to Shape Memory wires. However, if you are using it for a quick prototype or something that doesn't have to last 1000+ cycles, I would recommend crimping plus soldering. 

## Fabrication

Now that you know about electrical connection it is time to make your own piece. This part will explain the details of putting everything together.

### Material Selection

A very important topic of fabrication is the selection of material that your wire would be attached to. Generally, most wires including Flexinol and Nitinol regardless of their Two Way or One Way properties still need some force to pull them back. For that matter, ideal materials for the use with Shape Memory wires are those with springback properties, therefore you can commonly see people using paper or thin plastic which straightens up after being curled. 

Something to also keep in mind when selecting the materials - poor heat conductivity could be a problem when some types of plastics might melt over time when in contact with the materials that reach 90C and higher temperatures.

### Sewing

Attaching the wire closely to the material is important to ensure that it delivers maximum tension or range of movement. When working with Flexinol, making sure that it stays close to the material is key, as with only 3-5% of contraction, you would want to maximize that change in length.

The most common way of attaching is stitching. It could either be done with hand or using a sewing machine. Using the machine would save you time, however something to keep in mind is that you don't want the stitches to be too tight, as it would not let the wire move during the contraction. Additionally the distance between stitches doesn't have to be short, as remember, the main goal is just to have the wire stay close to the surface. At the sharp turns however, where the stress will be concentrated you might want to have stitches being closer to each other and tighter.

### Pre-tensioning

An extremely important step in fabricating the wires is pre-tensioning. This is important for Shape Memory wires that have muscle-like properties. The idea is to heat the wire and then fix it in place under that stress so that it has an inside force that keeps it in tension, so every little change in length will be greatly amplified.

To do this you need to heat the wire electrically. I would highly recommend against using a heatgun as it would not create uniform heating and is more likely to melt even heat resistance materials. Thus, it is better to activate the wire using current. Once activated, you can fix the wire in place by both ends. Fixing the wire can be performed using special crimps, glue gun or any other method as long as it holds the ends in place when the force of the wire tries to pull it apart.

### Silicon Encasing

Something you may want to do and something I generally was interested is encasing the whole piece in silicon. This could be done, although there are some rules you should follow. First, if you use stitches, it is vital that silicon doesn't attach to stitches so putting a thin layer of paper ot taping the stiches before encasing in silicon would give the wire a room to move. Additionally, when encasing in silicon you have to account for its added rigidity and to get a noticable contraction it is important that the piece contracts quite a bit even before silicon encasing.

### Overuse and Stretching

An important thing to keep in mind when working with SM wires is that although they have this SM property, they are not completely impossible to damage. By overstreching springs or bending into sharp corners regular straight SM wires you are most likely to **eliminate** SM property of that part altogether. 

## Step-By-Step Guide

Here in this step-by-step tutorial I will present and example of how you might want to make your own NiTi piece. I am using a Nitinol spring that has Two-Way memory, however any flexinol piece would be equally great:

### Step 0: Test your wire

Get a piece of fabric and weave the wire through the material and test it

![Spring Wire Test](https://github.com/Lotiq/SMART_Wire/blob/master/images/spring_test.jpg)

Here I overstreched a piece of wire to see how much can I stretch it before it loses its properties, so I know the approximate length I should work with. When working with straight wires you are less likely see much change, so you can omit this step, especially if you know wire properties already.

### Step 1: Attach to Surface

In this case I simply had to weave the wire through the fabric. In general, I realized that weaving a spring is hard without it twisting on itself or streching (and therefore damaging) the wire. In case of straight muscle wires, they need to be sewed onto the surface so that they stay close to the surface and deform it more when being activated.

### Step 2: Connect to Electrical Wires

Although this step can be reversed with Step 1 which might be easier for straight Flexinol wires, I couldn't do it with a spring. For electrical connection I went with soldering a small thin solid wire with 24 AWG stranded wire. This way I could then crimp the thin wire with the spring like so:

![Crimping Spring](https://github.com/Lotiq/SMART_Wire/blob/master/images/crimping_spring)

Note that I haven't used any solder in this example, as the connection seemed to be quite solid even without it.

### Step 3: Testing Connection & Pre-tensioning

The first thing you want to do is test the circuit with a multimeter for quality of the connection. If everything is fine and you are working with straight muscle wires, you might want to pre-tension them before fixing in place. For that you need to activate the wire and put it in tension once it was fully activated. Then, you need to fix the wire in place by either using glue gun or if you have a special crimp with a surface mount you can use that too. 

In case of the spring and fabric, no attaching to the surface is required since the crimp would prevent the wire from slipping.

## Examples

In this section I will be giving examples of various work and motions done using SMA by me and other people and breaking down the upsides and downsides of their techniques as well as showing the results.

### Transparent Leaf

![Transparent Leaf Image](https://github.com/Lotiq/SMART_Wire/blob/master/images/transparent_leaf.jpg)

This is one of the first and most proud of prototypes that I've made with [0.008" HT](https://www.robotshop.com/en/dynalloy-flexinol-008-ht-actuator-wire.html) Flexinol wire and a piece of transparent plastic that has great heat dissipation. The wire was hand-stitched to the material, which took quite a bit of time and I would normally recommend sewing machine instead. Flexinol was connected to a regular electric wire using a foldable crimp and solder. This type of crimps also have a hole which allowed for the needle to come through and sewed to the plastic, therefore taking very little space and being very sturdy. A video of the actuation is presented [here](https://vimeo.com/394957325). The wire was pre-tensioned quite well so that the range of movement is substantial.

### Folding Fabric
![Folding Fabric Image](https://github.com/Lotiq/SMART_Wire/blob/master/images//folding_fabric.jpg)

This was the latest prototype in which I wanted to experiment with SM springs. In this case I was using some proprietary wire, which didn't have any documentation, but had a Two Way Shape Memory, and extended quite a bit upon cooling. In your project, you could use any Flexinol wire instead. I have woven the wire into a piece of fabric, which turned out to be quite a challenge, as the wire would resist being rotated and it damaged quite a bit of wire because of overstreching. That being said, for future tests I would recommend crimping pieces together instead of trying to weave one piece through the fabric. Additionally, for this example I soldered thin wires to a regular 24AWG stranded wire which made the piece very flexible, while at the same time making it very easy to crimp with super tiny crimps without using any solder on them! Although I couldn't achieve a nice pattern as in [this example](#fabric-smocking), I was quite happy with what I achieved with the limited resources available. Here is a [video](https://vimeo.com/409905256) of actuation.

### Curling Tongue

![Curling Tongue Image](https://github.com/Lotiq/SMART_Wire/blob/master/images/curling_tongue.jpg)

This was of the first pieces that I made and was meant to be a quick functional prototype. The base material was cardboard, which turned out to be too rigid for the size. I also used what I recommended against - copper tape. This being said however, I still crimped the wire and soldered the crimp to the tape. I used looping back of the crimp which gives a sturdier connection. The original video can be found [here](https://vimeo.com/393475111).

I also practiced silicon encasing on this piece. After a few failed attempt I finally got very subtle movement presented [here](https://vimeo.com/396539259/f6b77e321f). The combination of silicon and cardboard turned out to be too sturdy and once I passed too much current to move it further, the piece snapped with solder coming off the copper tape. 

### Flapping Bird

Another great [example](http://highlowtech.org/?p=1448) by Jie Qi, which also goes step-by-step teaching how to make one yourself. I believe it is a great tutorial, but again, I have my doubts about solder on copper tape.

### Twisting Fabric

An interesting [example](https://vimeo.com/38043960) of Nitinol use for creating a twisting motion in fabric. I'm not entirely sure whether this motion is achieved through training Nitinol to a certain shape or something else, but it is still a great example.

### Fabric Smocking

Fabric smocking is also another interesting motion that can be done with SMAs. This particular [example](https://www.kobakant.at/DIY/?p=5276&fbclid=IwAR1e0WhZvmwoGbv198lMeYgVkWH3aSJB9Q_yohHjpdkoDIMQ3xBr8CIt414) seems to use Nitinol spring that contracts quite a bit creating this nice looking pattern out of fabric. The issue, as can be seen on video, is that there is no mechanism to stretch it back to the original flat shape. 







