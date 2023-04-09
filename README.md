# SwarmProject

## Installation

1- Install ARGoS (Instructions obtained from [github repo](https://github.com/ilpincy/argos3), check repo for dependencies)
```
git clone https://github.com/ilpincy/argos3.git argos3
cd argos3
mkdir build_simulator
cd build_simulator
cmake ../src
make
sudo make install
```

2- Install Buzz (Instructions obtained from [official repo](https://github.com/buzz-lang/Buzz))
```
git clone https://github.com/buzz-lang/Buzz.git buzz
cd buzz
mkdir build && cd build
cmake ../src
make
sudo make install
sudo ldconfig
```

3- Install Khepera plugin for argos
```
git clone https://github.com/ilpincy/argos3-kheperaiv.git
cd argos3-kheperaiv
mkdir build_sim
cd build_sim
cmake -DCMAKE_BUILD_TYPE=Release ../src
make
sudo make install
```

4- Clone and build the repository
```
clone git@github.com:Sh3mm/SwarmProject.git
cd SwarmProject/loop_funcs
mkdir build
cd build
cmake ..
make
```

## Source the required environment variables

```
export BUZZ_INCLUDE_PATH=~/SwarmProject/buzz_scripts/include/
```
Or add it to the bashrc
```
echo "export BUZZ_INCLUDE_PATH=~/SwarmProject/buzz_scripts/include/" >> ~/.bashrc
```

## Launch the simultation

```
cd SwarmProject
. run.sh
```