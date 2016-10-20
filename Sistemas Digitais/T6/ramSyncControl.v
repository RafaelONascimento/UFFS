module ramSyncControl(input clk,
		      input [6:0]key,
		      output reg [9:0] ax,ay,bx,by,cx,cy);

   always @(posedge clk) begin
      case(key)
	0: begin
	   ax <= 248; ay <=  60;
	   bx <= 217; by <= 122;
	   cx <= 279; cy <= 122;
	end
	1: begin
	   ax <= 216; ay <= 124;
	   bx <= 185; by <= 186;
	   cx <= 247; cy <= 186;
	end
	2: begin
	   ax <= 280; ay <= 124;
	   bx <= 249; by <= 186;
	   cx <= 233; cy <= 186;
	end
	3: begin
	   ax <= 120; ay <= 188;
	   bx <= 182; by <= 188;
	   cx <= 151; cy <= 250;
	end
	4: begin
	   ax <= 184; ay <= 188;
	   bx <= 215; by <= 250;
	   cx <= 153; cy <= 250;
	end
	5: begin
	   ax <= 248; ay <= 188;
	   bx <= 217; by <= 250;
	   cx <= 279; cy <= 250;
	end
	6: begin
	   ax <= 312; ay <= 188;
	   bx <= 281; by <= 250;
	   cx <= 343; cy <= 250;
	end
	7: begin
	   ax <= 314; ay <= 188;
	   bx <= 376; by <= 188;
	   cx <= 345; cy <= 250;
	end
	8: begin
	   ax <= 216; ay <= 252;
	   bx <= 185; by <= 314;
	   cx <= 247; cy <= 314;
	end
	9: begin
	   ax <= 280; ay <= 252;
	   bx <= 249; by <= 314;
	   cx <= 233; cy <= 314;
	end
	10: begin
	   ax <= 184; ay <= 317;
	   bx <= 246; by <= 317;
	   cx <= 215; cy <= 379;
	end
	11: begin
	   ax <= 250; ay <= 317;
	   bx <= 312; by <= 317;
	   cx <= 281; cy <= 379;
	end
	12: begin
	   ax <= 217; ay <= 381;
	   bx <= 279; by <= 381;
	   cx <= 248; cy <= 443;
	end
      endcase
   end
endmodule
