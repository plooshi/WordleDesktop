# Wordle, but for your desktop.

An almost-full remake of the popular game Wordle for your desktop.

## Preview

![Preview](https://plooshi.xyz/assets/WordleDesktopPreview.png)<br/>

## How to download
> Go into the releases tab
> Download the files for your platform
### Windows
> Download the Windows folder<br/>
> Extract it<br/>
> Open Wordle.exe inside the folder<br/>
### Linux
> just run the binary

## How to compile (for you developer nerds)<br/>

> Clone the repository.<br/>
> Install/Compile GTK3 and CMake.<br/>

> cd WordleDesktop<br/>
### Linux/Mac:<br/>
> cmake .<br/>
> cmake --build .<br/>
### Windows:<br/>
> cmake . -DGTK_DIR=(path to GTK)<br/>
> cmake --build .<br/>
### Linux/Mac:<br/>
> sudo cmake --install .<br/>
### Windows (in an admin terminal): <br/>
> cmake --install .<br/>
