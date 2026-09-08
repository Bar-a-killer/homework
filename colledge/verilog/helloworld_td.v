`timescale 1ns / 1ns
module helloworld_td;
    reg ain;
    reg bin;
    wire yout;

    helloworld uut (
        .a(ain),
        .b(bin),
        .y(yout)
    );

    initial begin 
        ain = 0; bin = 0;
        #10;
        ain = 0; bin = 1;
        #10;
        ain = 1; bin = 0;
        #10;
        ain = 1; bin = 1;
        #10;
        $finish;
    end

    initial begin
        $dumpfile("helloworld_td.vcd");
        $dumpvars(0, helloworld_td);
    end
endmodule
