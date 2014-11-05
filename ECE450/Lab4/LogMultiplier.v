module LogMultiplier(seven_seg, overflow, ledDebug, ain, bin);
	output wire[13:0] seven_seg;
	output reg overflow;
	input [4:0] ain, bin;//TODO YOU HAD THIS AD [3:0] FIX EVERYTHING INCLUDING PINS FOR THE 5 BIT IMPUT INSTEAD OF 4
	output reg [7:0] ledDebug;
	wire [8:0] product;
	log_add (product, ain, bin); 
	always @*
		begin
			overflow = product[8];
			
			ledDebug[7]=product[7];
			ledDebug[6]=product[6];
			ledDebug[5]=product[5];
			ledDebug[4]=product[4];
			ledDebug[3]=product[3];
			ledDebug[2]=product[2];
			ledDebug[1]=product[1];
			ledDebug[0]=product[0];
		end
	conversion (seven_seg[6:0], product[3:0]);
	conversion (seven_seg[13:7], product[7:4]);

endmodule

module conversion(seven_seg, binaryout);
	output reg[6:0] seven_seg;
	input [4:0] binaryout;
	always @*
		begin
			case(binaryout)
				0: seven_seg = 7'b1000000;//0
				1: seven_seg = 7'b1111001;//1
				2: seven_seg = 7'b0100100;//2
				3: seven_seg = 7'b0110000;//3
				4: seven_seg = 7'b0011001;//4
				5: seven_seg = 7'b0010010;//5
				6: seven_seg = 7'b0000010;//6
				7: seven_seg = 7'b1111000;//7
				8: seven_seg = 7'b00000000;//8
				9: seven_seg = 7'b0011000;//9
				10: seven_seg = 7'b0100000;//a
				11: seven_seg = 7'b0000011;//b
				12: seven_seg = 7'b1000110;//C
				13: seven_seg = 7'b0100001;//d
				14: seven_seg = 7'b0000110;//e
				default: seven_seg = 7'b0001110;//F
			endcase
		end
	
	
endmodule
module convert_log(log, binaryin);
	output reg [4:0] log;
	input [4:0] binaryin;
	always @*
		begin
			case(binaryin)
				0: log = 5'b00000;//wat is log(0)
				1: log = 5'b00000;
				2: log = 5'b00110;
				3: log = 5'b01001;
				4: log = 5'b01100;
				5: log = 5'b01101;
				6: log = 5'b01111;
				7: log = 5'b10000;
				8: log = 5'b10010;
				9: log = 5'b10011;
				10: log = 5'b10100;
				11: log = 5'b10100;
				12: log = 5'b10101;
				13: log = 5'b10110;
				14: log = 5'b10110;
				15: log = 5'b10111;
				16: log = 5'b11000;
				17: log = 5'b11000;
				18: log = 5'b11001;
				19: log = 5'b11001;
				20: log = 5'b11010;
				21: log = 5'b11010;
				22: log = 5'b11010;
				23: log = 5'b11011;
				24: log = 5'b11011;
				25: log = 5'b11011;
				26: log = 5'b11100;
				27: log = 5'b11100;
				28: log = 5'b11100;
				29: log = 5'b11101;
				30: log = 5'b11101;
				31: log = 5'b11101;
				//default should never happen
				default: log = 5'b11111;
			endcase
		end	
endmodule
module convert_loginv(binaryout, log);
	output reg [8:0] binaryout;
	input [5:0] log;
	always @*
		begin
			case(log)
				6'b000000: binaryout = 1;
				6'b000001: binaryout = 1;
				6'b000010: binaryout = 1;
				6'b000011: binaryout = 1;
				6'b000100: binaryout = 2;
				6'b000101: binaryout = 2;
				6'b000110: binaryout = 2;
				6'b000111: binaryout = 2;
				6'b001000: binaryout = 3;
				6'b001001: binaryout = 3;
				6'b001010: binaryout = 3;
				6'b001011: binaryout = 4;
				6'b001100: binaryout = 4;
				6'b001101: binaryout = 4;
				6'b001110: binaryout = 5;
				6'b001111: binaryout = 6;
				6'b010000: binaryout = 6;
				6'b010001: binaryout = 7;
				6'b010010: binaryout = 8;
				6'b010011: binaryout = 9;
				6'b010100: binaryout = 10;
				6'b010101: binaryout = 11;
				6'b010110: binaryout = 13;
				6'b010111: binaryout = 14;
				6'b011000: binaryout = 16;
				6'b011001: binaryout = 18;
				6'b011010: binaryout = 20;
				6'b011011: binaryout = 22;
				6'b011100: binaryout = 25;
				6'b011101: binaryout = 28;
				6'b011110: binaryout = 32;
				6'b011111: binaryout = 35;
				6'b100000: binaryout = 40;
				6'b100001: binaryout = 45;
				6'b100010: binaryout = 50;
				6'b100011: binaryout = 56;
				6'b100100: binaryout = 63;
				6'b100101: binaryout = 71;
				6'b100110: binaryout = 79;
				6'b100111: binaryout = 89;
				6'b101000: binaryout = 100;
				6'b101001: binaryout = 112;
				6'b101010: binaryout = 126;
				6'b101011: binaryout = 141;
				6'b101100: binaryout = 158;
				6'b101101: binaryout = 178;
				6'b101110: binaryout = 200;
				6'b101111: binaryout = 224;
				6'b110000: binaryout = 251;
				6'b110001: binaryout = 282;
				6'b110010: binaryout = 316;
				6'b110011: binaryout = 355;
				6'b110100: binaryout = 398;
				6'b110101: binaryout = 447;
				6'b110110: binaryout = 501;
				6'b110111: binaryout = 562;
				6'b111000: binaryout = 631;
				6'b111001: binaryout = 708;
				6'b111010: binaryout = 794;
				6'b111011: binaryout = 891;
				6'b111100: binaryout = 1000;
				default: binaryout = 8'b11111111;
			endcase
		end	
endmodule

module  log_add (product[8:0], ain[4:0], bin[4:0]);
    output wire [8:0] product;
    input [4:0] ain, bin;
    wire [6:0] aLog, bLog;
    wire [7:0] sum;
    convert_log(aLog, ain);//converts the inputs to log form
    convert_log(bLog, bin);
    wire c0;
	assign {c0,sum} = aLog + bLog;
	convert_loginv (product, sum);//converts log sum back to integer
endmodule
