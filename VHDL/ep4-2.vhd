entity fulladder is 
	port(
    	a, b, cin : in bit;
        s, cout : out bit
    );
end entity;

architecture fulladder_arch of fulladder is 

	begin
    
    	s <= ((not cin) and (a xor b)) or (cin and (not (a xor b)));
        cout <= (a and b) or (cin and a) or (cin and b);
    
end fulladder_arch;



library ieee;
use ieee.numeric_bit.all;

entity alu1bit is 
    port (
    	a, b, less, cin : in bit;
        result, cout, set, overflow : out bit;
        ainvert, binvert : in bit;
        operation : in bit_vector (1 downto 0)
    );
end entity;

architecture alu1_arch of alu1bit is 
	
    component fulladder is 
		port(
    		a, b, cin : in bit;
        	s, cout : out bit
    	);
	end component;
    
    signal a_aux : bit;
    signal b_aux : bit;
    
    signal resultado : bit;
    signal cout_var : bit;
    
	begin
        
        a_aux <= a xor ainvert;       
        b_aux <= b xor binvert;
        
    	somador : fulladder port map (a_aux, b_aux, cin, resultado, cout_var);

        cout <= cout_var;
        set <= resultado;
        overflow <= (cout_var xor cin);
        
        result <=   (a_aux and b_aux) when operation = "00" else 
                    (a_aux or b_aux) when operation = "01" else
                    resultado when operation = "10" else
                    less when operation = "11";

end alu1_arch;

entity alu is
    generic(
        size: natural := 10
    );
    port(
        A, B: in bit_vector(size-1 downto 0);
        F: out bit_vector(size-1 downto 0);
        S: in bit_vector(3 downto 0);
        Z: out bit;
        Ov: out bit;
        Co: out bit
    );
end entity alu;

architecture alu_arch of alu is
    component alu1bit is
        port(
            a, b, less, cin: in bit;
            result, cout, set, overflow: out bit;
            ainvert, binvert: in bit;
            operation: in bit_vector(1 downto 0)
        );
    end component alu1bit;
    
    type arCon is array (0 to size-1) of bit;
    signal carryArray: arCon; 
    signal zeroArray: arCon; 
    signal ovfArray: arCon; 
    
    signal check: bit_vector(size-1 downto 0); 
    signal zeroes: bit_vector(size-1 downto 0); 

    signal subtraction: bit; 

    begin 

        genCond: for i in 0 to size-1 generate

            lower: if i = 0 generate
                alu0: alu1bit port map(A(0), B(0), zeroArray(size-1), subtraction, check(0), carryArray(0), zeroArray(0), ovfArray(0), S(3), S(2), S(1 downto 0));
            end generate lower;

            middle: if (i /= 0 and i /= (size-1)) generate
                alux: alu1bit port map(A(i), B(i), '0', carryArray(i-1), check(i), carryArray(i), zeroArray(i), ovfArray(i), S(3), S(2), S(1 downto 0));
            end generate middle;

            ending: if (i /= 0 and i = (size-1)) generate
                aluf: alu1bit port map(A(size-1), B(size-1), '0', carryArray(size-2), check(size-1), carryArray(size-1), zeroArray(size-1), ovfArray(size-1), S(3), S(2), S(1 downto 0));
            end generate ending;

        end generate genCond;

        Ov <= ovfArray(size-1);
        Co <= carryArray(size-1);

        F <= check; 

        zeroes <= (others => '0');

        Z <= '1' when (check = zeroes) else
            '0'; 

        subtraction <= (S(2) and S(1)) or (S(3) and S(2)) ;
end architecture alu_arch;