entity alucontrol is
    port(
        aluop: in bit_vector(1 downto 0);
        opcode: in bit_vector(10 downto 0);
        aluCtrl: out bit_vector(3 downto 0)
    );
end entity;

architecture alucontrol_arch of alucontrol is
    signal aluCtrlBV: bit_vector(3 downto 0);
begin

    aluCtrlBV <= (
        3 => '0',
        2 => opcode(9),
        1 => opcode(3),
        0 => opcode(8)
    );

    with aluop select aluCtrl <=
        "0010"      when "00",
        "0111"      when "01",
        aluCtrlBV    when others;

end architecture alucontrol_arch;