# Save IMU's Data from Reach RTK (local storage)

## Software needed for Windows
- WinSCP: [Download link](https://winscp.net/eng/download.php).
- Putty: [Download link](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html). You have to go to the "Alternative binary files" section and download "putty.exe (the SSH and Telnet client itself)".

## Installation on the Reach RTK
1. Connect the Reach RTK and your computer to the same Wifi.
2. Download the repository "Save-IMU-s-Data-Reach-RTK".
3. Unzip the folder if it's not done yet.
4. Transfer this repository to the Reach:
  #### On Windows
    a. Open WinSCP (or a similar software)
    b. Connect to the Reach RTK with:
       - The host name: the IP address of the Reach
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
    b. Connect to the Reach RTK with:
       - The host name: the IP address of the Reach
       - Username: root
       - Default password: emlidreach
    c. Type these following commands: 
       1. sudo cp /home/root/Save-IMU-s-Data-Reach-RTK-master/imu-bash /etc/init.d/
       2. sudo chmod 0755 /etc/init.d/imu-bash
       3. systemctl daemon-reload
       3. sudo update-rc.d imu-bash defaults
    d. Restart the Reach with: sudo reboot
    e. Now every time that the reach is powered on, the program will automaticaly start
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
    e. Now every time that the reach is powered on, the program will automaticaly start

  ### Manual startup with command line
  **_For this method, the device that starts the program must be remain on and connected to the same network as the Reach. If one of these conditions is not respected, the program will end!_**
  #### On Windows
    a. Open Putty (or a similar software).
    b. Connect to the Reach RTK with:
       - The host name: the IP address of the Reach
       - Username: root
       - Default password: emlidreach
    c. Go to the repertory: cd /home/root/Save-IMU-s-Data-Reach-RTK-master/
    d. Type the command: sudo make
    e. Launch the program with: ./reach
  #### On Linux / macOS
    a. Open the Terminal.
    b. Connect to the Reach with the command: ssh root@IpAddressOfTheReach. 
       - Default password : emlidreach
    c. Go to the repertory: cd /home/root/Save-IMU-s-Data-Reach-RTK-master/
    d. Type the command: sudo make
    e. Launch the program with: ./reach
