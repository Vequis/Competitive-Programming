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

	type state is (
		esperando,
		calculando,
		finalizado
	);
	signal next_state, state_atual : state;

	signal f1s, f2s: bit_vector(15 downto 0);
	signal fns: bit_vector(7 downto 0);
	signal overflow_next: bit;
    signal proceed: bit := '1';
    signal soma: unsigned(16 downto 0);

begin

	process(clock, reset)
	begin
		if reset='1' then
			state_atual <= esperando;
		elsif rising_edge(clock) then
			state_atual <= next_state;
            proceed <= not proceed;
		end if;
	end process;


	Fn <= f1s;
	process(state_atual, inicio, proceed)
	begin
    	if true then
		case(state_atual) is
		when esperando =>
			f1s <= "0000000000000000";
			f2s <= "0000000000000000";
			overflow <= '0';
			overflow_next <= '0';
			fim <= '0';
			if inicio = '1' then
				f1s <= "00000000"&F1;
				f2s <= "00000000"&F2;
				if unsigned(n) > 1 then
					fns <= bit_vector(unsigned(n)-2);
					next_state <= calculando;
				elsif unsigned(n) = 1 then
					next_state <= finalizado;
				elsif unsigned(n) = 0 then
					next_state <= esperando;
				end if;
			end if;
		when calculando =>
            soma <= (unsigned('0'&f1s) + unsigned('0'&f2s));
			f2s <= bit_vector(soma(15 downto 0));
		    f1s <= f2s;
			fns <= bit_vector(unsigned(fns)-1);
		
            if fns = "00000000" then
                overflow_next <= '0';
                next_state <= finalizado;
            end if;

            if (soma(16) = '0') then
                overflow_next <= '1';
                next_state <= finalizado;
            end if;
        when finalizado =>
			overflow <= overflow_next;
			fim <= '1';
			next_state <= esperando;
            f1s <= "0000000000000000";
		end case;
        end if;
	end process;	
end architecture;