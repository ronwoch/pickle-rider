# pickle-rider
An attempt at an abstraction library for the Velleman 8048 PIC Programmer and experiment board.

## Inspiration 

I like telling a yarn, so if you wake up on your keyboard, skip to the TLDR; to read about the actual library.

# TLDR; - 
Frustrated by the amount of confusion and brain sweat I went through to understand how to make blinky lights; I wrote some Arduino-like (sort of) 
abstractions into a header file. This is meant specifically for the Velleman P8048 PIC Programmer kit, that you assemble yourself. Probably not THAT useful, but 
kinda fun, and not bad for being 12 hours into this project. Almost certainly useless to anyone using any other programmer, as this is mostly to address the built
in buttons and LED's. 


Also - learning markdown in VIM - so any weird line-breaks are to keep my lines from becoming massive paragraphs.

## So there I was...

In my basement, working on some of the vintage computers in my collection. Specifically a little gem of a Z80 CP/M machine called the Formula 1 
that has a built-in thermal printer and, more importantly, EEPROM programmer. Nothing to do with this project, but in the best "ADHD is my superpower" kind 
of way, I wound up looking for ways to transfer software to the machine via serial, as I have no way to write to disks directly on anything modern enough to
 matter. Anyway, poking around for serial cables reminded me that I had a Vellman microcontroller programmer stashed away in kit form. 

That I got like 10 years ago. So I dug it out, managed to not burn myself on the hot end of the metal-melting stick, and set about looking to test it. Random 
wall-wart from my electronics stash - check. Second wall-wart because the first one was not working correctly? Double-check. Serial cable - check. 
Serial-to-USB adapter - check. Powering it on, the power light worked, the flashing "DO NOT REMOVE PIC DURING PROGRAMMING/EXECUTION" led kicked in when the 
switch was moved to the appropriate positions. It is worth pointing out that Velleman provided NO documentation in the kit, save for a parts checklist
 (conveniently in installation order, I will admit!) along with a board diagram, circuit schematic, and a wiring diagram for wiring up a serial cable. 
They provided the necessary connectors, but I didn't have any cable laying around to stick them on, so just grabbed one from my cable curtain. It's like those
 beaded curtains, but computer cables. Yeah. So - software from Velleman requires you to enter a valid email address to recieve the link, and appears to be 
Windows only. I have an XP machine that I recently got running again, that would do nicely for this, and I may yet set it up. However, I was hoping to 
be able to use the USB converter and just tackle it from my Linux laptop, which was at least made in the last decade. A quick web search lead me to the Pickle
Microchip PIC ISP page at 
https://wiki.kewl.org/dokuwiki/projects:pickle  (Not affiliated in any way, just appreciate how easily and smoothly it worked. Followed the wiki to install and 
load the demo code, and everything worked the first time. Even more impressive, on top of my soldering job actually working the first time too! To make the story
even longer, I then spent the next 12 hours trying to install a C toolchain to be able to play with my own code on the PIC. While I intend to dig into SDCC a lot more (will be handy if I can get it working just for Z80 stuff) - I had issues with trying to the non-free libraries installed/usable. My tiny smattering of C
is longer ago than I had really realized, and even without the rust, it proved a mess. I could load pre-built example code just fine, but trying to build my 
own blinky lights became the major challenge. Eventually, I was able to get the linux versions of MPLAB and and the Micro compilers installed. Installation was slick, but I still need to dig into using the compiler directly, and while MPLAB isn't the worst IDE I have used, it doesn't want to talk to the Velleman board. 
Not exactly surprising. I may need to update this after a reboot - they did recommend it on install, so the not talking to the board might be my fault (though
I didn't see it listed in the available hardware choices, either, so.... Pickle to the rescue! Built the code in MPLAB connected to the simulator, then pushed
to the real hardware with pickle. Actually compiling C code and running it on the PIC, however....

Let's just say that there is a LOT less 'newb friendly' information out there for the PIC than, say, the wildly popular Arduino. This is both good and bad. 
I watched all 5 (ish) C PIC programming videos I could find in English on Youtube, and found a few scattered sample codes as well. None of which worked 
'out of the box' for me - and I spent a lot of time fiddling and crossing streams and breaking things etc. - and nothing I pushed to the board worked. 
Eventually, between the example ASM code from Velleman included as part of pickle (seriously, I CANNOT thank that guy enough!) I figured out that I was 
using the wrong setting for the clock. Between the ASM listing, and the datasheet for the PIC that came with the programmer, I finally was able to find the 
correct clock setting in MPLAB and set that - and finally got code working, sort of. Next hurdle was to make my code work. This was a combination of my lack of 
C knowledge - much rustier than I thought, though I slowly started getting some of it back, what little I had, that is - plus a bunch of very short, often 
conflicting code examples, all using various chips/toolchains/environments/etc. Hence this 'library' - Where I realized that, given that my programmer is also an
'experiment' board, with hard-wired LED's and buttons, it made sense to just make a header file with a bunch of define statements to make things a little less 
confusing. Yes, I WANT to learn how to manually throw data at PORTA / PORTB, toggle the individual pins from Input to Output, etc. In fact, this kind of 
low-level stuff is what I find fascinating about vintage computers, as well - the elegant, crazy solutions people came up with to make the most of limited 
resources. In the meantime, I also hope that, should there be any other (maybe 3?) crazy people in the world who decide to put together one of these nifty kits -
(Pretty sure they were discontinued, I had mine sitting for a LONG time) maybe I can make their lives just a tiny bit simpler as they try to figure out how to blink those bloody LED's on their own. 
