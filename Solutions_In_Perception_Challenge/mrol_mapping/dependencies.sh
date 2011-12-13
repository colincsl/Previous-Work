# Specify the directory to search for dependencies
# requires snakefood and graphviz
searchdir=$1
files=`find $searchdir | grep py$` 
deps=/tmp/deps.txt

echo $files

sfood -i $files > $deps 
grep mrol_mapping $deps | grep -v _test | sfood-graph | sfdp  -Tx11 &
grep mrol_mapping $deps | sfood-graph | sfdp  -Tx11
