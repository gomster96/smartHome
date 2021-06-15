# Process of setting
1. Download Raspbian from [https://www.raspberrypi.org/downloads/](raspberrypi.org)
2. Download balenaEtcher [https://www.balena.io/etcher/](Link)
3. Download Rasbian in SDcard by using balenaEtcher
4. After Dowonloading finish, then make file named "ssh" 
    - It is for accesss raspberryPi by using ssh
5. Making file named "wpa_supplicant.conf" then put code like this
<pre>
<code>
ctrl_interface=DIR=/var/run/wpa_supplicant GRUOP=netdev
update_config = 1
network={
    ssid="name of WIFI"
    psk= "password of WIFI"
}
</code>
</pre>
6. After That put your SDcard in your RaspberryPi
7. finally, you can connecn RaspberryPi.
- ssh pi@"IP address of WIFI"
- initial password is "raspberry"
8. That's all

## The problem that I got
- When you use ssh, this record is saved in our computer 
- Check the directory 
    - "/Users/home/.ssh/known_hosts"