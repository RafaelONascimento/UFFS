module values(input CLOCK_50, 
	      output [1:0]LEDG);
   
   reg [32:0] counter;
   reg lightON=0;
   
   assign LEDG[0] = lightON;
   assign LEDG[1] = ~lightON;
	
   always @(posedge CLOCK_50) begin		
      if(counter == 50000000) begin
	 lightON = ~lightON;
	 counter = 0;
      end
      else begin
	 counter <= counter+1;
      end
   end
   
endmodule
   
module test;
   
   reg clk;
   wire [1:0]light;
   
   
   values adder(clk,
		light);
   
   always #1 clk = ~clk;
   
   initial begin
      $dumpvars(0,adder);
      #0;
      clk <= 0;
      #400000000;
      $finish;   
   end
endmodule
