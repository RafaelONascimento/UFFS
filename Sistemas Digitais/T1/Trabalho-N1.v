module Values(
       input i_clk,
       output o_light);
   
   assign o_light = i_clk;
   
endmodule

module test;

   reg i_clk;
   wire o_light;
   
   Values V(i_clk,o_light);

   always #1 i_clk = ~i_clk;
   
   
   initial begin
      $dumpvars(0, V);
      i_clk <= 1'b1;
      #500;
      $finish;
   end
endmodule
