/************************************************************************
Avalon-MM Interface for AES Decryption IP Core

Dong Kai Wang, Fall 2017

For use with ECE 385 Experiment 9
University of Illinois ECE Department

---------------Register Map-------------------
 
 REG 0:|      A4      |      A3      |      A2      |      A1      |
       +--------------+-------------+--------------+---------------+
 REG 1:|      A8      |      A7      |      A6      |      A5      |
       +--------------+-------------+--------------+---------------+
 REG 2:|      B4      |      B3      |      B2      |      B1      |
       +--------------+-------------+--------------+---------------+
 REG 3:|      B8      |      B7      |      B6      |      B5      |
       +--------------+-------------+--------------+---------------+
 REG 4:|      C4      |      C3      |      C2      |      C1      |
       +--------------+-------------+--------------+---------------+
 REG 5:|      C8      |      C7      |      C6      |      C5      |
       +--------------+-------------+--------------+---------------+
 REG 6:|      D4      |      D3      |      D2      |      D1      |
       +--------------+-------------+--------------+---------------+
 REG 7:|      D8      |      D7      |      D6      |      D5      |
       +--------------+-------------+--------------+---------------+
 REG 8:|      E4      |      E3      |      E2      |      E1      |
       +--------------+-------------+--------------+---------------+
 REG 9:|      E8      |      E7      |      E6      |      E5      |
       +--------------+-------------+--------------+---------------+
 REG 10|    : F4      |      F3      |      F2      |      F1      |
       +--------------+-------------+--------------+---------------+
 REG 11|    : F8      |      F7      |      F6      |      F5      |
       +--------------+-------------+--------------+---------------+
 REG 12|    : G4      |      G3      |      G2      |      G1      |
       +--------------+-------------+--------------+---------------+
 REG 13|    : G8      |      G7      |      G6      |      G5      |
       +--------------+-------------+--------------+---------------+
 REG 14|    : H4      |      H3      |      H2      |      H1      |
       +--------------+-------------+--------------+---------------+
 REG 15|    : H8      |      H7      |      H6      |      H5      |
 
 ****************************************************************/

