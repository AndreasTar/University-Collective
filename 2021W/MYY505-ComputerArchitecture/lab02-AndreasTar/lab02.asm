
# lab02.asm - Pairwise swap in an array of 32bit integers
#   coded in  MIPS assembly using MARS
# for MYY-505 - Computer Architecture, Fall 2021
# Department of Computer Science and Engineering, University of Ioannina
# Instructor: Aris Efthymiou

        .globl swapArray # declare the label as global for munit
        
###############################################################################
        .data
array: .word 5, 6, 7, 8, 1, 2, 3, 4

###############################################################################
        .text 
# label main freq. breaks munit, so it is removed...
        la         $a0, array 	# This is address of first element of the array
        li         $a1, 8 		# This is the size of the array, ALWAYS EVEN


swapArray:
###############################################################################
# Write your code here.
# Any code above the label swapArray is not executed by the tester! 
###############################################################################

	srl $t1, $a1, 1 	# Divides by 2 the size of the array
	add $t2, $a0, $zero # $t2 points to a0[0]				
	add $t3, $a0, $zero # Points to a0[0]
	beq $a1, $zero, exit # Checks if array size is 0, if True then exits immidately
	
indexLoop: # This is for finding the middle of the array
	addi $t3, $t3, 4	# Points to next element in array
	addi $t1, $t1, -1
	bne $t1, $zero, indexLoop	# If t1 reaches 0, it means t3 is pointing at the middle element, and we start swapping

	srl $t1, $a1, 1 	# Same as line 27

swapLoop: # This is for swapping elements
	lw $t4, 0($t2)	# Makes temporary-t4 be data at a0[i]
	lw $t5, 0($t3)	# Makes temporary-t5 be data at a0[size/2 +i]
	sw $t5, 0($t2)	# Stores data of t5 to a0[i]
	sw $t4, 0($t3)	# Stores data of t4 to a0[size/2 +i]
	
	addi $t2, $t2, 4	# Increment t2 and t3 by 1 word size, basically next memory address
	addi $t3, $t3, 4
	
	addi $t1, $t1, -1
	bne $t1, $zero, swapLoop 	# If t1 == 0 we reached the end of the array and we leave. Otherwise we repeat
	

###############################################################################
# End of your code.
###############################################################################
exit:
        addiu      $v0, $zero, 10    # system service 10 is exit
        syscall                      # we are outta here.


