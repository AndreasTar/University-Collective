# ----------------------------------------------------------------------------------------
# testForwarding.asm 
#  Verify correctness of forwarding logic of the 5-stage pipelined MIPS processor
#    used in MYY505
# At exit, v1 will be 0 when all tests pass. Any other number indicates a mistake in pipeline control
# ----------------------------------------------------------------------------------------

.data

.text
# ----------------------------------------------------------------------------------------
# prepare register values.
# ----------------------------------------------------------------------------------------
#  DO NOT USE li as it breaks into 2 instructions and requires forwarding $at between them.
#  I use la here, but I should have assigned the address to $a0 differently

# ----------------------------------------------------------------------------------------
# Test 1 description here
# -to input A of ALU

#  -- code

# ---------------------
# -to input B of ALU
#  -- code

# ----------------------------------------------------------------------------------------
# Test 2 description here







exit:  # Check $v1. 0 means all tests pass, any other value is a unique error
    addiu      $v0, $zero, 10    # system service 10 is exit
    syscall