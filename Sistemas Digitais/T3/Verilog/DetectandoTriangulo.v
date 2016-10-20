module calculaCordenadas(input CLOCK_50, 
			 input [32:0]a,
			 output [10:0]x,
			 output [10:0]y);
   reg [32:0]aTmp;
   reg [32:10]l = 0;
   reg [10:0]area;
  
   always @(posedge CLOCK_50) begin
      aTmp = a;
      while(aTmp >= 600)begin
	 aTmp = aTmp-600;
	 l = l+1;
      end
   end
   assign x = l;
   assign y = area -(600-l);
endmodule

module calculaArea(input CLOCK_50,
		   input [10:0]ax,
		   input [10:0]ay,
		   input [10:0]bx,
		   input [10:0]by,
		   input [10:0]cx,
		   input [10:0]cy,
		   output [32:0]area);
   reg [32:0]valor;
 
   always @(posedge CLOCK_50) begin
      valor = (ax*(by-cy) + bx*(cy-ay)+ cx*(ay-by));
      
      if(valor < 0)begin
	 valor = valor *-1;
      end
   end
  
   assign area = valor;
endmodule
  
module main(input CLOCK_50,
	    output [1:0]LEDR,
	    output [1:0]LEDG);
   
   reg [32:0]pontoA = 299;
   reg [32:0]pontoB = 1800;
   reg [32:0]pontoC = 3399;
   reg [32:0]pontoD = 3000;
   reg flag = 0;
   wire [10:0]ax;
   wire [10:0]ay;
   wire [10:0]bx;
   wire [10:0]by;
   wire [10:0]cx;
   wire [10:0]cy;
   wire [10:0]dx;
   wire [10:0]dy;
   wire [32:0]areaA;
   wire [32:0]areaB;
   wire [32:0]areaC;
   wire [32:0]areaD;
  
   calculaCordenadas A(CLOCK_50,pontoA,ax,ay);
   opt2(A())
   calculaCordenadas B(CLOCK_50,pontoB,bx,by);
   calculaCordenadas C(CLOCK_50,pontoC,cx,cy);
   calculaCordenadas D(CLOCK_50,pontoD,dx,dy);

   calculaArea cA(CLOCK_50,ax,ay,bx,by,cx,cy,areaA);
   calculaArea cB(CLOCK_50,dx,dy,bx,by,cx,cy,areaB);
   calculaArea cC(CLOCK_50,ax,ay,dx,dy,cx,cy,areaC);
   calculaArea cD(CLOCK_50,ax,ay,bx,by,dx,dy,areaD);

   assign LEDG[0] = flag;
   assign LEDR[0] = ~flag;
   
   always @(posedge CLOCK_50)begin
      if(areaA == (areaB+areaC+areaD))begin
	 flag = 1;
      end
      else begin
	 flag = 0;
      end	  
   end
   
endmodule
