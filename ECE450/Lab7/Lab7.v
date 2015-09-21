module Lab7(CLK2, CLK4, P, P23, PULSE1, PULSE2, clk, clr, enable);
	output [4:1] P;
	output P23, PULSE1, PULSE2;
	output reg CLK2, CLK4;
	input clk, clr, enable;
	create_pulse_clock(P, P23, clk, enable, clr);
	pyramid_counter(PULSE1, PULSE2, clk, enable, clr);
	always @ (negedge clk)
		begin
			if (clr)begin
				CLK2=0;
			end
			if (enable)begin
				CLK2=~CLK2;
			end
		end
	always @ (posedge CLK2)
		begin
			if (clr)begin
				CLK4=0;
			end
			if(enable) begin
				CLK4=~CLK4;
			end
		end
endmodule

module create_pulse_clock(P, P23, clk, clr, enable);
	output reg[4:1] P;
	output reg P23;
	input clk, enable, clr;
	always @ (negedge clk)
		begin
		if(enable) begin
				//if the outputs are currently rotate the outputs of these
				case(P)
					1: begin
						P = 4'b0010;
						P23=1;//1
						end
					2: P = 4'b0100;//2
					4: begin 
						P = 4'b1000;
						P23=0;//3
						end
					8: P = 4'b0001;//4
					default: P = 4'b0001;//probably after a clear or something
				endcase
			end
			if (clr)begin
				P=4'b0000;
				P23=0;
			end
		end
endmodule
module pyramid_counter(PULSE1, PULSE2, clk, enable, clr);
	input clk, enable, clr; 
	output reg PULSE1, PULSE2;
	reg [3:0]cnt1=0, cnt2=15;
	always @ (posedge clk)begin
		if (enable)begin
			PULSE1=0;
			PULSE2=0;
			cnt1=cnt1 + 1;
			if (!(cnt1==cnt2))begin
				PULSE2=0;
				PULSE1=0;
			end	else begin
				cnt1=0;
				cnt2=cnt2 - 1;
				PULSE1=1;
				if (!(cnt2))begin
					cnt2=15;
					PULSE2=1;
				end
			end
			
		end
	end
endmodule



































