Author: Ed Musgrove
Be Dev #2076
Release Date: 19 March 1999
Compatibility: PPC R4 & x86 R4
Location: Utilities
Description:

Program Name: libBeGUI.so
Version: 1.4.2
date: 19 March 1999

BeGUI is a simple to use programmer's tool which allows for rapid development
of a program. It is sensitive to font sizes, style and families; has a lot of
color control preferences and had a window class which is self-sizing and
recalls it's position from instance to instance (two preference files get
stored in /home/config/settings--thanks to Jon Watte's libprefs).

A "Pref" menu entry allows access to a wide range of GUI settings, including
the font size and the color scheme of all the "gadgets". Applications are
entirely font sensitive, so play about with various silly sizes! Messing about
with the "gadget" colors can be fun, it can also make things very ugly! Give
these a try as well.

The archive unzips into a folder called BeGUIlib which contains a
handful of folders and some loose source and text files. All source code is
included, so you can see how I have done the BeGUI stuff.

Extensive html documentation of BeGUI and a major re-write of all the code has
been completed for this release. Check the documentation folder for the html,
start with documentation/indexDocumentation.html and check it all out from there.

As I have made extensive use of Jon Watte's libprefs, and as there is currently no 
x86 R4 version available, I was forced to craft a version which would compile
under R4 for both PPC and x86. I am sure that when Jon gets back from vacation 
he will do a much better job, but I have included source and makefile which
will work fine in a shared library (sorry--I have no static library experience) under 
both PPC and x86.

As this library is only of interest to programmers, I have chosen to release only 
the source code, in the interest of size. There are two script files (creationPPC.script 
and creationx86.script), one of which you will run to create both libBeGUI.so and 
libprefs.so. If you are compiling on a PPC machine use creationPPC.script, if on an 
x86 machine use creationx86.script. Whichever script you use MUST be run from
the parent directory which contains the BeGUIlib directory created by unzipping
this archive.

Unzip this archive anywhere, open a Terminal and make sure it is CD'ed 
to the BeGUI directory, type either:
creationPPC.script
or:
creationx86.script

Each script gives output on the Terminal letting you know what part of the process is 
going on. First libprefs will be created and copied into the local lib and /boot/home/
config/lib directories. Next libBeGUI.so will be created and copied into the local lib and 
/boot/home/config/lib directories. Next PrefsEDgar, ResEDgar and Resourceful (demo 
apps) will be created .

Look at the example application html file, the file "documentation/BeGUI Tutorial.txt".
If you need any help getting started coding with BeGUI let me know, I am always happy 
and eager to help others with the task of GUI creation. There is a user's and a
programmer's guide in the documentation directory. Look in the PrefsEDgar, ResEDgar 
and Resourceful directories for doc for each of these.
 
-Ed
edgar at harbornet dot com
