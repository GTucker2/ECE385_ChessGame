# ECE385_ChessGame
This game was developed as a final project for ECE385, Digital Systems Laboratory, at the University of Illinois at Urbana-Champaign. 

## Authors
* **Lance Pan** - []()
* **Griffin A. Tucker**  - [GTucker2](https://github.com/GTucker2)

## Files

Note: The files cataloged here are only those which have been written by the devekopers and external parties. System-generated files will not be listed.

### Documentation
* [README.md](https://github.com/GTucker2/ECE385_ChessGame/blob/master/README.md) - Summary of project and project contents
* [BUGLOG.md](https://github.com/GTucker2/ECE385_ChessGame/blob/master/BUGLOG.md) - Comprehensive, chronological report of all bugs encountered during the development of this project.

### Lab8_Starter
#### Hardware
* [lab8.sv](https://github.com/GTucker2/ECE385_ChessGame/blob/master/Lab8_Starter/Lab8_provided/lab8.sv) - Top-level module which integrates Nios II system with hardware
* [ball.sv](https://github.com/GTucker2/ECE385_ChessGame/blob/master/Lab8_Starter/Lab8_provided/ball.sv) - Tracks location and motion of on-screen ball (not used in final game)
* [Color_Mapper.sv](https://github.com/GTucker2/ECE385_ChessGame/blob/master/Lab8_Starter/Lab8_provided/Color_Mapper.sv) - Maps color to pixel location for VGA display
* [HexDriver.sv](https://github.com/GTucker2/ECE385_ChessGame/blob/master/Lab8_Starter/Lab8_provided/HexDriver.sv) - Converts a 4-bit decimal input to an 8-bit output signal compatible with Altera hex-display LEDs
* [hpi_io_intf.sv](https://github.com/GTucker2/ECE385_ChessGame/blob/master/Lab8_Starter/Lab8_provided/hpi_io_intf.sv) - Connects the Nios II and EX-OTG data channels
* [VGA_controller.sv](https://github.com/GTucker2/ECE385_ChessGame/blob/master/Lab8_Starter/Lab8_provided/VGA_controller.sv) - Sets VGA control signals and writes output values to the display
#### Software 
* [io_handler.c](https://github.com/GTucker2/ECE385_ChessGame/blob/master/Lab8_Starter/Lab8_provided/software/usb_kb/io_handler.c) - Contains sub-functions for reading and writing to be used with usb.c
* [main.c](https://github.com/GTucker2/ECE385_ChessGame/blob/master/Lab8_Starter/Lab8_provided/software/usb_kb/main.c) - Primary loop which handles USB keyboard implementation
* [usb.c](https://github.com/GTucker2/ECE385_ChessGame/blob/master/Lab8_Starter/Lab8_provided/software/usb_kb/usb.c) - Contains functions for reading and writing to the internal registers of the USB controller

## Acknowledgements
* **United States Chess Federation** - [Summary of the Moves of Chess](http://www.uschess.org/docs/forms/LetsPlay.pdf)
* **Xinying Wang and UIUC ECE Department** - Provided code for VGA and USB implementation, i.e. Lab8_Starter
