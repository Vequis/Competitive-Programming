library ieee;
use ieee.numeric_bit.all;

entity fib is
	port(
        reset, clock, inicio: in bit;
        F1, F2, n: in bit_vector(7 downto 0);
        Fn: out bit_vector(15 downto 0);
        fim, overflow: out bit
	);
end fib;

architecture fib_arch of fib is

	type estado is (
		idle,
		processing,
		finished
	);
	signal proximo_estado, estado_atual : estado;

	signal f1_in, f2_in: bit_vector(15 downto 0);
	signal f1_out, f2_out: bit_vector(15 downto 0);
	signal fn_in, fn_out: bit_vector(7 downto 0);
	signal overflow_next: bit;

begin

	process(clock, reset)
	begin
		if reset='1' then
			estado_atual <= idle;
		elsif rising_edge(clock) then
			estado_atual <= proximo_estado;
		end if;
	end process;


	Fn <= f1_out;
	process(estado_atual, inicio)
	begin
		case(estado_atual) is
		when idle =>
			f1_in <= "0000000000000000";
			f2_in <= "0000000000000000";
			overflow <= '0';
			overflow_next <= '0';
			fim <= '0';
			if inicio = '1' then
				f1_in <= "00000000"&F1;
				f2_in <= "00000000"&F2;
				if unsigned(n) > 1 then
					fn_in <= bit_vector(unsigned(n)-2);
					proximo_estado <= processing;
				elsif unsigned(n) = 1 then
					proximo_estado <= finished;
				elsif unsigned(n) = 0 then
					proximo_estado <= idle;
				end if;
			end if;
		when processing =>
			f2_in <= bit_vector(unsigned(f1_out) + unsigned(f2_out));
		    f1_in <= f2_out;
			fn_in <= bit_vector(unsigned(fn_out)-1);
		
            if fn_out = "00000000" then
                overflow_next <= '0';
                proximo_estado <= finished;
            end if;

            if (unsigned("0"&f1_out) + unsigned("0"&f2_out) > 65535) then
                overflow_next <= '1';
                proximo_estado <= finished;
            end if;
        when finished =>
			f1_in <= f1_out;
			f2_in <= f2_out;
			fn_in <= fn_out;
			overflow <= overflow_next;
			fim <= '1';
			proximo_estado <= idle;
		end case;
	end process;	
end architecture;