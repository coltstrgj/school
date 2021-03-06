//#!;:'what are comments in verilog

module  slice (fout, cout, funsel1, funsel0, ain, bin, cin)
    input funsel1, funsel0, ain, bin, cin;
    output fout, cout;
    wire bXc, bXcXa, f1NOT, flhs, aXb, f0NOT, fAc, f0NAaXb, aXbAf0NOf0Ac, frhs, clhs, aOb, cAaOb, cmid, bAc, bOc, aNOT, aNAbOc, crhs, partc; 
   
    xor (bXc, bin, cin);
        (bXcXa, bXc, ain);
    not (f1NOT, funsel1);
    and (flhs, f1NOT, bXcXa);
    
    xor (aXb, ain, bin);
    not (f0NOT, funsel0);
    and (fAc, funsel0, cin);
        (f0NAaXb, aXb, f0NOT);
    or  (aXbAf0NOf0Ac, f0NAaXb, fAc);
    and (frhs, aXbAf0NOf0Ac, funsel1);

    or  (fout, lhs, rhs);

    
        (clhs, ain, funsel1);
    
    or  (aOb, ain, bin);
    and (cAaOb, aOb, cin);
        (cmid, cAaOb, f0NOT);//could be combined with one above if accuracy is not an issue
    
    and (bAc, bin, cin);
    or  (bOc, bin, cin);
    not (aNOT, ain);
    and (aNAbOc, aNOT, bOc);
        (crhs, aNAbOc, f1NOT);//could be combined

    or  (partc, crhs, cmid);
        (cout, clhs, partc);//could be combined

endmodule


module  3bitALU (funcOut[2:0], funsel1, funsel0, ain[2:0], bin[2:0])
    output funcOut[2:0]
    input funsel1, funsel0, ain[2:0], bin[2:0];
    wire c0, c1, c2;//need c2?
    
    slice   (funcOut[0], c0, funsel1, funsel0, a[0], b[0], 0);//will this work?
            (funcOut[1], c1, funsel1, funsel0, a[1], b[1], c0);
            (funcOut[2], c2, funsel1, funsel0, a[2], b[2], c1);
endmodule

