/************************************************************************
Avalon-MM Interface for AES Decryption IP Core

Dong Kai Wang, Fall 2017

For use with ECE 385 Experiment 9
University of Illinois ECE Department

Register Map:
 0-7:   a1-a8
 8-15:  b1-b8
 16-23: c1-c8
 24-31: d1-d8
 32-39: e1-e8
 40-47: f1-f8
 48-55: g1-g8
 56-63: h1-h8

************************************************************************/

module chess_game_interface(
    input  logic        CLK,
    input  logic        RESET,
    input  logic        READ,
    input  logic        WRITE,
    input  logic        CS,
    input  logic [3:0]  BYTE_EN,
    input  logic [7:0]  ADDR,
    input  logic [31:0] WRITE_DATA,
    output logic [31:0] READ_DATA,
    output logic [31:0] EXPORT_DATA
);
    
    // Declare connection for read routing
    logic [31:0] read_data;
    logic [31:0] WRITEDATA;
    
    // Declare internal logic connections for new data input
    logic [31:0] A_next [7:0];
    logic [31:0] B_next [7:0];
    logic [31:0] C_next [7:0];
    logic [31:0] D_next [7:0];
    logic [31:0] E_next [7:0];
    logic [31:0] F_next [7:0];
    logic [31:0] G_next [7:0];
    logic [31:0] H_next [7:0];
    
    // Declare internal logic connections for recycled data
    logic [31:0] A_cur [7:0];
    logic [31:0] B_cur [7:0];
    logic [31:0] C_cur [7:0];
    logic [31:0] D_cur [7:0];
    logic [31:0] E_cur [7:0];
    logic [31:0] F_cur [7:0];
    logic [31:0] G_cur [7:0];
    logic [31:0] H_cur [7:0];
    
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
    
    // Declare muxes for each of the 64 registers
    reg_mux M_A1(.WRITE, .ADDR, .NAME(6'h00), .WRITEDATA, .RECDATA(A_cur[0]), .data_out(A_next[0]));
    reg_mux M_A2(.WRITE, .ADDR, .NAME(6'h01), .WRITEDATA, .RECDATA(A_cur[1]), .data_out(A_next[1]));
    reg_mux M_A3(.WRITE, .ADDR, .NAME(6'h02), .WRITEDATA, .RECDATA(A_cur[2]), .data_out(A_next[2]));
    reg_mux M_A4(.WRITE, .ADDR, .NAME(6'h03), .WRITEDATA, .RECDATA(A_cur[3]), .data_out(A_next[3]));
    reg_mux M_A5(.WRITE, .ADDR, .NAME(6'h04), .WRITEDATA, .RECDATA(A_cur[4]), .data_out(A_next[4]));
    reg_mux M_A6(.WRITE, .ADDR, .NAME(6'h05), .WRITEDATA, .RECDATA(A_cur[5]), .data_out(A_next[5]));
    reg_mux M_A7(.WRITE, .ADDR, .NAME(6'h06), .WRITEDATA, .RECDATA(A_cur[6]), .data_out(A_next[6]));
    reg_mux M_A8(.WRITE, .ADDR, .NAME(6'h07), .WRITEDATA, .RECDATA(A_cur[7]), .data_out(A_next[7]));
    
    reg_mux M_B1(.WRITE, .ADDR, .NAME(6'h08), .WRITEDATA, .RECDATA(B_cur[0]), .data_out(B_next[0]));
    reg_mux M_B2(.WRITE, .ADDR, .NAME(6'h09), .WRITEDATA, .RECDATA(B_cur[1]), .data_out(B_next[1]));
    reg_mux M_B3(.WRITE, .ADDR, .NAME(6'h0A), .WRITEDATA, .RECDATA(B_cur[2]), .data_out(B_next[2]));
    reg_mux M_B4(.WRITE, .ADDR, .NAME(6'h0B), .WRITEDATA, .RECDATA(B_cur[3]), .data_out(B_next[3]));
    reg_mux M_B5(.WRITE, .ADDR, .NAME(6'h0C), .WRITEDATA, .RECDATA(B_cur[4]), .data_out(B_next[4]));
    reg_mux M_B6(.WRITE, .ADDR, .NAME(6'h0D), .WRITEDATA, .RECDATA(B_cur[5]), .data_out(B_next[5]));
    reg_mux M_B7(.WRITE, .ADDR, .NAME(6'h0E), .WRITEDATA, .RECDATA(B_cur[6]), .data_out(B_next[6]));
    reg_mux M_B8(.WRITE, .ADDR, .NAME(6'h0F), .WRITEDATA, .RECDATA(B_cur[7]), .data_out(B_next[7]));
    
    reg_mux M_C1(.WRITE, .ADDR, .NAME(6'h10), .WRITEDATA, .RECDATA(C_cur[0]), .data_out(C_next[0]));
    reg_mux M_C2(.WRITE, .ADDR, .NAME(6'h11), .WRITEDATA, .RECDATA(C_cur[1]), .data_out(C_next[1]));
    reg_mux M_C3(.WRITE, .ADDR, .NAME(6'h12), .WRITEDATA, .RECDATA(C_cur[2]), .data_out(C_next[2]));
    reg_mux M_C4(.WRITE, .ADDR, .NAME(6'h13), .WRITEDATA, .RECDATA(C_cur[3]), .data_out(C_next[3]));
    reg_mux M_C5(.WRITE, .ADDR, .NAME(6'h14), .WRITEDATA, .RECDATA(C_cur[4]), .data_out(C_next[4]));
    reg_mux M_C6(.WRITE, .ADDR, .NAME(6'h15), .WRITEDATA, .RECDATA(C_cur[5]), .data_out(C_next[5]));
    reg_mux M_C7(.WRITE, .ADDR, .NAME(6'h16), .WRITEDATA, .RECDATA(C_cur[6]), .data_out(C_next[6]));
    reg_mux M_C8(.WRITE, .ADDR, .NAME(6'h17), .WRITEDATA, .RECDATA(C_cur[7]), .data_out(C_next[7]));
    
    reg_mux M_D1(.WRITE, .ADDR, .NAME(6'h18), .WRITEDATA, .RECDATA(D_cur[0]), .data_out(D_next[0]));
    reg_mux M_D2(.WRITE, .ADDR, .NAME(6'h19), .WRITEDATA, .RECDATA(D_cur[1]), .data_out(D_next[1]));
    reg_mux M_D3(.WRITE, .ADDR, .NAME(6'h1A), .WRITEDATA, .RECDATA(D_cur[2]), .data_out(D_next[2]));
    reg_mux M_D4(.WRITE, .ADDR, .NAME(6'h1B), .WRITEDATA, .RECDATA(D_cur[3]), .data_out(D_next[3]));
    reg_mux M_D5(.WRITE, .ADDR, .NAME(6'h1C), .WRITEDATA, .RECDATA(D_cur[4]), .data_out(D_next[4]));
    reg_mux M_D6(.WRITE, .ADDR, .NAME(6'h1D), .WRITEDATA, .RECDATA(D_cur[5]), .data_out(D_next[5]));
    reg_mux M_D7(.WRITE, .ADDR, .NAME(6'h1E), .WRITEDATA, .RECDATA(D_cur[6]), .data_out(D_next[6]));
    reg_mux M_D8(.WRITE, .ADDR, .NAME(6'h1F), .WRITEDATA, .RECDATA(D_cur[7]), .data_out(D_next[7]));
    
    reg_mux M_E1(.WRITE, .ADDR, .NAME(6'h20), .WRITEDATA, .RECDATA(E_cur[0]), .data_out(E_next[0]));
    reg_mux M_E2(.WRITE, .ADDR, .NAME(6'h21), .WRITEDATA, .RECDATA(E_cur[1]), .data_out(E_next[1]));
    reg_mux M_E3(.WRITE, .ADDR, .NAME(6'h22), .WRITEDATA, .RECDATA(E_cur[2]), .data_out(E_next[2]));
    reg_mux M_E4(.WRITE, .ADDR, .NAME(6'h23), .WRITEDATA, .RECDATA(E_cur[3]), .data_out(E_next[3]));
    reg_mux M_E5(.WRITE, .ADDR, .NAME(6'h24), .WRITEDATA, .RECDATA(E_cur[4]), .data_out(E_next[4]));
    reg_mux M_E6(.WRITE, .ADDR, .NAME(6'h25), .WRITEDATA, .RECDATA(E_cur[5]), .data_out(E_next[5]));
    reg_mux M_E7(.WRITE, .ADDR, .NAME(6'h26), .WRITEDATA, .RECDATA(E_cur[6]), .data_out(E_next[6]));
    reg_mux M_E8(.WRITE, .ADDR, .NAME(6'h27), .WRITEDATA, .RECDATA(E_cur[7]), .data_out(E_next[7]));
    
    reg_mux M_F1(.WRITE, .ADDR, .NAME(6'h28), .WRITEDATA, .RECDATA(F_cur[0]), .data_out(F_next[0]));
    reg_mux M_F2(.WRITE, .ADDR, .NAME(6'h29), .WRITEDATA, .RECDATA(F_cur[1]), .data_out(F_next[1]));
    reg_mux M_F3(.WRITE, .ADDR, .NAME(6'h2A), .WRITEDATA, .RECDATA(F_cur[2]), .data_out(F_next[2]));
    reg_mux M_F4(.WRITE, .ADDR, .NAME(6'h2B), .WRITEDATA, .RECDATA(F_cur[3]), .data_out(F_next[3]));
    reg_mux M_F5(.WRITE, .ADDR, .NAME(6'h2C), .WRITEDATA, .RECDATA(F_cur[4]), .data_out(F_next[4]));
    reg_mux M_F6(.WRITE, .ADDR, .NAME(6'h2D), .WRITEDATA, .RECDATA(F_cur[5]), .data_out(F_next[5]));
    reg_mux M_F7(.WRITE, .ADDR, .NAME(6'h2E), .WRITEDATA, .RECDATA(F_cur[6]), .data_out(F_next[6]));
    reg_mux M_F8(.WRITE, .ADDR, .NAME(6'h2F), .WRITEDATA, .RECDATA(F_cur[7]), .data_out(F_next[7]));
    
    reg_mux M_G1(.WRITE, .ADDR, .NAME(6'h30), .WRITEDATA, .RECDATA(G_cur[0]), .data_out(G_next[0]));
    reg_mux M_G2(.WRITE, .ADDR, .NAME(6'h31), .WRITEDATA, .RECDATA(G_cur[1]), .data_out(G_next[1]));
    reg_mux M_G3(.WRITE, .ADDR, .NAME(6'h32), .WRITEDATA, .RECDATA(G_cur[2]), .data_out(G_next[2]));
    reg_mux M_G4(.WRITE, .ADDR, .NAME(6'h33), .WRITEDATA, .RECDATA(G_cur[3]), .data_out(G_next[3]));
    reg_mux M_G5(.WRITE, .ADDR, .NAME(6'h34), .WRITEDATA, .RECDATA(G_cur[4]), .data_out(G_next[4]));
    reg_mux M_G6(.WRITE, .ADDR, .NAME(6'h35), .WRITEDATA, .RECDATA(G_cur[5]), .data_out(G_next[5]));
    reg_mux M_G7(.WRITE, .ADDR, .NAME(6'h36), .WRITEDATA, .RECDATA(G_cur[6]), .data_out(G_next[6]));
    reg_mux M_G8(.WRITE, .ADDR, .NAME(6'h37), .WRITEDATA, .RECDATA(G_cur[7]), .data_out(G_next[7]));
    
    reg_mux M_H1(.WRITE, .ADDR, .NAME(6'h38), .WRITEDATA, .RECDATA(H_cur[0]), .data_out(H_next[0]));
    reg_mux M_H2(.WRITE, .ADDR, .NAME(6'h39), .WRITEDATA, .RECDATA(H_cur[1]), .data_out(H_next[1]));
    reg_mux M_H3(.WRITE, .ADDR, .NAME(6'h3A), .WRITEDATA, .RECDATA(H_cur[2]), .data_out(H_next[2]));
    reg_mux M_H4(.WRITE, .ADDR, .NAME(6'h3B), .WRITEDATA, .RECDATA(H_cur[3]), .data_out(H_next[3]));
    reg_mux M_H5(.WRITE, .ADDR, .NAME(6'h3C), .WRITEDATA, .RECDATA(H_cur[4]), .data_out(H_next[4]));
    reg_mux M_H6(.WRITE, .ADDR, .NAME(6'h3D), .WRITEDATA, .RECDATA(H_cur[5]), .data_out(H_next[5]));
    reg_mux M_H7(.WRITE, .ADDR, .NAME(6'h3E), .WRITEDATA, .RECDATA(H_cur[6]), .data_out(H_next[6]));
    reg_mux M_H8(.WRITE, .ADDR, .NAME(6'h3F), .WRITEDATA, .RECDATA(H_cur[7]), .data_out(H_next[7]));

    // Declare the 64 registers
    square_data_reg R_A1(.CLK, .RESET, .REG_DATA_IN(A_next[0]), .REG_DATA_OUT(A_cur[0]));
    square_data_reg R_A2(.CLK, .RESET, .REG_DATA_IN(A_next[1]), .REG_DATA_OUT(A_cur[1]));
    square_data_reg R_A3(.CLK, .RESET, .REG_DATA_IN(A_next[2]), .REG_DATA_OUT(A_cur[2]));
    square_data_reg R_A4(.CLK, .RESET, .REG_DATA_IN(A_next[3]), .REG_DATA_OUT(A_cur[3]));
    square_data_reg R_A5(.CLK, .RESET, .REG_DATA_IN(A_next[4]), .REG_DATA_OUT(A_cur[4]));
    square_data_reg R_A6(.CLK, .RESET, .REG_DATA_IN(A_next[5]), .REG_DATA_OUT(A_cur[5]));
    square_data_reg R_A7(.CLK, .RESET, .REG_DATA_IN(A_next[6]), .REG_DATA_OUT(A_cur[6]));
    square_data_reg R_A8(.CLK, .RESET, .REG_DATA_IN(A_next[7]), .REG_DATA_OUT(A_cur[7]));
    
    square_data_reg R_B1(.CLK, .RESET, .REG_DATA_IN(B_next[0]), .REG_DATA_OUT(B_cur[0]));
    square_data_reg R_B2(.CLK, .RESET, .REG_DATA_IN(B_next[1]), .REG_DATA_OUT(B_cur[1]));
    square_data_reg R_B3(.CLK, .RESET, .REG_DATA_IN(B_next[2]), .REG_DATA_OUT(B_cur[2]));
    square_data_reg R_B4(.CLK, .RESET, .REG_DATA_IN(B_next[3]), .REG_DATA_OUT(B_cur[3]));
    square_data_reg R_B5(.CLK, .RESET, .REG_DATA_IN(B_next[4]), .REG_DATA_OUT(B_cur[4]));
    square_data_reg R_B6(.CLK, .RESET, .REG_DATA_IN(B_next[5]), .REG_DATA_OUT(B_cur[5]));
    square_data_reg R_B7(.CLK, .RESET, .REG_DATA_IN(B_next[6]), .REG_DATA_OUT(B_cur[6]));
    square_data_reg R_B8(.CLK, .RESET, .REG_DATA_IN(B_next[7]), .REG_DATA_OUT(B_cur[7]));
    
    square_data_reg R_C1(.CLK, .RESET, .REG_DATA_IN(C_next[0]), .REG_DATA_OUT(C_cur[0]));
    square_data_reg R_C2(.CLK, .RESET, .REG_DATA_IN(C_next[1]), .REG_DATA_OUT(C_cur[1]));
    square_data_reg R_C3(.CLK, .RESET, .REG_DATA_IN(C_next[2]), .REG_DATA_OUT(C_cur[2]));
    square_data_reg R_C4(.CLK, .RESET, .REG_DATA_IN(C_next[3]), .REG_DATA_OUT(C_cur[3]));
    square_data_reg R_C5(.CLK, .RESET, .REG_DATA_IN(C_next[4]), .REG_DATA_OUT(C_cur[4]));
    square_data_reg R_C6(.CLK, .RESET, .REG_DATA_IN(C_next[5]), .REG_DATA_OUT(C_cur[5]));
    square_data_reg R_C7(.CLK, .RESET, .REG_DATA_IN(C_next[6]), .REG_DATA_OUT(C_cur[6]));
    square_data_reg R_C8(.CLK, .RESET, .REG_DATA_IN(C_next[7]), .REG_DATA_OUT(C_cur[7]));
    
    square_data_reg R_D1(.CLK, .RESET, .REG_DATA_IN(D_next[0]), .REG_DATA_OUT(D_cur[0]));
    square_data_reg R_D2(.CLK, .RESET, .REG_DATA_IN(D_next[1]), .REG_DATA_OUT(D_cur[1]));
    square_data_reg R_D3(.CLK, .RESET, .REG_DATA_IN(D_next[2]), .REG_DATA_OUT(D_cur[2]));
    square_data_reg R_D4(.CLK, .RESET, .REG_DATA_IN(D_next[3]), .REG_DATA_OUT(D_cur[3]));
    square_data_reg R_D5(.CLK, .RESET, .REG_DATA_IN(D_next[4]), .REG_DATA_OUT(D_cur[4]));
    square_data_reg R_D6(.CLK, .RESET, .REG_DATA_IN(D_next[5]), .REG_DATA_OUT(D_cur[5]));
    square_data_reg R_D7(.CLK, .RESET, .REG_DATA_IN(D_next[6]), .REG_DATA_OUT(D_cur[6]));
    square_data_reg R_D8(.CLK, .RESET, .REG_DATA_IN(D_next[7]), .REG_DATA_OUT(D_cur[7]));
    
    square_data_reg R_E1(.CLK, .RESET, .REG_DATA_IN(E_next[0]), .REG_DATA_OUT(E_cur[0]));
    square_data_reg R_E2(.CLK, .RESET, .REG_DATA_IN(E_next[1]), .REG_DATA_OUT(E_cur[1]));
    square_data_reg R_E3(.CLK, .RESET, .REG_DATA_IN(E_next[2]), .REG_DATA_OUT(E_cur[2]));
    square_data_reg R_E4(.CLK, .RESET, .REG_DATA_IN(E_next[3]), .REG_DATA_OUT(E_cur[3]));
    square_data_reg R_E5(.CLK, .RESET, .REG_DATA_IN(E_next[4]), .REG_DATA_OUT(E_cur[4]));
    square_data_reg R_E6(.CLK, .RESET, .REG_DATA_IN(E_next[5]), .REG_DATA_OUT(E_cur[5]));
    square_data_reg R_E7(.CLK, .RESET, .REG_DATA_IN(E_next[6]), .REG_DATA_OUT(E_cur[6]));
    square_data_reg R_E8(.CLK, .RESET, .REG_DATA_IN(E_next[7]), .REG_DATA_OUT(E_cur[7]));
    
    square_data_reg R_F1(.CLK, .RESET, .REG_DATA_IN(F_next[0]), .REG_DATA_OUT(F_cur[0]));
    square_data_reg R_F2(.CLK, .RESET, .REG_DATA_IN(F_next[1]), .REG_DATA_OUT(F_cur[1]));
    square_data_reg R_F3(.CLK, .RESET, .REG_DATA_IN(F_next[2]), .REG_DATA_OUT(F_cur[2]));
    square_data_reg R_F4(.CLK, .RESET, .REG_DATA_IN(F_next[3]), .REG_DATA_OUT(F_cur[3]));
    square_data_reg R_F5(.CLK, .RESET, .REG_DATA_IN(F_next[4]), .REG_DATA_OUT(F_cur[4]));
    square_data_reg R_F6(.CLK, .RESET, .REG_DATA_IN(F_next[5]), .REG_DATA_OUT(F_cur[5]));
    square_data_reg R_F7(.CLK, .RESET, .REG_DATA_IN(F_next[6]), .REG_DATA_OUT(F_cur[6]));
    square_data_reg R_F8(.CLK, .RESET, .REG_DATA_IN(F_next[7]), .REG_DATA_OUT(F_cur[7]));
    
    square_data_reg R_G1(.CLK, .RESET, .REG_DATA_IN(G_next[0]), .REG_DATA_OUT(G_cur[0]));
    square_data_reg R_G2(.CLK, .RESET, .REG_DATA_IN(G_next[1]), .REG_DATA_OUT(G_cur[1]));
    square_data_reg R_G3(.CLK, .RESET, .REG_DATA_IN(G_next[2]), .REG_DATA_OUT(G_cur[2]));
    square_data_reg R_G4(.CLK, .RESET, .REG_DATA_IN(G_next[3]), .REG_DATA_OUT(G_cur[3]));
    square_data_reg R_G5(.CLK, .RESET, .REG_DATA_IN(G_next[4]), .REG_DATA_OUT(G_cur[4]));
    square_data_reg R_G6(.CLK, .RESET, .REG_DATA_IN(G_next[5]), .REG_DATA_OUT(G_cur[5]));
    square_data_reg R_G7(.CLK, .RESET, .REG_DATA_IN(G_next[6]), .REG_DATA_OUT(G_cur[6]));
    square_data_reg R_G8(.CLK, .RESET, .REG_DATA_IN(G_next[7]), .REG_DATA_OUT(G_cur[7]));
    
    square_data_reg R_H1(.CLK, .RESET, .REG_DATA_IN(H_next[0]), .REG_DATA_OUT(H_cur[0]));
    square_data_reg R_H2(.CLK, .RESET, .REG_DATA_IN(H_next[1]), .REG_DATA_OUT(H_cur[1]));
    square_data_reg R_H3(.CLK, .RESET, .REG_DATA_IN(H_next[2]), .REG_DATA_OUT(H_cur[2]));
    square_data_reg R_H4(.CLK, .RESET, .REG_DATA_IN(H_next[3]), .REG_DATA_OUT(H_cur[3]));
    square_data_reg R_H5(.CLK, .RESET, .REG_DATA_IN(H_next[4]), .REG_DATA_OUT(H_cur[4]));
    square_data_reg R_H6(.CLK, .RESET, .REG_DATA_IN(H_next[5]), .REG_DATA_OUT(H_cur[5]));
    square_data_reg R_H7(.CLK, .RESET, .REG_DATA_IN(H_next[6]), .REG_DATA_OUT(H_cur[6]));
    square_data_reg R_H8(.CLK, .RESET, .REG_DATA_IN(H_next[7]), .REG_DATA_OUT(H_cur[7]));

    // Read routing
    assign READ_DATA = read_data;
    always_comb begin
        read_data = 32'b0;
        if(READ & CS == 1) begin
            case(ADDR)
                6'h00: read_data = A_cur[0];
                6'h01: read_data = A_cur[1];
                6'h02: read_data = A_cur[2];
                6'h03: read_data = A_cur[3];
                6'h04: read_data = A_cur[4];
                6'h05: read_data = A_cur[5];
                6'h06: read_data = A_cur[6];
                6'h07: read_data = A_cur[7];
                
                6'h08: read_data = B_cur[0];
                6'h09: read_data = B_cur[1];
                6'h0A: read_data = B_cur[2];
                6'h0B: read_data = B_cur[3];
                6'h0C: read_data = B_cur[4];
                6'h0D: read_data = B_cur[5];
                6'h0E: read_data = B_cur[6];
                6'h0F: read_data = B_cur[7];
                
                6'h10: read_data = C_cur[0];
                6'h11: read_data = C_cur[1];
                6'h12: read_data = C_cur[2];
                6'h13: read_data = C_cur[3];
                6'h14: read_data = C_cur[4];
                6'h15: read_data = C_cur[5];
                6'h16: read_data = C_cur[6];
                6'h17: read_data = C_cur[7];
                
                6'h18: read_data = D_cur[0];
                6'h19: read_data = D_cur[1];
                6'h1A: read_data = D_cur[2];
                6'h1B: read_data = D_cur[3];
                6'h1C: read_data = D_cur[4];
                6'h1D: read_data = D_cur[5];
                6'h1E: read_data = D_cur[6];
                6'h1F: read_data = D_cur[7];
                
                6'h20: read_data = E_cur[0];
                6'h21: read_data = E_cur[1];
                6'h22: read_data = E_cur[2];
                6'h23: read_data = E_cur[3];
                6'h24: read_data = E_cur[4];
                6'h25: read_data = E_cur[5];
                6'h26: read_data = E_cur[6];
                6'h27: read_data = E_cur[7];
                
                6'h28: read_data = F_cur[0];
                6'h29: read_data = F_cur[1];
                6'h2A: read_data = F_cur[2];
                6'h2B: read_data = F_cur[3];
                6'h2C: read_data = F_cur[4];
                6'h2D: read_data = F_cur[5];
                6'h2E: read_data = F_cur[6];
                6'h2F: read_data = F_cur[7];
                
                6'h30: read_data = G_cur[0];
                6'h31: read_data = G_cur[1];
                6'h32: read_data = G_cur[2];
                6'h33: read_data = G_cur[3];
                6'h34: read_data = G_cur[4];
                6'h35: read_data = G_cur[5];
                6'h36: read_data = G_cur[6];
                6'h37: read_data = G_cur[7];
                
                6'h38: read_data = H_cur[0];
                6'h39: read_data = H_cur[1];
                6'h3A: read_data = H_cur[2];
                6'h3B: read_data = H_cur[3];
                6'h3C: read_data = H_cur[4];
                6'h3D: read_data = H_cur[5];
                6'h3E: read_data = H_cur[6];
                6'h3F: read_data = H_cur[7];
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
    input logic  [7:0] ADDR, 
    input logic  [7:0] NAME, 
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