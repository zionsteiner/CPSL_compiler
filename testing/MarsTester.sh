testList=("examples/simple_expressions" "examples/control" "examples/udt")
echo "" > marsOutput.txt
for dir in "${testList[@]}"; do
  for testFile in "$dir"/*.cpsl; do
    echo "" > mips.asm
    ./../cmake-build-debug/CPSL_compiler < "$testFile" > mips.asm 2>&1
    java -jar ../../Mars4_5.jar mips.asm >> marsOutput.txt
  done
done