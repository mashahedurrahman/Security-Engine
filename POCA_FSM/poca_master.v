//`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Md Sami Ul Islam Sami
// 
// Create Date: 08/22/2021 12:48:49 AM
// Design Name: 
// Module Name: poca_master
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


 module poca_master ( clk, rstn, generator_mult, capture_cntl, test_response, go, KS_value, addr_out, is_write, poca_output_response,
write_complete, enable_data_out, data_in, data_input_ready, ecc_input_1, ecc_input_2, hash_input_r, hash_input_g_p_qa_r, hsm_key_received, hsm_public_key,
shared_secret_key_ready,input_data_transfer_complete, poca_output_ready, test_response_ready


 );

  //`include "parameter_poca.v"   
  //input ports
    input [ecc_mult_input_size-1:0] generator_mult;
    input [test_response_size-1:0] test_response;
    input clk, go, rstn;
    input [KS_value_size-1:0] KS_value;
    input write_complete;
    input [data_bus_size-1:0] data_in;     //input data which will come from TRNG, DH and SHA sequencially 32 bit by 32 bit
    input data_input_ready;
    input hsm_key_received;
    input [ecc_output_size-1:0] hsm_public_key;
    input input_data_transfer_complete;
   //output ports 
    output reg capture_cntl;
    output reg [hash_output_size+hash_output_size+ecc_output_size-1:0] poca_output_response;
    output reg [address_bus_size-1:0] addr_out;
    output reg is_write;
