module three_bit_alu(seven_seg, ain, bin, funsel);
	output wire[6:0] seven_seg;
	input [2:0] ain, bin;
	input [1:0] funsel;
	wire [3:0] three_bit_alu;
	three_bit_out (three_bit_alu, funsel[1], funsel[0], ain, bin); 
	conversion (seven_seg, three_bit_alu);

endmodule

module conversion(seven_seg, binaryIn);
	output reg[6:0] seven_seg;
	input [3:0] binaryIn;
	always @*
		begin
			case(binaryIn)
				0: seven_seg = 7'b1000000;
				1: seven_seg = 7'b1111001;
				2: seven_seg = 7'b0100100;
				3: seven_seg = 7'b0110000;
				4: seven_seg = 7'b0011001;
				5: seven_seg = 7'b0010010;
				6: seven_seg = 7'b0000010;
				7: seven_seg = 7'b1111000;
				8: seven_seg = 7'b00000000;
				9: seven_seg = 7'b0011000;
				10: seven_seg = 7'b0100000;
				11: seven_seg = 7'b0000011;
				12: seven_seg = 7'b1000110;
				13: seven_seg = 7'b0100001;
				14: seven_seg = 7'b0000110;	
				default: seven_seg = 7'b1111111;
			endcase
		end
	
	
endmodule

module  slice (fout, cout, funsel1, funsel0, ain, bin, cin);
    input funsel1, funsel0, ain, bin, cin;
    output fout, cout;
    wire bXc, bXcXa, f1NOT, flhs, aXb, f0NOT, fAc, f0NAaXb, aXbAf0NOf0Ac, frhs, clhs, aOb, cAaOb, cmid, bAc, bOc, aNOT, aNAbOc, crhs, partc; 
   
    xor (bXc, bin, cin),
        (bXcXa, bXc, ain);
    not (f1NOT, funsel1);
    and (flhs, f1NOT, bXcXa);
    
    xor (aXb, ain, bin);
    not (f0NOT, funsel0);
    and (fAc, funsel0, cin),
        (f0NAaXb, aXb, f0NOT);
    or  (aXbAf0NOf0Ac, f0NAaXb, fAc);
    and (frhs, aXbAf0NOf0Ac, funsel1);

    or  (fout, flhs, frhs),

    
        (clhs, ain, funsel1);
    
    or  (aOb, ain, bin);
    and (cAaOb, aOb, cin),
        (cmid, cAaOb, f0NOT);//could be combined with one above if accuracy is not an issue
    
    and (bAc, bin, cin);
    or  (bOc, bin, cin);
    not (aNOT, ain);
    and (aNAbOc, aNOT, bOc),
        (crhs, aNAbOc, f1NOT);//could be combined

    or  (partc, crhs, cmid),
        (cout, clhs, partc);//could be combined

endmodule


module  three_bit_out (funcOut[3:0], funsel1, funsel0, ain[2:0], bin[2:0]);
    output [3:0] funcOut;
    input funsel1, funsel0;
    input [2:0] ain, bin;
    wire c0, c1;//need c2?
    
    slice   (funcOut[0], c0, funsel1, funsel0, ain[0], bin[0], 0),//will this work?
            (funcOut[1], c1, funsel1, funsel0, ain[1], bin[1], c0),
            (funcOut[2], funcOut[3], funsel1, funsel0, ain[2], bin[2], c1);
endmodule
