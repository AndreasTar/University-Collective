# lab03.asm - Recursive palindrome string tester
#   coded in  MIPS assembly using MARS
# for MYΥ-505 - Computer Architecture, Fall 2021
# Department of Computer Science and Engineering, University of Ioannina
# Instructor: Aris Efthymiou

.globl pdrome

###############################################################################
.data
anna:  .asciiz "anna"
bobob: .asciiz "bobob"

###############################################################################
.text
  la    $a0, anna
  addi  $a1, $zero, 4
  jal   pdrome
  add   $s0, $v0, $zero  # keep the return value

  la    $a0, bobob
  addi  $a1, $zero, 5
  jal   pdrome
  add   $s1, $v0, $zero  # keep the return value
  # both s1 and s0 must be 1 here

  addiu   $v0, $zero, 10    # system service 10 is exit
  syscall                   # we are outa here.


pdrome:
###############################################################################
# Write your code here.
# Any code above the label swapArray is not executed by the tester! 
###############################################################################

	addi $sp, $sp, -12 	# Make space for the 2 s registers we are gonna use and ra...
	sw $ra, 8($sp)
	sw $s2, 4($sp)
	sw $s3, 0($sp)		# ... and store them
	
	add $s3, $a0, $a1	
	addi $s3, $s3, -1	# The address of last letter
	add $s2, $a0, $zero # Address of first letter
	jal pProc
	
	lw $ra, 8($sp)		# Restore them after we are done...
	lw $s2, 4($sp)
	lw $s3, 0($sp)		
	addi $sp, $sp, 12	# ... and pop 3 items
	jr $ra

pProc:
	addi $sp, $sp, -12 	# Make space for 2 addresses and the return Address...
	sw $ra, 8($sp)		
	sw $s3, 4($sp)		
	sw $s2, 0($sp)		# ...and save them
	
	slt $t2, $s3, $s2		# Check if s3 < s2 which only happens if the 2 pointers point to the same letter
							# or have actually passed eachother
	bne $t2, $zero, exitL	# in which case we exit
							# If s3 > s2, we continue
	lb $t3, 0($s2)	# Value of first letter
	lb $t4, 0($s3)	# Value of last letter
	bne $t3, $t4, notPal
	addi $s2, $s2, 1 	# 'Low' pointer increments to next letter
	addi $s3, $s3, -1	# 'High' pointer reduces to previous letter
	jal pProc
	lw $ra, 8($sp)	# Restore return address
	addi $sp, $sp, 12 	# Pop 3 items
	jr $ra
	
	 
notPal:
	add $v0, $zero, $zero	# Set output v0 to 0 = string isnt a palindrome
	lw $ra, 8($sp)	# Restore return address
	addi $sp, $sp, 12 	# Pop 3 items
	jr $ra				# Return to caller

exitL:
	addi $v0, $zero, 1 	# If we get here it means that string is a palindrome
						# So we set output v0 to 1
	lw $ra, 8($sp)	# Restore return address
	addi $sp, $sp, 12 	# Pop 3 items
	jr $ra				# Return to caller

###############################################################################
# End of your code.
###############################################################################
  jr $ra

