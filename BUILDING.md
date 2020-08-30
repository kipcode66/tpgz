## Compiling

1. Clone this repo and do a `git submodule update --init --recursive` to pull down the correct
TP Bindings.

2. Copy your copy of Twilight Princess Wii (Currently only NTSC-U) to the root folder
for this project.

3. Install WIT from [here](https://wit.wiimm.de/download.html)

4. Run
```
wit EXTRACT isoname.iso iso-extract
```
Note: Wit will automatically create the directory where the extracted files are placed.

5. Install devkitpro
    - Windows: Download [here](https://github.com/devkitPro/installer/releases)
    - MacOS/Linux: Read [this guide](https://devkitpro.org/wiki/Getting_Started)

6. Download and compile the Romhack-Compiler tool [here](https://github.com/kipcode66/romhack-compiler). This will be used for adding the compiled source code into the game files.

7. Browse to the directory where you cloned your code and run:
```
make
```

8. After the build succeeds, run:
```
romhack build --raw
```

9. The patched game files will now be in a build/ folder in the same directory as the source code. From here you can either use it from opening DATA/sys/main.dol in dolphin, or use the command below to make an iso from the game files.

---
To make in iso from the game files, run:
```
wit COPY built_iso_extract tpgzw.iso
```
Don't be alarmed if WIT says it can't find a file; It should still work once the command is complete.
Once the command is complete you can either run the iso on dolphin or run it on a usb loader such as wiiflow.

---  
If you want to compile alternative fonts:  
1. Place your font in external/fonts/fonts/

2. Replace the following command in the Makefile
```rust
cargo run -I fonts/your_font.ttf -S 18.0 -N Your_Font_Name -O build
```

3. Run
```
make font
```
---  
If you'd like to create a patch file for sharing you can with:
```
romhack build --raw --patch
```
