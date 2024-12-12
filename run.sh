setup(){
    echo "Entering libInMemoryDB and running makefile..."
    cd ./libInMemoryDB
    if ! make; then
        echo "Library did not compile. Exiting."
        exit
    fi
    cd ..
}

run(){
    echo "Compiling and running test file"
    g++ -std=c++17 -o test.out test.cpp -L ./libInMemoryDB -lInMemoryDB
    ./test.out
}

main(){
    setup
    run
}

main