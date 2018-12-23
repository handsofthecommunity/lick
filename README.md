# LICK
LICK is a free program to install Linux from Windows without burning a CD or
using a USB. It is as simple as installing and running LICK, selecting a Linux
ISO image, and clicking install. A few seconds later, you can reboot into
Linux. Currently only Puppy Linux-based distributions are supported.

LICK runs on any Windows version, from Windows 95 to Windows 10. Check below
for any special notes on your Windows version type.

# Download
You can download the latest version of LICK
[from Github](https://github.com/noryb009/lick/releases/latest).

# Windows Version Notes
## Windows 8, 8.1 and 10
Windows 8 and up have a feature called 'Fast Startup'. This **cannot** be
enabled if LICK is installed. LICK disables Fast Startup upon installation.

## UEFI Systems with Secure Boot
LICK supports secure boot, but requires a manual step during the first
reboot.

1. On the first reboot, if you see a blue screen with writing, press enter
   to select `OK`.
2. Press enter again to select `Enroll Hash`.
3. Use the up and down arrow keys to highlight `loader.efi`, and press enter.
4. Press the down arrow to select `Yes`, then press enter.
5. Use the down arrow to highlight `Exit`, then press enter.

On subsequent reboots, these steps will not need to be taken.

## Windows ME
By default, Windows ME does not have all dependencies LICK requires. To fix
this, install [Me2Dos](http://www.rkgage.net/bobby/download/Me2Dos.exe).
You can also read the [README](http://www.rkgage.net/bobby/download/readme.txt).

## Early Versions of Windows

The GUI does not work on some early versions of Windows, including 95, 98,
and 2000. If run, it will complain that a procedure could not be found in
a dll file.

If this occurs, you must use the command line interface.

# Using the Command Line Interface

An example CLI session is shown below. I suggest you place the ISO file
in a path with a short name (eg. in `C:/`). On some versions of Windows,
you can drag and drop the ISO file onto the command prompt window to
automatically type the ISO path.

```
  Main menu:
  1) Install ISO or from CD
  2) Entry submenu (view/delete)
  3) Install/uninstall boot loader
  4) Quit
  Choice:
1<enter>
  ISO file or CD drive:
C:/xenialpup64-7.5-uefi.iso<enter>
  Install to drive:
  1) C:/
  2) D:/
1<enter>
  Enter ID [xenialpup64-7.5-uefi]:
<enter>
  Enter Name [xenialpup64 7.5 uefi]:
<enter>
```
