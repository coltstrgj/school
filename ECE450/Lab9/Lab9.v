module Lab9(output [7:0] A, output [2:0] B, output [2:0] C, output wire ST, input wire TL, input wire TS, input wire SC);
	state(A, B, C, ST, TL, TS, SC);
endmodule

module state(output reg [7:0] A, output reg [2:0] B, output reg [2:0] C, output reg ST, input wire TL, input wire TS, input wire SC);
	reg [3:0] state;
	
	initial A=8'b10000100;
	initial B=3'b100;
	initial C=3'b100;
	initial state=0;
	
	always @(posedge TS) begin
			case (state)
				0:	begin
						A=8'b00101100;
						B=3'b100;
						C=3'b100;
						ST=1;
						state=1;
					end
				1:	begin
						A=8'b00110100;
						B=3'b100;
						C=3'b100;
						ST=1;
						state=2;
					end
				2:	begin
						A=8'b00100100;
						B=3'b100;
						C=3'b100;
						ST=1;
						state=3;
					end
				3:	begin
						A=8'b00100001;
						B=3'b100;
						C=3'b100;
						ST=0;
						state=4;
					end			
				4:	begin
						A=8'b01000010;
						B=3'b100;
						C=3'b100;
						ST=1;
						state=5;
					end
				5:	begin 
						A=8'b10000100;
						B=3'b100;
						C=3'b100;
						ST=1;
						if(SC)//if the farm road has a car then go there.
							state=9;
						if(~SC)
							state=6;
					end
				6:	begin
						A=8'b10000100;
						B=3'b001;
						C=3'b100;
						ST=0;
						state=7;
					end
				7:	begin
						A=8'b10000100;
						B=3'b010;
						C=3'b100;
						ST=1;
						state=8;
					end
				8:	begin
						A=8'b10000100;
						B=3'b100;
						C=3'b100;
						ST=1;
						state=0;
					end
				9:	begin
						A=8'b10000100;
						B=3'b100;
						C=3'b001;
						ST=0;
						state=10;
					end			
				10:	begin
						A=8'b10000100;
						B=3'b100;
						C=3'b010;
						ST=1;
						state=11;
					end
				11:	begin 
						A=8'b10000100;
						B=3'b100;
						C=3'b100;
						ST=1;
						state=0;
					end
				default: 
					begin
						A=8'b11111111;
						B=3'b111;
						C=3'b111;
						ST=0;
						state=0;
					end
		endcase
	end

endmodule