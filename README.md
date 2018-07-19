# Save IMU's Data from Reach RTK (local storage)

## Installation on the Reach RTK
1. Connect the Reach RTK and your computer to the same Wifi.
2. Download the repository "Save-IMU-s-Data-Reach-RTK".
3. Transfer this repository to the Reach:
  #### On Windows
    a. Open WinSCP (or a similar software)
    b. Connect to the Reach RTK with its IP address
       - Username: root
       - Default password: emlidreach
    c. Go to the repertory: /home/root/
    d. Copy the repository from your computer and paste it on the Reach
  #### On Linux / macOS
    a. Open a new Terminal window
    b. Connect to the Reach with the command: ssh root@IpAddressOfTheReach. 
       - Default password : emlidreach
    c. Type: sudo scp /ThePathOfTheFolderOnYourComputer root@IpAddressOfTheReach:/home/root/
    d. Then follow the steps by typping your password and the Reach's password

## Start the program
  Two possibilities are available to start this program:
  ### Automatic startup when the Reach is powered on
  ####  On Windows
    a. Open Putty (or a similar software)
    b. Connect to the Reach RTK with its IP address
       - Username: root
       - Default password: emlidreach
    c. Type these following commands: 
       1. sudo cp /home/root/Save-IMU-s-Data-Reach-RTK-master/imu-bash /etc/init.d/
       2. sudo chmod 0755 /etc/init.d/imu-bash
       3. systemctl daemon-reload
       3. sudo update-rc.d imu-bash defaults
    d. Restart the Reach with: sudo reboot
  ####  On Linux / macOS
    a. Open a new Terminal window
    b. Connect to the Reach with the command: ssh root@IpAddressOfTheReach. 
       - Default password : emlidreach
    c. Type these foloowing commands:
       1. sudo cp /home/root/Save-IMU-s-Data-Reach-RTK-master/imu-bash /etc/init.d/
       2. sudo chmod 0755 /etc/init.d/imu-bash
       3. systemctl daemon-reload
       3. sudo update-rc.d imu-bash defaults
    d. reatsrt the Reach with: sudo reboot
     
