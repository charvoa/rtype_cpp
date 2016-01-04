#R-PINT [![Build Status](https://travis-ci.com/charvoa/rtype_cpp.svg?token=pSML9SHkZtFx2hRSmJ4q&branch=dev)](https://travis-ci.com/charvoa/rtype_cpp)

This project is a video game based on the famous R-Type.

## Installation

1. Clone the repo.
2. You'll need all of this :
   - sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
   - sudo apt-get update -qq
   - sudo apt-get install -y cmake
   - sudo apt-get install -y make
   - sudo apt-get install -y g++-4.8
   - export CXX="g++-4.8"
   - wget http://sfml-dev.org/download/sfml/2.1/SFML-2.1-linux-gcc-64bits.tar.bz2 -O /tmp/sfml.tar.bz2
   - tar -xjvf /tmp/sfml.tar.bz2
   - sudo cp -r SFML-2.1/* /usr/
   - sudo apt-get install -y libjpeg62-dev libsndfile1-dev libglew1.5 libglew1.5-dev libfreetype6 libjpeg-turbo8 libjpeg8 libopenal-data libopenal1  libxrandr2 libxrender1 libsoil1
3. `./install.sh` will compile everything you'll need to play the game.
4. See Usage

## Usage

1. After cloning and compiling everything you'll have two executable files, one is the server and the other one is the client.
2. First launch a server on your computer using `cd server/build && ./server_rtype`.
3. Then go to `client/config/PersonalConfig.ini`, set the IP with the IP's computer where the server is launched (0 for localhost) and set the port (default is 4253)
4. Launch the client on your computer : `cd client/build && ./r-type_client`
5. Enjoy ! 

## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request :D

## History

Project started on November 9th 2015. Published on January 4th 2016.

## Credits

Team member : Nicolas Charvoz, Serge Heitlzer, Louis Audibert, Joris Bertomeu, Nicolas Girardot, Viveka Barneaud, Antoine Garcia.