#!/bin/bash

cd Source/
make mrproper
make
make clean
cd ../
echo "cd Source/" > RicochetRobot.sh
echo "./RicochetRobot" >> RicochetRobot.sh
chmod u+x RicochetRobot.sh

nom=`pwd`
#nom=${nom#*'/home/'}
#nom=${nom%%'/'*}

#echo 'export PATH=$PATH:'`pwd`'/Sources/RicochetRobot' >> /home/`echo $nom`/.bashrc 
#PATH=$PATH:$nom/Sources/RicochetRobot


echo "#!/bin/bash" > Unistall_RicochetRobot.sh
echo "cd Source/" >> Unistall_RicochetRobot.sh
echo "make mrproper" >> Unistall_RicochetRobot.sh
echo "cd ../" >> Unistall_RicochetRobot.sh
echo "rm RicochetRobot.sh" >> Unistall_RicochetRobot.sh
echo "rm Unistall_RicochetRobot.sh" >> Unistall_RicochetRobot.sh

chmod u+x Unistall_RicochetRobot.sh