//    output reg [total_number_byte_size-1:0] total_number_byte;
    output reg [enable_data_out_size-1:0] enable_data_out;
    output reg [ECC_input_size-1:0] ecc_input_1, ecc_input_2;
    output reg [test_response_size-1:0] hash_input_r;
    output reg [ecc_mult_input_size+P_value_size+ecc_output_size+test_response_size-1:0] hash_input_g_p_qa_r;
    output reg shared_secret_key_ready;
    output reg poca_output_ready;
    output reg test_response_ready; // mash
    //output reg capture_start;
    
    //signals
    //reg [P_value_size-1:0] P_value;
    reg [capture_count_size-1:0] cnt;
    reg capture_en, capture_count_done;
    reg [Private_key_chip_size-1:0] private_key_chip;
    reg private_key_ready;
    reg [ecc_mult_input_size-1:0] generator_reg;
    reg [KS_value_size-1:0] KS_value_reg;
    reg p_value_ready;
    reg [test_response_size-1:0] test_response_reg;
    reg hash_R_ready;
    reg [hash_output_size-1:0] hash_R_reg;
    reg ecc_mult_ready;
    reg [ecc_output_size-1:0] public_key_chip;
    reg hash_combination_ready;
    reg [hash_output_size-1:0] hash_g_p_qa_r;
 //   reg [ecc_mult_input_size+P_value_size+ecc_output_size+test_response_size-1:0] combination__g_p_qa_r;
    reg [ecc_output_size-1:0] hsm_public_key_reg;
    reg secret_key_ready;
    reg [ecc_output_size-1:0] secret_key_chip; 
    //reg test_response_ready;
    reg [test_response_size-1:0] counter_scan_shift;
    reg [TRNG_output_size-1:0] P_value_trng_reg;
	reg ecc_write_wait_additional_cycle;
	reg ecc_write_wait_additional_cycle_cntl;
 //   reg ecc_hash_read_transfer_complete_seperate;
    //state signal
    reg [3:0] state, next_state;
    
    wire [ecc_mult_input_size+P_value_size+ecc_output_size+test_response_size-1:0] combination__g_p_qa_r;
    
    
    assign combination__g_p_qa_r = {generator_reg, P_value_trng_reg[P_value_size-1:0], public_key_chip, test_response_reg};
    //generator "G" stored in register
    always @(posedge clk) begin
         if (rstn == 0) begin
            generator_reg <= 0;
         end
         else begin
            generator_reg <= generator_mult;
         end
    end
    
    //KS_value "KS1" stored in register
    always @(posedge clk) begin
         if (rstn == 0) begin
            KS_value_reg <= 0;
         end
         else begin
            KS_value_reg <= KS_value;
         end
    end
    
     //test_response "R" stored in register
    always @(posedge clk) begin
         if (rstn == 0) begin
            test_response_reg <= 0;
         end
         else begin
            test_response_reg <= test_response;
         end
    end
    
    //Capture control unit
    always @(posedge clk)
    begin
        if (rstn == 0) begin
            capture_cntl <= 0;
            cnt <= 0;
            capture_count_done <= 0;
          //  capture_start <= 0;
        end
        else if (capture_en != 1) begin
            cnt <= {KS_value, P_value_trng_reg[P_value_size-1:0]};
        end
        else if (capture_en == 1) begin
            capture_cntl <= 1;
            cnt <= cnt-1;
      //      capture_start <= 1;
         
            if (cnt == 0) begin
                capture_count_done <= 1;
       //         capture_start <= 0;
                capture_cntl <= 0;
                cnt <= 0;       
            end
         end       
    end
    
    //Scan chain shifts the response to test_response_reg. Counter for imitating the delay for the shifting.
     always @(posedge clk) begin
        if (rstn == 0) begin
            counter_scan_shift <= 0; 
            test_response_ready <= 0;
        end
        else if (capture_count_done == 1) begin
            counter_scan_shift <= counter_scan_shift+1;
            if (counter_scan_shift == test_response_size) begin
                test_response_ready <= 1;
                counter_scan_shift <= 0;
            end
         end
    
    end
    
    //private key of chip 
    always @(posedge clk) begin
        if (rstn == 0) begin
            private_key_chip <= 0; 
   //         count_trng_byte <= 0;
        end
        else if (private_key_ready == 1) begin
   //         count_trng_byte <= count_trng_byte+1;
            private_key_chip <= {data_in, private_key_chip[TRNG_output_size-1:data_bus_size]};
   //             if (count_trng_byte == TRNG_output_size/data_bus_size+1) begin
   //                    count_trng_byte <= 0;
   //             end
         end
    
    end
    
    //P_value of the chip
    always @(posedge clk) begin
        if (rstn == 0) begin
          
			P_value_trng_reg <= 0;
        end
        else if (p_value_ready == 1) begin
            P_value_trng_reg <= {data_in, P_value_trng_reg[TRNG_output_size-1:data_bus_size]};
            
         end
    
    end
	
	
    
    //H(R) of the chip
    always @(posedge clk) begin
        if (rstn == 0) begin
            hash_R_reg <= 0; 
        end
        else if (hash_R_ready == 1) begin
            hash_R_reg <= {data_in, hash_R_reg[hash_output_size-1:data_bus_size]};
         end
    
    end
    
    //Public key "Qa" of the chip
    always @(posedge clk) begin
        if (rstn == 0) begin
            public_key_chip <= 0; 
        end
        else if (ecc_mult_ready == 1) begin
            public_key_chip <= {data_in, public_key_chip[ecc_output_size-1:data_bus_size]};
         end
    
    end
    
    //H(G,P,Qa,R1) of the chip
    always @(posedge clk) begin
        if (rstn == 0) begin
            hash_g_p_qa_r <= 0; 
        end
        else if (hash_combination_ready == 1) begin
            hash_g_p_qa_r <= {data_in, hash_g_p_qa_r[hash_output_size-1:data_bus_size]};
         end
    
    end
    
    
     //HSM public key of the chip
    always @(posedge clk) begin
        if (rstn == 0) begin
            hsm_public_key_reg <= 0; 
        end
        else if (hsm_key_received == 1) begin
            hsm_public_key_reg <=  hsm_public_key;
         end
    
    end
    
     //Secret key "S" of the chip
    always @(posedge clk) begin
        if (rstn == 0) begin
            secret_key_chip <= 0; 
        end
        else if (secret_key_ready == 1) begin
            secret_key_chip <= {data_in, secret_key_chip[ecc_output_size-1:data_bus_size]};
         end
    
    end
	
	
	//ECC additional delay after write_complete
	always @(posedge clk)begin
		if (rstn == 0) begin
			ecc_write_wait_additional_cycle <= 0;
		end
		else if (ecc_write_wait_additional_cycle_cntl == 1)
			ecc_write_wait_additional_cycle <= 1;
	end

