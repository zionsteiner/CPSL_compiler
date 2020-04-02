testList=("examples/simple_expressions")
echo "" > grammarCheck.txt
for dir in "${testList[@]}"; do
  for testFile in "$dir"/*.cpsl; do
    echo "$testFile" >> grammarCheck.txt
    ./../cmake-build-debug/CPSL_compiler < "$testFile" >> grammarCheck.txt 2>&1
    echo "" >> grammarCheck.txt
  done
done