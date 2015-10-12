C++ Graphics With OpenGL and GLUT
#################################

By itself, C++ knows nothing about graphics, but it is an exceppelt language to use when developing graphics applications. We will do a few experiments using graphics as we learn about object oriented programming, but to do that, we need to set up our systems a bit.

Specifically, we are going to use OpenGL, a very popular graphics system that works on any platform and isolates most of the hardware dependencies from your program. Instead you focus on a set of graphics "primitives" which are simple graphics operations any graphics application will need to be able to do. OpenGL hides the details of making those primative things happen on your specific machine.

Unfortunalety programming directly with OpenGL is a bit tough for befginners, so we will add anothe package, GLUT, which further simplifies the interface so we can concentrate on drawing images on the screen.

On top of GLUT, I have created a final layer to make youe job even easier yet. This last layer is just a small set of basic shape drawing functions we can use to draw simple images ona screen. We will be able to make things move, just to make things a bit more fun:

..  graphviz::
    
    digraph G {
        C++ Code -> Graphics -> GLUT -> OpenGL -> Machine;
    }

Getting Started
***************

First, we need to make sure OpenGL and GLUT are installed on your system. 

If you have a Mac, and you have installed XCode, you can skip this section, since modern Xcode instalations include both OpenGL and GLUT. 
This note assumes you have MinGW installed on your PC system, or have XCode instaled on your Ma
