# Save IMU's Data from Reach RTK (local storage)
## Information
- You have to connect the Reach M+ and your computer to the same WiFi. 
  - To connect the Reach to a new WiFi, follow this link: [Emild documentation](https://docs.emlid.com/reachm-plus/common/reachview/).
  - If you are not able to connect the Reach to a network, the Reach will automatically create its own WiFi named like "reach:3B:C8" and the blue light remains on (not flashing). To connect to this network with your computer, the password is "emlidreach". 
- In all following command lines where "IpAddressOfTheReach" is written, you have to replace it by the address IP of the Reach (for example: 192.168.42.1).
- When you use Putty or the Terminal, you'll be asked to enter :
  - "Password" -> This is the password of your computer
  - "root@IpAddressOfTheReach password" --> This is the Reach password (Default password : emlidreach)

## Searching the IP address
- The easiest way to find the IP address is the ReachView app. You can download it for:
  - iPhone: [AppStore](https://itunes.apple.com/us/app/reachview/id1295196887?mt=8).
  - Android: [Google Play](https://play.google.com/store/apps/details?id=com.reachview). ## Software needed for Windows
- WinSCP: [Download link](https://winscp.net/eng/download.php).
- Putty: [Download link](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html). You have to go to the "Alternative binary files" section and download "putty.exe (the SSH and Telnet client itself)".

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
    b. Type: sudo scp /ThePathOfTheFolderOnYourComputer root@IpAddressOfTheReach:/home/root/
    c. Then follow the steps by typping your password and the Reach's password

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
       1. cd /home/root/Save-IMU-s-Data-Reach-RTK-master/
       2. sudo make clean && make
       3. sudo cp /home/root/Save-IMU-s-Data-Reach-RTK-master/imu-bash /etc/init.d/
       4. sudo chmod 0755 /etc/init.d/imu-bash
       5. systemctl daemon-reload
       6. sudo update-rc.d imu-bash defaults
    d. Restart the Reach with: sudo reboot
    e. Now every time that the reach is powered on, the program will automaticaly start
  ####  On Linux / macOS
    a. Open a new Terminal window
    b. Connect to the Reach with the command: ssh root@IpAddressOfTheReach. 
       - Default password : emlidreach
    c. Type these following commands:
       1. cd /home/root/Save-IMU-s-Data-Reach-RTK-master/
       2. sudo make clean && make
       3. sudo cp /home/root/Save-IMU-s-Data-Reach-RTK-master/imu-bash /etc/init.d/
       4. sudo chmod 0755 /etc/init.d/imu-bash
       5. systemctl daemon-reload
       6. sudo update-rc.d imu-bash defaults
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
    d. Type the command: sudo make clean && make
    e. Launch the program with: ./reach
  #### On Linux / macOS
    a. Open the Terminal.
    b. Connect to the Reach with the command: ssh root@IpAddressOfTheReach. 
       - Default password : emlidreach
    c. Go to the repertory: cd /home/root/Save-IMU-s-Data-Reach-RTK-master/
    d. Type the command: sudo make clean && make
    e. Launch the program with: ./reach

## Receive data
  ####  On Windows
    a. Open WinSCP (or a similar software)
    b. Connect to the Reach M+ with:
       - The host name: the IP address of the Reach
       - Username: root
       - Default password: emlidreach
    c. On the right window of WinSCP, go to
	-> "Save-IMU-data-from-Reach-M-Plus-master"
		-> "TXT-Files"
    d. Now, you can drag and drop all files of this folder to your computer and then delete them on the Reach.
  ####  On Linux / macOS
    a. Open a new Terminal window
    b. Type this command line: sudo scp -r root@IpAddressOfTheReach:/home/root/Save-IMU-Data-from-Reach-M-Plus-master/TXT-Files/ ~/Downloads/
    c. Now, you can delete all TXT-files: sudo rm -r root@IpAddressOfTheReach:/home/root/Save-IMU-Data-from-Reach-M-Plus-master/TXT-Files/ && sudo mkdir root@IpAddressOfTheReach:/home/root/Save-IMU-Data-from-Reach-M-Plus-master/TXT-Files/
