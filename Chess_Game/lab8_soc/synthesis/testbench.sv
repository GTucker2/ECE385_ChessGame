module testbench();

timeunit 10ns;
timeprecision 1ns;

logic CLK = 0;
logic RESET;
logic READ = 0;
logic WRITE = 0;
logic CS = 0;
logic [3:0] BYTE_EN;
logic [7:0] ADDR;
logic [31:0] WRITE_DATA;
logic [31:0] READ_DATA;
logic [31:0] EXPORT_DATA; 

chess_game_interface tr(.*);

always begin: CLOCK_GENERATION
	#1 CLK = ~CLK;
end

initial begin: CLOCK_INITIALIZATION
	CLK = 0;
end

initial begin: TEST_VECTORS
	RESET = 1; // Toggle Reset
	READ = 0;
	WRITE = 0;
	CS = 0;
	BYTE_EN = 4'b0;
	ADDR = 4'b0;
	WRITE_DATA = 32'b0;
	
	#2 RESET = 0;
	
	// Load Starting Data
	// Load KEY
	#2 CS = 1; 
		WRITE = 1;
		BYTE_EN = 4'b1111;
		ADDR = 4'b00000011;
		WRITE_DATA = 32'h00010203;
	#2 ADDR = 4'b00000010;
	   WRITE_DATA = 32'h04050607;
	#2 ADDR = 4'b00000001;
		WRITE_DATA = 32'h08090a0b;
	#2 ADDR = 4'b00000000;
		WRITE_DATA = 32'h0c0d0e0f;
		
	// Load ENCODED MESSAGE
	//#2 AVL_ADDR = 4'b0111;
	//   AVL_WRITEDATA = 32'hdaec3055;
	//#2 AVL_ADDR = 4'b0110;
	//   AVL_WRITEDATA = 32'hdf058e1c;
	//#2 AVL_ADDR = 4'b0101;
	//   AVL_WRITEDATA = 32'h39e814ea;
	//#2 AVL_ADDR = 4'b0100;
	//   AVL_WRITEDATA = 32'h76f6747e;
		
	// Wait for the key to finish expanding
	#20;
		
	// Start decoding
	//#2 AVL_WRITEDATA = 1;
	//	AVL_ADDR = 4'b1110;

	
	
end

endmodule
