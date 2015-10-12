Configuring GitHub SSH Keys
###########################

..  include::   /references.inc

Assuming you have set up MsysGit on your PC, you can make your life easier if
you set up security keys on your development station.

Security keys are a pair of text files generated using a tool that is included
in MsysGit_, or using part of the Putty_ system. We will use the tools that come
with MsysGit_, since the exact same commands will work on Mac or Linux systems
as well.

Generating Your Keys
********************

Open up a ``Git Bash`` window and type this:

..  code-block:: text

    $ ssh-ketgen -t rsa

This command will generate a set of keys encrypted using a standsrd scheme
(RSA). 

The script will ask you where to install the keys. You should accept the
default loction , which is in a folder named ``.ssh`` in your home directory.

You will also be asked to provide a password to be used when this key is
accessed. Pick a good password, and keep it private! 

You should see something like this on your screen:

..  code-block:: text

    $ ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
    Generating public/private rsa key pair.
    Enter file in which to save the key (/c/Users/rblack/.ssh/id_rsa):
    Enter passphrase (empty for no passphrase):
    Enter same passphrase again:
    Your identification has been saved in /c/Users/rblack/.ssh/id_rsa.
    Your public key has been saved in /c/Users/rblack/.ssh/id_rsa.pub.
    The key fingerprint is:
    4b:85:87:b3:ad:47:d9:e7:f7:f1:36:32:58:f8:5f:46 rblack@PCDEV
    The key's randomart image is:
    +--[ RSA 2048]----+
    |    ....         |
    |   o o.. .       |
    |  o o o . .      |
    | .   o . o . .   |
    |  . .   S o o E  |
    |   .   . + . + o |
    |        . . + +  |
    |         . o . . |
    |          .      |
    +-----------------+

Look in your ``.ssh`` folder. You should find two new files:

    * ``id_rsa.pub`` - this is your "public key"

    * ``id_rsa`` - this is your private key

You never let anyone see your "private key" (that iw why it is called
"private"). However, you can freely distribute your "public key". We want to
copy this file onto your GitHub_ account so you can use it to avoid having to
log in every time you access the server.

Adding Public Key to GitHub
***************************

Open up your GitHub_ account page, and go to your "profile page". Click on
``Edit Settings`` and then on ``SSH keys``.  Here you can add a new SSH key to
your account. Normally, I keep a different key on each computer I use to access
my account. 

Open up your ``id_rsa.pub`` key using a text editor.

..  warning::

    Never alter this key by adding line breaks to it. It must remain a very
long singe line of text!

Copy the text of the key to your clipboard. then paste it into the form that
opens up when you click on ``Add SSH key``. I name the key something to remind
me which machine a particular key is for,

On tour development key, you need to do one more thing to get rid of those password prompts.

Add a Key Manager
*****************

Add this to your ``.bashrc`` file in your home directory:

..  code-block:: text

    if [ -z #$SSH_AUTH_SOCL" ] ; then
        eval `ssh-agent -s`
        ssh-add
    fi

Note those back-tick characters in that code, they are important!

Now, do this in your current ``Git Bash`` session:

..  code-block:: text

    $ source ~/.bashrc
    Agent pid 9728
    Enter passphrase for /c/Users/rblack/.ssh/id_rsa:
    Identity added: /c/Users/rblack/.ssh/id_rsa (/c/Users/rblack/.ssh/id_rsa)

Test your setup by doing this:

..  code-block:: text

    $ ssh -T github.com
    The authenticity of host 'github.com (192.30.252.130)' can't be established
    RSA key fingerprint is 16:27:ac:a5:76:28:2d:36:63:1b:56:4d:eb:df:a6:48.
    Are you sure you want to continue connecting (yes/no)?

You should answer "yes" to this prompt. It will only happen the first time you
use SSH to access this server.

..  code-block:: text

    Welcome to Git (version 1.9.5-preview20150319)


    Run 'git help git' to display the help index.
    Run 'git help <command>' to display help for specific commands.
    Agent pid 13704
    Enter passphrase for /c/Users/rblack/.ssh/id_rsa:
    Bad passphrase, try again for /c/Users/rblack/.ssh/id_rsa:
    Identity added: /c/Users/rblack/.ssh/id_rsa (/c/Users/rblack/.ssh/id_rsa)

Here, I entered a badd passphrase to show the error message.

With these lines in the ``.bashrc`` file, every time you open up a ``Git Bash``
window, you will be asked for your SSH passphrase. You will only enter this
once per session, and can use Git- commands freely. They will be much faster!

