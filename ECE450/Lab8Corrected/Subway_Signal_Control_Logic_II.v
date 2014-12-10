module Subway_Signal_Control_Logic_II(D, P, CLK, A, B, C, cur_state);
	output D, A, B, C;
	output [2:0] cur_state;
	input wire [2:1] P;
	input wire CLK;
	
	state(D,P, A, B, C, CLK);
	//stated(D, CLK, P, RESET, cur_state);
endmodule

module state(D, P, A, B, C, CLK);
	input wire [2:1] P;
	input wire CLK;
	output reg D;
	initial D=1;
	output reg A, B, C;
	initial A=0;
	initial B=0;
	initial C=0;

	always @ (posedge CLK)
		begin
			A = (!A*B*C*!P[1]*P[2])+(A*!B*!C*P[1]*!P[2])+(A*!B*!P[1]*!P[2])+(A*!B*P[2]);//(!A*B*C*!P[1]*P[2])+(A*!B);
			B =	(!A*!B*C*!P[1]*P[2])+(!A*B*!C*!P[1]*P[2])+(!A*B*!P[2])+(!A*B*P[1]*P[2]);//(!A*!B*C*!P[1]*P[2])+(!A*B*!C*!P[1]*!P[2])+(!A*B*!P[2])+(!A*B*P[1]*P[2]);
			C = (!A*!C*P[1]*!P[2])+(!A*B*C*!P[1]*!P[2])+(!A*B*C*P[1]*P[2])+(A*!B*!C*!P[1]*P[2])+(!B*C*!P[1]*!P[2])+(!B*C*P[1]*P[2]);//(!A*!C*P[1]*!P[2])+(!A*B*C*!P[1]*!P[2])+(!A*B*C*P[1]*P[2])+(A*!B*!C*!P[1]*P[2])+(!B*C*!P[1]*!P[2])+(!B*C*P[1]*P[2]);
			D = (!A*!B*C*!P[1]*P[2])+(!A*!C*!P[1]*P[2])+(!A*!C*P[1]*!P[2])+(!A*!P[1]*!P[2])+(!A*B*C*P[1]*!P[2])+(!A*P[1]*P[2])+(!B*C*P[1]*!P[2]);//(!A*!B*C*!P[1]*P[2])+(A*!C*!P[1]*P[2])+(!A*!C*P[1]*!P[2])+(!A*!P[1]*!P[2])+(!A*B*C*P[1]*!P[2])+(!A*P[1]*!P[2])+(!B*C*P[1]*!P[2]);
		end
endmodule
module stated(D, CLK, P, RESET, cur_state);
	output reg D;
	input [2:1] P;
	input RESET, CLK;
	output reg [2:0] cur_state;
	initial cur_state=0;
	initial D=1;
	always @ (posedge CLK) begin 
		if(RESET) begin
			cur_state=0;
		end
		case (cur_state)
			0:	if(P[1])begin 
					cur_state=1;
					D=1;end
			1:	begin if(P[2]) 
					cur_state=2;
				else if(P[1])
					cur_state=0;
				end
			2:	if(P[1]) 
					cur_state=3;
			3:	begin if(P[2])begin 
					cur_state=4;
					D=0;end
				else if(P[1])
					cur_state=2;
				end			
			4:	if(P[2]) 
					cur_state=5;
			5:	begin if(P[2])
					cur_state=4;
				else if(P[1])begin 
					cur_state=0;
					D=1;end
				end
			default: D=1;
		
		endcase
	end
endmodule 