module chess_game_interface(
    input  logic        CLK,
    input  logic        RESET,
    input  logic        READ,
    input  logic        WRITE,
    input  logic        CS,
    input  logic [3:0]  BYTE_EN,
    input  logic [4:0]  ADDR,
    input  logic [31:0] WRITE_DATA,
    output logic [31:0] READ_DATA,
    output logic [31:0] EXPORT_DATA
);
    
    // Declare connection for read routing
    logic [31:0] read_data;
    logic [31:0] WRITEDATA;
    
    // Declare internal logic connections for new data input
    logic [31:0] A4toA1_next;
    logic [31:0] A8toA5_next;
    logic [31:0] B4toB1_next;
    logic [31:0] B8toB5_next;
    logic [31:0] C4toC1_next;
    logic [31:0] C8toC5_next;
    logic [31:0] D4toD1_next;
    logic [31:0] D8toD5_next;
    logic [31:0] E4toE1_next;
    logic [31:0] E8toE5_next;
    logic [31:0] F4toF1_next;
    logic [31:0] F8toF5_next;
    logic [31:0] G4toG1_next;
    logic [31:0] G8toG5_next;
    logic [31:0] H4toH1_next;
    logic [31:0] H8toH5_next;
    
    // Declare internal logic connections for recycled data
    logic [31:0] A4toA1_cur;
    logic [31:0] A8toA5_cur;
    logic [31:0] B4toB1_cur;
    logic [31:0] B8toB5_cur;
    logic [31:0] C4toC1_cur;
    logic [31:0] C8toC5_cur;
    logic [31:0] D4toD1_cur;
    logic [31:0] D8toD5_cur;
    logic [31:0] E4toE1_next;
    logic [31:0] E8toE5_next;
    logic [31:0] F4toF1_next;
    logic [31:0] F8toF5_next;
    logic [31:0] G4toG1_next;
    logic [31:0] G8toG5_next;
    logic [31:0] H4toH1_next;
    logic [31:0] H8toH5_next;
    
    // Write routing
    always_comb begin
        WRITEDATA = 32'b0;
        if(CS & WRITE == 1) begin
            case(BYTE_EN)
                4'b1111: WRITEDATA[31:0] = WRITE_DATA[31:0];
                4'b1100: WRITEDATA[31:16] = WRITE_DATA[31:16];
                4'b0011: WRITEDATA[15:0] = WRITE_DATA[15:0];
                4'b1000: WRITEDATA[31:24] = WRITE_DATA[31:24];
                4'b0100: WRITEDATA[23:16] = WRITE_DATA[23:16];
                4'b0010: WRITEDATA[15:8] = WRITE_DATA[15:8];
                4'b0001: WRITEDATA[7:0] = WRITE_DATA[7:0];
				default: WRITEDATA = 32'b0;
			endcase
        end
    end
    
    // Declare muxes for each of the 16 registers
    reg_mux M_A4toA1(.WRITE, .ADDR, .NAME(4'h0), .WRITEDATA, .RECDATA(A4toA1_cur), .data_out(A4toA1_next));
    reg_mux M_A8toA5(.WRITE, .ADDR, .NAME(4'h1), .WRITEDATA, .RECDATA(A8toA5_cur), .data_out(A8toA5_next));
    reg_mux M_B4toB1(.WRITE, .ADDR, .NAME(4'h2), .WRITEDATA, .RECDATA(B4toB1_cur), .data_out(B4toB1_next));
    reg_mux M_B8toB5(.WRITE, .ADDR, .NAME(4'h3), .WRITEDATA, .RECDATA(B8toB5_cur), .data_out(B8toB5_next));
    reg_mux M_C4toC1(.WRITE, .ADDR, .NAME(4'h4), .WRITEDATA, .RECDATA(C4toC1_cur), .data_out(C4toC1_next));
    reg_mux M_C8toC5(.WRITE, .ADDR, .NAME(4'h5), .WRITEDATA, .RECDATA(C8toC5_cur), .data_out(C8toC5_next));
    reg_mux M_D4toD1(.WRITE, .ADDR, .NAME(4'h6), .WRITEDATA, .RECDATA(D4toD1_cur), .data_out(D4toD1_next));
    reg_mux M_D8toD5(.WRITE, .ADDR, .NAME(4'h7), .WRITEDATA, .RECDATA(D8toD5_cur), .data_out(D8toD5_next));
    reg_mux M_E4toE1(.WRITE, .ADDR, .NAME(4'h8), .WRITEDATA, .RECDATA(E4toE1_cur), .data_out(E4toE1_next));
    reg_mux M_E8toE5(.WRITE, .ADDR, .NAME(4'h9), .WRITEDATA, .RECDATA(E8toE5_cur), .data_out(E8toE5_next));
    reg_mux M_F4toF1(.WRITE, .ADDR, .NAME(4'hA), .WRITEDATA, .RECDATA(F4toF1_cur), .data_out(F4toF1_next));
    reg_mux M_F8toF5(.WRITE, .ADDR, .NAME(4'hB), .WRITEDATA, .RECDATA(F8toF5_cur), .data_out(F8toF5_next));
    reg_mux M_G4toG1(.WRITE, .ADDR, .NAME(4'hC), .WRITEDATA, .RECDATA(G4toG1_cur), .data_out(G4toG1_next));
    reg_mux M_G8toG5(.WRITE, .ADDR, .NAME(4'hD), .WRITEDATA, .RECDATA(G8toG5_cur), .data_out(G8toG5_next));
    reg_mux M_H4toH1(.WRITE, .ADDR, .NAME(4'hE), .WRITEDATA, .RECDATA(H4toH1_cur), .data_out(H4toH1_next));
    reg_mux M_H8toH5(.WRITE, .ADDR, .NAME(4'hF), .WRITEDATA, .RECDATA(H8toH5_cur), .data_out(H8toH5_next));
    
  
    // Declare the 16 registers
    square_data_reg R_A4toA1(.CLK, .RESET, .REG_DATA_IN(A4toA1_next), .REG_DATA_OUT(A4toA1_cur));
    square_data_reg R_A8toA5(.CLK, .RESET, .REG_DATA_IN(A8toA5_next), .REG_DATA_OUT(A8toA5_cur));
    square_data_reg R_B4toB1(.CLK, .RESET, .REG_DATA_IN(B4toB1_next), .REG_DATA_OUT(B4toB1_cur));
    square_data_reg R_B8toB5(.CLK, .RESET, .REG_DATA_IN(B8toB5_next), .REG_DATA_OUT(B8toB5_cur));
    square_data_reg R_C4toC1(.CLK, .RESET, .REG_DATA_IN(C4toC1_next), .REG_DATA_OUT(C4toC1_cur));
    square_data_reg R_C8toC5(.CLK, .RESET, .REG_DATA_IN(C8toC5_next), .REG_DATA_OUT(C8toC5_cur));
    square_data_reg R_D4toD1(.CLK, .RESET, .REG_DATA_IN(D4toD1_next), .REG_DATA_OUT(D4toD1_cur));
    square_data_reg R_D8toD5(.CLK, .RESET, .REG_DATA_IN(D8toD5_next), .REG_DATA_OUT(D8toD5_cur));
    square_data_reg R_E4toE1(.CLK, .RESET, .REG_DATA_IN(E4toE1_next), .REG_DATA_OUT(E4toE1_cur));
    square_data_reg R_E8toE5(.CLK, .RESET, .REG_DATA_IN(E8toE5_next), .REG_DATA_OUT(E8toE5_cur));
    square_data_reg R_F4toF1(.CLK, .RESET, .REG_DATA_IN(F4toF1_next), .REG_DATA_OUT(F4toF1_cur));
    square_data_reg R_F8toF5(.CLK, .RESET, .REG_DATA_IN(F8toF5_next), .REG_DATA_OUT(F8toF5_cur));
    square_data_reg R_G4toG1(.CLK, .RESET, .REG_DATA_IN(G4toG1_next), .REG_DATA_OUT(G4toG1_cur));
    square_data_reg R_G8toG5(.CLK, .RESET, .REG_DATA_IN(G8toG5_next), .REG_DATA_OUT(G8toG1_cur));
    square_data_reg R_H4toH1(.CLK, .RESET, .REG_DATA_IN(H4toH1_next), .REG_DATA_OUT(H4toH1_cur));
    square_data_reg R_H8toH5(.CLK, .RESET, .REG_DATA_IN(H8toH5_next), .REG_DATA_OUT(H8toH5_cur));
    
    // Read routing
    assign READ_DATA = read_data;
    always_comb begin
        read_data = 32'b0;
        if(READ & CS == 1) begin
            case(ADDR)
                4'h0: read_data = A4toA1_cur;
                4'h1: read_data = A8toA5_cur;
                4'h2: read_data = B4toB1_cur;
                4'h3: read_data = B8toB5_cur;
                4'h4: read_data = C4toC1_cur;
                4'h5: read_data = C8toC5_cur;
                4'h6: read_data = D4toD1_cur;
                4'h7: read_data = D8toD5_cur;
                4'h8: read_data = E4toE1_cur;
                4'h9: read_data = E8toE5_cur;
                4'hA: read_data = F4toF1_cur;
                4'hB: read_data = F8toF5_cur;
                4'hC: read_data = G4toG1_cur;
                4'hD: read_data = G8toG5_cur;
                4'hE: read_data = H4toH1_cur;
                4'hF: read_data = H8toH5_cur;
            endcase
        end
    end
    
    // Export routing
    assign EXPORT_DATA = 32'b0;
    
endmodule

/************************************************************************

************************************************************************/
module square_data_reg (
	input  logic        CLK,
	input  logic        RESET,
	input  logic [31:0] REG_DATA_IN,
	output logic [31:0] REG_DATA_OUT
);

// Internal register
logic [31:0] data;

assign REG_DATA_OUT = data;

always_ff @ (posedge CLK) begin
	if(RESET) data = 32'b0; 
	else data = REG_DATA_IN;
end
endmodule 

/************************************************************************

************************************************************************/
module reg_mux (
	input logic  WRITE,			
    input logic  [3:0] ADDR, 
    input logic  [3:0] NAME, 
    input logic  [31:0] WRITEDATA,		
    input logic  [31:0] RECDATA,		
	output logic [31:0] data_out		
);
	// Temporary data connection
	logic [31:0] temp;			

	// Assign output connections
	assign data_out = temp;		

	// Choose which data to output
	always_comb begin			
		if(WRITE == 1) begin	
			if(ADDR & NAME == 1) begin	
				temp = WRITEDATA;
			end
		end	
		else temp = RECDATA;		
	end					
endmodule 