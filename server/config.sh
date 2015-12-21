rm -rf build/ && rm -f ./server_rtype && ls --color=auto && mkdir build && cd build && cmake .. && make && cp ./server_rtype ../ && cd .. && ls --color=auto && cd libs/ && ./allbuild.sh
