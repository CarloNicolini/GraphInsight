# Ripulisce tutto quanto 
git clean -df .

# Fa la build delle 3 versioni con le 3 licenze diverse
for license in `echo "Trial Pro Academic"`
do
cmake -DCMAKE_BUILD_TYPE=Release -DLICENSE_TYPE=${license} .
make all package -j 8 
done

