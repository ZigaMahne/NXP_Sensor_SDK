# NXP Sensor SDK using Open-CMSIS-Pack

Proof of concept for NXP Sensor SDK using Open-CMSIS-Pack csolution - CMSIS Project Manager.

Demonstrates a scalable solution for sensor examples using multiple boards and shields.

Projects are using software layers with specified standard interfaces.

Source code has been taken from existing NXP SDKs, restructured (only some files have been slightly modified) 
and extended with CMSIS Project Manager YML files.

## Repository top-level structure

Directory                   | Description
----------------------------|-------------------------------------------------
[boards](./boards)          | Board layers for various evaluation boards
[examples](./examples)      | ISSDK examples for various sensors
[middleware](./middleware)  | Middleware: FreeMASTER, ISSDK, SDMMC (not used)
[shields](./shields)        | Shield layers for various Arduino sensor shields

Details about the repository contents and how it was derived from NXP SDKs is described in [Contents.md](./Contents.md).

## ISSDK Sensor examples

IoT Sensing SDK (ISSDK) examples for various sensors are located in directory [examples/issdk/sensors](./examples/issdk/sensors).

Projects are described with CMSIS Project Manager input files (YML format) and are using CMSIS software packs (Open-CMSIS-Pack format).

The projects consists of:
 - application with middleware
 - board software layer
 - shield software layer

### Software Prerequisites
 - [CMSIS-Toolbox 1.3.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases/tag/1.3.0) or later
 - Arm Compiler 6.18 or later
 - CMSIS software packs listed in the project `<sensor_example>.csolution.yml` file

### Building the examples

1. Go to directory `examples/issdk/sensors/<sensor_name>/<sensor_example>`

2. Use the `csolution` command to create `.cprj` project files for all build and target types.
   ```
   csolution convert -s <sensor_example>.csolution.yml
   ```

3. Use the `cbuild` command to create executable file for specified build and target type.
   ```
   cbuild <sensor_example>.<build_type>+<target_type>.cprj
   ```