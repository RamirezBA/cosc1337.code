Installing MinGW
################

I do most of my development work using command line tools. FOr that reason, I
make sure all of my systems have a good C/C++ compiler installed for those
projects needing those languages. On a PC, the tools I use are based on the
open source Gnu C/C++ compiler suite. This is the standard compiler tool set in
the Linux world, and the entire system has been ported to the PC world through
the MinGW (Minimal GNU for Windows) project. There are versions of this tool
set for both 32-bit and 64-bit systems. Since most systems in use today are
64-bit, I will be installing MinGW64 in this note.

System Setup
************

Like many serious developers who work on platforms other than Windows, I do not
like Window's habit of installing things in weird places like "Program Files",
"Program Files (x86)", "My Documents", etc. Those spaces in the names really
get in the way when you start working as a developer. So, I create a simpler
set of directories on my PC systems, doing something similar to what you see on
other systems.

Here are my development folders:

..  code-block:: text

    c:\usr
        |
        +-local
            |
            +- bin\             # simple executable files live here
            |
            +- include\         # C/C++ header files live here
            |
            +- lib\             # precompiled library files live here

I add the ``bin`` folder to the system ``PATH`` variable on my system so any
simple program I want to run from the command line can be easily "installed" by
just dropping the file in this folder. I add other places in this setup to the
system PATH as needed depending on what tools I install.

In this note, we will be installing a compiler, and a build tool to be used
when writing C/C++ applications. These folders will be used in that setup.

Download MinGW64 Installer:
***************************

Open up a web browser and navigate to this link:

    * `mingw-w64-install.exe
      <http://sourceforge.net/projects/mingw-w64/files/latest/download>`_

This program will install the compiler on your system, but we need to instal it temporarily in one place, then copy files into their final position to simplify working in the ``Git Bash`` window.

Run the installer, and let it install into it's default location.

    * c:\Program FIles (x86)]i686-5.3.0-release-posix-dwarf-rt_vr-rev0

What a messy name for a folder!

Create a New Home
=================

I set up a new folder for my applications inusing these commands at the ``Git Bash`` prompt:

..  code-block:: text

    $ mkdir -p /c/usr/local/{bin,include/lib}

Add these lines to the system ``PATH`` variable:

    ;c:\usr\locak\bin;c:\usr\local\mingw64\bin

We will place the compiler in that last location next.

Copy the files
==============

We will copy the main directory in this location to the area where ``Git Bash``
places system files.

You can do this with the Windows Explorer or at the command line:

    * copy c:\Program Files (x86)\mingw-w64\i686-5.2.0-posix-dwarf-rt_v4-rev0\mingw32

    * save in c:\usr\local\bin\mingw64

I prefer to name the folder with 64 to remind me that this is the 64-bit
version of the tools.

Command Line Copy
-----------------

Create the new directory for the compiler:

..  code-block:: text

    $ mkdir -p /usr/local/mingw64

Then run this (long) command:

..  code-block:: text

    cp -R /c/$ ls /c/Program\ Files\ \(x86\)/mingw-w64/i686-5.2.0-posix-dwarf-rt_v4-rev0/min gw32/
        /c/usr/local/mingw64

That long line is all on one line. Be careful when you type it in, those back-slashes are needed so the command line does not get upset at all those spaces in Microsoft-land! See why I prefer simpler names for places on my system, even on PCs?

Update System Path
==================

Once the tools are installed, we need to make them available by modifying the
system ``PATH`` variable. To do this, right click on the computer line in
WIndows Explorer and select Properties. In the window that comes up select
"EAdvanced Properties, then Environment Variables. In that last panel, find the
``PATH`` variable line under ``System Variables`` and add this text to the end
of the line:

..  code-block:: text

    ;c:\usr\local\mingw64\bin;c:\usr\local\bin

That last part is important, since we will set up a simple directory to hold important programs for our work that do not need a full installation on Windows. I put all such tools in a standard lplace on my system: ``c:\\tools\\bin``.

Installing Make
***************

Working at the command line means typing in a lot of commands. Being a lazy
programmer, I prefer to let a good programmer's tool do that for me when I
build programs. The tool of choice for beginners is probably ``make``, which
has been around for over 35 years, and in fact powers many IDE systems.

The current version of Make for Windows systems is version 4.1, which can be
downloaded from this link:

    * `make.exe <ftp://ftp.equation.com/make/64/make.exe>`_

This tool needs to be copied into a folder that is on the system PATH. For my
systems, this is ``c:\\usr\\local\\bin``.

You can check that it in installed properly by typing this command:

..  code-block:: text

    $ make --version
    GNU Make 4.1
    This program is built by Equation Solution <http://www.Equation.com>
    for Windows.
    Copyright (C) 1988-2014 Free Software Foundation, Inc.
    License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
    This is free software: you are free to change and redistribute it.
    There is NO WARRANTY, to the extent permitted by law.

If you see this, you are ready to build programs the easy way.

Make sure the compiler runs from the command line by trying this command:

..  code-block:: text

    $ g++ --version
    g++.exe (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 5.2.0
    Copyright (C) 2015 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

If you see this, your tools are ready for development!

