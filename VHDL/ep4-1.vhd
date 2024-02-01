library IEEE;
use IEEE.numeric_bit.all;

entity signExtend is 
    port(
        i: in bit_vector(31 downto 0);
        o: out bit_vector(63 downto 0)
    );
end entity signExtend;

architecture signExtend_arch of signExtend is

    signal concB: bit_vector(37 downto 0);
    signal concCBZ: bit_vector(44 downto 0);
    signal concDATA: bit_vector(54 downto 0);
    
    begin
        concB <= (others => '0');
        concCBZ <= (others => '0');
        concDATA <= (others => '0');

        o <= (concB & i(25 downto 0)) when (i(31 downto 26) = "000101" and i(25) = '0')          else
            (not(concB) & i(25 downto 0)) when (i(31 downto 26) = "000101" and i(25) = '1')      else
            (concCBZ & i(23 downto 5)) when (i(31 downto 24) = "10110100" and i(23) = '0')       else
            (not(concCBZ) & i(23 downto 5)) when (i(31 downto 24) = "10110100" and i(23) = '1')  else
            (concDATA & i(20 downto 12)) when (i(31 downto 27) = "11111" and i(20) = '0')        else
            (not(concDATA) & i(20 downto 12)) when (i(31 downto 27) = "11111" and i(20) = '1');
end architecture signExtend_arch;    
