cmake -DLICENSE_TYPE=PROFESSIONAL_LICENSE -DCMAKE_BUILD_TYPE=Debug --graphviz=GIdeps.dot .

mkdir -p dependencies
rm dependencies/*
cp graphviz-cleaner.py dependencies/
cp GIdeps* dependencies/
cd dependencies

for f in `ls *.dot*`
do
python graphviz-cleaner.py -u -p KDE -p pthread -p imageplugin -f ${f}.cleaned  ${f}
done

for f in `ls *.cleaned`
do
dot -Teps $f > ${f}.eps
done
