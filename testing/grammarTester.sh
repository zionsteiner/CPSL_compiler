testList=("examples/simple_expressions")
for dir in "${testList[@]}"; do
  for testFile in examples/simple_expressions/*.cpsl; do
    echo "${dir}"
    echo "${testFile}"
    ./../cmake-build-debug/CPSL_compiler < "${testFile}" >> grammarCheck.txt
  done
done