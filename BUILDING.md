## Compiling

1. Clone this repo and do a `git submodule update --init --recursive` to pull down the correct
TP Bindings.

2. Copy your copy of Twilight Princess (Currently only NTSC 1.0) to the root folder
for this project, and rename it to `rzde01.iso`.

3. Install devkitpro
    - Windows: Download [here](https://github.com/devkitPro/installer/releases)
    - MacOS/Linux: Read [this guide](https://devkitpro.org/wiki/Getting_Started)

4. Download and install the [Wiimms Tools](https://wit.wiimm.de/download.html). We will need the `wit` command to extract and repack the iso.

5. Download the Romhack-Compiler tool from the [current release of TPGZW](https://github.com/kipcode66/tpgzw/releases). This will be used for adding the compiled source code into the ISO.

6. Browse to the directory where you cloned your code and run:
    ```
    make
    ```

7. After the build succeeds, run the following commands:
    ```
    wit EXTRACT rzde01.iso rzde01_iso/
    romhack build --raw
    wit COPY build/rzde01_iso/ tpgzw.iso
    ```

8. The built ISO will now be in the same directory as the source code.

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