/*   //ECC additional delay after write_complete
	always @(posedge clk)begin
		if (rstn == 0) begin
			combination__g_p_qa_r <= 0;
		end
		else if (combination__g_p_qa_r_crtl == 1)
			combination__g_p_qa_r <= {generator_reg, P_value_trng_reg[P_value_size-1:0], public_key_chip, test_response_reg};
	end*/    
    
    // States for the POCA FSM controller
    parameter   IDLE = 4'd0,
                TRNG_write = 4'd1,
                TRNG_read = 4'd2,
                ECC_write = 4'd3,
                TRNG_write_p = 4'd4,  
                TRNG_read_p = 4'd5,
                Capture_wait = 4'd6,
                Hash_write = 4'd7,
                Hash_read = 4'd8,
                ECC_read = 4'd9,
                Hash_write_1 = 4'd10,
                Hash_read_1 =  4'd11,
                Output_poca = 4'd12,
                ECC_write_secret_key = 4'd13,
                ECC_read_secret_key = 4'd14,
                Done_FSM = 4'd15;
                
     always @(posedge clk) begin
        if (rstn == 0) begin
            state <= IDLE;
        end
        else begin
            state <= next_state;
        end
     end         
       
     always @(*) 
     begin
        
        addr_out = 0;
        enable_data_out = 0;
        is_write= 0;
 //       total_number_byte = 0;
        next_state = state;
        private_key_ready = 0;
       // combination__g_p_qa_r = 0;
        shared_secret_key_ready = 0;
        secret_key_ready = 0;
        ecc_input_1 = 0;
        ecc_input_2 = 0;
        p_value_ready = 0;
        hash_input_r = 0;
        hash_R_ready = 0;
        ecc_mult_ready = 0;
        hash_input_g_p_qa_r = 0;
        hash_combination_ready = 0;
        poca_output_response = 0;
       // capture_load = 0;
        capture_en = 0;
		ecc_write_wait_additional_cycle_cntl = 0;
        poca_output_ready = 0;
	//	ecc_hash_read_transfer_complete_seperate = 0;
        case(state)
            IDLE:   begin
                       if (go == 1) begin
                            next_state = TRNG_write;
                       end
                       else begin
                            next_state = IDLE;
                       end                     
                    end
            
            TRNG_write: begin
                            addr_out = TRNG_write_base_addr;
                            enable_data_out = 32'h00000001;
                            is_write = 1'b1;
  //                          total_number_byte = 8'd4;
                            if (write_complete == 1) begin
                                next_state = TRNG_read;
                            end
                            else begin
                                next_state = TRNG_write;
                            end
                        end
            
            TRNG_read:  begin
                            addr_out = TRNG_read_base_addr;
                            is_write = 1'b0;
                            if (data_input_ready == 1 ) begin
                                private_key_ready = 1;
                            end
                            else  begin
                                private_key_ready = 0;
                            end
                            if (input_data_transfer_complete == 1) begin
                                next_state = ECC_write;
                            end 
                            else begin
                                 next_state = TRNG_read;
                            end
                        end
     
            ECC_write:  begin
							
                            addr_out = ECC_write_base_addr;
                            enable_data_out = 32'h00000001;
                            ecc_input_1 = generator_reg;
                            ecc_input_2 = private_key_chip;
                            is_write = 1'b1;
                            if (write_complete == 1 & state == ECC_write) begin
				ecc_write_wait_additional_cycle_cntl = 1;
		 	    end
			    else if (write_complete == 0 & ecc_write_wait_additional_cycle == 1) begin
                                next_state = TRNG_write_p;
                            end
                            else begin
                                next_state = ECC_write;
                            end
                        end
                        
            TRNG_write_p:   begin
                                addr_out = TRNG_write_base_addr;
                                enable_data_out = 32'h00000001;
                                is_write = 1'b1;
  
                                if (write_complete == 1) begin
                                    next_state = TRNG_read_p;
                                end
                                else begin
                                    next_state = TRNG_write_p;
                                end
                             end 
                               
              TRNG_read_p:  begin
                                addr_out = TRNG_read_base_addr;
                                is_write = 1'b0;
                               
                                if (data_input_ready == 1 ) begin
                                    p_value_ready = 1;
                                end
                                else  
                                   p_value_ready = 0;
                                                          
                                if (input_data_transfer_complete == 1) begin
                                    //capture_load = 1;
                                    next_state = Capture_wait;
                                end
                                else begin
                                     next_state = TRNG_read_p;
                                end
                               
                               
                            end
                              
               Capture_wait: begin
								
                                capture_en = 1;
                                if (test_response_ready == 1 ) begin
                                   next_state = Hash_write; 
                                end
                                else 
                                    next_state = Capture_wait;
                            end 
               
                        
               Hash_write: begin
                                addr_out = Hash_write_base_addr;
                                enable_data_out = 32'h00000001;
                                hash_input_r = test_response_reg;
                                is_write = 1'b1;
                                if (write_complete == 1) begin
                                    next_state = Hash_read;
                                end
                                else begin
                                    next_state = Hash_write;
                                end
                            end
                            
                Hash_read:  begin
                                addr_out = Hash_read_base_addr;
                                is_write = 1'b0;
                                if (data_input_ready == 1 ) begin
                                    hash_R_ready = 1;
                                end
                                else  
                                   hash_R_ready = 0;
                                                          
                               if (input_data_transfer_complete == 1) begin
                                     next_state = ECC_read;
                                end
                                else begin
                                     next_state = Hash_read;
                                end
                                
                             end
                            
                  ECC_read:  begin
                                addr_out = ECC_read_base_addr;
                                is_write = 1'b0;
                                if (data_input_ready == 1 ) begin
                                    ecc_mult_ready = 1;
                        //            ecc_hash_read_transfer_complete_seperate = 1;
                                end
                                else  
                                   ecc_mult_ready = 0;
                                                          
                               if ( input_data_transfer_complete == 1) begin
                                   next_state = Hash_write_1;
                                     
                                end
                                else begin
                                     next_state = ECC_read;
                                end
                                
                            end         
         
                 Hash_write_1: begin
                                addr_out = Hash_write_base_addr;
                                enable_data_out = 32'h00000001;
                                hash_input_g_p_qa_r = combination__g_p_qa_r;
                                is_write = 1'b1;
                                if (write_complete == 1) begin
                                    next_state = Hash_read_1;
                                end
                                else begin
                                    next_state = Hash_write_1;
                                end
                            end
                            
                Hash_read_1:  begin
                                addr_out = Hash_read_base_addr;
                                is_write = 1'b0;
                                if (data_input_ready == 1 ) begin
                                    hash_combination_ready = 1;
                                end
                                else  
                                   hash_combination_ready = 0;
                                                          
                                if (input_data_transfer_complete == 1) begin
                                     next_state = Output_poca;
                                end
                                else begin
                                     next_state = Hash_read_1;
                                end
                            end
                            
               Output_poca: begin
                                poca_output_response = {hash_R_reg, hash_g_p_qa_r, public_key_chip};
                                poca_output_ready = 1;
                                if (hsm_key_received == 1) begin
                                    next_state = ECC_write_secret_key;
                                end
                                else begin
                                    next_state = Output_poca;
                                end
                            end
               
                            
                ECC_write_secret_key: begin
                                            addr_out = ECC_write_base_addr;
                                            enable_data_out = 32'h00000001;
                                            ecc_input_1 = hsm_public_key_reg;
                                            ecc_input_2 = private_key_chip;
                                            is_write = 1'b1;
                                            if (write_complete == 1) begin
                                                next_state =  ECC_read_secret_key;
                                            end
                                            else begin
                                                next_state = ECC_write_secret_key;
                                            end
                
                                      end
                                      
                 ECC_read_secret_key:  begin
                                            addr_out = ECC_read_base_addr;
                                            is_write = 1'b0;
                                            if (data_input_ready == 1 ) begin
                                                secret_key_ready = 1;
                                            end
                                            else  
                                                secret_key_ready = 0;
                                                          
                                            if ( input_data_transfer_complete == 1) begin
                                                next_state = Done_FSM;
                                     
                                            end
                                            else begin
                                                next_state = ECC_read_secret_key;
                                            end

                                        end    
                                        
                 Done_FSM:  begin
                                   
                                            shared_secret_key_ready = 1;
                                            if (go == 0) begin
                                                next_state = IDLE;
                                            end
                                           
                                            else begin
                                                next_state = Done_FSM;
                                            end
                                        end               
        endcase
    end
    
endmodule
