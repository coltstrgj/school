module Subway_Signal_Control_Logic_II(D, P);
	output D;
	input [2:1] P;
	state(D,P);
//	always @ *
//		begin
//		end
endmodule

module state(D, P);
	input reg P[2:1] ;
	output reg D;
	T_FF A(A,(~A&B&C&~P[1]&P[2])+(A&~B&C&P[1]&~P[2]));
	T_FF B(B,(~A&B&C&~P[1]&P[2])+(~A&~B&C&~P[1]&P[2]));
    T_FF C(C,);
    T_FF D(C,(~A&B&C&~P[1]&P[2])+(A&~B&C&P[1]&~P[2]));
	always @ *
		begin
//			A = (~A&B&C&~P[1]&P[2])+(A&~B&C&P[1]&~P[2]);
			B = (~A&B&C&~P[1]&P[2])+(~A&~B&C&~P[1]&P[2]);
			C = (~A&B&C&~P[1]&P[2]);//not Finished at all
			D = (~A&B&C&~P[1]&P[2])+(A&~B&C&P[1]&~P[2]);
		end
endmodule
module T_FF(T, in);
	input reg D;
endmodule 