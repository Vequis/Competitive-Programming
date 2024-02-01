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

architecture fibArch of fib is 

    signal contador, limite: unsigned(7 downto 0);
    signal ant1: unsigned(15 downto 0) := unsigned("00000000" & F1);
    signal ant2: unsigned(15 downto 0) := unsigned("00000000" & F2);
    signal soma: unsigned(16 downto 0) := "000000000" & "00000000"; 
    signal acabou: bit := '1';
    signal fim2: bit;

begin
    fim <= fim2;

    process(clock, reset)
    begin

        if (reset = '1') then
            ant1 <= unsigned("00000000" & F1);
            ant2 <= unsigned("00000000" & F2);
            contador <= "00000001";
            fim2 <= '0';
            acabou <= '1';

            Fn <= "00000000" & "00000000";
            contador <= contador + 1;

            soma <= "000000000" & "00000000";

            overflow <= '0';
            limite <= unsigned(n);
        end if;

        if (clock'event and clock = '1') then 

            if (fim2 = '1') then
                fim2 <= '0';
            end if;

            if (acabou = '1') then 
                overflow <= '0';
                fim2 <= '0';
                Fn <= "00000000" & "00000000";
            end if;

            if (acabou = '1' and inicio = '1') then
 
                ant1 <= unsigned("00000000" & F1);
                ant2 <= unsigned("00000000" & F2);
                contador <= "00000001";
                fim2 <= '0';
                acabou <= '0';

                Fn <= "00000000" & F1;
                contador <= contador + 1;

                soma <= "000000000" & "00000000";

                overflow <= '0';
                limite <= unsigned(n);

                if (n = "00000000") then 
                	acabou <= '1';
                end if;

            elsif (acabou = '0') then
            if (contador = "00000010") then
                    Fn <= "00000000" & F2;
                elsif (contador <= limite) then
                    soma <= ('0' & ant1) + ('0' & ant2);
                    contador <= contador + 1;

                    if (soma(16) = '1') then
                        fim2 <= '1';
                        acabou <= '1';
                        overflow <= '1';
                    else
                        ant1 <= ant2;
                        ant2 <= soma(15 downto 0);
                        Fn <= bit_vector(soma(15 downto 0));
                    end if;
                elsif (contador >= limite) then
                	acabou <= '1';
                    fim2 <= '1';
                end if; 

            end if;
        end if;
    end process;

end fibArch;