# <img src="./res/icons/icon.jpg" height="42" width="45" align="top"/>tpgz</h1>

## About

tpgzw is a rom hack of the game Twilight Princess Wii geared towards enhancing practice and testing for speedrunning.

<p align="center">
  <img src="./res/icons/giphy.gif?raw=true" />
</p>

## Features

```
Use Z+C+Minus to open the main menu which contains the following options:

cheats menu:
- infinite air                  // Gives Link infinite air underwater
- infinite arrows               // Gives Link 99 arrows
- infinite bombs                // Gives Link 99 bombs in all bags
- infinite hearts               // Link will always have full hearts
- infinite oil                  // Gives Link infinite lantern oil
- infinite rupees               // Link will always have 1000 rupees
- infinite slingshot            // Gives Link 99 slingshot pellets
- invincible                    // Makes Link invincible (no hurtbox, but can still take fall damage and drown)
- invincible enemies*           // Makes some enemies invincible (infinite health)
- moon jump                     // Hold Z+C+A to moon jump
- super clawshot (TBD)          // Clawshot is long and can grab most things (not implemented yet)
- super spinner (TBD)           // Spinner is very fast and can hover (not implemented yet)

flags menu:
- boss flag                     // Set the boss flag value. Press A to lock the value
- epona stolen                  // Toggle flag for Epona being stolen
- epona tamed                   // Toggle flag for Epona being tamed
- map warping                   // Toggle flag for having map warping
- midna charge                  // Toggle flag for Midna charge
- midna healthy                 // Toggle flag for Midna being healthy/sick
- midna on back                 // Toggle flag for Midna appearing on Wolf Link's back
- midna on z                    // Toggle flag for being able to use Midna
- transform/warp                // Toggle flag for transforming/warping
- wolf sense                    // Toggle flag for having wolf sense
- hide weapon as wolf           // Toggle flag for hiding weapons as wolf

inventory menu:
- item wheel                    // Can set the 24 item wheel slots to any item
- pause menu (TBD)              // Can modify the pause menu collection (not implemented yet)

memory menu:
- Add memory watches to the screen (not implemented yet)

practice menu:
- Load practice files* (supports popular Any% and 100% locations)

scene menu:
- disable bg music*             // Disables background and enemy music
- disable sfx                   // Disables sound effects (item, weather, etc.)
- freeze actors                 // Freezes actors
- freeze camera                 // Locks the camera in place
- hide actors                   // Hides actors
- hide hud                      // Hides the heads-up display
- time (hrs)                    // The current in-game hour
- time (mins)                   // The current in-game minutes

settings menu:
- log level                     // Changes log level for debugging
- drop shadows                  // Adds shadows to all font letters
- save card                     // Save settings to memory card
- load card                     // Load settings from memory card
- area reload behavior          // load area = Reload last area; load file = Reload last file

tools menu:
- area reload                   // Use Z+C+B+Plus to reload current area
- fast bonk recovery            // Reduces bonk animation significantly
- fast movement                 // Link's movement is much faster
- gorge checker                 // Use Z+C+A+1 to warp to Kakariko Gorge
- input viewer                  // Show current inputs (buttons only for now)
- link debug info               // Show Link's position, angle, and speed
- no sinking in sand            // Link won't sink in sand
- roll checker                  // Frame counter for chaining rolls
- teleport                      // Z+C+1 to set, Z+C+2 to load
- timer                         // Frame timer: Z+C+A+B to start/stop, Z+C+B+Plus to reset
- link tunic color:             // Changes Link's tunic color (green, blue, red, orange, yellow, white, or cycle)

warping menu:
- warp to dungeons, towns, grottos, etc. (not implemented yet)
```

## Known Bugs

```
- invicible enemies cheat can't be turned off once turned on
- disabled bg music tool may not always disable bg music
- loading practice files can crash in certain situations
```

## Planned Features

```
- free cam
- actor spawner
- frame advance
- collision viewer
- menu font selector
- lag counter & loading counter
```

## Download / Usage

You will need the **Twilight Princess ISO** -- currently only the Wii NTSC 1.0 version is supported.

*NOTE: This process won't work for now. We are currently trying to make a new one.*

1. Download the latest release [here](https://github.com/hallcristobal/tpgzw/releases).

2. Unzip the contents into a folder and run the `romhack-patcher.exe`

3. Select the associated patch file and the Twilight Princess ISO

4. Click apply

   - You will be asked to select a save directory for the newly patched ISO. After giving the ISO a name, the patcher will freeze briefly while generating the ISO.

5. You can now load the generated ISO in Dolphin emulator or in a Wii in a homebrew loader such as [Nintendont](https://github.com/FIX94/Nintendont).

6. Use L+R+dpadDown to open the features menu in game.

## Project structure

```
tpgzw
├───.github
│   └───workflows         // github action(s) used to test code compilation
├───external              // external libraries and programs consumed by tpgz
│   ├───fonts             // small rust program to generate raw bytes and c code for utilizing true-type fonts in game
│   │   ├───fonts         // ttf files
│   │   └───src           // source code for fonts
│   ├───gcn_c             // game independent gamecube apis to link to
│   │   ├───include       // header files for gcn_c
│   │   └───src           // source code for gcn_c
│   └───libtpw_c          // game bindings for twilight princess
│       ├───.github
│       │   └───workflows // github action(s) used to test code compilation
│       ├───include       // header files for libtpw_c
│       └───src           // source code for libtpw_c
├───include               // header files for tpgzw
│   └───fonts             // individual font properties such as width, height, glyphs, etc.
├───res                   // external resources to be consumed
│   └───save_files        // raw quest log bytes to be injected at compile time
└───src                   // source code for tpgzw
    └───fonts             // raw bytes for fonts
```

## Building

See [BUILDING](./BUILDING.md).

## Contributing

See [CONTRIBUTING](./CONTRIBUTING.md).
