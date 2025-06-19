# Cloudnine C979

![c979](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Dimitris Mantzouranis](https://github.com/dexter93)
* Hardware Supported: Cloudnine C979
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make cloudnine/c979:default

Flashing example for this keyboard:

    make cloudnine/c979:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

* **Reset Key**: The master and slave side should be flashed individually, to enter flashing mode, hold down the key located at K01, which programmed as PC Lock while plugging in the keyboard for the master side and hold down the key located at K52, which programmed as Pause while plugging in the keyboard for the slave side.

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the **Reset Key** and plug in the keyboard
* **Physical reset button**: Hold down the switch under Spacebar and plug in the keyboard
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
