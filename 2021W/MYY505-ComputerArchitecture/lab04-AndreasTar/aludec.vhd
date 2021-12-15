library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;


entity aludec is
    port(
        funct      : in  std_logic_vector(5 downto 0); -- Funct Field of R-type Instructions.
        aluop      : in  std_logic_vector(1 downto 0);
        alucontrol : out std_logic_vector(2 downto 0)
    );
end entity aludec;


architecture RTL of aludec is
begin
    proc : process(aluop, funct)
    begin
        case aluop is
            when "00" => -- force ADD (for lw, sw)
                alucontrol <= "010" after 2 ns;
            when "01" => -- force SUB (for beq)
                alucontrol <= "110" after 2 ns; -- SUB
            when "10" => 
                case funct is
                    when "100000" =>  -- ADD
                        alucontrol <= "010" after 2 ns;
                    when "100100" =>  -- AND
                        alucontrol <= "000" after 2 ns;
                    when "100101" =>  -- OR
                        alucontrol <= "001" after 2 ns;
                    when "100010" =>  -- SUB
                        alucontrol <= "110" after 2 ns; -- It had the same command code as ADD, changed it to be the same as seen in 'Force SUB'
                    when "101010" =>  -- SLT
                        alucontrol <= "111" after 2 ns;
                    when others => 
                        alucontrol <= "XXX" after 2 ns;
                end case;
            when "11" =>  -- force OR (for ORI, LUI)
                alucontrol <= "001" after 2 ns;
            when others => 
                alucontrol <= "XXX" after 2 ns;
        end case;
    end process proc;
end architecture RTL;
