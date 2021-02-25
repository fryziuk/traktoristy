g++ io_handler.cpp main.cpp -o solution
for f in b.txt c.txt d.txt e.txt f.txt; do
    echo "$f..."
    cat $f | ./solution > $f.out
done
