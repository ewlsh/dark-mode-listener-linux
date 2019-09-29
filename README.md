# dark-mode-listener-linux

A small CLI tool to listen to "dark mode" changes on Linux via the active GTK theme.

Modeled after [DarkModeListener](https://github.com/LinusU/DarkModeListener) for MacOS.

## Build

Build via [Meson](https://mesonbuild.com/).

```sh
$ meson build
$ cd build
$ ninja
```

## Install

After [building](#Build) install with ninja:

```sh
$ ninja install
```

## Usage

```sh
$ dark-mode-listener-linux
light
dark
light
...
```

The program will first print a line with either `light` or `dark` depending on the current active GTK theme. It will then print a new line whenever the value changes.