Building the OpenOffice (TM) Writer plugin for AbiWord (R)
requires requires libgsf ( ftp://ftp.gnome.org/pub/gnome/sources/libgsf )
[personally using 1.8.1 for Win32, see abiword.pchasm.org/source/plugins/ ]
which in turn requires glib ( http://www.gtk.org/ )
[personally using WinGimp's GLIB 2.2.2 dll with its iconv, dev headers, etc.
 http://www.gimp.org/win32/ ]

I believe the auto build on Unix Systems (R) (e.g. Linux (R) ) will
properly detect and use system installed libgsf, glib, ...
however on Windows these libraries should be placed off the peer
libs/ subdirectory or adjust the Makefiles prior to building.

On Windows to build:
 - copy the required libraries (libgsf, glib) so the Makefiles
   can find the libs and headers
   [zlib is also required, but the peer zlib built library is used]
 - then cd into the WordPerfect directory and run
   make
 - you will probably see some warnings, but will get a mostly working plugin
 - copy the glib files (libglib-2.0-0.dll, libgobject-2.0-0.dll, iconv.dll and 
   intl.dll) to the bin subdirectory (same location as AbiWord.exe) and
   if necessary copy the plugin to the plugin directory
 - AbiWord should now be able to import WordPerfect files.

On Unix Systems:
 - build the same way you build other plugins via auto build system
   [please add more details here]


AbiWord is a registered trademark of SourceGear Corporation.
All other trademarks are the property of their respective owners.
