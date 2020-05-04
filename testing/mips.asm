                                
	.text
.globl main
main:
move $fp, $sp
addi $sp, $sp, -24
# Assignment
# LVal
li $25, -12
sub $25, $fp, $25
li $24, 1
sw $24, ($25)
# Assignment
# LVal
li $25, -16
sub $25, $fp, $25
li $24, 2
sw $24, ($25)
# Assignment
# LVal
li $25, -20
sub $25, $fp, $25
li $24, 3
sw $24, ($25)
# Assignment
# LVal
li $25, 0
sub $25, $fp, $25
li $24, 0
# Sub
sub $23, $25, $24
# LVal
li $24, -12
sub $24, $fp, $24
lw $24, ($24)
# LVal
li $25, -16
sub $25, $fp, $25
lw $25, ($25)
# Mult
mult $24, $25
mflo $22
sw $22, ($23)
# Assignment
# LVal
li $23, 0
sub $23, $fp, $23
li $22, 4
# Sub
sub $24, $23, $22
# LVal
li $22, -16
sub $22, $fp, $22
lw $22, ($22)
# LVal
li $23, -20
sub $23, $fp, $23
lw $23, ($23)
# Mult
mult $22, $23
mflo $25
sw $25, ($24)
# Assignment
# LVal
li $24, 0
sub $24, $fp, $24
li $25, 8
# Sub
sub $22, $24, $25
# LVal
li $25, -20
sub $25, $fp, $25
lw $25, ($25)
# LVal
li $24, -12
sub $24, $fp, $24
lw $24, ($24)
# Mult
mult $25, $24
mflo $23
sw $23, ($22)
# Write STR
li $v0, 4
# StrConstExpr
la $22, str1
la $a0, ($22)
syscall
# Write INT OR BOOL
li $v0, 1
# LVal
li $22, 0
sub $22, $fp, $22
li $23, 0
sub $22, $22, $23
lw $22, ($22)
move $a0, $22
syscall
# Write CHR
li $v0, 11
li $22, ' '
move $a0, $22
syscall
# Write INT OR BOOL
li $v0, 1
# LVal
li $22, 0
sub $22, $fp, $22
li $23, 4
sub $22, $22, $23
lw $22, ($22)
move $a0, $22
syscall
# Write CHR
li $v0, 11
li $22, ' '
move $a0, $22
syscall
# Write INT OR BOOL
li $v0, 1
# LVal
li $22, 0
sub $22, $fp, $22
li $23, 8
sub $22, $22, $23
lw $22, ($22)
move $a0, $22
syscall
# Write CHR
li $v0, 11
li $22, '\n'
move $a0, $22
syscall
# Write STR
li $v0, 4
# StrConstExpr
la $22, str2
la $a0, ($22)
syscall
# Exit
li $v0, 10
syscall
	.data

str1: .asciiz "Result  : "
str2: .asciiz "Expected: 2 6 3\n"
