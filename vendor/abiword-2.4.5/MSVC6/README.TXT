AbiWord Microsoft Visual C++ 6.0 project files and project workspace

How to compile AbiWord using MSVC 6
===================================

Note: you may have to convert the VC++ 6 Project and Workspace files to use DOS line endings before starting (unix2dos *.ds[pw] will do the trick)

1. Open the workspace file (AbiWord.dsw) in MSVC
2. set "AbiWord classes" as the active project
3. Set the configuration to "AbiWord - Win32 Release" or "AbiWord - Win32 Debug" using the menu "Build -> Set Active Configuration" depending on your needs
4. Hit F7 to compile

That should do it.
