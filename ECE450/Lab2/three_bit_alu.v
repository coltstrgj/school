module three_bit_alu(seven_seg, cout, ain, bin, funsel);
	output wire[6:0] seven_seg;
	output reg cout;
	input [2:0] ain, bin;
	input [1:0] funsel;
	wire [3:0] three_bit_alu;
	three_bit_out (three_bit_alu, funsel, ain, bin); 
	always @*
		begin
			cout = three_bit_alu[3];
		end
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
module  slice (fout, cout, funsel[1:0], ain, bin, cin);
    input [1:0] funsel;
    input ain, bin, cin;
    output reg fout, cout;
	always @*
		begin
			case(funsel)
				0:	begin
						fout = ain ^ bin ^ cin;
						cout = (ain & bin) + (cin & (ain ^ bin)); 
					end
				1: 	begin
						fout = ain ^ bin ^ cin;
						cout = (~ain & bin) + (cin & ~(ain ^ bin)); 
					end
				2:	begin
						fout = ain ^ bin;
						cout = 0; 
					end
				3:	begin
						fout = cin;
						cout = ain; 
					end
			endcase
		end


endmodule
/*
module  slice (fout, cout, funsel1, funsel0, ain, bin, cin);
    input funsel1, funsel0, ain, bin, cin;
    output fout, cout;
    wire bXc, bXcXa, f1NOT, flhs, aXb, f0NOT, f0Ac, f0NAaXb, aXbAf0NOf0Ac, frhs, clhs, aOb, cAaOb, f0AaNAbOc, cmid, bAc, bOc, aNOT, aNAbOc, lotsofc, crhs, partc, aAbOc; //aOb
   
    xor (bXc, bin, cin),
        (bXcXa, bXc, ain);
    not (f1NOT, funsel1);
    and (flhs, f1NOT, bXcXa);
    //flhs=f1'(ax(bxc))
    xor (aXb, ain, bin);
    not (f0NOT, funsel0);
    and (f0Ac, funsel0, cin),
        (f0NAaXb, aXb, f0NOT);
    or  (aXbAf0NOf0Ac, f0NAaXb, f0Ac);
    and (frhs, aXbAf0NOf0Ac, funsel1);
    //frhs=f1(f0'(axb)+f0c)
    or  (fout, flhs, frhs);

/////////////////////////////////////////////////////
    /////////cout from here down
	and	(clhs, ain, funsel1);
	//clhs=AF1
 /*   or  (aOb, ain, bin);
    and (cAaOb, aOb, cin),
        (cmid, cAaOb, f0NOT);//could be combined with one above if accuracy is not an issue
    //cmid=f0'(c(a+b))////wrong on the net*//*
    //or	(bOc, bin, cin);
    and	(aAbOc, ain, bOc),
		(cmid, f0NOT, aAbOc);
    //cmid=F0(a(b+c))
    and (bAc, bin, cin);
    or  (bOc, bin, cin);
    not (aNOT, ain);
    and (aNAbOc, anot, bOc),
        (f0AaNAbOc, aNAbOc, funsel0);//could be combined
    or	(lotsofc, f0AaNAbOc, bAc);
    and	(crhs, f1NOT, lotsofc);
	//crhs=f1'((bc)+ f0(a'(b+c)))
    or  (partc, crhs, cmid),
        (cout, clhs, partc);//could be combined

endmodule
*/

module  three_bit_out (funcOut[3:0], funsel[1:0], ain[2:0], bin[2:0]);
    output [3:0] funcOut;
    input [1:0] funsel;
    input [2:0] ain, bin;
    wire c0, c1;//need c2?
    
    slice   (funcOut[0], c0, funsel, ain[0], bin[0], 0);//will this work?
    slice	(funcOut[1], c1, funsel, ain[1], bin[1], c0);
    slice	(funcOut[2], funcOut[3], funsel, ain[2], bin[2], c1);
endmodule