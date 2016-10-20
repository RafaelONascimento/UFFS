module triangleMemory(input clk,
		      input [2:0]  andress,
		      output [9:0]ax, ay, bx, by, cx,cy);
   
   always @(posedge clk) begin
      case (andress)
	0: begin
	   ax = 30;
	   ay = 180;
	   bx = 510;
	   by = 150;
	   cx = 120;
	   cy = 420;
       	end
	1: begin
	   ax = 300;
	   ay = 360;
	   bx = 540;
	   by = 390;
	   cx = 390;
	   cy = 540;
	end
	2: begin
	   ax = 150;
	   ay = 480;
	   bx = 270;
	   by = 570;
	   cx = 120;
	   cy = 630;
	end
	3: begin
	   ax = 540;
	   ay = 570;
	   bx = 480;
	   by = 630;
	   
	end
	
data = {300,360,540,390,390,540};
	2: data = {150,480,270,570,120,630};
	3: data = {540,570,480,630,450,540};
      endcase 
   end
endmodule
