I have attempted to zip this up with links preserved. If for some reason the BeGUI
header files seem not to be found, you may have to re-make the links. Simply open the 
BeGUIlib directory, select all the .h header files and create links for all of them in both the
PrefsEDgar and ResEDgar directories.

I have tested the PPC script here on my BeBox. The x86 script should work just fine as
well. These will all compile under r4 or above. Due to cercumstances beyond my control,
I am unable to compile and link with optimization levels other than NONE or warning levels
other than NONE. Depending upon your platform and OS version you may want to change
all the makefiles to FULL optimization and ALL warnings.

This BeGUI directory may be placed anywhere. Open a Terminal and ce to this BeGUI
directory then type:
creationPPC.script
if on a BeBox or Mac (PPC)
or:
creationx86.script
if on x86 (intel compatible)

If you have any problems or questions please email me at:

edgar at harbornet dot com