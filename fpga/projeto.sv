module projeto(
     input [0:3] ESP, //entrada: ESP GPIO
     input [0:15] CH, // Chaves
     output logic S//, //saída: Estado da chave	  
    );
	 
    always_comb //processo combinacional: executado de forma contínua
    begin
        case (ESP) //caso a variável ESP vale:
            0 :  S = CH[0];
            1 :  S = CH[1];
            2 :  S = CH[2]; 
            3 :  S = CH[3]; 
            4 :  S = CH[4]; 
            5 :  S = CH[5]; 
            6 :  S = CH[6]; 
            7 :  S = CH[7];
            8 :  S = CH[8];
            9 :  S = CH[9];
	      10 :  S = CH[10];
            11 :  S = CH[11];  
            12 :  S = CH[12]; 
            13 :  S = CH[13];
            14 :  S = CH[14];
            15 :  S = CH[15];
            default :  S = CH[10];
        endcase
    end
endmodule
